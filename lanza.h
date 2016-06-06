#pragma once
#include "arma.h"
#include<string>

using std::string;

class lanza: public arma{
 public:
	lanza(string,double=100.0);
	string toString()const;

};
