#include <linux/interrupt.h> 
#include <linux/cdev.h>
#include <linux/module.h>
#include <linux/io.h>
#include <linux/gpio.h> 
#include <asm/uaccess.h>
#include <linux/ioport.h>
#include <linux/uaccess.h>
#include <linux/signal.h>
//#include <linux/sched.h>
//#include <linux/kdev_t.h>
//#include <linux/module.h>
//#include <linux/init.h>
//#include <linux/kernel.h>
#include <linux/sched/signal.h>

#define MOD_MAJOR 0
#define DEVICE_NAME "gpio_signal"
#define GPIO_BTN 6 // BCM_GPIO #6
static int Major;
static int btn_irq;
static char msg[40] = {0};
int dev_pid;

void kill_proc(int pid, int sig)
{
	struct task_struct* p;
	struct task_struct* t = NULL;
	struct pid* pspid;
	rcu_read_lock();
	p = &init_task;
	do {
		if (p->pid == pid){
			t = p;
			break;
		}
		p=next_task(p);
	} while(p != &init_task);
	if(t != NULL) {
		//pspid = t->pids[PIDTYPE_PID].pid;
		pspid = get_task_pid(t, PIDTYPE_PID);
		printk("Kill\n\r");
		if (pspid != NULL) kill_pid(pspid,sig,1);
	}
	rcu_read_unlock();
}
static irqreturn_t btn_interrupt(int irq, void *dev_id) {
//	char temp[40] = "GPIO Switch was Pushed!";
//	strcpy(msg, temp);
	kill_proc(dev_pid,SIGUSR1);
	return 0;
}

static ssize_t gpiobtn_read(struct file *filp, char *buf, size_t count, loff_t *l) {
	int result;
	result = copy_to_user(buf, &msg, sizeof(msg));
	memset(msg, 0, 40);
	return result;
}

static ssize_t gpiobtn_write(struct file *filp, const char *buff, size_t len, loff_t * off)
{
	dev_pid = (*(buff+1) << 8) + *buff;
	printk("pid= %d",dev_pid);
	return len;
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
	.write = gpiobtn_write,
	.release = gpiobtn_release,
};

int gpio_intr_init(void) {
	int irq;
	Major = register_chrdev(MOD_MAJOR, DEVICE_NAME,&gpiobtn_fops);
	if(Major < 0) {
		printk(KERN_WARNING"Can't get major %d\n",MOD_MAJOR);
	}
	gpio_request(GPIO_BTN, "SWITCH");
	gpio_direction_input(GPIO_BTN);
	btn_irq = gpio_to_irq(GPIO_BTN);
	irq = request_irq(btn_irq, &btn_interrupt, IRQF_TRIGGER_FALLING,"SWITCH", NULL);
	if(irq < 0)
	printk(KERN_ERR "%s: Request for IRQ %d failed\n",__FUNCTION__, GPIO_BTN);
	printk("init module, GPIO major number : %d\n", Major);
	return 0;
}

void gpio_intr_exit(void){
	unregister_chrdev(Major, DEVICE_NAME);
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