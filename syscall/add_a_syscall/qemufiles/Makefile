.PHONY: initramfs
initramfs:
	cd initramfs_d && find . -print0|cpio -ov --null --format=newc|gzip -9 >../initramfs.img
.PHONY: run
run:
	qemu-system-x86_64\
	       	-kernel bzImage\
	       	-smp 2\
	       	-initrd initramfs.img\
	       	-m 1G\
	       	-nographic\
	       	-append "earlyprintk=serial,ttyS0 console=ttyS0"
.PHONY: clean
clean:
	rm initramfs.img
