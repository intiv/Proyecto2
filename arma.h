#pragma once
#include<string>

using std::string;

class arma{
 protected:
	double damage;
	string atribute;
 public:
	arma(string,double=100.0);
	double getDamage();
	string getAtribute();
	virtual string toString()=0;

};
