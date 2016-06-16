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
	ss<<"Robe: Attribute "<<this->atribute<<", Defense "<<this->defense<<", "<<currDur<<"/"<<durability<<" Durability";
	return ss.str();
}
