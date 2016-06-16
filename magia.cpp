#include "arma.h"
#include "magia.h"
#include<string>
#include<sstream>

using std::string;
using std::stringstream;

magia::magia(string atribute,double damage):arma(atribute,damage){
	
}

string magia::toString()const{
	stringstream ss;
	ss<<"Magic: Attribute "<<this->atribute<<", Attack "<<this->damage<<", "<<currDur<<"/"<<durability<<" Durability";
	return ss.str();
}
