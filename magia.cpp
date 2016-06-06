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
	ss<<"Magia: Atributo "<<this->atributo<<", Ataque "<<this->damage;
	return ss.str();
}
