#include<stdio.h>
#include<stdlib.h>

int main()
{
	// it will execute the command by calling /bin/sh -c command
	system("date");
	
	puts("command sucessful");
	return 0;
}
