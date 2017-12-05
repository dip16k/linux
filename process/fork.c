#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int pid;

	if(fork()==0)
	{
		printf("child:%d  parent:%d\n",getpid(),getppid());
	}
	printf("parent :%d\n",getpid());
	wait(0);
}
