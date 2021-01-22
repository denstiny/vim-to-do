#include <cstdio>
#include <cstdlib>
#include <cstring>
#include<regex>
#include <string>
#include<typeinfo>
#include<fstream>
#include<iostream>
#include<unistd.h>

#include "../include/json.hpp"
#include "./voice.cpp"

using json = nlohmann::json;

typedef std::string Str;

Da Date(std::string date)
{

	Da time;
	std::string str;
	std::string Weekpattern{"^(\\D{3}) "};
	std::string pattern{"^\\D{3}.(\\D{3}).(\\d{2}).(\\d{4}).(\\d{2}):(\\d{2}):(\\d{2})"};

	std::regex re(pattern);
	std::regex res(Weekpattern);
	std::smatch Weekres;

	std::regex_search(date,Weekres,res);

	// Dec 18 2021 22:15:00
	std::regex_search(date,Weekres,re);
	time.Y = Weekres[3];
	time.M = Weekres[1];
	for(int i = 0;i < 12;i++)
		if(time.M == MONTH[i])
			time.M = std::to_string(i+1);
	time.D = Weekres[2];
	time.H = Weekres[4];
	time.m = Weekres[5];
	time.s = Weekres[6];
	return time;
}
void PrintTodoJson(New todo)
{
	std::cout << "标题:" << todo.topic << std::endl;
	std::cout <<  "描述:"<< todo.detail << std::endl;
	
	Da data = Date(todo.date);
	todo.te = data;
	//std::cout << "开始时间: " << data.Y << ' ' << data.M  << ' '<< data.D << ' ' << data.H << ' ' << data.m << data.s << std::endl;

	//std::cout <<  "结束时间:"<< todo.due << std::endl;
	
	Da due = Date(todo.due);
	todo.de = due;
	std::cout << "结束时间: " << data.Y << ' ' << data.M << ' ' << data.D << ' ' << data.H << ' ' << data.m << data.s << std::endl;
	std::cout << std::endl;
}

Str reads(std::ifstream &file)
{
	std::ostringstream oss;
	char stc;
	Str str;
	int chrSize = 2;
	do{
		file.get(stc);

		if(stc == '[') continue;
		if(stc == '}') chrSize--;



		if(chrSize == 0 && stc == ',' || stc == ']')
		{
			chrSize = 2;

			str = oss.str();

			return str;
			oss.str("");  //清空
		}
		oss << stc;
	}while(file.good() && !file.eof());
	return str;

}

New* RegexMaset(std::string str)

{
	std::string tempstr;
	if(str.length() == 0)
		return nullptr;
	nlohmann::json tempJson = json::parse(str,nullptr,false);

	New *todo = new New;
	/*tood {
    "uid": "405989d0-80d2-4ba7-8b1a-4cb36a280ee0",
    "todo": {
      "topic": "吃早餐",
      "date": "Fri Jan 15 2021 06:30:00 GMT+0800 (中国标准时间)",
	  			星期 月 日  年   时间
      "active": false,
      "due": "Fri Jan 15 2021 06:31:00 GMT+0800 (中国标准时间)",
      "detail": "一晚上没睡觉"
    }
  }

	 * */

	if(tempJson["todo"]["topic"].is_string())
		todo->topic  = tempJson["todo"]["topic"];

	if(tempJson["todo"]["detail"].is_string())
		todo->detail = tempJson["todo"]["detail"];


	if(tempJson["todo"]["date"].is_string())
		todo->date   = tempJson["todo"]["date"];

	if(tempJson["todo"]["due"].is_string())
		todo->due    = tempJson["todo"]["due"];
	//PrintTodoJson(*todo);
	return todo;
}
int main(int argc , char *argv[])
{
	char *args = new char[1024];
	if(argc < 2)
	{
		strcpy(args,"/home/aercn/.config/coc/extensions/coc-todolist-data/coc-todolist.json");
		argv[1] = args;
	}
	std::ifstream file;
	file.open(argv[1],std::ios::in); // open coc-todolist-data json file
	std::cout << "star" << std::endl;
	New *root = nullptr,*temp = nullptr;
	Str str;
	while(!file.eof())
	{
		str= reads(file);
		New *todo = new New;
		todo = RegexMaset(str);
		if(todo == nullptr)
			break;
		PrintTodoJson(*todo);
		if(root == nullptr)
		{
			root=todo;
			root->next = nullptr;
		}
		else
		{
			temp->next = todo;
			todo->next = nullptr;
		}
		temp = todo;
		//std::cout << todo->topic << std::endl;
	}
	if(root!=nullptr)  // 段错误
		while(root != nullptr)
		{
			usleep(1000000);
			std::cerr << root->topic << std::endl;
			root=root->next;
		}
	else
		std::cout << "root is nullptr" << std::endl;
	delete [] args;
	file.close();
	return 0;
}
