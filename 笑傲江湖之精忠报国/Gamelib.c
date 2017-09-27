#include "Gamelib.h"
/**********************************************************
*�ļ��� game����.c
*������ʵ�֣�������ͷ�ļ��еĺ���
*�����ˣ�andinana
*���ڣ�2017-3-12
*�汾��1.0
**********************************************************/
void setTitle(char *title){
	SetConsoleTitle(title);
}
void setColor(int foreColor, int backColor){
	HANDLE winHandle;//���
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	//����������ɫ
	SetConsoleTextAttribute(winHandle, foreColor + backColor * 0x10);
}
void setPosition(int x, int y){
	HANDLE winHandle;//���
	COORD pos = { x, y };
	winHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(winHandle, pos);
}
void clear(int x, int y, int rowcount){
	setPosition(x+1, y);
	//ÿ�����73���ַ�
	for (int i = 0; i < rowcount; i++){
		setPosition(x+1, y + i );
		for (int j = 0; j < 72; j++){
			printf(" ");
		}
	}
}