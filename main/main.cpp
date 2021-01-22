#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../src/todo.cpp"
int main(int argc,char *argv[])
{

	while(1)
	{
		TodoMain(argc,argv);
		usleep(12000);
	}
	return 0;
}
