#include"armadura.h"
#include<string>
#include<sstream>

using std::stringstream;
using std::string;

armadura::armadura(string atribute, double defense):atribute(atribute){
	if(defense>0.0&&defense<=400.0){
		this->defense=defense;
	}else{
		this->defense=100.0;
	}
	this->durability=100;
	this->currDur=this->durability;
	this->upgrades=0;
}

armadura::~armadura(){

}

string armadura::getAtribute()const{
	return this->atribute;
}

void armadura::setAtribute(const string& nAtr){
	this->atribute=nAtr;
}

void armadura::setDefense(double nDef){
	this->defense=nDef;
}

double armadura::getDefense()const{
	return this->defense;
}

int armadura::getDur()const{
	return this->durability;
}

void armadura::setDur(int nDur){
	this->durability=nDur;
}

int armadura::getCurrDur()const{
	return this->currDur;
}	

int armadura::getUpgrades()const{
	return this->upgrades;
}

void armadura::setCurrDur(int nDur){
	this->currDur=nDur;
}

void armadura::upgrade(){
	upgrades++;
}
void armadura::setUpgrades(const int& nUp){
	this->upgrades=nUp;
}
/*
string armadura::toString()const{
	stringstream ss;
	ss<<"Armadura "<<defense<<" "<<atribute<<" "<<durability<<" "<<currDur;
	return ss.str();
}*/
