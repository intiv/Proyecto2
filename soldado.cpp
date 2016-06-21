#include "soldado.h"
#include<vector>
#include<string>
#include<sstream>
#include<iostream>

using std::string;
using std::stringstream;	
using std::vector;

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
	std::cout<<"Deleting soldier "<<this->name<<"..."<<std::endl;
	delete this->weapon;
	delete this->armor;
	std::cout<<"Deleted succesfuly!"<<std::endl;
}

void soldado::setAlive(bool nAlive){
	this->alive=nAlive;
}

double soldado::getCurrHP()const{
	return this->currHP;
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

void soldado::state(){
	if(currHP<=0){
		alive=false;
	}
	if(alive){
		if(burned){
			this->currHP-=(currHP*0.05);
			if(currHP<=0){
                		alive=false;
  	 	     	}
		}

		if(armor->getAtribute().compare("Dark")==0){
			if(currHP>hp*0.10){
				currHP-=(hp*0.10);
			}else{
				currHP=0;
			}
			if(currHP<=0){
                                alive=false;
                        }

		}else if(armor->getAtribute().compare("Light")==0){
			if((currHP+(hp*0.05))>=hp){
				currHP=hp;
			}else{
				currHP+=(hp*0.05);
			}
		}

		if(weapon->getAtribute().compare("Light")==0){
			 if((currHP+(hp*0.05))>=hp){
                                currHP=hp;
                        }else{
                                currHP+=(hp*0.05);
                        }
		}
		for(int i=0;i<inventory.size();i++){
			if(inventory.at(i)->getCurrUses()==0){
				delete inventory[i];
				inventory.erase(inventory.begin()+i);
			}
		}
	}

	
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

void soldado::setHP(double nHP){
	this->hp=nHP;
}

string soldado::getName()const{
	return this->name;
}

item* soldado::getItem(int ind)const{
	return this->inventory.at(ind);
}

vector<item*> soldado::getInv()const{
	return this->inventory;
}

int soldado::invSize()const{
	return this->inventory.size();
}

void soldado::addItem(item* nItem){
	this->inventory.push_back(nItem);
}
/*
string soldado::toString(){
	stringstream ss;
	ss<<"Soldado "<<name<<" "<<hp<<" "<<currHP<<" \narma: "<<weapon->toString();
	ss<<"\narmadura: "<<armor.toString();
	return ss.str();
}*/

