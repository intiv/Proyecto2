#include "soldado.h"
#include "arma.h"
#include "armadura.h"
#include<string>
#include<sstream>
#include<iostream>

using std::string;
using std::stringstream;	
soldado::soldado(string name,arma* weapon,armadura* armor,double hp):name(name),weapon(weapon),armor(armor){
	if(hp>0.0&&hp<5000.0){
		this->hp=hp;
	}else{
		this->hp=500.0;
	}
	this->currHP=this->hp;
	this->alive=true;
	this->frozen=false;
	this->burned=false;
	
}

soldado::~soldado(){
	std::cout<<"Destruyendo soldado "<<this->name<<"..."<<std::endl;
	delete this->weapon;
	delete this->armor;
	std::cout<<"Destruido con exito!"<<std::endl;
}

void soldado::setAlive(bool nAlive){
	this->alive=nAlive;
}

void soldado::setCurrHP(double nHP){
	this->currHP=nHP;
}

arma* soldado::getWeapon()const{
	return this->weapon;
}

armadura* soldado::getArmor()const{
	return this->armor;
}

bool soldado::isAlive()const{
	return this->alive;
}

bool soldado::isFrozen()const{
	return this->frozen;
}

bool soldado::isBurned()const{
	return this->burned;
}

void soldado::Freeze(bool flag){
	this->frozen=flag;
}

void soldado::Burn(bool flag){
	this->burned=flag;
}

double soldado::getHP()const{
	return this->hp;
}

string soldado::getName()const{
	return this->name;
}
/*
string soldado::toString(){
	stringstream ss;
	ss<<"Soldado "<<name<<" "<<hp<<" "<<currHP<<" \narma: "<<weapon->toString();
	ss<<"\narmadura: "<<armor.toString();
	return ss.str();
}*/

