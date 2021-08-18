#include<iostream>
#include<windows.h>
using namespace std;
void draw_ship(int x, int y) {
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	cout << "<-0->";
}
int main() {
	draw_ship(5, 10);
	return 0;
}