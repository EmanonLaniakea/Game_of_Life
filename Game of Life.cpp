﻿#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<graphics.h>
#include"resource.h"

#define CELL 10	//单个细胞大小，像素
#define SIZE 70 //画布大小,每行列细胞数

bool live[SIZE][SIZE] = { 0 };	//每个cell的存活状态
bool temp[SIZE][SIZE] = { 0 };
bool running = true;
bool pulse = true;
bool pass = true;	//是否进入开始页面
int rx[3] = { -1,0,1 };	//用于遍历周围九宫格
int ry[3] = { -1,0,1 };
int sleeptime = 10;

void Update();	//更新
bool update(int x, int y);	//判定cell存活
void fillcell();	//更新cell
void start();
void map();
void control();
void preset();

int main() {
	while (running || pass) {
		while (pass) {
			start();
		}
		if (running) {
			Sleep(sleeptime);	//控制每代刷新间隔
			fillcell();
			control();
			Update();
		}
	}
	return 0;
}

void Update()
{
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			temp[i][j] = update(i, j);
		}
	}
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			live[i][j] = temp[i][j];
		}
	}
}

bool update(int x, int y)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			int xt = (x + rx[i] + SIZE) % SIZE, yt = (y + ry[j] + SIZE) % SIZE;	//边界规则,模拟无限平面
			if (live[xt][yt])  sum += 1;
		}
	if (live[x][y])
	{
		sum--;
		if (sum < 2 || sum>3) return false;
		else return true;
	}
	else
	{
		if (sum == 3) return true;
		else return false;
	}
}

void fillcell()
{
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (live[i][j]) {
				fillrectangle(i * CELL, j * CELL, (i + 1) * CELL, (j + 1) * CELL);
			}
			else {
				clearrectangle(i * CELL + 1, j * CELL + 1, (i + 1) * CELL - 1, (j + 1) * CELL - 1);
			}
		}
	}
}

void start()
{
	initgraph(1400, 800, 0);
	loadimage(NULL, L"PNG", MAKEINTRESOURCE(IDB_PNG2));
	ExMessage m;
	while (1) {
		getmessage(&m, -1);
		if (m.message == WM_KEYDOWN) {
			if (m.vkcode == VK_ESCAPE) {
				running = false;
				pass = false;
				return;
			}
		}
		if (m.message == WM_LBUTTONUP) {
			if (m.x > 1078 && m.x < 1327) {
				if (m.y > 415 && m.y < 499) {	//playground
					for (int i = 0; i < SIZE; i++) {
						for (int j = 0; j < SIZE; j++) {
							live[i][j] = 0;
						}
					}
					sleeptime = 10;
					map();
					pass = false;
					return;
				}
				if (m.y > 544 && m.y < 627) {	//presets
					preset();
					if (!pass) {
						map();
					}
					return;
				}
				if (m.y > 671 && m.y < 754) {	//options
					closegraph();
					initgraph(1400, 800, 0);
					//loadimage()
					while (1) {
						peekmessage(&m, -1);
						if (m.message == WM_KEYDOWN) {
							if (m.vkcode == VK_ESCAPE) {
								return;
							}
						}
					}
				}
			}
		}
	}
}

void map()
{
	int i, j;
	initgraph(CELL * SIZE, CELL * SIZE, 0);
	setbkcolor(LIGHTGRAY);
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	cleardevice();
	for (i = 0; i < SIZE; i++) {
		line(0, i * CELL, SIZE * CELL, i * CELL);
		line(i * CELL, 0, i * CELL, SIZE * CELL);
	}
}

