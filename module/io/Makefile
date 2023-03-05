obj-m := drv_io.o
KDIR := /lib/modules/$(shell uname -r)/build
all:
	make   -C $(KDIR) M=$(PWD) modules
	gcc -o test drv_io_test.c
clean:
	make   -C $(KDIR) M=$(PWD) modules clean
	rm test
