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

void TimeTask(New *todo)

{

	  //Sat Dec 18 2021 22:15:00

	time_t tt;
	time(&tt);
	tt+= 8*3600;
	tm *ts = gmtime(&tt);
	char *tts = new char[BUFSIZ];

	sprintf(tts,"当前时间 %d-%d-%d %d:%d:%d\n",ts->tm_year+1900,ts->tm_mon+1,ts->tm_mday,ts->tm_hour,ts->tm_min,ts->tm_sec);
	std::cout << tts << std::endl;

	 //2021-1-21 14:38:25


	printf("任务时间: %d-%d-%d %d:%d:%d\n",std::stoi(todo->te.Y),std::stoi(todo->te.M),std::stoi(todo->te.D),std::stoi(todo->te.H),std::stoi(todo->te.m),std::stoi(todo->te.s));



	  if( 	  std::stoi(todo->te.Y) == ts->tm_year+1900 
			  && std::stoi(todo->te.M) == ts->tm_mon+1
			  && std::stoi(todo->te.D) == ts->tm_mday
			  && std::stoi(todo->te.H) == ts->tm_hour
			  && todo->te.m == std::to_string(ts->tm_min)
			  && todo->todo == true
			  && todo->active
			  )
	  {
		  todo->todo = false;
		char *shell = new char [BUFSIZ];
		sprintf(shell, "%s \"%s\" \"%s \n开始时间: %s:%s:%s\n结束时间: %s:%s:%s\n任务开始\"",
				SED,
				todo->topic.c_str(),
				todo->detail.c_str(),
				todo->te.H.c_str(),
				todo->te.m.c_str(),
				todo->te.s.c_str(),
				todo->de.H.c_str(),
				todo->de.m.c_str(),
				todo->de.s.c_str()
				);

 		//date,   // 开始时间
		//due,    // 结束时间
		std::cout << shell << std::endl;
		SYS(shell);
		Maxmain(*todo);
	  }

	  if( 	  std::stoi(todo->de.Y) == ts->tm_year+1900 
			  && std::stoi(todo->de.M) == ts->tm_mon+1
			  && std::stoi(todo->de.D) == ts->tm_mday
			  && std::stoi(todo->de.H) == ts->tm_hour
			  && todo->de.m == std::to_string(ts->tm_min)
			  && todo->end == true
			  && todo->active
			  )
	  {
		  todo->end = false;
		char *shell = new char [BUFSIZ];
		sprintf(shell, "%s \"%s\" \"%s \n开始时间: %s:%s:%s\n结束时间: %s:%s:%s\n任务结束\"",
				SED,
				todo->topic.c_str(),
				todo->detail.c_str(),
				todo->te.H.c_str(),
				todo->te.m.c_str(),
				todo->te.s.c_str(),
				todo->de.H.c_str(),
				todo->de.m.c_str(),
				todo->de.s.c_str()
				);

 		//date,   // 开始时间
		//due,    // 结束时间
		std::cout << shell << std::endl;
		SYS(shell);
		Maxmain(*todo);
	  }
}

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
void PrintTodoJson(New *todo)
{
//	std::cout << "标题:" << todo.topic << std::endl;
//	std::cout <<  "描述:"<< todo.detail << std::endl;
	
	Da data = Date(todo->date);
	todo->te = data;
	//std::cout << "开始时间: " << data.Y << ' ' << data.M  << ' '<< data.D << ' ' << data.H << ' ' << data.m << data.s << std::endl;

	//std::cout <<  "结束时间:"<< todo.due << std::endl;
	
	Da due = Date(todo->due);
	todo->de = due;
	todo->todo = true;
	todo->end = true;
//	std::cout << "结束时间: " << data.Y << ' ' << data.M << ' ' << data.D << ' ' << data.H << ' ' << data.m << data.s << std::endl;
//	std::cout << std::endl;
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






		if( chrSize == 0 && stc == ',' || stc == ']' )
		{
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

	if(tempJson["todo"]["active"].is_boolean())
		todo->active = tempJson["todo"]["active"];
	//  添加 事件判断

	if(tempJson["todo"]["date"].is_string())
		todo->date   = tempJson["todo"]["date"];

	if(tempJson["todo"]["due"].is_string())
		todo->due    = tempJson["todo"]["due"];
	//PrintTodoJson(*todo);
	return todo;
}

long FileSize(std::ifstream &ifs)
{
  	long tmppos;
    long respos;
    tmppos=ifs.tellg();
    ifs.seekg(0,std::ios::end);
    respos=ifs.tellg();
    ifs.seekg(tmppos,std::ios::beg);
    return respos; 
}

