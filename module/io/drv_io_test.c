
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
 * ./test -w abc
 * ./test -r
 */
int main(int argc, char **argv)
{
	int fd;
	char buf[1024];
	int len;
	int ret;
	

	if (argc < 2) 
	{
		printf("Usage: %s -w <string>\n", argv[0]);
		printf("       %s -r\n", argv[0]);
		return -1;
	}


	fd = open("/dev/dev_io_1", O_RDWR);
	if (fd == -1)
	{
		printf("can not open file /dev/dev_io_1\n");
	        printf("errno is %d\n",errno);
		return -1;
	}


	if ((0 == strcmp(argv[1], "-w")) && (argc == 3))
	{
		len = strlen(argv[2]) + 1;
		//len + 1 add \0 at tail
		ret = write(fd, argv[2], len);
		printf("write %d char to drv\n",ret);
	}
	else
	{
		ret  = read(fd, buf, 1024);
		printf("read  %d char from drv\n",ret);
		printf("read : %s\n", buf);
	}
	
	close(fd);
	
	return 0;
}


