#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    struct timespec  begin, end;
    long time;
    
    while(1){ 
    	clock_gettime(CLOCK_MONOTONIC, &begin); 
    	while(1){
    		clock_gettime(CLOCK_MONOTONIC, &end);
    		time = 1000000000*(end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec);
    		if (time > 1000000) break;
    	}
    	printf("Time (nsec): %5ld\r", time);
    }
    return 0;   
}