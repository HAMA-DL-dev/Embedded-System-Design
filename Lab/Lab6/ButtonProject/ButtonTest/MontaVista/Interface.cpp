/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: control
	Component	: ButtonTest 
	Configuration 	: MontaVista
	Model Element	: Interface
//!	Generated Date	: Mon, 13, Apr 2020  
	File Path	: ButtonTest/MontaVista/Interface.cpp
*********************************************************************/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int fd_button;  
int fd_led;

int initButton(void)
{
	fd_button=open("/dev/gpio_button",O_RDWR);
	if (fd_button < 0) {
        printf("Device open error : %s\n","/dev/gpio_button");
        exit(1);
	}
}
int initLed(void)
{ 
	fd_led=open("/dev/gpio_led",O_RDWR);
	if (fd_led < 0) {
        printf("Device open error : %s\n","/dev/gpio_led");
        exit(1);
	}
}
unsigned char readButton(void)
{        
	char buf[30];
	read(fd_button, buf, 1);
    return buf[0];
}     
void onLed(unsigned char data)
{  
	char wbuf[30];  
	wbuf[0]=data;
    write(fd_led,&wbuf,1);	
}
/*********************************************************************
	File Path	: ButtonTest/MontaVista/Interface.cpp
*********************************************************************/
