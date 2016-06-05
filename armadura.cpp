#include"armadura.h"
#include<string>

using std::string;

armadura::armadura(string atribute, double defense):atribute(atribute){
	if(defense>0.0&&defense<400.0){
		this->defense=defense;
	}else{
		this->defense=100.0;
	}
}

string armadura::getAtribute()const{
	return this->atribute;
}

void armadura::setAtribute(const string& nAtr){
	this->atribute=nAtr;
}

void armadura::setDefense(double& nDef){
	this->defense=nDef;
}

double armadura::getDefense()const{
	return this->defense;
}
virtual string armadura::toString()=0;

