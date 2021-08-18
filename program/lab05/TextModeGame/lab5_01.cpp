#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
char ch = ' ';
int x = 32, y = 20;
string ship = " <-0-> ";
void draw_ship(int x, int y);

void gotoxy(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void erase_ship(int x,int y) {
	gotoxy(x, y);
	cout << "       ";
}

void draw_ship(int x,int y) {
	gotoxy(x,y);
	cout << ship;
}

int main() {
	draw_ship(x,y);
	do {
		if (_kbhit())
		{
			ch = _getch();
			if (ch=='a' && x>0)
				draw_ship(--x, y);
			if (ch=='d' && x <= 80)
				draw_ship(++x, y);
			if (ch == 'w')
			{
				erase_ship(x, y);
				draw_ship(x, --y);
			}
			if (ch == 's') 
			{
				erase_ship(x, y);
				draw_ship(x, ++y);
			}
			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}