#pragma once
#include<string>
#include "arma.h"
#include "armadura.h"

using std::string;

class soldado{
 protected:
	string name, Class;
	arma weapona;
	armadura armor;
	double hp, currHP;
	bool alive;
 public:
	soldado(string, const arma&,const armadura&,double&=500.0);
	soldado(const soldado&);
	void equip(const arma&);
	void equip(const armadura&);
	void setAlive(bool);
	const arma& getWeapon()const;
	const armadura& getArmor()const;
	double getHP()const;
	string getName()const;
	string getClass()const;
	void setCurrHP(unsigned double&);
	double getCurrHP()const;
	bool isAlive()const;
	virtual void atacar(soldado&)=0;
	virtual string toString()=0;	
};
