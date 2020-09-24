#include<stdio.h>
#include<windows.h>
#include<conio.h>

void erase_ship(int x, int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("     ");
}

void draw_ship(int x,int y)
{
	COORD c = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
	printf("<-o->");
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO IpCursor;
	IpCursor.bVisible = visible;
	IpCursor.dwSize = 20;
	SetConsoleCursorInfo(console,&IpCursor);
}

void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

int main()
{
	setcursor(0);
	setcolor(2, 4);
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
			if (ch == 'w' && y!=0) { erase_ship(x, y); draw_ship(x, --y); }
			if (ch == 's') { erase_ship(x, y); draw_ship(x, ++y); }

			fflush(stdin);
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}