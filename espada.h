#pragma once
#include "arma.h"
#include<string>

using std::string;

class espada: public arma{
 public:
	espada(string,double=100.0);
	string toString()const;
};