void control()
{
	ExMessage m;
	peekmessage(&m, -1, true);
	if (m.message == WM_KEYDOWN || m.message == WM_RBUTTONDOWN) {
		if (m.vkcode == VK_ESCAPE) {
			pass = true;
			return;
		}
		if (m.vkcode == VK_SPACE || m.rbutton) {
			pulse = true;
		}
		if (m.vkcode == 0x53) {	//s键，进入预设设置
			preset();
			pulse = true;
		}
		if (m.vkcode == VK_UP) {
			sleeptime += 10;
		}
		if (m.vkcode == VK_DOWN) {
			sleeptime -= 50;
			if (sleeptime <= 0) {
				sleeptime = 10;
			}
		}
	}
	while (pulse) {
		getmessage(&m, -1);
		if (m.lbutton == 1) {
			int x = m.x / CELL, y = m.y / CELL;
			if (live[x][y]) {
				live[x][y] = false;
				clearrectangle(x * CELL + 1, y * CELL + 1, (x + 1) * CELL - 1, (y + 1) * CELL - 1);
			}
			else {
				live[x][y] = true;
				fillrectangle(x * CELL, y * CELL, (x + 1) * CELL, (y + 1) * CELL);
			}
		}
		if (m.vkcode == VK_DELETE) {
			for (int i = 0; i < SIZE; i++) {
				for (int j = 0; j < SIZE; j++)
				{
					live[i][j] = false;
					clearrectangle(i * CELL + 1, j * CELL + 1, (i + 1) * CELL - 1, (j + 1) * CELL - 1);
				}
			}
		}
		if (m.message == WM_KEYDOWN) {
			if (m.vkcode == VK_SPACE) {
				flushmessage();
				return;
			}
		}
		if (m.rbutton) {
			flushmessage();
			pulse = false;
			return;
		}
	}
}

