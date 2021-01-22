// 处理json数据
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
void TimeTask(Da date,Da due,New todo)
{

	  //Sat Dec 18 2021 22:15:00

		time_t tt;
	time(&tt);
	tt+= 8*3600;
	tm *ts = gmtime(&tt);

	printf("%d-%d-%d %d:%d:%d\n",ts->tm_year+1900,ts->tm_mon+1,ts->tm_mday,ts->tm_hour,ts->tm_min,ts->tm_sec);

	 //2021-1-21 14:38:25


	printf("%d-%d-%d %d:%d:%d\n",std::stoi(date.Y),std::stoi(date.M),std::stoi(date.D),std::stoi(date.H),std::stoi(date.m),std::stoi(date.s));
	  if( 		 std::stoi(date.Y) == ts->tm_year+1900 
			  && std::stoi(date.M) == ts->tm_mon+1
			  && std::stoi(date.D) == ts->tm_mday
			  && std::stoi(date.H) == ts->tm_hour
			  //&& date.m == std::to_string(ts->tm_min)
			  )
	  {
		char *shell =(char *) malloc(sizeof(char)*BUFSIZ);
		sprintf(shell, "%s \"%s\" \"%s\"",
				SED,
				todo.topic.c_str(),
				todo.detail.c_str());
		std::cout << "测试" <<shell << std::endl;
		SYS(shell);
	  }
	//Maxmain(todo);
}
void PrintTodoJson(New todo)
{
	std::cout << "标题:" << todo.topic << std::endl;
	std::cout <<  "描述:"<< todo.detail << std::endl;
	
	Da data = Date(todo.date);
	std::cout << "开始时间: " << data.Y << ' ' << data.M  << ' '<< data.D << ' ' << data.H << ' ' << data.m << data.s << std::endl;

	//std::cout <<  "结束时间:"<< todo.due << std::endl;
	
	Da due = Date(todo.due);
	std::cout << "结束时间: " << data.Y << ' ' << data.M << ' ' << data.D << ' ' << data.H << ' ' << data.m << data.s << std::endl;
	std::cout << std::endl;

	TimeTask(data,due,todo);

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
	PrintTodoJson(*todo);
	delete todo;
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

int TodoMain(int argc , char *argv[])
{
	char *args = new char[1024];
	if(argc < 2)
	{
		strcpy(args,"/home/aercn/.config/coc/extensions/coc-todolist-data/coc-todolist.json");
		argv[1] = args;
	}
	reads(argv[1]);

	delete [] args;
	return 0;
}
