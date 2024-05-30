#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>

static int __init hello_init(void)
{
    printk("Hello GDSC from the kernel\n");

    return 0;
}

static void __exit hello_exit(void)
{
    printk("KERN_INFO: Exiting module, goodbye GDSC\n");
}

module_init(hello_init);
module_init(hello_exit);

MODULE_LICENCE("GPL");
