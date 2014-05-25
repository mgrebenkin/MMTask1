#pragma once

#include <iostream>
#include <vector>
#include "windows.h"
#include "mobject.h"
#include "calender.h"

extern mobject o;
extern vector<calender> c;
using namespace std;

class console
{
private:
	HANDLE hStdOut;
	COORD cursPos;
public:
	console(){ hStdOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	    cursPos.X = 0; cursPos.Y = 0;
	    }
	~console(){}

	void printTitle();

	void clearRow(int row);

	void printStat();

	void printCalender();

};
