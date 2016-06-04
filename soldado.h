#pragma once
#include<string>
#include "arma.h"
#include "armadura.h"
#include<vector>

using std::string;
using std::vector;

class soldado{
 protected:
	arma weapona;
	armadura armor;
	double hp;
	bool alive;
	~soldado();
 private:
	soldado(armadura,double=500.0);
	soldado(const soldado&);
	const arma& equip(const arma&,int);
	void setArmor(const armadura&);
	void setAlive(bool);
	arma& getWeapon()const;
	armadura& getArmor()const;
	double getHP();
	bool isAlive()const;
	virtual void atacar(soldado&)=0;
	string toString();
	
};