void preset()
{
	closegraph();
	initgraph(1400, 800, 0);
	loadimage(NULL, L"PNG", MAKEINTRESOURCE(IDB_PNG1));
	ExMessage m;
	while (1) {
		flushmessage();
		getmessage(&m, -1);
		if (m.message == WM_KEYDOWN) {
			if (m.vkcode == VK_ESCAPE) {
				return;
			}
		}
		if (m.message == WM_LBUTTONUP) {
			if (m.x > 600 && m.x < 1400 && m.y>0 && m.y < 270) {	//gosper gliter gun
				pass = false;
				pulse = true;
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						live[i][j] = 0;
					}
				}
				{
					live[2 + 2][5] = true;
					live[2 + 2][6] = true;
					live[3 + 2][5] = true;
					live[3 + 2][6] = true;
					live[11 + 3][5] = true;
					live[11 + 3][6] = true;
					live[11 + 3][7] = true;
					live[12 + 3][4] = true;
					live[12 + 3][8] = true;
					live[13 + 3][3] = true;
					live[13 + 3][9] = true;
					live[14 + 3][3] = true;
					live[14 + 3][9] = true;
					live[15 + 3][6] = true;
					live[16 + 3][4] = true;
					live[16 + 3][8] = true;
					live[17 + 3][5] = true;
					live[17 + 3][6] = true;
					live[17 + 3][7] = true;
					live[18 + 3][6] = true;
					live[21 + 3][3] = true;
					live[21 + 3][4] = true;
					live[21 + 3][5] = true;
					live[22 + 3][3] = true;
					live[22 + 3][4] = true;
					live[22 + 3][5] = true;
					live[23 + 3][2] = true;
					live[23 + 3][6] = true;
					live[25 + 3][1] = true;
					live[25 + 3][2] = true;
					live[25 + 3][6] = true;
					live[25 + 3][7] = true;
					live[35 + 3][3] = true;
					live[35 + 3][4] = true;
					live[36 + 3][3] = true;
					live[36 + 3][4] = true;
				}
				return;
			}
			if (m.x > 0 && m.x < 300 && m.y>400 && m.y < 600) {	// pulsar
				pass = false;
				pulse = true;
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						live[i][j] = 0;
					}
				}
				{
					live[2][4] = true;
					live[2][5] = true;
					live[2][6] = true;
					live[2][10] = true;
					live[2][11] = true;
					live[2][12] = true;
					live[7][4] = true;
					live[7][5] = true;
					live[7][6] = true;
					live[7][10] = true;
					live[7][11] = true;
					live[7][12] = true;
					live[9][4] = true;
					live[9][5] = true;
					live[9][6] = true;
					live[9][10] = true;
					live[9][11] = true;
					live[9][12] = true;
					live[14][4] = true;
					live[14][5] = true;
					live[14][6] = true;
					live[14][10] = true;
					live[14][11] = true;
					live[14][12] = true;
					live[4][2] = true;
					live[4][7] = true;
					live[4][9] = true;
					live[4][14] = true;
					live[5][2] = true;
					live[5][7] = true;
					live[5][9] = true;
					live[5][14] = true;
					live[6][2] = true;
					live[6][7] = true;
					live[6][9] = true;
					live[6][14] = true;
					live[10][2] = true;
					live[10][7] = true;
					live[10][9] = true;
					live[10][14] = true;
					live[11][2] = true;
					live[11][7] = true;
					live[11][9] = true;
					live[11][14] = true;
					live[12][2] = true;
					live[12][7] = true;
					live[12][9] = true;
					live[12][14] = true;
				}
				return;
			}
			if (m.x > 0 && m.x < 300 && m.y>600 && m.y < 800) {	//penta
				pass = false;
				pulse = true;
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						live[i][j] = 0;
					}
				}
				{
					live[2 + 3][3 + 5] = true;
					live[2 + 3][3 + 10] = true;
					live[3 + 3][3 + 3] = true;
					live[3 + 3][3 + 4] = true;
					live[3 + 3][3 + 6] = true;
					live[3 + 3][3 + 7] = true;
					live[3 + 3][3 + 8] = true;
					live[3 + 3][3 + 9] = true;
					live[3 + 3][3 + 11] = true;
					live[3 + 3][3 + 12] = true;
					live[4 + 3][3 + 5] = true;
					live[4 + 3][3 + 10] = true;
				}
				return;
			}
			if (m.x > 300 && m.x < 600 && m.y>400 && m.y < 600) {	//mwss
				pass = false;
				pulse = true;
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						live[i][j] = 0;
					}
				}
				{
					live[2][4] = true;
					live[2][6] = true;
					live[3][3] = true;
					live[4][3] = true;
					live[5][3] = true;
					live[6][3] = true;
					live[7][3] = true;
					live[7][4] = true;
					live[7][5] = true;
					live[6][6] = true;
					live[4][7] = true;
				}
				return;
			}
			if (m.x > 300 && m.x < 600 && m.y>600 && m.y < 800) {	//hwss
				pass = false;
				pulse = true;
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						live[i][j] = 0;
					}
				}
				{
					live[2][2] = true;
					live[2][4] = true;
					live[3][5] = true;
					live[4][1] = true;
					live[4][5] = true;
					live[5][1] = true;
					live[5][5] = true;
					live[6][5] = true;
					live[7][2] = true;
					live[7][5] = true;
					live[8][3] = true;
					live[8][4] = true;
					live[8][5] = true;
				}
				return;
			}
			if (m.x > 600 && m.x < 1400 && m.y>275 && m.y < 800) {	//simkin
				pass = false;
				pulse = true;
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						live[i][j] = 0;
					}
				}
				{
					live[5 + 1][5 + 1] = true;
					live[5 + 2][5 + 1] = true;
					live[5 + 1][5 + 2] = true;
					live[5 + 2][5 + 2] = true;
					live[5 + 8][5 + 1] = true;
					live[5 + 8][5 + 2] = true;
					live[5 + 9][5 + 1] = true;
					live[5 + 9][5 + 2] = true;
					live[5 + 5][5 + 4] = true;
					live[5 + 5][5 + 5] = true;
					live[5 + 6][5 + 4] = true;
					live[5 + 6][5 + 5] = true;
					live[5 + 22][5 + 11] = true;
					live[5 + 22][5 + 12] = true;
					live[5 + 22][5 + 13] = true;
					live[5 + 22][5 + 18] = true;
					live[5 + 21][5 + 18] = true;
					live[5 + 21][5 + 19] = true;
					live[5 + 22][5 + 20] = true;
					live[5 + 23][5 + 20] = true;
					live[5 + 24][5 + 20] = true;
					live[5 + 24][5 + 21] = true;
					live[5 + 23][5 + 10] = true;
					live[5 + 23][5 + 13] = true;
					live[5 + 24][5 + 13] = true;
					live[5 + 24][5 + 10] = true;
					live[5 + 26][5 + 10] = true;
					live[5 + 27][5 + 10] = true;
					live[5 + 28][5 + 11] = true;
					live[5 + 29][5 + 12] = true;
					live[5 + 28][5 + 13] = true;
					live[5 + 27][5 + 14] = true;
					live[5 + 32][5 + 12] = true;
					live[5 + 32][5 + 13] = true;
					live[5 + 33][5 + 12] = true;
					live[5 + 33][5 + 13] = true;
				}
				return;
			}
		}
	}
}