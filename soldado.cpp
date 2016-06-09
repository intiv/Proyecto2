#include "soldado.h"
#include "arma.h"
#include "armadura.h"
#include<string>
#include<sstream>
using std::string;
using std::stringstream;	
soldado::soldado(string name,const arma& weapon,const armadura& armor,double hp):name(name),weapon(weapon),armor(armor){
	if(hp>0.0&&hp<5000.0){
		this->hp=hp;
	}else{
		this->hp=500.0;
	}
	this->currHP=this->hp;
	this->alive=true;
	
}

soldado::~soldado(){
	
}

void soldado::equip(const arma& nWeapon){
	this->weapon=nWeapon;
}

void soldado::equip(const armadura& nArmor){
	this->armor=nArmor;
}

void soldado::setAlive(bool nAlive){
	this->alive=nAlive;
}

void soldado::setCurrHP(double& nHP){
	this->currHP=nHP;
}

const arma& soldado::getWeapon()const{
	return this->weapon;
}

const armadura& soldado::getArmor()const{
	return this->armor;
}

bool soldado::isAlive()const{
	return this->alive;
}

double soldado::getHP()const{
	return this->hp;
}

string soldado::getName()const{
	return this->name;
}

string soldado::toString(){
	stringstream ss;
	ss<<"Soldado "<<name<<" "<<hp<<" "<<currHP<<" \narma: "<<weapon.toString();
	ss<<"\narmadura: "<<armor.toString();
	return ss.str();
}

