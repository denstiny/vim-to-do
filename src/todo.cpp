// 处理json数据
#include <cstring>
#include<regex>
#include<typeinfo>
#include<fstream>
#include<iostream>
#include<unistd.h>

#include "../include/json.hpp"
#include "./voice.cpp"


using json = nlohmann::json;

typedef std::string Str;
	/* {
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

void PrintTodoJson(New todo)
{
	std::string pattern{"(\\d{4})-(0\\d{1}|1[0-2])-(0\\d{1}|[12]\\d{1}|3[01])\\s(0\\d{1}|1\\d{1}|2[0-3]):[0-5]\\d{1}:([0-5]\\d{1})"};
	std::regex re(pattern);
	std::cout << "标题:" << todo.topic << std::endl;
	std::cout <<  "描述:"<< todo.detail << std::endl;
	todo.date = std::regex_search(todo.date,re);
	std::cout <<  "开始时间:"<< todo.date << std::endl;
	std::cout <<  "结束时间:"<< todo.due << std::endl;
	std::cout << std::endl;
	Maxmain(todo);
}


New RegexMaset(std::string str)

{
   std::string tempstr;
   nlohmann::json tempJson = json::parse(str,nullptr,false);

   New todo;

   if(tempJson["todo"]["topic"].is_string())
   	todo.topic  = tempJson["todo"]["topic"];

   if(tempJson["todo"]["detail"].is_string())
   	todo.detail = tempJson["todo"]["detail"];


   if(tempJson["todo"]["date"].is_string())
   	todo.date   = tempJson["todo"]["date"];

   if(tempJson["todo"]["due"].is_string())
   	todo.due    = tempJson["todo"]["due"];
   PrintTodoJson(todo);

   return todo;
}

int pairing(char stc)
{
	if(stc == '{')
		return 1;
	else if(stc == '}')
		return -1;
	return 0;
}


void reads(const char *FileName)
{
	std::ifstream file;


	char stc;
	file.open(FileName,std::ios::in); // open coc-todolist-data json file

	
	std::cout << "star" << std::endl;
	std::string str;

	std::ios_base::sync_with_stdio(false);
	int chrSize = 2;

	std::ostringstream oss;

	do{
		file.get(stc);

		if(stc == '[') continue;
		if(stc == '}') chrSize--;



		if(chrSize == 0 && stc == ',' || stc == ']')
		{
			chrSize = 2;

			str = oss.str();

			RegexMaset(str);

			oss.str("");  //清空
			continue;
		}
		oss << stc;
	}while(file.good() && !file.eof());

	file.close();
}

int main(int argc , char *argv[])
{
	char *args = new char[1024];
	if(argc < 2)
	{
		strcpy(args,"/home/aercn/.config/coc/extensions/coc-todolist-data/coc-todolist.json");
		argv[1] = args;
	}
	reads(args);

	delete [] args;
	return 0;
}
