#pragma once
#include "arma.h"
#include<string>

using std::string;

class magia: public arma{
 public:
	magia(string,double=100.0);
	string toString()const;
}
