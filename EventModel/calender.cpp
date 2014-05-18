#include "calender.h"


void Schedule(vector<calender>& c, double inT, int inCode)
{
	vector<calender>::iterator it = c.end(); //�������� ������� � �����, ����� ����� �������
	it--;
	while (it->T > inT && it != c.begin())	 //������� �� ������� � ��������� ����� ����� ���
	{
		it--;
	}
	c.insert(it + 1, calender(inT, inCode));
}