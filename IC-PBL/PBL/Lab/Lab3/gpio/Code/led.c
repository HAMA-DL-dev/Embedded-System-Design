#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
int fd;
char wbuf[2];

fd=open("/dev/io_dev",O_RDWR);
if (fd < 0) {

        printf("Device open error : %s\n","/dev/io_dev");

        exit(1);

    }

wbuf[0]=1;
wbuf[1]=0;
write(fd, wbuf, sizeof(wbuf));

close(fd);
}
