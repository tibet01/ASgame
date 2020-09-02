#include<stdio.h>
#include<windows.h>
#include<conio.h>

void erase_ship(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("       ");
}

void draw_ship(int x,int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("<-o->");
}

int main()
{
	char ch = ' ';
	int x = 38, y = 20;
	draw_ship(x, y);
	do
	{
		if (_kbhit())
		{
			ch = _getch();
			if (ch == 'a' && x!=0) { erase_ship(x, y); draw_ship(--x, y); }
			if (ch == 'd' && x != 75) { erase_ship(x, y); draw_ship(++x, y); }
			if (ch == 'w') { erase_ship(x, y); draw_ship(x, --y); }
			if (ch == 's') { erase_ship(x, y); draw_ship(x, ++y); }

			fflush(stdin);
		}
		Sleep(500);
	} while (ch != 'x');
	printf("%d", x);
	return 0;
}