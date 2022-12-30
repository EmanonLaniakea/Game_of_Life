#include"head.h"

void menu()
{
	initgraph(1400, 800, 0);
	loadimage(NULL, L"PNG", MAKEINTRESOURCE(IDB_PNG3));
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
			if (m.x > 1025 && m.x < 1375) {
				if (m.y > 400 && m.y < 500) {	//playground
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
				if (m.y > 510 && m.y < 610) {	//presets
					preset();
					for (int i = 0; i < SIZE; i++) {
						for (int j = 0; j < SIZE; j++) {
							last_live[i][j] = 0;
						}
					}
					if (!in_menu) {
						map();
					}
					return;
				}
				if (m.y > 620 && m.y < 720) {	//options
					closegraph();
					initgraph(1400, 800, 0);
					loadimage(NULL, L"PNG", MAKEINTRESOURCE(IDB_PNG4));
					while (1) {
						getmessage(&m, -1);
						if (m.lbutton && m.x > 1326 && m.x < 1400 && m.y>245 && m.y < 560) {
							loadimage(NULL, L"PNG", MAKEINTRESOURCE(IDB_PNG5));
						}
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