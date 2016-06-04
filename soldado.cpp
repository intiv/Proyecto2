#include "soldado.h"
	

soldado(arma weapon,armadura armor,double hp){
	
	if(hp>0.0&&hp<3000.0){
		this->hp=hp;
	}else{
		this->hp=500.0;
	}
	this->armor=armor;
	this->alive=true;
}

soldado::soldado(const soldado& s){
	this->hp=s.hp;
	this->armor=s.armor;
	this->weapons=s.weapons;
}

~soldado(){	
}



void equip(const arma&){}
void setArmor(const armadura&){}
void setAlive(bool){}
arma* getWeapons()const{}
arma& getWeapon()const{}
armadura& getArmor()const{}
bool isAlive()const{}
void atacar(soldado&){}
string toString(){}

