#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()
{
	int fd;
	char wbuf[30];

	fd=open("/dev/gpio_led",O_RDWR);
	if (fd < 0) {
        printf("Device open error : %s\n","/dev/gpio_led");
        exit(1);
	}
	while(1) {
      wbuf[0]=1; // LED on 
      write(fd, wbuf, 1);
      sleep(1);
      wbuf[0]=0;
      write(fd, wbuf, 1);
      sleep(1);
   }

	close(fd);
}
