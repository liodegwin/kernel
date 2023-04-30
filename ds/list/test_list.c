#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/list.h>
#include <linux/vmalloc.h>
 
struct number
{
   int data;
   struct list_head list;
};
 
LIST_HEAD(number_list_head);
 
static int test_list_init(void)
{
	struct list_head *tmp;
	for(int i = 0;i<10;i++){
		struct number * np = vmalloc(sizeof(struct number));
		np->data = i;
		list_add(&np->list,&number_list_head);
	}
	
	list_for_each(tmp, &number_list_head)
	{
		struct number * np_tmp = list_entry(tmp, struct number, list);
		printk("%d",np_tmp->data);
	}	
 
    return 0;
}
 
static void test_list_exit(void)
{
   return;
}
 
module_init(test_list_init);
module_exit(test_list_exit);
MODULE_LICENSE("GPL");
