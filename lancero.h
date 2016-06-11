#pragma once
#include "soldado.h"
#include "arma.h"
#include "armadura.h"
#include<string>

using std::string;

class lancero: public soldado{
  public:
	lancero(string, arma*, armadura*, double=1000.0);
	~lancero();
	void atacar(soldado*);
	string toString()const;
};

