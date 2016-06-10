#pragma once
#include "armadura.h"
#include<string>
using std::string;

class robe: public armadura{
 public:
	robe(string,double=100.0);
	string toString()const;
};
