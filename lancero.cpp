#include "soldado.h"
#include "lancero.h"
#include "arma.h"
#include "armadura.h"
#include<string>
#include<sstream>

using std::string;
using std::stringstream;

lancero::lancero(string name, arma* weapon, armadura* armor, double hp):soldado(name,weapon,armor,hp){
}

lancero::~lancero(){
}

void lancero::atacar(soldado* enemy){

}

string lancero::toString()const{
	stringstream ss;
	ss<<name<<" - Lancero: "<<currHP<<"/"<<hp<<" HP";
	ss<<"\n\t"<<weapon->toString()<<"\n\t"<<armor->toString();
	return ss.str();
}
