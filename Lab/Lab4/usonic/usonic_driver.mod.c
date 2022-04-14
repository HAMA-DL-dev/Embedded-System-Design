#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0x45cd1b70, "module_layout" },
	{ 0xfe990052, "gpio_free" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x1d37eeed, "ioremap" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x550257fc, "gpiod_to_irq" },
	{ 0x2c6dab0e, "gpiod_direction_input" },
	{ 0x47229b5c, "gpio_request" },
	{ 0xc5850110, "printk" },
	{ 0x6a5fd0e8, "__register_chrdev" },
	{ 0x8e865d3c, "arm_delay_ops" },
	{ 0xbdd88d28, "gpiod_set_raw_value" },
	{ 0x7bac67ed, "gpio_to_desc" },
	{ 0xdecd0b29, "__stack_chk_fail" },
	{ 0x9ec6ca96, "ktime_get_real_ts64" },
	{ 0x8f678b07, "__stack_chk_guard" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "3173C6C0E4DFA0013E78E42");
