#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../src/todo.cpp"
int main(int argc,char *argv[])
{

	SYS("notify-send \"to do list\" ");
	TodoMain(argc,argv);
	return 0;
}
