#include "armadura.h"
#include "pesada.h"
#include<string>
#include<sstream>

using std::string;
using std::stringstream;

pesada::pesada(string atribute, double defense):armadura(atribute,defense){
}

string pesada::toString()const{
	stringstream ss;
	ss<<"Heavy Armor: Attribute "<<this->atribute<<", Defense "<<this->defense<<", "<<currDur<<"/"<<durability<<" Durability";
	return ss.str();

}
