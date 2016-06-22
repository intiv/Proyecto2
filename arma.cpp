#include "arma.h"
#include<string>
#include<sstream>

using std::stringstream;
using std::string;

arma::arma(string atribute,double damage):atribute(atribute){
	if(damage>0&&damage<500){
		this->damage=damage;
	}else{
		this->damage=150.0;
	}
	this->durability=100;
	this->currDur=100;
	this->upgrades=0;
}

arma::~arma(){

}

double arma::getDamage()const{ 
	return this->damage;
}

void arma::setCurrDur(int nDur){
	this->currDur=nDur;
}

int arma::getCurrDur()const{
	return this->currDur;
}
string arma::getAtribute()const{ 
	return this->atribute;
}

int arma::getDurability()const{
	return this->durability;
}

int arma::getUpgrades()const{
	return this->upgrades;
}
void arma::setDurability(int nDur){
	this->durability=nDur;
}

void arma::upgrade(){
	upgrades++;
}

void arma::setUpgrades(const int& nUp){
	this->upgrades=nUp;
}

void arma::setDamage(double nDmg){
	if(nDmg>0&&nDmg<=500){
		this->damage=nDmg;
	}
}

void arma::setAtribute(string nAtr){
	this->atribute=nAtr;
}
/*
string arma::toString()const{
	stringstream ss;
	ss<<"Arma "<<damage<<" "<<atribute<<" "<<durability<<" "<<currDur;
	return ss.str();
}*/
