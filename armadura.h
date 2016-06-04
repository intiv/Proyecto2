#pragma once
#include<string>

using std::string;

class armadura{
 protected:
	double defense;
	string atribute;
 private:
	armadura();
	armadura(double,string);	
	string toString();
	
};
