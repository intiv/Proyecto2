#include "soldado.h"
#include "arma.h"
#include "armadura.h"
#include "espadachin.h"
#include<string>
#include<sstream>
using std::string;
using std::stringstream;

espadachin::espadachin(string name,arma* weapon,armadura* armor,double hp):soldado(name,weapon,armor,hp){
}

espadachin::~espadachin(){
}

void espadachin::atacar(soldado* enemy){
	double dmg=this->weapon->getDamage();
	if(this->weapon->getAtribute().compare("Light")==0){
		dmg-=((enemy->getArmor()->getDefense())*0.75);
	}
}

string espadachin::toString()const{
	stringstream ss;
	ss<<name<<" - Espadachin: "<<currHP<<"/"<<hp<<" HP";
	//ss<<"\n\t\t\t\t\t\t\t\t\t"<<weapon->toString()<<"\n\t\t\t\t\t\t\t\t"<<armor->toString();
	return ss.str();
}
