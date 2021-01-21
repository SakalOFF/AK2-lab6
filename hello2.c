#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/types.h>
#include <linux/slab.h>
#include <linux/ktime.h>
#include <hello1.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("AK-2 lab_6: hello2.c\n");
MODULE_AUTHOR("Volodymyr Sokolov");

static uint n = 1;

module_param(n, uint, 0);
MODULE_PARM_DESC(n, "How many hellos to print\n");

static int __init init_hello(void)
{
	pr_info("hello2 init\n");
	print_hello(n);
	return 0;
}

static void __exit exit_hello(void)
{
	pr_info("hello2 exit\n");
}

module_init(init_hello);
module_exit(exit_hello);
