#include "armadura.h"
#include "ligera.h"
#include<string>
#include<sstream>

using std::string;
using std::stringstream;

ligera::ligera(string atribute, double defense):armadura(atribute,defense){
}

string ligera::toString()const{
	stringstream ss;
	ss<<"Armadura Ligera: Atributo "<<this->atribute<<", Defensa "<<this->defense<<", "<<currDur<<"/"<<durability<<" durabilidad";
	return ss.str();
}
