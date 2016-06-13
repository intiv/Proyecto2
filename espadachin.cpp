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
	
}

string espadachin::toString()const{
	stringstream ss;
	ss<<name<<" - Espadachin: "<<currHP<<"/"<<hp<<" HP";
	ss<<"\n\t"<<weapon->toString()<<"\n\t"<<armor->toString();
	return ss.str();
}
