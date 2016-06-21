#pragma once
#include "item.h"
#include "soldado.h"
#include<string>

class elixir: public item{
  public:
	elixir();
	~elixir();
	elixir(double);
	string toString(int)const;
	void function(soldado*);
};
