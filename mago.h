#pragma once
#include "soldado.h"
#include "magia.h"
#include "robe.h"
#include<string>

using std::string;

class mago: public soldado{
  public:
	mago(string,arma*,armadura*,double=500.0); 
	~mago();
	void atacar(soldado*);
	string toString()const;
};
