#include <iostream>
#include <vector>
#include "windows.h"
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
	cout << "Press SPACE to run model." << endl;
	cout << "Press ARROW RIGHT to run model step by step." << endl;
	cout << "Press ESC to quit." << endl;
	bool done = false;

	while (!done)
	{

		switch ()
		{
		case VK_ESCAPE:
			done = true;
			break;
		case VK_SPACE:
			break;
		case VK_RIGHT:
			break;
		default:
			break;
		}
	}
	


	getchar();
	
	return;
	

}