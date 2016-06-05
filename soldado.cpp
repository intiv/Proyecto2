#include "soldado.h"
#include "arma.h"
#include "armadura.h"
#include<string>

using std::string;
	
soldado::soldado(const arma& weapon,const armadura& armor,double& hp):weapon(weapon),armor(armor),{
	
	if(hp>0.0&&hp<5000.0){
		this->hp=hp;
	}else{
		this->hp=500.0;
	}
}

soldado::soldado(const soldado& s){
	this->hp=s.hp;
	this->armor=s.armor;
	this->weapons=s.weapons;
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

const arma& soldado::getWeapon()const{
	return this->weapon;
}

const armadura& soldado::getArmor()const{
	return this->armor;
}

bool soldado::isAlive()const{
	return this->alive;
}

virtual void soldado::atacar(soldado&)=0;

virtual string soldado::toString()=0;

