#pragma once
#include<string>

using std::string;

class armadura{
 protected:
	double defense;
	string atribute;
	double durability, currDur,upgrades;
 public:
	armadura(string,double=100.0);
	string getAtribute()const;
	virtual ~armadura();
	void setAtribute(const string&);
	void setDefense(double);
	double getDefense()const;	
	int getDur()const;
	int getCurrDur()const;
	int getUpgrades()const;
	void setCurrDur(int);
	void setDur(int);
	void setUpgrades(const int&);
	void upgrade();
	virtual string toString()const=0;
};
