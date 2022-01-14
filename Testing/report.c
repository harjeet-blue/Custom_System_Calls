#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

#define New_sys_call 550   // 550 is my syscall id, change 
//this no according to your sycall id ( number which you gave it in the table )

long identity_syscall(void)
{
	return syscall(New_sys_call);
}

int main(int argc, char *argv[])
{
	long result = identity_syscall();

	if(result < 0)
	{
		perror("fail");
	}
	else
	{
		printf("Congrats, your syscall is working\n");
	}

	return 0;
}