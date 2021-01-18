#ifndef __CONFIG_H__
#define __CONFIG_H__


#include <string>
#define Lang  "--english-speed"
#define EKHO "ekho -v Cantonese "
#define EKHOCOFIG false
#define VOIDO "playout"
#define VOIDOCONFIG true
#define VOIDOFILE "/mnt/home/todo-list/src/bang.mp3"
#define SYS system
typedef std::string Str;
typedef struct Todo
{
	Str topic,  // 标题
		date,   // 开始时间
		due,    // 结束时间
		detail; // 事件描述
}New;

typedef struct date
{
	Str Y,
		M,
		D,
		H,
		m,
		s;
}Da;

#define Mon 1
#define Tue 2
#define Wed 3
#define Thu 4
#define Fri 5
#define Sat 6
#define Sun 7

#define Jan 1
#define Feb 2
#define Mar 3
#define Apr 4
#define May 5
#define Jun 6
#define Jul 7
#define Aug 8
#define Sep 9
#define Oct 10
#define Nov 11
#define Dec 12
const std::string MONTH[12]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};

#endif
