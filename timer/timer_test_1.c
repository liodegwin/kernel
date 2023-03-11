#include <linux/jiffies.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/timer.h>

static struct timer_list timer_1;
void timer_func(struct timer_list* ptl){

    printk("in %s\n",__FUNCTION__ );
    mod_timer(&timer_1, jiffies+msecs_to_jiffies(2000));
}
static int __init tiemr_test_init(void)
{
    printk("In %s %s %s\n",__FILE__,__FUNCTION__,__LINE__);


    timer_1.expires = jiffies + msecs_to_jiffies(2000);
    timer_setup(&timer_1, timer_func, 0);

    add_timer(&timer_1);

    return 0;
}
static void __exit tiemr_test_exit(void)
{
    printk("In %s %s %s\n",__FILE__,__FUNCTION__,__LINE__);
    del_timer(&timer_1);
}
module_init(tiemr_test_init);
module_exit(tiemr_test_exit);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("liodeGwin@gmail.com");
