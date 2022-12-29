#include"head.h"

void menu()
{
	initgraph(1400, 800, 0);
	loadimage(NULL, L"PNG", MAKEINTRESOURCE(IDB_PNG2));
	ExMessage m;
	while (1) {
		getmessage(&m, -1);
		if (m.message == WM_KEYDOWN) {
			if (m.vkcode == VK_ESCAPE) {
				running = false;
				in_menu = false;
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
					in_menu = false;
					return;
				}
				if (m.y > 544 && m.y < 627) {	//presets
					preset();
					if (!in_menu) {
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
