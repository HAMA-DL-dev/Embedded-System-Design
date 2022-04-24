#include <linux/interrupt.h> 
#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/gpio.h> 
#include <asm/uaccess.h>
#include <linux/ioport.h>
#include <linux/uaccess.h>
#include <linux/delay.h>
#include <linux/time.h>

#define GPFSEL0 0
#define GPFSEL1 4
#define GPFSEL2 8
#define GPSET0 0x1c
#define GPCLR0 0x28
#define GPLEV0 0x34

static unsigned PORT = 0xFE200000; 
static unsigned RANGE =  0xB0;
volatile u8 *addr;

#define MOD_MAJOR 0
#define DEVICE_NAME "usonic"
#define GPIO_TRIGGER 23 // BCM_GPIO #23
#define GPIO_ECHO 24 // BCM_GPIO #24
static int usonic_echo_irq;
static int major;
struct timeval after, before;
static int distance;

void do_gettimeofday(struct timeval *tv)
{
struct timespec64 ts;
ktime_get_real_ts64(&ts);
tv->tv_sec = ts.tv_sec;
tv->tv_usec = ts.tv_nsec/1000;
}

static irqreturn_t usonic_echo_interrupt(int irq, void *dev_id) {
	if ((char)(readl(addr+GPLEV0) >> GPIO_ECHO) & 0x01){
		do_gettimeofday( &before);
	}
	else {
		do_gettimeofday( &after ); 
		//printk(KERN_ALERT" Distance : %.0ld [cm] \n ", (after.tv_usec - before.tv_usec) / 58); 
		distance = (after.tv_usec - before.tv_usec) / 58;	
		memset(&before, 0 , sizeof(struct timeval ) );
		memset(&after , 0 , sizeof(struct timeval ) );
	}
	return 0;
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

void gpio_input(u8 pin_number)
{
	u8 pin_position;
	u32 value;
	pin_position = pin_number % 10;
	switch(pin_number/10) {
		case 0:
			value=readl(addr+GPFSEL0);
			value &= ~((u32)0x03 <<(3*pin_position));
			writel(value,addr+GPFSEL0);
			break;
		case 1:
			value=readl(addr+GPFSEL1);
			value &= ~((u32)0x03 <<(3*pin_position));
			writel(value,addr+GPFSEL1);
			break;
		case 2:
			value=readl(addr+GPFSEL2);
			value &= ~((u32)0x03 <<(3*pin_position));
			writel(value,addr+GPFSEL2);
			break;
		default:
			break;	
	}
}

void output_sonicburst(void)
{
	gpio_set_value(GPIO_TRIGGER, 1);
	udelay(10);
	gpio_set_value(GPIO_TRIGGER, 0);
}

static ssize_t usonic_read(struct file *filp, char *buf, size_t count, loff_t *l) {
	output_sonicburst();
	mdelay(1);
	buf[0]=distance;
	return 0;
}

static int usonic_open(struct inode *inode, struct file *filp) {
	return 0;
}

static int usonic_release(struct inode *inode, struct file *filp) {
	disable_irq(GPIO_ECHO);
	return 0;
}

static struct file_operations usonic_fops = {
	.read = usonic_read,
	.open = usonic_open,
	.release = usonic_release,
};

int usonic_init(void) {
	int irq;
	major = register_chrdev(MOD_MAJOR, DEVICE_NAME,&usonic_fops);
	if(major < 0) {
		printk(KERN_WARNING"Can't get major %d\n",MOD_MAJOR);
	}
	gpio_request(GPIO_ECHO, "SWITCH");
	gpio_direction_input(GPIO_ECHO);
	usonic_echo_irq = gpio_to_irq(GPIO_ECHO);
	irq = request_irq(usonic_echo_irq, &usonic_echo_interrupt, IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,"SWITCH", NULL);
	if(irq < 0)
	printk(KERN_ERR "%s: Request for IRQ %d failed\n",__FUNCTION__, GPIO_ECHO);
	printk("init module, GPIO major number : %d\n", major);
	
	addr = ioremap(PORT, RANGE);
	gpio_input(GPIO_ECHO);
	gpio_output(GPIO_TRIGGER);
	return 0;
}

void usonic_exit(void){
	unregister_chrdev(major, DEVICE_NAME);
	free_irq(usonic_echo_irq, NULL);
	gpio_free(GPIO_ECHO);
	printk("%s DRIVER CLEANUP\n", DEVICE_NAME);
	return;
}
module_init(usonic_init);
module_exit(usonic_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("melee");
MODULE_DESCRIPTION("Raspberry Pi 4 Ultrasonic Device Driver Module");