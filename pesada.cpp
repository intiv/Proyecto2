#include "armadura.h"
#include "pesada.h"
#include<string>
#include<sstream>

using std::string;
using std::stringstream;

pesada::pesada(string atribute, double defense):arma(atribute,defense){
}

string pesada::toString()const{
	stringstream ss;
	ss<<"Armadura Pesada: Atributo "<<this->atribute<<", Defensa "<<this->defense;
	return ss.str();

}
