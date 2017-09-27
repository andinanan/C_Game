#include "Gamelib.h"
/**********************************************************
*文件名 gameｌｉｂ.c
*描述：实现ｇａｍｅｌｉｂ头文件中的函数
*创建人：andinana
*日期：2017-3-12
*版本：1.0
**********************************************************/
void setTitle(char *title){
	SetConsoleTitle(title);
}
void setColor(int foreColor, int backColor){
	HANDLE winHandle;//句柄
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置文字颜色
	SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);
}
void setPosition(int x, int y){
	HANDLE winHandle;//句柄
	COORD pos = { x, y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(winHandle, pos);
}
void clear(int x, int y, int rowcount){
	setPosition(x+1, y);
	//每行清除73个字符
	for (int i = 0; i < rowcount; i++){
		setPosition(x+1, y + i );
		for (int j = 0; j < 72; j++){
			printf(" ");
		}
	}
}