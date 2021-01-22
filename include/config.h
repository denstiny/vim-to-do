#ifndef __CONFIG_H__
#define __CONFIG_H__


#include <string>






#define Lang  "--english-speed"
#define EKHO "ekho -v Cantonese "
#define EKHOCOFIG false
#define VOIDO "mpg123"
#define VOIDOCONFIG false
#define VOIDOFILE "/mnt/home/todo-list/src/material/keli.mp3"
#define SYS system
#define SED "notify-send"










typedef std::string Str;


typedef struct date
{
	Str Y,
		M,
		D,
		H,
		m,
		s;
}Da;
typedef struct Todo
{
	Str topic,  // 标题 string
 		date,   // 开始时间
		due,    // 结束时间
		detail; // 事件描述
	Da te,de;
	bool todo;  
	struct Todo *next;
}New;

const std::string MONTH[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};


#endif
