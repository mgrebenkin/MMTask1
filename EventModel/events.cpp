#include "events.h"

extern mobject o;
extern vector<calender> c;

void gen1()
{
	o.NewEnt();
	o.setX(1);
	if (o.getType() == 0)
	{
		o.setType(1);
		Schedule(c, o.getTime(), _PROCSTART);
	}
	else
	{
		o.Qadd(1);
	}
	Schedule(c, o.getTime() + 15 + o.getRnd1(), _GEN1);
}
void gen2()
{
	o.NewEnt();
	o.setX(2);
	if (o.getType() == 0)
	{
		o.setType(2);
		Schedule(c, o.getTime(), _PROCSTART);
	}
	else
	{
		o.Qadd(2);
	}
	Schedule(c, o.getTime() + 15 + o.getRnd1(), _GEN2);
}
void procstart()
{
	Schedule(c, o.getTime() + 7.0, _PROCEND);
}
void procend()
{
	o.MoreLoadTime();
	if (o.getType() == 1) Schedule(c, o.getTime(), _OUT1);
	else if (o.getType() == 2) Schedule(c, o.getTime(), _OUT2);

	int buf = o.Qtake();
	if (buf == 1)
	{
		Schedule(c, o.getTime(), _PROCSTART);
		o.setType(1);
	}
	else if (buf == 2)
	{
		Schedule(c, o.getTime(), _PROCSTART);
		o.setType(2);
	}
	else
	{
		o.setType(0);
	}
}

void out1()
{
	if (!o.isProc1())
		Schedule(c, o.getTime(), _OUT1START);
	else
	o.Q1add();
}
void out1start()
{
	double buf = o.getRnd2();
	Schedule(c, o.getTime() + 15 + buf, _OUT1END);
	o.MoreLoadTime1(15 + buf);
	o.proc1(1);
}
void out1end()
{
	int buf = o.Q1take();
	if (buf)
		Schedule(c, o.getTime(), _OUT1START);
	else
		o.proc1(0);
}

void out2()
{
	if (!o.isProc2())
		Schedule(c, o.getTime(), _OUT2START);
	else
		o.Q2add();
}
void out2start()
{
	double buf = o.getRnd2();
	Schedule(c, o.getTime() + 15 + buf, _OUT2END);
	o.MoreLoadTime2(15 + buf);
	o.proc2(1);
}
void out2end()
{
	int buf = o.Q2take();
	if (buf)
		Schedule(c, o.getTime(), _OUT2START);
	else
		o.proc2(0);
}