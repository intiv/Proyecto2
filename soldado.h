#pragma once
#include<string>
#include "arma.h"
#include "armadura.h"
#include "item.h"
#include<vector>

using std::string;
using std::vector;
class item;

class soldado{
  protected:
	string name;
	vector<item*> inventory;
	arma* weapon;
	armadura* armor;
	double hp, currHP;
	bool alive, frozen, burned;
  public:
	virtual ~soldado();
	soldado(string, arma*,armadura*,double=500.0);
	arma* getWeapon()const;
	armadura* getArmor()const;
	item* getItem(int)const;
	vector<item*> getInv()const;
	string getName()const;
	int invSize()const;
	double getHP()const;
	double getCurrHP()const;
	bool isAlive()const;
	bool isFrozen()const;
	bool isBurned()const;
	void Freeze(bool);
	void Burn(bool);
	void setCurrHP(double);
	void state();
	void addItem(item*);
	void use(int);
	void setHP(double);
	void setAlive(bool);
	virtual bool atacar(soldado*,int)=0;
	virtual string toString()const=0;
};
