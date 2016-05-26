#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <asm/uaccess.h>
#include <linux/random.h>

unsigned char get_random_byte (int max);

static ssize_t dice_read(struct file * file, char * buf, 
			  size_t count, loff_t *ppos)
{
	int number;
	number = get_random_byte(6)+1;
	if (count == 0||*ppos !=0)
		return 0;
	
	 
	if (copy_to_user(buf, &number, sizeof(int)))
		return -EINVAL;
	
	
	*ppos = 1;

	return *ppos;
}



static const struct file_operations dice_fops = {
	.owner		= THIS_MODULE,
	.read		= dice_read,
};
unsigned char get_random_byte(int max) {
     unsigned char c;
     get_random_bytes(&c, 1);
     return c%max;
}
static struct miscdevice dice_driver = {
	/*
	 * We don't care what minor number we end up with, so tell the
	 * kernel to just pick one.
	 */
	MISC_DYNAMIC_MINOR,
	/*
	 * Name ourselves /dev/hello.
	 */
	"dice",
	/*
	 * What functions to call when a program performs file
	 * operations on the device.
	 */
	&dice_fops
};

static int __init
dice_init(void)
{
	int ret;

	
	ret = misc_register(&dice_driver);
	if (ret)
		printk(KERN_ERR
		       "Unable to register \"Dice Driver\" misc device\n");

	return ret;
}

module_init(dice_init);

static void __exit
dice_exit(void)
{
	misc_deregister(&dice_driver);
}

module_exit(dice_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Luke Kraus <lek81@pitt.edu>");
MODULE_DESCRIPTION("\"Dice Driver\" minimal module");
MODULE_VERSION("dev");
