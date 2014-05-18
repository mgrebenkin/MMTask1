#include "calender.h"


void Schedule(vector<calender>& c, double inT, int inCode)
{
	vector<calender>::iterator it = c.end(); //просмотр вектора с конца, чтобы найти элемент
	it--;
	while (it->T > inT && it != c.begin())	 //меньший по времени и поставить новый перед ним
	{
		it--;
	}
	c.insert(it + 1, calender(inT, inCode));
}