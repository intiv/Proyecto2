#include "espada.h"
#include "arma.h"
#include<string>
#include<sstream>

using std::string;
using std::stringstream;

espada::espada(string atribute, double damage):arma(atribute,damage){

}

string espada::toString()const{
	stringstream ss;
	ss<<"Espada:  Atributo: "<<this->atribute<<", Ataque: "<<this->damage;
	return ss.str();
}
