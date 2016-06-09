#pragma once
#include<string>
#include "arma.h"
#include "armadura.h"

using std::string;

class soldado{
 protected:
	string name;
	arma weapon;
	armadura armor;
	double hp, currHP;
	bool alive, frozen, burned;
 public:
	soldado(string, const arma&,const armadura&,double=500.0);
	virtual ~soldado();
	void equip(const arma&);
	void equip(const armadura&);
	void setAlive(bool);
	const arma& getWeapon()const;
	const armadura& getArmor()const;
	double getHP()const;
	string getName()const;
	void setCurrHP(double&);
	double getCurrHP()const;
	bool isAlive()const;
	string toString();
	/*virtual void atacar(soldado&)=0;
	virtual string toString()const=0;*/
};
