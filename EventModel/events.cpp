#include "events.h"

extern mobject o;
extern vector<calender> c;

void gen1()
{
	o.X = 1;
	o.ents++;
	o.Qadd(1);

	if (o.enttype == 0) schedule(c, o.fullt, _PROC);
	
	schedule(c, o.fullt + 15 + o.getRnd1(), _GEN1);
}

void gen2()
{
	o.X = 2;
	o.ents++;
	o.Qadd(2);

	if (o.fullt == 0) schedule(c, o.fullt, _PROC);
	
	schedule(c, o.fullt + 15 + o.getRnd1(), _GEN2);
}

void proc()
{
	int buf = o.Qtake();
	if (buf == 0) o.enttype = 0;
	else
	{
		o.enttype = buf;
		schedule(c, o.fullt + 7, _PROC);

		o.ldtime += 7;

		if (buf == 1) schedule(c, o.fullt + 7, _OUTBUF1);
		else if (buf == 2) schedule(c, o.fullt + 7, _OUTBUF2);
		
	}
}

void out1buf()
{
	if (o.Q1 >= 3) o.den++;
	else
	{
		o.Q1++;
		if (o.ld1 == 0) schedule(c, o.fullt, _OUT1PROC);
	}

	
}

void out2buf()
{
	if (o.Q2 >= 3) o.den++;
	else
	{
		o.Q2++;
		if (o.ld2 == 0) schedule(c, o.fullt, _OUT2PROC);
	}
}

void out1proc()
{
	if (o.Q1 == 0) o.ld1 = 0;
	else
	{
		o.ld1 = 1;
		double tproc = 15 + o.getRnd2();
		schedule(c, o.fullt + tproc, _OUT1PROC);
		
		o.ldtime1 += tproc;
	}
}

void out2proc()
{
	if (o.Q2 == 0) o.ld2 = 0;
	else
	{
		o.ld2 = 1;
		double tproc = 15 + o.getRnd2();
		schedule(c, o.fullt + tproc, _OUT2PROC);

		o.ldtime2 += tproc;
	}

}

void stat()
{
	o.denprb = (double)o.den / (double)o.ents;
	o.ldproc = o.ldtime / o.fullt;
	o.ldproc1 = o.ldtime1 / o.fullt;
	o.ldproc2 = o.ldtime2 / o.fullt;
}