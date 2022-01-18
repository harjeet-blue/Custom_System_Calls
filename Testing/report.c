#include <linux/kernel.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define __NR_identity 550  // 550 is my syscall id, change 
//this no according to your sycall id ( number which you gave it in the table )

long identity_syscall(void)
{
	return syscall(__NR_identity);
}

int main(int argc, char *argv[])
{
	long activity = identity_syscall();

	if(activity < 0)
	{
		perror("fail :( \n");
	}
	else
	{
		printf("Congrats, your syscall is working fine\n");
	}

	return 0;
}