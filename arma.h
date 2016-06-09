#pragma once
#include<string>

using std::string;

class arma{
 protected:
	double damage;
	string atribute;
	int durability, currDur;
 public:
	arma(string,double=100.0);
	double getDamage()const;
	void setDamage(double&);
	string getAtribute()const;
	void setAtribute(string&);
	int getDurability()const;
	void setDurability();
	void setCurrDur(int&);
	int getCurrDur()const;
	virtual string toString()const;
};
