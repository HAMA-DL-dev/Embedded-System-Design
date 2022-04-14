#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    struct timespec  begin, end;
    long time, total_time;
    long msec, sec;
	int fd;
	char buf[30];

	fd=open("/dev/gpio_button",O_RDWR);
	if (fd < 0) {
        printf("Device open error : %s\n","/dev/gpio_button");
        exit(1);
	}
    printf("Press the button to start the stopwatch:\n\r");

    while(1){ 
    	
    	clock_gettime(CLOCK_MONOTONIC, &begin); 
    
    	while(1){
    		clock_gettime(CLOCK_MONOTONIC, &end);
    		time = total_time + 1000*(end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec)/1000000; 		
    		sec = time / 1000;
    		msec = time % 1000;
    		
    		printf("Time : %10ld %5ld sec %5ld msec \r", time, sec ,msec);
    		usleep(1);
    	}
    	total_time = time;
    	
    }
    return 0;   
}