#include "events.h"

extern mobject o;
extern vector<calender> c;

void gen1()
{
	o.X = 1;
	o.ents++;
	if (o.enttype == 0 && o.Qsize() == 0) schedule(c, o.fullt, _PROC);
	o.Qadd(1);

	
	
	schedule(c, o.fullt + 15 + o.getRnd1(), _GEN1);
}

void gen2()
{
	o.X = 2;
	o.ents++;
	if (o.enttype == 0 && o.Qsize() == 0) schedule(c, o.fullt, _PROC);
	o.Qadd(2);

	
	
	schedule(c, o.fullt + 15 + o.getRnd1(), _GEN2);
}

void proc()
{
	if (o.enttype != 0) o.ldtime += 7;
	int buf = o.Qtake();
	if (buf == 0) o.enttype = 0;
	else
	{

		o.enttype = buf;

		if (buf == 1) schedule(c, o.fullt + 7, _OUTBUF1);
		else if (buf == 2) schedule(c, o.fullt + 7, _OUTBUF2);

	
		schedule(c, o.fullt + 7, _PROC);
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
	if (o.ld1 == 1) o.ldtime1 += o.tproc1;
	if (o.Q1 == 0) o.ld1 = 0;
	else
	{
		o.ld1 = 1;
		o.tproc1 = 15 + o.getRnd2();
		schedule(c, o.fullt + o.tproc1, _OUT1PROC);

	}
}

void out2proc()
{
	if (o.ld2 == 1) o.ldtime2 += o.tproc2;
	if (o.Q2 == 0) o.ld2 = 0;
	else
	{
		o.ld2 = 1;
		o.tproc2 = 15 + o.getRnd2();
		schedule(c, o.fullt + o.tproc2, _OUT2PROC);
	}

}

void stat()
{
	if (o.ents == 0) o.denprb = 0;
	else o.denprb = (double)o.den / (double)o.ents;

	if (o.fullt == 0)
	{
		o.ldproc = 0; o.ldproc1 = 0; o.ldproc2 = 0;
	}
	else
	{
		o.ldproc = o.ldtime / o.fullt;
		o.ldproc1 = o.ldtime1 / o.fullt;
		o.ldproc2 = o.ldtime2 / o.fullt;
	}
}