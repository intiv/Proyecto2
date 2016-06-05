#pragma once
#include<string>

using std::string;

class armadura{
 protected:
	double defense;
	string atribute;
 public:
	armadura(string, double=100.0);
	string getAtribute()const;
	void setAtribute(const string&);
	void setDefense(double&);
	double getDefense()const;	
	virtual string toString()=0;
	
};
