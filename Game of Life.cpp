#include"head.h"

bool live[SIZE][SIZE] = { 0 };	//每个cell的存活状态
bool temp[SIZE][SIZE] = { 0 };
bool last_live[SIZE][SIZE] = { 0 };
bool running = true;
bool pulse = true;
bool in_menu = true;	//是否进入开始页面
int rx[3] = { -1,0,1 };	//用于遍历周围九宫格
int ry[3] = { -1,0,1 };
int sleeptime = 10;

int main() {
	while (running || in_menu) {
		while (in_menu) {
			menu();
		}
		if (running) {
			fillcell();
			control();
			Update();
		}
	}
	return 0;
}