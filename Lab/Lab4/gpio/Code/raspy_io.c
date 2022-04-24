#include "linux/version.h"
#include <linux/module.h>
#include <linux/fs.h>
#include <asm/uaccess.h>	/* for put_user */
#include <linux/ioport.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");

#define SUCCESS 0
#define DEVICE_NAME "io_dev" // Dev name as it appears in /proc/devices   
#define BUF_LEN 80		     // Max length of the message from the device 

static unsigned PORT = 0x3F200000; 

static unsigned RANGE =  0xB0;
unsigned cmd_word;
unsigned out_word;
volatile u8 *addr;


static int Major;		/* Major number assigned to our device driver */
static int Device_Open = 0;	/* Is device open?  
				 * Used to prevent multiple access to device */
static char msg[BUF_LEN];	/* The msg the device will give when asked */
static char *msg_Ptr;

static int device_open(struct inode *inode, struct file *file)
{

	u32 cmd;   // command word to write
	msg_Ptr = msg;

	sprintf(msg,"Not implemented\n");
	if (Device_Open)
		return -EBUSY;

	Device_Open++;
	try_module_get(THIS_MODULE);
	addr = ioremap(PORT, RANGE);
	if (addr  != NULL)
	{
		cmd = 0;
		writel(cmd, (addr+4)); // clear the setting of pin 10
		cmd = 1;
		writel(cmd, (addr+4)); // set pin 10 as output
		writel(1 << 10, (addr+0x1c));
		return SUCCESS;
    }
    else
      return -ENODEV;

}

static int device_release(struct inode *inode, struct file *file)
{
	//writel(0x00, (addr+4));  // claer the setting before release
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
	int bytes_written = 1;
	u32 cmd;   // command word to write
	if (buff)
	{
		if (buff[0] == 1)
		{
			cmd = 1 << 10;
			writel(cmd, (addr+0x1c));
		}
		else
		{
			if (buff[0] == 0)
			{
				cmd = 1 << 10;
				writel(cmd, (addr+0x28));
			}
		}
	}
	return bytes_written;
}

static struct file_operations fops = {
	.owner   = THIS_MODULE,
	.open    = device_open,
	.release = device_release,
	.read    = device_read,
	.write   = device_write
};

int init_module(void)
{
	Major = register_chrdev(0,DEVICE_NAME, &fops);
	if (Major < 0) {
	  printk(KERN_ALERT "Registering char device failed with %d\n", Major);
	  return Major;
	}

	return SUCCESS;
}

void cleanup_module(void)
{
	//printk(KERN_ALERT "Ade :-)\n");
	//release_mem_region(PORT, RANGE); 
	unregister_chrdev(Major, DEVICE_NAME);
}
