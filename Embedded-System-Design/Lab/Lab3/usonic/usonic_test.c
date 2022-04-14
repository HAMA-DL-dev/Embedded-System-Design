#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main(void)
{
	int fd;
	int retn;
	char buf[10] = {0};	
	int loop = 0;
	
	fd = open("/dev/usonic", O_RDWR);
	printf("fd = %d\n", fd);
	
	if(fd<0){
		perror("/dev/us error");
		exit(-1);
	}else{
		printf("< us device has been detected >\n");
	}

	while(1){
		read(fd,buf,2);
		printf("%d\n\r",buf[0]);
		for(loop = 0; loop < 100000; loop++) {};
	}

	close(fd);

	return 0;
	
}
