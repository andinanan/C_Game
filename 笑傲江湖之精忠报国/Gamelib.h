#ifndef __GAMELIB_H_
#define __GAMELIB_H_
/**********************************************************
*�ļ��� gamelib.h
*����������������Ϸ�г��õ�ϵͳ����������������ɫ��������
*�����ˣ�andinana
*���ڣ�2017-3-12
*�汾��1.0
**********************************************************/
#include <stdio.h>
#include <windows.h>
#include "Gamelib.h"
/*���ÿ���̨���ڵı���*/
void setTitle(char *title);
/*�������ֵ�ǰ��ɫ�ͱ���ɫ*/
/* 0-��ɫ, 1-��ɫ,   2-��ɫ,      3-ǳ��ɫ,     4-��ɫ,   5-��ɫ,   6-��ɫ,   7-��ɫ,
* 8-��ɫ, 9-����ɫ, 10-����ɫ,   11-��ǳ��ɫ   12-����ɫ 13-����ɫ 14-����ɫ 15-����ɫ
*/
void setColor(int foreColor,int backColor);
/*���ù���λ��*/
void setPosition(int x,int y);
/*��x,y���꿪ʼ��rowcount��*/
void clear(int x, int y, int rowcount);
#endif