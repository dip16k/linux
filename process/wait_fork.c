#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int  main()
{
	int pid;
	pid_t id;
	
	if(fork()==0)
	{
		printf("child:%d\n",getpid());
	}
	id = wait(&pid);
	printf("in parent id:%d  pid:%d\n",id,pid);
}
