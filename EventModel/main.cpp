#include "mobject.h"
#include "calender.h"
#include "events.h"
#include "console.h"
using namespace std;


//цкнаюкэмше оепелеммше
mobject o;
vector<calender> c;



//рекн опнцпюллш
void main()
{
	console con;
	con.printTitle();
	c.push_back(calender(0, _GEN1));
	c.push_back(calender(0, _GEN2));

	con.printStat();
	con.printCalender();

	char PressedKey = 0;

	while (PressedKey != VK_ESCAPE)
	{
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
			con.printCalender();
			con.printStat();
			break;
		default:
			break;
		}

	}
	
	return;
	

}