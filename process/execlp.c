#include<stdio.h>
#include<unistd.h>

int main()
{
	execlp("date","date",NULL);
	puts("sucess");
}
