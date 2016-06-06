#include "arma.h"
#include "hacha.h"
#include<string>
#include<sstream>

using std::string;
using std::stringstream;

hacha::hacha(string atribute,double damage):arma(atribute,damage){
}

string hacha::toString()const{
	stringstream ss;
	ss<<"Hacha: Atributo "<<this->atribute<<", Ataque "<<this->damage;
	return ss.str();
}
