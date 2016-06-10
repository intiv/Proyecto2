#include "soldado.h"
#include "mago.h"
#include "magia.h"
#include "string"
#include "sstream"

using std::string;
using std::stringstream;

mago::mago(string name,arma* magic,armadura* armor,double hp):soldado(name,magic,armor,hp){
}

mago::~mago(){

}

void mago::atacar(soldado* enemy){

}

/*
mago::mago(soldado* m){
	this->name=m->getName();
	this->weapon=m->getWeapon();
	this->armor=m->getArmor();
	this->hp=m->getHP();
	this->currHP=m->getCurrHP();
	this->alive=m->isAlive();
	this->frozen=m->isFrozen();
	this->burned=m->isBurned();
}*/

string mago::toString()const{
	stringstream ss;
	ss<<name<<"- Mago: "<<currHP<<" HP \n\t"<<weapon->toString()<<"\n\t"<<armor->toString();
	return ss.str();
}
