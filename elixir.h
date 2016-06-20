#pragma once
#include "item.h"
#include "soldado.h"
#include<string>

class elixir: public item{
  public:
	elixir();
	~elixir();
	elixir(int,double);
	string toString()const;
	void function(soldado*);
};
