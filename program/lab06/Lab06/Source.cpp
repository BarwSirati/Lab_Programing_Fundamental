#include<iostream>
#include<vector>
#include<windows.h>
#include<conio.h>
using namespace std;

//Input Variable
char ch = ' ';
//Set Bullets
int bulletsNow = 0;

//Settings
struct SHIP
{
	enum STATUS { LEFT, RIGHT, STOP };
	STATUS status = STOP;
	int x = 38;
	int y = 20;
	string draw = "<-0->";
}ship;
struct BULLETS
{
	enum SHOOT { OPEN, CLOSE };
	SHOOT status = CLOSE;
	int x = ship.x + 2;
	int y = ship.y - 1;
	string draw = "^";
}bullets[5];

//Function
void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}
void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}
void gotoxy(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void erase_ship(int x, int y) {
	setcolor(2, 0);
	gotoxy(x, y);
	cout << "     ";
}
void draw_ship(int x, int y)
{
	setcolor(2, 4);
	gotoxy(x, y);
	cout << ship.draw;
}
void erase_shoot(int x, int y)
{
	setcolor(2, 0);
	gotoxy(x, y);
	cout << " ";
}
void shoot(int x, int y)
{
	setcolor(2, 0);
	gotoxy(x, y);
	cout << bullets->draw;
}
void movement(char ch) 
{
	switch (ch)
	{
	case 97:
		ship.status = ship.LEFT;
		break;
	case 100:
		ship.status = ship.RIGHT;
		break;
	case 115:
		ship.status = ship.STOP;
		break;
	case 32:
		if (bullets[bulletsNow].status == bullets[bulletsNow].CLOSE)
		{
			bullets[bulletsNow].x = ship.x + 2;
			bullets[bulletsNow].y = ship.y - 1;
			bullets[bulletsNow].status = bullets[bulletsNow].OPEN;
			bulletsNow++;
		}
		break;
	default:
		break;
	}
}
void autoLeft() 
{
	erase_ship(ship.x, ship.y);
	draw_ship(--ship.x, ship.y);
}
void autoRight()
{
	erase_ship(ship.x, ship.y);
	draw_ship(++ship.x, ship.y);
}
void shootCheck(int count) 
{
	if (bullets[count].status == bullets[count].OPEN)
	{
		erase_shoot(bullets[count].x, bullets[count].y);
		if (bullets[count].y > 0)
		{
			shoot(bullets[count].x, --bullets[count].y);
		}
		else
		{
			bullets[count].status = bullets[count].CLOSE;
		}
	}
}

int main() {
	setcursor(0);
	draw_ship(ship.x, ship.y);
	do {
		bulletsNow %= 5;
		if (_kbhit())
		{
			ch = _getch();
			movement(ch);
			fflush(stdin);
		}
		if (ship.status == ship.LEFT && ship.x > 0) autoLeft();
		if (ship.status == ship.RIGHT && ship.x < 81) autoRight();
		for (int i = 0; i < 5; i++) shootCheck(i);
		Sleep(60);
	} while (ch != 'x');
	return 0;
}