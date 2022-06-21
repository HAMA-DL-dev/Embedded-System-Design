#include "linux/version.h"
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>	/* for put_user */
#include <linux/ioport.h>
#include <asm/io.h>
#include <linux/delay.h>
#include <linux/string.h>

MODULE_LICENSE("GPL");

#define SUCCESS 0
#define DEVICE_NAME "lcd1602" // Dev name as it appears in /proc/devices   
#define BUF_LEN 80		     // Max length of the message from the device 
#define GPFSEL0 0
#define GPFSEL1 4
#define GPFSEL2 8
#define GPSET0 0x1c
#define GPCLR0 0x28
#define DATA4 18
#define DATA5 19
#define DATA6 20
#define DATA7 21
#define RS 26				/* Define Register Select pin */
#define EN 16 				/* Define Enable signal pin */

static unsigned PORT = 0xFE200000; 
static unsigned RANGE =  0xB0;
unsigned cmd_word;
unsigned out_word;
volatile u8 *addr;

static int Major;		/* Major number assigned to our device driver */
static int Device_Open = 0;	/* Is device open?  
				 * Used to prevent multiple access to device */
static char msg[BUF_LEN];	/* The msg the device will give when asked */
static char *msg_Ptr;

void LCD_Command( unsigned char cmnd )
{
	writel((u32)(cmnd>>4 & 0x0F)<<DATA4,addr+GPSET0); /* sending upper nibble */
	writel((u32)((~cmnd)>>4 & 0x0F)<<DATA4,addr+GPCLR0);	
	writel((u32)1<<RS,addr+GPCLR0); /* RS=0, command reg. */
	writel((u32)1<<EN,addr+GPSET0); /* Enable pulse */
	udelay(1);
	writel((u32)1<<EN,addr+GPCLR0);

	udelay(200);

	writel((u32)(cmnd & 0x0F)<<DATA4,addr+GPSET0); /* sending lower nibble */
	writel((u32)((~cmnd) & 0x0F)<<DATA4,addr+GPCLR0);
	writel((u32)1<<EN,addr+GPSET0); /* Enable pulse */
	udelay(1);
	writel((u32)1<<EN,addr+GPCLR0);
	mdelay(2);
}

void LCD_Char( unsigned char data )
{
	writel((u32)(data>>4 & 0x0F)<<DATA4,addr+GPSET0); /* sending upper nibble */
	writel((u32)(~data>>4 & 0x0F)<<DATA4,addr+GPCLR0);	
	writel((u32)1<<RS,addr+GPSET0); /* RS=1, data reg. */
	writel((u32)1<<EN,addr+GPSET0); /* Enable pulse */
	udelay(1);
	writel((u32)1<<EN,addr+GPCLR0);

	udelay(200);

	writel((u32)(data & 0x0F)<<DATA4,addr+GPSET0); /* sending lower nibble */
	writel((u32)(~data & 0x0F)<<DATA4,addr+GPCLR0);	
	writel((u32)1<<EN,addr+GPSET0); /* Enable pulse */
	udelay(1);
	writel((u32)1<<EN,addr+GPCLR0);
	mdelay(2);
}

void LCD_String (char *str)		/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)		/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);
	}
}

void gpio_output(u8 pin_number)
{
	u8 pin_position;
	u32 value;
	pin_position = pin_number % 10;
	switch(pin_number/10) {
		case 0:
			value=readl(addr+GPFSEL0);
			value |= (u32)1<<(3*pin_position);
			writel(value,addr+GPFSEL0);
			break;
		case 1:
			value=readl(addr+GPFSEL1);
			value |= (u32)1<<(3*pin_position);
			writel(value,addr+GPFSEL1);
			break;
		case 2:
			value=readl(addr+GPFSEL2);
			value |= (u32)1<<(3*pin_position);
			writel(value,addr+GPFSEL2);
			break;
		default:
			break;	
	}
}

void LCD_Init (void)			/* LCD Initialize function */
{
	gpio_output(DATA4);
	gpio_output(DATA5);
	gpio_output(DATA6);
	gpio_output(DATA7);
	gpio_output(RS);
	gpio_output(EN);
	
	mdelay(20);			/* LCD Power ON delay always >15ms */
	
	LCD_Command(0x02);		/* send for 4 bit initialization of LCD  */
	LCD_Command(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	LCD_Command(0x0c);              /* Display on cursor off*/
	LCD_Command(0x06);              /* Increment cursor (shift cursor to right)*/
	LCD_Command(0x01);              /* Clear display screen*/
	mdelay(2);
}



static int device_open(struct inode *inode, struct file *file)
{
	msg_Ptr = msg;

	sprintf(msg,"Not implemented\n");
	if (Device_Open)
		return -EBUSY;

	Device_Open++;
	try_module_get(THIS_MODULE);
	
	return SUCCESS;

}

static int device_release(struct inode *inode, struct file *file)
{
	Device_Open--;		     //make ready for the next caller
	module_put(THIS_MODULE);

	return 0;
}

static ssize_t device_read(struct file *filp,	
			   char *buffer,	
			   size_t length,	
			   loff_t * offset)
{
    int bytes_read = 1;
    int index;
    u32 res;   // status word to read
	msg_Ptr = msg;
	res = readl(addr+0x34);
	msg[3] = res & 0xFF;
	msg[2] = (res >> 8) & 0xFF;
	msg[1] = (res >> 16) & 0xFF;
	msg[0] = (res >> 24) & 0xFF;
	msg[4] = 0; 
	index = 4;
	while (length && (index >= 0))
	{

		put_user(*(msg_Ptr++), buffer++);

		length--;
		index--;
		bytes_read++;
	}
	return bytes_read;
}

static ssize_t device_write(struct file *filp, const char *buff, size_t len, loff_t * off)
{
	u8 string[30];
	memcpy(string,buff,len);
	string[len]=0x0;
	LCD_Command(0x80); /*Go to 1st line home position */
	LCD_String(string);
	
	return len;
}


static long device_ioctl(struct file *filp, unsigned int cmd,unsigned long gdata)
{
if (cmd == 0){
	LCD_Command(gdata);
	if(gdata == 0x55) {
		LCD_Init();
		LCD_Command(0xC0);
		LCD_String("Running");
	}
	else if(gdata == 0x33){
		LCD_Init();
		LCD_Command(0xC0);
		LCD_String("Cleared");
	}
	else if(gdata == 0x22){
		LCD_Init();
		LCD_Command(0xC0);
		LCD_String("Stopped");
	}
	}
	printk("%lx\n",gdata);
	return 0;
}

static struct file_operations fops = {
	.owner   = THIS_MODULE,
	.open    = device_open,
	.release = device_release,
	.read    = device_read,
	.write   = device_write,
	.unlocked_ioctl = device_ioctl,
};

int init_module(void)
{
	Major = register_chrdev(0,DEVICE_NAME, &fops);
	if (Major < 0) {
	  printk(KERN_ALERT "Registering char device failed with %d\n", Major);
	  return Major;
	}
	addr = ioremap(PORT, RANGE);
	LCD_Init();
//	LCD_String("Hanyang Univ.");
//	LCD_Command(0xC0); /* Go to 2nd line*/
//	LCD_String("LCD1602 driver");	/* Write string on 2nd line*/
	return SUCCESS;
}

void cleanup_module(void)
{
	unregister_chrdev(Major, DEVICE_NAME);
}
