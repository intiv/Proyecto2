#pragma once
#include "soldado.h"
#include "arma.h"
#include "armadura.h"
#include<string>

using std::string;

class espadachin: public soldado{
  public:
	espadachin(string,arma*,armadura*,double=800.0);
	~espadachin();
	bool atacar(soldado*,int);
	string toString()const;

};
