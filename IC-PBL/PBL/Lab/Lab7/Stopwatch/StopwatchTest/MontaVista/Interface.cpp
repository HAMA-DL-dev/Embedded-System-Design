/********************************************************************
	Rhapsody	: 7.5.3 
	Login		: hayeon
	Component	: StopwatchTest 
	Configuration 	: MontaVista
	Model Element	: Interface
//!	Generated Date	: Wed, 20, Apr 2022  
	File Path	: StopwatchTest/MontaVista/Interface.cpp
*********************************************************************/

/*********************************************************************
	File Path	: StopwatchTest/MontaVista/Interface.cpp
*********************************************************************/
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
#include <sys/ioctl.h>

int fd_button;  
int fd_led;
int fd_lcd;     
     
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
int initLcd(void)
{
   fd_lcd=open("/dev/lcd1602",O_RDWR);
	if (fd_lcd < 0) {
        printf("Device open error : %s\n","/dev/lcd1602");
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
void onLcd(int min, int sec)
{            
    char lcd_buf[30];
    char tbuf[30];
    ioctl(fd_lcd, 1, 0x01);
	sleep(1);
	strcpy(lcd_buf,"                   ");
	write(fd_lcd, lcd_buf, strlen(lcd_buf));	
	
	sprintf(tbuf,"%d:%d",min,sec);
    write(fd_lcd, tbuf, strlen(tbuf));
	sleep(1);
	close(fd_lcd);

}
/*********************************************************************
	File Path	: ButtonTest/MontaVista/Interface.cpp
*********************************************************************/