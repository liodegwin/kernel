#include <stdio.h>
#include <unistd.h>
int main(){
	pid_t pid = syscall(39);
	printf("pid is %d\n",pid);
	int cpu_num = syscall(449);
	printf("syscall 449 ,cpu num is %d\n",cpu_num);
	return 0;
}
