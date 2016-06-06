#include "armadura.h"
#include "robe.h"
#include<string>
#include<sstream>

using std::string;
using std::stringstream;

robe::robe(string atribute,double defense):armadura(atribute,defense){
}

string robe::toString()const{
	stringstream ss;
	ss<<"Tunica: Atributo "<<this->atributo<<", Defensa "<<this->defensa;
	return ss.str();
}