#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

static int dev_pid;
static int fd;

void usrsignal(int sig)
{
		printf("GPIO button signal\n\r");
}
void usrsignal2(int sig)
{
	close(fd);
	printf("device closed\n\r");
	exit(1);
}

int main(void) {

	char buf[40];
	
	(void)signal(SIGUSR1, usrsignal);
	(void)signal(SIGINT, usrsignal2);
	fd = open("/dev/gpio_signal", O_RDWR);
	if(fd < 0) {
		printf( "Device Open ERROR!\n");
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
	}
	close(fd);
	return 0;
}