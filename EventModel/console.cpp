#include "console.h"

void console::printTitle()
{
	cout << "Press SPACE to run model." << endl;
	cout << "Press ESC to quit." << endl;
	
}

void console::clearRow(int row)
{
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

void console::printStat()
{
	cout << fixed;
	cout.precision(0);
	cursPos.X = 0; cursPos.Y = 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursPos);
	clearRow(3); clearRow(4); clearRow(5);
	cout << "Denial probability: " << o.denprb * 100 << "%" << endl;
	cout << "Load of main processor: " << o.ldproc * 100 << "%" << endl;
	cout << "Load of output channels: " << o.ldproc1 * 100 << "% and " << o.ldproc2 * 100 << "%" << endl;


}

void console::printCalender()
{
	cout.precision(2);
	cout.width(30);
	cursPos.X = 0; cursPos.Y = 6;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursPos);
	cout << left << "Calender:" << endl;
	for (int i = 0; i < _PROCAMOUNT; i++) clearRow(8 + i);
	cursPos.X = 0; cursPos.Y = 8;
	int cnt = 0;
	for (vector<calender>::iterator it = c.begin(); it != c.end(); it++)
	{
		cnt++;
		cout << cnt << ". ";
		cout.width(25);
		switch (it->code)
		{
		case _GEN1:
			cout << "Entity 1 generated:";
			break;
		case _GEN2:
			cout << "Entity 2 generated:";
			break;
		case _PROC:
			cout << "Processing begins:";
			break;
		case _OUTBUF1:
			cout << "Entity 1 -> output:";
			break;
		case _OUTBUF2:
			cout << "Entity 2 -> output:";
			break;
		case _OUT1PROC:
			cout << "Processing in output 1:";
			break;
		case _OUT2PROC:
			cout << "Processing in output 2:";
			break;
		default:
			break;
		}
		
		cout << it->T << "ms" << endl;
    }
}