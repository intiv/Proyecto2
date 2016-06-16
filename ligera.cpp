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
	ss<<"Light Armor: Attribute "<<this->atribute<<", Defense "<<this->defense<<", "<<currDur<<"/"<<durability<<" Durability";
	return ss.str();
}
