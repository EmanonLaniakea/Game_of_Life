#pragma once
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<graphics.h>
#include"resource.h"

#define CELL 10	//����ϸ����С������
#define SIZE 80 //������С,ÿ����ϸ����

extern bool live[SIZE][SIZE];	//ÿ��cell�Ĵ��״̬
extern bool temp[SIZE][SIZE];
extern bool last_live[SIZE][SIZE];	//��һ�غϴ��״̬
extern bool running;
extern bool pulse;
extern bool in_menu;	//�Ƿ���뿪ʼҳ��
extern int rx[3];	//���ڱ�����Χ�Ź���
extern int ry[3];
extern int sleeptime;

extern void menu();
extern void Update();	//����
extern bool update(int x, int y);	//�ж�cell���
extern void fillcell();	//����cell
extern void map();
extern void control();
extern void preset();