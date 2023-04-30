#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/device/class.h>
#include <linux/device.h>
#include <linux/of.h>
#define BUF_S 1000
static int major;
static struct class * cls;
static char drv_buf[BUF_S];
#define MIN(a,b) (a<b?a:b)
static struct device_node *np = NULL;
static struct property * pp = NULL;
static ssize_t drv_read (struct file *file, char __user *buf, size_t size, loff_t *offset)
{
	printk("%s %s line %d\n", __FILE__, __FUNCTION__, __LINE__);
	return 0;
}

static ssize_t drv_write (struct file *file, const char __user *buf, size_t size, loff_t *offset)
{
	printk("%s %s line %d\n", __FILE__, __FUNCTION__, __LINE__);
	//copy_from_user(drv_buf, buf, MIN(BUF_S, size));
    np = of_find_node_by_path(buf);
    if(np == NULL)
    {
        printk("input node error!\n");
    }else{
        printk("node's name is %s\n",np->name);
        printk("node's full name is %s\n",np->full_name);
        pp = np->properties;
        while(pp){
            printk("property : %s\n",pp->name);
            pp =  pp->next;
        }
    }
	return MIN(BUF_S, size);
}

static int drv_open (struct inode *node, struct file *file)
{
	printk("%s %s line %d\n", __FILE__, __FUNCTION__, __LINE__);
	return 0;
}

static int drv_close (struct inode *node, struct file *file)
{
	printk("%s %s line %d\n", __FILE__, __FUNCTION__, __LINE__);
	return 0;
}


static struct file_operations fops={
    .owner = THIS_MODULE,
    .open = drv_open,
    .release = drv_close,
    .read = drv_read,
    .write = drv_write
};
 
static int __init drv_init(void)
{
    printk("dt show node info\n");

    
    major = register_chrdev(0,"drv_io",&fops);

    cls = class_create(THIS_MODULE,"drv_io_class");
    if(IS_ERR(cls)){
      long errcode = PTR_ERR(cls);
      printk("errno %d in file %s function %s line %s ",errcode, __FILE__,__FUNCTION__,__LINE__);
      unregister_chrdev(major,"drv_io");
    }

    device_create(cls, NULL, MKDEV(major,0), NULL, "dev_io_1");
    
    return 0;
}
static void __exit drv_exit(void)
{
    printk("Goodbye world\n");
    device_destroy(cls, MKDEV(major,0));
    class_destroy(cls);
    unregister_chrdev(major,"drv_io");
}
module_init(drv_init);
module_exit(drv_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("liodeGwin@gmail.com");
