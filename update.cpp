#include"head.h"

void Update()
{
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			last_live[i][j] = live[i][j];
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