#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../src/todo.cpp"
#include <cstring>

int main(int argc , char *argv[])
{
	char *args = new char[1024];
	long FileLong = 0;
	if(argc < 2)
	{
		strcpy(args,"/home/aercn/.config/coc/extensions/coc-todolist-data/coc-todolist.json");
		argv[1] = args;
	}
	std::ifstream file;
	New *root = nullptr,*temp = nullptr;
	file.open(argv[1],std::ios::in); // open coc-todolist-data json file

	while(root == nullptr)
	{
		if(FileLong < FileSize(file))
		{
			std::cout << "start "<< std::endl;
			FileLong = FileSize(file);
			while(!file.eof() && file.good())
			{
				Str str = reads(file);
				New *todo = new New;
				todo = RegexMaset(str);
				if(todo == nullptr)
				{
					delete todo;
					continue;
				}
				PrintTodoJson(todo);
				if(root == nullptr)
				{
					root = todo;
					root->next = nullptr;
				}else{
					temp->next = todo;
					todo->next = nullptr;
				}
				temp = todo;
			}
			//TimeTask(todo);
		}
		usleep(1000000);
	}
	temp = root;
	while(temp != nullptr)
	{
		std::cout << temp->topic << std::endl;
		temp = temp->next;
	}

	while(1)
	{

		file.open(argv[1],std::ios::in); // open coc-todolist-data json file
		// 设置指针到文件的开头
	  	file.clear(std::ios::goodbit);
	  	file.seekg(std::ios::beg);

		if(FileLong < FileSize(file))
		{
			std::cout << "start "<< std::endl;
			FileLong = FileSize(file);

			Str str = reads(file);
			New *todo = new New;
			todo = RegexMaset(str);
			if(todo == nullptr)
			{
				delete todo;
				continue;
			}
			PrintTodoJson(todo);
			temp = root;
			while(temp->next != nullptr)
				temp = temp->next;
			temp->next = todo;
			todo->next = nullptr;
			//TimeTask(todo);
		}
		temp = root;
		while(temp != nullptr)
		{
//			std::cout << temp->topic << std::endl;
			TimeTask(temp);
			temp = temp->next;
		}

		file.close();
		usleep(1000000);
	}
	delete [] args;
	return 0;
}
