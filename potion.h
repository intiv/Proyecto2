#pragma once
#include<string>
#include "soldado.h"

using std::string;

class potion: public item{
  public:
	potion();
	potion(double);
	~potion();
	string toString(int)const;
	void function(soldado*);
};
