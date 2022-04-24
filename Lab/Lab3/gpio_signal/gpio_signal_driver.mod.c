#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
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
__used __section("__versions") = {
	{ 0x44afce, "module_layout" },
	{ 0xfe990052, "gpio_free" },
	{ 0xc1514a3b, "free_irq" },
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0x72daeeb6, "gpiod_to_irq" },
	{ 0x54535e55, "gpiod_direction_input" },
	{ 0xead0d68d, "gpio_to_desc" },
	{ 0x47229b5c, "gpio_request" },
	{ 0x615c316, "__register_chrdev" },
	{ 0x6293b76e, "kill_pid" },
	{ 0x29490fd4, "get_task_pid" },
	{ 0x2d5f69b3, "rcu_read_unlock_strict" },
	{ 0x8c3b08f9, "init_task" },
	{ 0x51a910c0, "arm_copy_to_user" },
	{ 0x5f754e5a, "memset" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0xc5850110, "printk" },
	{ 0xb1ad28e0, "__gnu_mcount_nc" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B980FBBD714D9228D9D25CF");
