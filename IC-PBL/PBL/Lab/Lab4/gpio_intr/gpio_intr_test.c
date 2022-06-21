#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
static int fd;

void usrsignal(int sig)
{
	close(fd);
	printf("device closed\n\r");
	exit(1);
}
int main(void) {

	char buf[40];
	
	(void)signal(SIGINT, usrsignal);
	fd = open("/dev/gpio_intr", O_RDWR);
	if(fd < 0) {
		printf( "Device Open ERROR!\n");
		exit(1);
	}
	printf("Please push the GPIO button!\n");
	while(1){
		read(fd, buf, 40); // read
		if (buf[0] !=0 )
		printf("%s\n", buf);
		usleep(20000);
	}
	close(fd);
	return 0;
}