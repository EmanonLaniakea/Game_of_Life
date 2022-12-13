#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<graphics.h>

#define CELL 10	//单个细胞大小，像素
#define SIZE 40 //画布大小,每行列细胞数

bool live[SIZE][SIZE] = { 0 };	//每个cell的存活状态
bool temp[SIZE][SIZE] = { 0 };
int rx[3] = { -1,0,1 };	//用于遍历周围九宫格
int ry[3] = { -1,0,1 };

bool update(int x, int y);	//更新每个cell
int main() {
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
	live[10][10] = true;
	live[11][10] = true;
	live[11][9] = true;
	live[11][11] = true;
	live[12][10] = true;
	while (1) {
		Sleep(10);	//控制每代刷新间隔
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
	return 0;
}

bool update(int x, int y)
{
	int sum = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			int xt = x + rx[i], yt = y + ry[j];
			if (live[xt][yt])  sum += 1;
		}
	if (live[x][y])
	{
		if (sum < 3 || sum>4) return false;
		else return true;
	}
	else
	{
		if (sum == 3 || sum == 4) return true;
		else return false;
	}
}