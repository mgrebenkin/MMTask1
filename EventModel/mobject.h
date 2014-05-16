#include <vector>

#pragma once


class mobject
{
private:
	int X;					//������� ��������
	int enttype;			//��� ������ � ����������
	std::vector<int> Q;		//�������
	int ents;				//���������� �������������� ������
	int den;				//���������� ����������� ������
	double ldtime;			//����� ������ ����������
	double fullt;			//������ ����� �������������
	double dnlprb;			//����������� ������
	double prcld;			//�������� ����������
public:
	mobject(): X(0), enttype(0), 
		ents(0), den(0), ldtime(0), dnlprb(0), prcld(0)
	{}
	~mobject();
	void setX(int inX){ if (inX >= 0 && inX <= 2) X = inX; }
	void setType(int type){ if (type >= 0 && type <= 2) enttype = type; }
	void Qadd(int type){ if (type == 1 || type == 2) Q.push_back(type); }
	int Qtake(){
		if (Q.size() != 0)
		{
			int buf = Q.front(); Q.erase(Q.begin()); return buf;
		}

		else return 0;
	}
	void NewEnt() { ents++; dnlprb = den / ents; }
	void EntDenied() { den++; dnlprb = den / ents; }
	void IncTime(double time){ fullt += time; prcld = prcld / fullt; }
	void MoreLoadTime(double time) { ldtime += time; prcld = prcld / fullt; }
	double getDenProbability() { return dnlprb; }
	double getLoadTime(){ return prcld; }
	int getType() { return enttype; }

};

