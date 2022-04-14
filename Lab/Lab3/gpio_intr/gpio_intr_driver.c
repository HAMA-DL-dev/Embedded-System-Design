#include <linux/interrupt.h> 
#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/gpio.h> 
#include <asm/uaccess.h>
#include <linux/ioport.h>
#include <linux/uaccess.h>

#define MOD_MAJOR 0
#define DEVICE_NAME "gpio_intr"
#define GPIO_BTN 6 // BCM_GPIO #6
static int btn_irq;
static int major;
static char msg[40] = {0};

static irqreturn_t btn_interrupt(int irq, void *dev_id) {
	char temp[40] = "GPIO Switch was Pushed!";
	strcpy(msg, temp);
	return 0;
}

static ssize_t gpiobtn_read(struct file *filp, char *buf, size_t count, loff_t *l) {
	int result;
	result = copy_to_user(buf, &msg, sizeof(msg));
	memset(msg, 0, 40);
	return result;
}

static int gpiobtn_open(struct inode *inode, struct file *filp) {
	return 0;
}

static int gpiobtn_release(struct inode *inode, struct file *filp) {
	disable_irq(GPIO_BTN);
	return 0;
}

static struct file_operations gpiobtn_fops = {
	.read = gpiobtn_read,
	.open = gpiobtn_open,
	.release = gpiobtn_release,
};

int gpio_intr_init(void) {
	int irq;
	major = register_chrdev(MOD_MAJOR, DEVICE_NAME,&gpiobtn_fops);
	if(major < 0) {
		printk(KERN_WARNING"Can't get major %d\n",MOD_MAJOR);
	}
	gpio_request(GPIO_BTN, "SWITCH");
	gpio_direction_input(GPIO_BTN);
	btn_irq = gpio_to_irq(GPIO_BTN);
	irq = request_irq(btn_irq, &btn_interrupt, IRQF_TRIGGER_FALLING,"SWITCH", NULL);
	if(irq < 0)
	printk(KERN_ERR "%s: Request for IRQ %d failed\n",__FUNCTION__, GPIO_BTN);
	printk("init module, GPIO major number : %d\n", major);
	return 0;
}

void gpio_intr_exit(void){
	unregister_chrdev(major, DEVICE_NAME);
	free_irq(btn_irq, NULL);
	gpio_free(GPIO_BTN);
	printk("%s DRIVER CLEANUP\n", DEVICE_NAME);
	return;
}
module_init(gpio_intr_init);
module_exit(gpio_intr_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("melee");
MODULE_DESCRIPTION("Raspberry Pi 3 GPIO Switch Device Driver Module");