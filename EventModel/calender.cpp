#include "calender.h"


void schedule(vector<calender>& c, double inT, int inCode)
{
	vector<calender>::iterator it = c.end(); //просмотр вектора с конца, чтобы найти элемент
	it--;
	while (it->T > inT && it != c.begin())	 //меньший по времени и поставить новый перед ним
	{
		it--;
	}
	c.insert(it + 1, calender(inT, inCode));


}

void PrintCalender(vector<calender>& c)
{
	COORD pos;
	pos.X = 0; pos.Y = 4;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout.precision(1);
	if (c.size() == 0) cout << "Calender is empty." << endl;
	else
	{
		cout << "Calender: " << endl;
		for (size_t i = 0; i < c.size(); i++)
			cout << c[i].T << "   " << c[i].code << endl;
	}

}