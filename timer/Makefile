obj-m := timer_test_1.o
KDIR := /lib/modules/$(shell uname -r)/build
all:
	make   -C $(KDIR) M=$(PWD) modules
clean:
	make   -C $(KDIR) M=$(PWD) modules clean
	rm test
