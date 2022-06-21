#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/ioctl.h>

int main(){

	struct timespec  begin, end;
	long time, total_time =0 ;
	int fd;
	
	char buf[30];
	char sbuf[30];
	
	long msec,msec_100,msec_10;
	long min,min_10,min_1,sec,sec_10,sec_1;
	
	fd=open("/dev/gpio_button",O_RDWR);
	if (fd < 0) {
        printf("Device open error : %s\n","/dev/gpio_button");
        exit(1);
	}
    printf("Press the button to start the stopwatch:\n\r");

// *************** LCD driver open *************** // 

	int lcd_fd;
	char wbuf[30];

	lcd_fd=open("/dev/lcd1602",O_RDWR);
	if (lcd_fd < 0) {
        printf("Device open error : %s\n","/dev/lcd1602");
        exit(1);
	}
	ioctl(lcd_fd, 0, 0x01);
//	ioctl(lcd_fd, 0, 0x55);					//	Run
//	ioctl(lcd_fd, 0, 0x33);					//  Clear
//  ioctl(lcd_fd, 0, 0x22);					//  Stopped 
	strcpy(wbuf,"                      "); // LCD clear 
	write(lcd_fd, wbuf, strlen(wbuf));
	sleep(1);

// ***************					*************** //

    while(1){
    	while(1){
    		read(fd, buf, 1);
    		if(buf[1]==0){
    			ioctl(lcd_fd, 0, 0x33);
    			time,total_time=0;
    			clock_gettime(CLOCK_MONOTONIC, &begin);
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
    		}
    		if (buf[0]==0) break;
    		
    	}
    	ioctl(lcd_fd, 0, 0x55);
    	clock_gettime(CLOCK_MONOTONIC, &begin); 
    	while(1){
    		read(fd, buf, 1);
    		if (buf[0]!=0) break;
    	}
    	while(1){
    		read(fd, buf, 1);
    		if(buf[1] ==0) {
    			ioctl(lcd_fd, 0, 0x33);
	    		clock_gettime(CLOCK_MONOTONIC, &begin);   
    		}
    		if (buf[0]==0) {
     		
    		ioctl(lcd_fd,0,0x22);							// Stopped 
    		write(lcd_fd, wbuf, strlen(wbuf));
    		break;
    		}
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
    	}
        total_time = time; 
        
    	while(1){ 
    		read(fd, buf, 1);
    		if (buf[0]!=0) break;
    	}
    }
    close(lcd_fd);
    return 0;   
}
