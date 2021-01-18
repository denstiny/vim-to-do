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

#endif
