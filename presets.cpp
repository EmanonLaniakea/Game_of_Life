#include"head.h"

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
				in_menu = false;
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
				in_menu = false;
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
				in_menu = false;
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
			if (m.x > 300 && m.x < 600 && m.y>150 && m.y < 280) {	// lwss
				in_menu = false;
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
					live[4][5] = true;
					live[5][5] = true;
					live[5][2] = true;
					live[6][3] = true;
					live[6][4] = true;
					live[6][5] = true;
				}

				return;
			}
			if (m.x > 300 && m.x < 600 && m.y>400 && m.y < 600) {	//mwss
				in_menu = false;
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
			if (m.x > 300 && m.x < 600 && m.y>600 && m.y < 800) {	//lwss & mwss & hwss
				in_menu = false;
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
					live[4][5] = true;
					live[5][5] = true;
					live[5][2] = true;
					live[6][3] = true;
					live[6][4] = true;
					live[6][5] = true;
				}
				{
					live[2][4 + 8] = true;
					live[2][6 + 8] = true;
					live[3][3 + 8] = true;
					live[4][3 + 8] = true;
					live[5][3 + 8] = true;
					live[6][3 + 8] = true;
					live[7][3 + 8] = true;
					live[7][4 + 8] = true;
					live[7][5 + 8] = true;
					live[6][6 + 8] = true;
					live[4][7 + 8] = true;
				}
				{
					live[2][2 + 20] = true;
					live[2][4 + 20] = true;
					live[3][5 + 20] = true;
					live[4][1 + 20] = true;
					live[4][5 + 20] = true;
					live[5][1 + 20] = true;
					live[5][5 + 20] = true;
					live[6][5 + 20] = true;
					live[7][2 + 20] = true;
					live[7][5 + 20] = true;
					live[8][3 + 20] = true;
					live[8][4 + 20] = true;
					live[8][5 + 20] = true;
				}
				return;
			}
			if (m.x > 600 && m.x < 1400 && m.y>275 && m.y < 800) {	//simkin
				in_menu = false;
				pulse = true;
				for (int i = 0; i < SIZE; i++) {
					for (int j = 0; j < SIZE; j++) {
						live[i][j] = 0;
					}
				}
				{
					live[20 + 1][20 + 1] = true;
					live[20 + 2][20 + 1] = true;
					live[20 + 1][20 + 2] = true;
					live[20 + 2][20 + 2] = true;
					live[20 + 8][20 + 1] = true;
					live[20 + 8][20 + 2] = true;
					live[20 + 9][20 + 1] = true;
					live[20 + 9][20 + 2] = true;
					live[20 + 5][20 + 4] = true;
					live[20 + 5][20 + 5] = true;
					live[20 + 6][20 + 4] = true;
					live[20 + 6][20 + 5] = true;
					live[20 + 22][20 + 11] = true;
					live[20 + 22][20 + 12] = true;
					live[20 + 22][20 + 13] = true;
					live[20 + 22][20 + 18] = true;
					live[20 + 21][20 + 18] = true;
					live[20 + 21][20 + 19] = true;
					live[20 + 22][20 + 20] = true;
					live[20 + 23][20 + 20] = true;
					live[20 + 24][20 + 20] = true;
					live[20 + 24][20 + 21] = true;
					live[20 + 23][20 + 10] = true;
					live[20 + 23][20 + 13] = true;
					live[20 + 24][20 + 13] = true;
					live[20 + 24][20 + 10] = true;
					live[20 + 26][20 + 10] = true;
					live[20 + 27][20 + 10] = true;
					live[20 + 28][20 + 11] = true;
					live[20 + 29][20 + 12] = true;
					live[20 + 28][20 + 13] = true;
					live[20 + 27][20 + 14] = true;
					live[20 + 32][20 + 12] = true;
					live[20 + 32][20 + 13] = true;
					live[20 + 33][20 + 12] = true;
					live[20 + 33][20 + 13] = true;
				}
				return;
			}
		}
	}
}