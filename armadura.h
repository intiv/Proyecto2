#pragma once
#include<string>

using std::string;

class armadura{
 protected:
	double defense;
	string atribute;
	int durability, currDur;
 public:
	armadura(string,double=100.0);
	string getAtribute()const;
	void setAtribute(const string&);
	void setDefense(double);
	double getDefense()const;	
	int getDur()const;
	int getCurrDur()const;
	void setCurrDur(int);
	void setDur(int);
	virtual string toString()const=0;
};
