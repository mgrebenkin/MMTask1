
#pragma once

#include <vector>
#include <random>
class mobject
{
private:
	std::random_device eng;
	std::uniform_real_distribution<double> dist1;
	std::uniform_real_distribution<double> dist2;
	int X;					//входная величина
	int enttype;			//тип заявки в процессоре
	int ld1;
	int ld2;
	std::vector<int> Q;		//очередь
	std::vector<int> Q1;
	std::vector<int> Q2;
	double ents;			//количество сгенерированых заявок
	double den;				//количество отклоненных заявок
	double ldtime;			//время работы процессора
	double fullt;			//полное время моделирования
	double dnlprb;			//вероятность отказа
	double prcld;			//загрузка процессора
	double ldtime1;
	double ldtime2;
	double out1ld;
	double out2ld;

	
public:

	mobject() : X(0), enttype(0),
		ents(0), den(0), ldtime(0), dnlprb(0), prcld(0),
		eng(), dist1(-7.0, 7.0), dist2(-5.0, 5.0)
	{}
	~mobject();
	int ent1;
	int ent2;
	void setX(int inX){ if (inX >= 0 && inX <= 2) X = inX; }
	void setType(int type){ if (type >= 0 && type <= 2) enttype = type; }
	void proc1(int onoff) { ld1 = onoff; }
	void proc2(int onoff) { ld2 = onoff; }
	int isProc1() { return ld1; }
	int isProc2() { return ld2; }
	void Qadd(int type){ if (type == 1 || type == 2) Q.push_back(type); }
	int Qtake(){
		if (Q.size() != 0)
		{
			int buf = Q.front(); Q.erase(Q.begin()); return buf;
		}
		else return 0;
	}
	void Q1add(){ if (Q1.size() <= 2) Q1.push_back(1);
			else
				EntDenied();
	}
	void Q2add(){
		if (Q2.size() <= 2) Q2.push_back(2);
		else
			EntDenied();
	}
	int Q1take(){
		if (Q1.size() != 0)
		{
			int buf = Q1.front(); Q1.erase(Q1.begin()); return buf;
		}
		else return 0;
	}
	int Q2take(){
		if (Q2.size() != 0)
		{
			int buf = Q2.front(); Q2.erase(Q2.begin()); return buf;
		}
		else return 0;
	}
	void NewEnt() { ents++; dnlprb = den / ents; }
	void EntDenied() { den++; dnlprb = den / ents; }
	void setTime(double time){ fullt = time; prcld = ldtime / fullt; 
	out1ld = ldtime1 / fullt; out2ld = ldtime2 / fullt;
	}
	double getTime(){ return fullt; }
	void MoreLoadTime() { ldtime += 7.0; prcld = ldtime / fullt; }
	void MoreLoadTime1(double time) { ldtime1 += time; out1ld = ldtime1 / fullt; }
	void MoreLoadTime2(double time) { ldtime2 += time; out2ld = ldtime2 / fullt; }
	double getDenProbability() { return dnlprb; }
	double getLoadTime(){ return prcld; }
	int getType() { return enttype; }
	double getRnd1() { dist1.reset(); return dist1(eng); }
	double getRnd2() { dist2.reset(); return dist2(eng); }
	double getDnPob() { return dnlprb; }
	double getProcLd() { return prcld; }
	double getLd1() { return out1ld; }
	double getLd2() { return out2ld; }

};

