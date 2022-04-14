#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/ioctl.h>

int main()
{
	int fd;
	char wbuf[30];
	fd=open("/dev/lcd1602",O_RDWR);
	if (fd < 0) {
        printf("Device open error : %s\n","/dev/lcd1602");
        exit(1);
	}
	
	ioctl(fd, 0, 0x01);
	sleep(1);
	ioctl(fd, 0, 0x55);
	strcpy(wbuf,"Hello World        ");
	write(fd, wbuf, strlen(wbuf));	
	
	sleep(1);
	close(fd);
}