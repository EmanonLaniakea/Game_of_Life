#include"head.h"

void fillcell()
{
	int i, j;
	Sleep(sleeptime);	//控制每代刷新间隔
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			if (last_live[i][j] != live[i][j]) {
				if (live[i][j]) {
					fillrectangle(i * CELL, j * CELL, (i + 1) * CELL, (j + 1) * CELL);
				}
				else {
					clearrectangle(i * CELL + 1, j * CELL + 1, (i + 1) * CELL - 1, (j + 1) * CELL - 1);
				}
			}
		}
	}
}

void map()
{
	int i;
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