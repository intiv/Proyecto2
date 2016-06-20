#pragma once
#include<string>
#include "soldado.h"

using std::string;
class soldado;

class item{
  protected:
	int uses,currUses, value;
	double price;
  public:
	item();
	virtual ~item();
	item(int,double,int);
	int getUses()const;
	double getPrice()const;
	int getCurrUses()const;
	virtual string toString()const=0;
	virtual void function(soldado*)=0;
};
