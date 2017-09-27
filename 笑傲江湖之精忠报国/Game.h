#ifndef __GAME_H_
#define __GAME_H_
/**********************************************************
*�ļ��� game.h
*������������Ϸ�ĺ��ĵĽṹ�ͺ���
*�����ˣ�andinana
*���ڣ�2017-3-12
*�汾��1.0
**********************************************************/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/**��Ϸ�Ľṹ���Ͷ���**/
//��ҡ���ͼ��װ��������
/*��ͼ�ṹ*/

typedef struct _map{
	int id;//��ͼ���
	char name[50];//��ͼ����
	int minlevel;//��ҽ������С�ȼ�
	COORD coord;//��ͼ�����꣨windows�Դ�ֻ��x,y��
	char desc[500];//��ͼ����
}Map;
/*��Ϸ���ߣ����������ߡ�����Ʒ���߿�Ƭ*/
//��Ϸ��������ö�٣����������ߡ�����Ʒ����Ƭ����Ƭ
typedef enum _proptype{
	Weapon,Armor,Con,Card,Frag//��Ϸ�������ͣ����������ߡ�����Ʒ����Ƭ����Ƭ
}Proptype;
typedef struct _prop
{
	int id;//���߱��
	char name[50];//��������
	int level;//���߼���
	Proptype type;//���ߵ�����
	int stock;//���ߵĿ�����ұ����еĵ�������
	union {      //���϶�ѡһ
		int minattack;//����������Ͷ�Ӧ������
		int mindefence;//����Ƿ��߾Ͷ�Ӧ������
		int minpower;//�����Ѫƿ����������Ʒ���Ͷ�Ӧ���ӵ�����ֵ
	};
	union {      //���϶�ѡһ
		int maxattack;//����������Ͷ�Ӧ������
		int maxdefence;//����Ƿ��߾Ͷ�Ӧ������
		int maxpower;//�����Ѫƿ����������Ʒ���Ͷ�Ӧ���ӵ�����ֵ
	};
	double price;//���ߵĵ���
	char describe[300];//���ߵĹ�������
}Prop;
/*����*/

typedef struct _martial{//����
	int id;
	char name[50];
	char type[8];//�������ͣ�����а
	COORD coord;//��������
	int isOpen;//�Ƿ񿪷�
	char desc[1000];//��������

}Martial;
typedef struct _bag{
	int playerId;//�������Id
	int propCount;//�������ߵ�����
	int max;//�������ɴ�ŵĵ�����
	Prop props[8];//���߱����еĵ������飬Ĭ��8�����߲��(8�������óɳ���)

}Bag;
typedef struct _player{
	int id;//��ҵ�id
	char name[50];//��ҵ�����
	char password[50];//��ҵ�����
	int life;//��ҵ�����ֵ
	int level;//��ҵļ���
	int exp;//��Ҿ���ֵ
	int hp;//��ҵ�Ѫ��
	int mp;//��ҵ�����ֵ
	int mp_max;//��ǰ������ҵ�����ֵ
	int gold;//��ҵĽ��ֵ
	COORD coord;
	Martial martial;//��ҵ�����
	Prop weapon;//���װ��������
	Prop armor;//���װ����
	
	Bag bag;//��ҵı���
}Player;
typedef struct _monster{
	int id;//�����id
	char name[50];
	int level;
	int hp;
	int att;//����Ĺ�����
	int def;//����ķ�����
	int minmoney;//���������������С���ֵ
	int maxmoney;//������������������ֵ
	int exp;//������������ľ���ֵ
	//��չ��ɱ�������������Ʒ
	int state;//����״̬��0��ʾ��������0��ʾ����
	COORD coord;//��������
}Monster;

void Init();//��ʼ������
void Show();//��ʾ����
//void login();//��¼����
//void regist();//ע�ắ��
void ShowWelcom();//��ʾ��Ϸ�Ļ�ӭ��Ϣ
void ShowMap();//��ʾ��Ϸ��ͼ
void ShowMapInfo();//����ʾ��ͼʱ��ʾ��ͼ��Ϣ
void ShowInformation();//��ʾ��Ϸ��ͼ�·���Ϣ
void ShowMainMenu();//��ʾ��Ϸ���˵�
void ProcessMainMenu(char key);//���ݴ�����Ϸ���˵�����ҵ��
void ShowPlayerInfo();//����Ϣ������ʾ��ҵĸ�������
void ShowMonsters();//����Ϣ������ʾ��ǰ��ͼ�Ĺ���
void Fight(Monster *monster);//���
void move(int X, int Y);//˲���ƶ�
void showExist();//�˳���Ϸ
int trade(Player *player, int propId);//����
void showProp();//��ʾ��Ʒ
void showtradeInfo();//��ʾ������Ϣ
#endif