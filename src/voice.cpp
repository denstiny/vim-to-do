#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include<unistd.h>
#include <sys/types.h>
#include <cstring>
#include "../include/config.h"
void voice(char *argv)
{
	char *shell = (char *)malloc(sizeof(char)*BUFSIZ);

	sprintf(shell,"%s%s%s%s%s",EKHO," \"",argv,"\" ",Lang);

	std::cout << shell << std::endl;

	SYS(shell);
	delete shell;
}
void Remind()
{
	char *shell = (char *)malloc(sizeof(char)*BUFSIZ);

	sprintf(shell, "%s%s%s >/dev/null 2>&1",VOIDO," ",VOIDOFILE);

	std::cout << shell << std::endl;

	SYS(shell);
	delete shell;
}
int Maxmain(New todo)
{
	if(EKHOCOFIG)
	{
		char *shell = (char *)malloc(sizeof(char)*BUFSIZ);
		//  语音播报
		strcat(shell,(char*)todo.topic.c_str());
		std::cout << shell << std::endl;
		voice(shell);
		delete shell;
	}
	if(VOIDOCONFIG)
		Remind();
		// 铃声提醒
	return 0;
}
