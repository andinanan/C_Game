#ifndef __GAMELIB_H_
#define __GAMELIB_H_
/**********************************************************
*文件名 gamelib.h
*描述：用来定义游戏中常用的系统操作：更改文字颜色、清屏等
*创建人：andinana
*日期：2017-3-12
*版本：1.0
**********************************************************/
#include <stdio.h>
#include <windows.h>
#include "Gamelib.h"
/*设置控制台窗口的标题*/
void setTitle(char *title);
/*设置文字的前景色和背景色*/
/* 0-黑色, 1-蓝色,   2-绿色,      3-浅绿色,     4-红色,   5-紫色,   6-黄色,   7-白色,
* 8-灰色, 9-淡蓝色, 10-淡绿色,   11-淡浅绿色   12-淡红色 13-淡紫色 14-淡黄色 15-亮白色
*/
void setColor(int foreColor,int backColor);
/*设置光标的位置*/
void setPosition(int x,int y);
/*从x,y坐标开始清rowcount行*/
void clear(int x, int y, int rowcount);
#endif