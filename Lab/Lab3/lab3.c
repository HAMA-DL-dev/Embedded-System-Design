#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <pthread.h>

int led_fd;
char wbuf[30];
	
int button_fd;
char buf[30];

int cnt=0;

void* thread_Button_function(void* button)
{ 
    while(1){
     printf("if pushed, it will be zero and current value is %d\n",*(int*)button);
     sleep(1);
     
     if(*(int*)button == 0){
      cnt++;
      if(cnt>2)cnt=0;
      }  
    }   
	pthread_exit(0);
}

void* thread_LED_function(void* led)
{ 
  while(1){
	switch(cnt){
   case 0:
    printf("count vale is %d and LED on\n",cnt);
    sleep(1);
    wbuf[0]=1;
    write(led_fd,wbuf,1);
    break;
    
   case 1:
    printf("count value is %d and LED blink\n",cnt);
    sleep(1);
    wbuf[0]=1;
	write(led_fd,wbuf,1);
	sleep(1);
	wbuf[0]=0;
	write(led_fd,wbuf,1);
	break;
   
   case 2:
    printf("count value is %d and LED blink quickly\n",cnt);
    sleep(1);
    wbuf[0]=1;
	write(led_fd,wbuf,1);
	usleep(100000);
	wbuf[0]=0;
	write(led_fd,wbuf,1);
	break;
  }	
	}
	pthread_exit(0);	
}

int main()
{
	led_fd=open("/dev/gpio_led",O_RDWR);
	if (led_fd < 0) {
        printf("Device open error : %s\n","/dev/gpio_led");
        exit(1);
	}
	
	button_fd=open("/dev/gpio_button",O_RDWR);
	if (button_fd < 0) {
        printf("Device open error : %s\n","/dev/gpio_button");
        exit(1);
	}
	
	pthread_t t1,t2;
	read(button_fd, buf, 1);
	void* ptr = &buf[0];

	pthread_create(&t1,NULL,thread_Button_function,ptr);
	pthread_create(&t2,NULL,thread_LED_function,ptr);
		
	while(1)
	{
		read(button_fd, buf, 1);
	}
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	close(button_fd);
	close(led_fd);
}