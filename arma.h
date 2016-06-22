#pragma once
#include<string>

using std::string;

class arma{
 protected:
	double damage;
	string atribute;
	int durability, currDur, upgrades;
 public:
	arma(string,double=100.0);
	virtual ~arma();
	double getDamage()const;
	void setDamage(double);
	string getAtribute()const;
	void setAtribute(string);
	int getDurability()const;
	void setDurability(int);
	void setCurrDur(int);
	int getCurrDur()const;
	void upgrade();
	int getUpgrades()const;
	void setUpgrades(const int&);
	virtual string toString()const=0;
};
