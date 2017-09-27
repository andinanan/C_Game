#ifndef __GAME_H_
#define __GAME_H_
/**********************************************************
*文件名 game.h
*描述：用来游戏的核心的结构和函数
*创建人：andinana
*日期：2017-3-12
*版本：1.0
**********************************************************/
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/**游戏的结构类型定义**/
//玩家、地图、装备、怪物
/*地图结构*/

typedef struct _map{
	int id;//地图编号
	char name[50];//地图名称
	int minlevel;//玩家进入的最小等级
	COORD coord;//地图的坐标（windows自带只有x,y）
	char desc[500];//地图介绍
}Map;
/*游戏道具：武器、防具、消耗品或者卡片*/
//游戏道具类型枚举：武器、道具、消耗品、卡片、碎片
typedef enum _proptype{
	Weapon,Armor,Con,Card,Frag//游戏道具类型：武器、道具、消耗品、卡片、碎片
}Proptype;
typedef struct _prop
{
	int id;//道具编号
	char name[50];//道具名称
	int level;//道具级别
	Proptype type;//道具的类型
	int stock;//道具的库存或玩家背包中的叠加数量
	union {      //联合多选一
		int minattack;//如果是武器就对应攻击力
		int mindefence;//如果是防具就对应防御力
		int minpower;//如果是血瓶或其他消耗品，就对应增加的能量值
	};
	union {      //联合多选一
		int maxattack;//如果是武器就对应攻击力
		int maxdefence;//如果是防具就对应防御力
		int maxpower;//如果是血瓶或其他消耗品，就对应增加的能量值
	};
	double price;//道具的单价
	char describe[300];//道具的功能描述
}Prop;
/*背包*/

typedef struct _martial{//门派
	int id;
	char name[50];
	char type[8];//门派类型：正、邪
	COORD coord;//门派坐标
	int isOpen;//是否开放
	char desc[1000];//门派描述

}Martial;
typedef struct _bag{
	int playerId;//所属玩家Id
	int propCount;//背包道具的总数
	int max;//背包最多可存放的道具数
	Prop props[8];//道具背包中的道具数组，默认8个道具插槽(8可以设置成常量)

}Bag;
typedef struct _player{
	int id;//玩家的id
	char name[50];//玩家的姓名
	char password[50];//玩家的密码
	int life;//玩家的生命值
	int level;//玩家的级别
	int exp;//玩家经验值
	int hp;//玩家的血量
	int mp;//玩家的内力值
	int mp_max;//当前级别玩家的内力值
	int gold;//玩家的金币值
	COORD coord;
	Martial martial;//玩家的门派
	Prop weapon;//玩家装备的武器
	Prop armor;//玩家装备的
	
	Bag bag;//玩家的背包
}Player;
typedef struct _monster{
	int id;//怪物的id
	char name[50];
	int level;
	int hp;
	int att;//怪物的攻击力
	int def;//怪物的防御力
	int minmoney;//打死怪物后掉落的最小金币值
	int maxmoney;//打死怪物后掉落的最大金币值
	int exp;//打死怪物后掉落的经验值
	//扩展：杀死怪物后掉落的物品
	int state;//怪物状态：0表示已死，非0表示活着
	COORD coord;//怪物坐标
}Monster;

void Init();//初始化函数
void Show();//显示函数
//void login();//登录函数
//void regist();//注册函数
void ShowWelcom();//显示游戏的欢迎信息
void ShowMap();//显示游戏地图
void ShowMapInfo();//在显示地图时显示地图信息
void ShowInformation();//显示游戏地图下方信息
void ShowMainMenu();//显示游戏主菜单
void ProcessMainMenu(char key);//根据处理游戏主菜单键的业务
void ShowPlayerInfo();//在信息界面显示玩家的个人资料
void ShowMonsters();//在信息界面显示当前地图的怪物
void Fight(Monster *monster);//打怪
void move(int X, int Y);//瞬间移动
void showExist();//退出游戏
int trade(Player *player, int propId);//交易
void showProp();//显示商品
void showtradeInfo();//显示交易信息
#endif