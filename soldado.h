#pragma once
#include<string>
#include "arma.h"
#include "armadura.h"

using std::string;

class soldado{
  protected:
	virtual ~soldado();
	string name;
	arma* weapon;
	armadura* armor;
	double hp, currHP;
	bool alive, frozen, burned;
  public:
	soldado(string, arma*,armadura*,double=500.0);
	void setAlive(bool);
	arma* getWeapon()const;
	armadura* getArmor()const;
	double getHP()const;
	string getName()const;
	void setCurrHP(double);
	double getCurrHP()const;
	bool isAlive()const;
	bool isFrozen()const;
	bool isBurned()const;
	void Freeze(bool);
	void Burn(bool);
	virtual void atacar(soldado*)=0;
	virtual string toString()const=0;
};
