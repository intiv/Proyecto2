#pragma once
#include "armadura.h"
#include<string>
using std::string;

class pesada: public armadura{
 public:
	pesada(string,double=200.0);
	string toString()const;
};
