#include <iostream>
#include <vector>
#include "windows.h"
#include "conio.h"
#include "mobject.h"
#include "calender.h"
#include "events.h"

using namespace std;


//ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
mobject o;
vector<calender> c;

void clearRow(int row)
{
	// получаем хэндл окна консоли
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// получаем координаты строки для очистки
	COORD coord = { 0, row - 1 };

	// получаем данные из буфера вывода консоли
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);

	// заполняем строку пробелами
	FillConsoleOutputCharacter(hStdOut, ' ', 80, coord, NULL);
	// сбрасываем позицию курсора
	SetConsoleCursorPosition(hStdOut, csbi.dwCursorPosition);
}

//ТЕЛО ПРОГРАММЫ
void main()
{
	cout << "Press SPACE to run model." << endl;
	cout << "Press ESC to quit." << endl;
	cout << fixed;
	cout.precision(0);
	c.push_back(calender(0, _GEN1));
	c.push_back(calender(0, _GEN2));

	char PressedKey = 0;
	COORD pos;


	while (PressedKey != VK_ESCAPE)
	{
		pos.X = 0; pos.Y = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

 		PressedKey = _getch();
		switch (PressedKey)
		{
		case VK_SPACE :
			o.fullt = c[0].T;
			switch (c[0].code)
			{
			case _GEN1:
				gen1();
				break;
			case _GEN2:
				gen2();
				break;
			case _PROC:
				proc();
				break;
			case _OUTBUF1:
				out1buf();
				break;
			case _OUTBUF2:
				out2buf();
				break;
			case _OUT1PROC:
				out1proc();
				break;
			case _OUT2PROC:
				out2proc();
				break;
			}
			c.erase(c.begin());
			stat();
			clearRow(3); clearRow(4); clearRow(5);
			cout << "Denial probability: " << o.ldproc*100 << "%"  << endl;
			cout << "Load of main processor: " << o.ldproc*100 << "%" << endl;
			cout << "Load of output channels: " << o.ldproc1*100 << "% and " << o.ldproc2*100 << "%" << endl;

			break;
		case VK_TAB:
			PrintCalender(c);
			break;
		default:
			break;
		}

	}
	
	return;
	

}