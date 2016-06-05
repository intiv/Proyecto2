#include "arma.h"
#include<string>

using std::string;

arma::arma(string atribute,double damage):atribute(atribute),damage(damage){
}

double arma::getDamage(){ 
	return this->damage;
}

string getAtribute(){ 
	return this->atribute;
}

string arma::toString()=0;

