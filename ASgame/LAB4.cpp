#include<stdio.h>
#include<windows.h>
#include<conio.h>

void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship(int x, int y)
{
	setcolor(2, 4);
	gotoxy(x, y); printf("<-0->");
}

void erase_ship(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf("     ");
}

void draw_bullet(int x, int y)
{
	setcolor(5, 0);
	gotoxy(x, y); printf("|");
}

void erase_bullet(int x, int y)
{
	gotoxy(x, y);
	setcolor(0, 0);
	printf(" ");
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

int main()
{
	setcursor(0);
	int x = 38, y = 20, stateship = 0, i, state = 0, bullet = 0, shoot[5] = { 0 }, axisx[5] = { 0 }, axisy[5] = { 0 };
	char ch = '.';
	draw_ship(x, y);
	do {
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { stateship = 1; }
			if (ch == 'd') { stateship = 2; }
			if (ch == 's') { stateship = 0; }
			if (ch == ' ')
			{
				for (i = 0; i < 5; i++)
				{
					if (shoot[i] == 0)
					{
						shoot[i] = 1;
						axisx[i] = x + 2;
						axisy[i] = y - 1;
						break;
					}
				}
			}
			fflush(stdin);
		}
		if (stateship == 1 && x > 0)
		{
			erase_ship(x, y);
			draw_ship(--x, y);
		}
		if (stateship == 2 && x < 75)
		{
			erase_ship(x, y);
			draw_ship(++x, y);
		}
		if (stateship == 0 && x < 75)
		{
			erase_ship(x, y);
			draw_ship(x, y);
		}
		for (i = 0; i < 5; i++) {
			if (shoot[i] == 1 && axisy[i] > 0)
			{
				erase_bullet(axisx[i], axisy[i]); draw_bullet(axisx[i], --axisy[i]);
			}
			if (shoot[i] == 1 && axisy[i] == 0)
			{
				erase_bullet(axisx[i], axisy[i]);
				shoot[i] = 0;
			}
		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}