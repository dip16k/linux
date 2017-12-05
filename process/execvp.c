#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	char *p = "date";
	char *cmd[4];// array of pointers
	cmd[0]=p;
	cmd[1]=NULL;
	
	execvp(p,cmd);
	puts("sucess");
}
