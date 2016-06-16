#include "arma.h"
#include "lanza.h"
#include<string>
#include<sstream>

using std::stringstream;
using std::string;

lanza::lanza(string atribute,double damage):arma(atribute,damage){
}

string lanza::toString()const{
	stringstream ss;
	ss<<"Lance: Attribute "<<this->atribute<<", Attack "<<this->damage<<", "<<currDur<<"/"<<durability<<" Durability";


	return ss.str();
}
