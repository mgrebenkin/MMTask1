
#pragma once

#include <vector>
#include <random>
class mobject
{
private:
	std::random_device eng;
	std::uniform_real_distribution<double> dist1;
	std::uniform_real_distribution<double> dist2;
	
	std::vector<int> Q;		//очередь
	
public:

	mobject() : X(0), enttype(0),
		ents(0), den(0), ldtime(0),
		eng(), dist1(-7.0, 7.0), dist2(-5.0, 5.0)
	{}
	~mobject(){};

	int X;					//входная величина
	int enttype;			//тип заявки в процессоре
	int ld1;
	int ld2;

	int Q1;
	int Q2;
	double ents;			//количество сгенерированых заявок
	double den;				//количество отклоненных заявок
	double ldtime;			//время работы процессора
	double fullt;			//полное время моделирования
	double ldtime1;
	double ldtime2;

	double denprb = 0;
	double ldproc = 0;
	double ldproc1 = 0;
	double ldproc2 = 0;

	void Qadd(int type){ if (type == 1 || type == 2) Q.push_back(type); }
	
	int Qsize() { return Q.size(); }
	int Qtake(){
		if (Q.size() != 0)
		{
			int buf = Q.front(); Q.erase(Q.begin()); return buf;
		}
		else return 0;
	}

	

	double getRnd1() { dist1.reset(); return dist1(eng); }
	double getRnd2() { dist2.reset(); return dist2(eng); }

};

