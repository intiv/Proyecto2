#pragma once
#include "soldado.h"
#include "magia.h"
#include<string>

using std::string;

class mago: public soldado{
  public:
	mago(string,const magia&,const armadura&,double&=500.0); 
	mago(const mago&);
	virtual ~mago();
	virtual void atacar(soldado&);
	string toString()const;
};
