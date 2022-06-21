#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

static int dev_pid;
static int fd;
volatile int stopwatch_en;

//void stopwatch();

void usrsignal(int sig){
	printf("GPIO button signal interrrupt!\n\r"); // buf msg 
	if(stopwatch_en == 0){
		printf("stopwatch running\n\r");
		usleep(1);
		stopwatch_en = 1;
	}
	else if(stopwatch_en == 1){
		printf("stopwatch stopped\n\r");
		usleep(1);
		stopwatch_en = 0;
	}
	printf("\n");
}

void usrsignal2(int sig)
{
	close(fd);
	printf("device closed\n\r");
	exit(1);
}

int main(){

struct timespec  begin, end;
long time, total_time =0 ;
	
char buf[30];
char sbuf[30];
	
long msec,msec_100,msec_10;
long min,min_10,min_1,sec,sec_10,sec_1;

// *************** LCD driver open *************** // 

	int lcd_fd;
	char wbuf[30];

	lcd_fd=open("/dev/lcd1602",O_RDWR);
	if (lcd_fd < 0) {
        printf("Device open error : %s\n","/dev/lcd1602");
        exit(1);
	}
//	ioctl(lcd_fd, 0, 0x01);
	strcpy(wbuf,"                      "); // LCD clear 
	write(lcd_fd, wbuf, strlen(wbuf));
	sleep(1);

// ***************					*************** /

	(void)signal(SIGUSR1, usrsignal);
	(void)signal(SIGINT, usrsignal2);
	fd = open("/dev/gpio_signal", O_RDWR);
	if(fd < 0) {
		printf( "Device Open ERROR!\n");
//		printf( "Erorr : gpio_signal device\n");
		exit(1);
	}
	dev_pid=getpid();
	printf("dev_pid=%d\n", dev_pid);
	buf[0] = 0xff & dev_pid;
	buf[1] = 0xff & (dev_pid >> 8);
	write(fd,buf,sizeof(dev_pid));
	printf("Please push the GPIO button!\n");
	
	while(1){
		read(fd, buf, 40); // read
		if (buf[0] !=0 )
		printf("%s\n", buf);
		usleep(20000);

//		printf("buffer is  %s\n",buf);
//		printf("stopwatch enabled : %d\n",stopwatch_en);
		switch(stopwatch_en){
			case 0: 
			while(1){
//				printf("stopwatch disabled\n");
				if(stopwatch_en == 1)break;
			}
			break;

			case 1:
//			printf("stopwatch enabled\n");
			clock_gettime(CLOCK_MONOTONIC,&begin);
        	while(1){		
    			clock_gettime(CLOCK_MONOTONIC, &end);
    			time = total_time + 1000*(end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/1000000; 		
    		
				sec = time / 1000;
    			min = sec / 60 ;
			
				sec_10 = (sec - (sec/60)*60) / 10 ;
				sec_1  = (sec - (sec/60)*60) % 10 ;
							
				min_10 = min / 10;
				min_1  = min % 10;
					
				msec = time % 1000;
				msec_100 = msec / 100 ; 
				msec_10  = (msec % 100) / 10; 
				
				sprintf(sbuf,"%d%d:%d%d:%d%d",min_10,min_1,sec_10,sec_1,msec_100,msec_10);
				strcpy(wbuf,sbuf);
				write(lcd_fd, wbuf, strlen(wbuf));
				usleep(1);
				if(stopwatch_en == 0) break;
    		}
			total_time = time;
			break;
		}
	}

	close(fd);
	return 0;
}