 
#include "Game.h"
#include "Gamelib.h"
#include <stdlib.h>
//���赱ǰ�û�����Ϊ��3,2��
extern int x, y;
int main(){
	char key;//���յ����û�����
	Init();
	//login();
	setTitle("Ц������֮���ұ���");
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
		key = _getch();//�޻��ԵĽ��ռ���¼��
		fflush(stdin);
		if (key == '1' || key == '2' || key == '3' || key == '4' || key == '5' || key == '6' || key == '7'){//����˵�
			ProcessMainMenu(key);
			continue;
		}
		else if (key == VK_UP || key == 72)//�û������ϼ�
		{
			y--;
		}
		else if (key == 39 || key == 77)//��
		{
			x++;
		}
		else if (key == 40 || key == 80)//��
		{
			y++;
		}
		else if (key == 37 || key == 75)//��
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
		ShowMap();//������ʾ��ͼ
	}




	return 0;
}