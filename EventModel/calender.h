#pragma once

#include <iostream>
#include "conio.h"
#include <vector>
#include "Codes.h"
#include "windows.h"


using namespace std;


struct calender
{
public:
	calender(double inT, int inCode){ 
		if (inT >= 0) T = inT; else T = 0; 
		if (inCode >= _GEN1 && code <= _STAT) code = inCode; else code = _GEN1;
	}
	double T;	//�����
	int code;	//��� �������
	
};

void schedule(vector<calender>& c, double inT, int inCode);
void PrintCalender(vector<calender>& c);