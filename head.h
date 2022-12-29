#pragma once
#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<graphics.h>
#include"resource.h"

#define CELL 10	//单个细胞大小，像素
#define SIZE 80 //画布大小,每行列细胞数

extern bool live[SIZE][SIZE];	//每个cell的存活状态
extern bool temp[SIZE][SIZE];
extern bool last_live[SIZE][SIZE];	//上一回合存活状态
extern bool running;
extern bool pulse;
extern bool in_menu;	//是否进入开始页面
extern int rx[3];	//用于遍历周围九宫格
extern int ry[3];
extern int sleeptime;

extern void menu();
extern void Update();	//更新
extern bool update(int x, int y);	//判定cell存活
extern void fillcell();	//更新cell
extern void map();
extern void control();
extern void preset();