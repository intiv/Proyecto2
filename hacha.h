#pragma once
#include "arma.h"
#include<string>

using std::string;

class hacha: public arma{
 public:
	hacha(string,double=100.0);
	string toString()const;

};
