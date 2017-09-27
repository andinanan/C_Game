 
#include "Game.h"
#include "Gamelib.h"
#include <stdlib.h>
//假设当前用户坐标为（3,2）
extern int x, y;
int main(){
	char key;//接收到的用户按键
	Init();
	//login();
	setTitle("笑傲江湖之精忠报国");
	clear(0, 0, 20);
	setColor(10, 0);
	ShowWelcom();
	ShowMap();
	ShowInformation();
	ShowMapInfo();
	ShowMainMenu();
	while (1)
	{
		fflush(stdin);
		key = _getch();//无回显的接收键盘录入
		fflush(stdin);
		if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7'){//处理菜单
			ProcessMainMenu(key);
			continue;
		}
		else if (key == VK_UP || key == 72)//用户按了上键
		{
			y--;
		}
		else if (key == 39 || key == 77)//右
		{
			x++;
		}
		else if (key == 40 || key == 80)//下
		{
			y++;
		}
		else if (key == 37 || key == 75)//左
		{
			x--;
		}

		if (x > 7){
			x = 0;
		}
		if (x < 0){
			x = 7;
		}
		if (y > 7){
			y = 0;
		}
		if (y < 0){
			y = 7;
		}
		ShowMap();//重新显示地图
	}




	return 0;
}