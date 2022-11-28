#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(){
    pid_t pid = syscall(39);
    printf("pid = %d\n",pid);
    return 0;
}