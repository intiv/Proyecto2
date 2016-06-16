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

bool lancero::atacar(soldado* enemy,int hit){

}

string lancero::toString()const{
	stringstream ss;
	ss<<name<<" - Halberdier: "<<currHP<<"/"<<hp<<" HP";

	//ss<<"\n\t\t\t\t\t\t\t\t\t"<<weapon->toString()<<"\n\t\t\t\t\t\t\t\t\t"<<armor->toString();
	return ss.str();
}
