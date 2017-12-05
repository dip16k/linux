#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	int pid;

	execv("date");
	printf("command execute succesful");
}
