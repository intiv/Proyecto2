#pragma once
#include "item.h"
#include<string>
#include "soldado.h"

using std::string;

class powder: public item{
  public:
	powder();
	~powder();
	powder(double);
	string toString(int)const;
	void function(soldado*);
};
