#pragma once
#include<string>
#include "soldado.h"

using std::string;

class potion: public item{
  public:
	potion();
	potion(int,double);
	~potion();
	string toString()const;
	void function(soldado*);
};
