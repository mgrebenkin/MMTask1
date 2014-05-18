#include <iostream>
#include <vector>
#include "mobject.h"
#include "calender.h"
#include "events.h"

using namespace std;


//цкнаюкэмше оепелеммше
mobject o;
vector<calender> c;
//рекн опнцпюллш
void main()
{
	
	c.push_back(calender(0, _GEN1));
	c.push_back(calender(0, _GEN2));


	double endtime = 10000;
	int i = 0;
	
	while (c[i].T < endtime)
	{
		o.setTime(c[i].T);

		switch (c[i].code)
		{
		case _GEN1:
			gen1();
			break;
		case _GEN2:
			gen2();
			break;
		case _PROCSTART:
			procstart();
			break;
		case _PROCEND:
			procend();
			break;
		case _OUT1:
			out1();
			break;
		case _OUT1START:
			out1start();
			break;
		case _OUT1END:
			out1end();
			break;
		case _OUT2:
			out2();
			break;
		case _OUT2START:
			out2start();
			break;
		case _OUT2END:
			out2end();
			break;
		default:
			break;
		}

		i++;
	}

	cout << "Denial probability: " << o.getDenProbability() << endl;
	cout << "Loads: " << o.getProcLd() << " | " << o.getLd1() << " | " <<
		o.getLd2() << endl;
	getchar();

}