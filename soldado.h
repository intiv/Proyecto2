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
 public:
	soldado(const arma&,const armadura&,double=500.0);
	soldado(const soldado&);
	void equip(const arma&);
	void equip(const armadura&);
	void setAlive(bool);
	const arma& getWeapon()const;
	const armadura& getArmor()const;
	double getHP();
	bool isAlive()const;
	virtual void atacar(soldado&)=0;
	virtual string toString()=0;
	
};
