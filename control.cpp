#include"head.h"

void control()
{
	ExMessage m;
	peekmessage(&m, -1, true);
	if (m.message == WM_KEYDOWN || m.message == WM_RBUTTONDOWN) {
		if (m.vkcode == VK_ESCAPE) {
			in_menu = true;
			return;
		}
		if (m.vkcode == VK_SPACE || m.rbutton) {
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
