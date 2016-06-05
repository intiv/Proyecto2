#pragma once
#include<string>

using std::string;

class arma{
 protected:
	double damage;
	string atribute;
	int durability;
	bool frozen, burned;
 public:
	arma(string,double=100.0);
	double getDamage()const;
	void setDamage(double&);
	string getAtribute()const;
	void setAtribute(string&);
	int getDurability()const;
	void setDurability();
	virtual string toString()const=0;
	bool isFrozen()const;
	void setFrozen(bool);
};
