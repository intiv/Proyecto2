#include "arma.h"
#include<string>

using std::string;

arma::arma(string atribute,double damage):atribute(atribute){
	if(damage>0&&damage<500){
		this->damage=damage;
	}else{
		this->damage=100.0;
	}
}

double arma::getDamage()const{ 
	return this->damage;
}

string getAtribute()const{ 
	return this->atribute;
}

int getDurability()const{
	return this->durability;
}

void setDamage(double& nDmg){
	if(nDmg>0&&nDmg<500){
		this->damage=nDmg;
	}
}

void setAtribute(string& nAtr){
	this->atribute=nAtr;
}


virtual string arma::toString()=0;

