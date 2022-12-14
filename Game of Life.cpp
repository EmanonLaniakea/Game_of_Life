#include<stdio.h>
#include<conio.h>
#include<Windows.h>
#include<graphics.h>

#define CELL 10	//单个细胞大小，像素
#define SIZE 40 //画布大小,每行列细胞数

bool live[SIZE][SIZE] = { 0 };	//每个cell的存活状态
bool temp[SIZE][SIZE] = { 0 };
bool running = true;
bool pulse = false;
int  mode = 1;	//1-连续繁衍，enter；2-代际繁衍，space
int rx[3] = { -1,0,1 };	//用于遍历周围九宫格
int ry[3] = { -1,0,1 };

bool update(int x, int y);	//更新每个cell
void control();
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

	while (running) {
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
		control();
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

void control()
{
	ExMessage m;
	peekmessage(&m, -1, true);
	if (m.vkcode == VK_ESCAPE) {
		running = false;
	}
	if (m.vkcode == VK_SPACE || m.rbutton) {
		pulse = true;
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