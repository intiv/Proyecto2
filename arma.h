#pragma once
#include<string>

using std::string;

class arma{
 protected:
	double damage;
	string atribute;
 private:
	arma();
	arma(string,double=100.0);
	double getDamage();
	string getAtribute();
	string toString();

};
