#include "soldado.h"
#include "mago.h"
#include "magia.h"
#include<string>
#include<sstream>
#include<cstdlib>
using std::string;
using std::stringstream;

mago::mago(string name,arma* magic,armadura* armor,double hp):soldado(name,magic,armor,hp){
}

mago::~mago(){

}

bool mago::atacar(soldado* enemy,int hit){
	if(hit>0){
                double dmg=this->weapon->getDamage();
                int chance=rand()%101;
                if(this->weapon->getAtribute().compare("Light")==0){
			if(enemy->getArmor()->getDur()>0)
                        	dmg-=((enemy->getArmor()->getDefense())*0.75);
                }else if(weapon->getAtribute().compare("Dark")==0){
                        if(armor->getAtribute().compare("Dark")==0){
                                dmg+=200;
				if(enemy->getArmor()->getDur()>0)
                                	dmg-=enemy->getArmor()->getDefense();
                                double drain=dmg/2;
                                if((getCurrHP()+drain)>=getHP()){
                                        setCurrHP(getHP());
                                }else{
                                        setCurrHP(getCurrHP()+drain);
                                }

                        }else{
                                dmg=0;
                        }
                }else if(weapon->getAtribute().compare("Electricity")==0){
                        if(enemy->getArmor()->getAtribute().compare("Electricity")==0){
                                dmg-=15;
                        }else{
                                dmg+=50;
                        }
			
			if(enemy->getArmor()->getDur()>0)
                        	enemy->getArmor()->setCurrDur(enemy->getArmor()->getCurrDur()-10);
			
			if(enemy->getWeapon()->getDurability()>0)
                        	enemy->getWeapon()->setCurrDur(enemy->getWeapon()->getCurrDur()-5);
			if(enemy->getArmor()->getDur()>0)
                        	dmg-=enemy->getArmor()->getDefense();
		}else if(weapon->getAtribute().compare("Fire")==0){
                        if(enemy->getArmor()->getAtribute().compare("Ice")==0){
                                if(chance<=25){
                                        enemy->Burn(true);
                                }
                                dmg+=100;
                        }else if(enemy->getArmor()->getAtribute().compare("Fire")==0){
                                dmg-=20;
                        }else{
                                if(chance<=15){
                                        enemy->Burn(true);
                                }
                                dmg+=30;
                        }	
			if(enemy->getArmor()->getDur()>0)
                        	dmg-=enemy->getArmor()->getDefense();
                }else if(weapon->getAtribute().compare("Ice")==0){
			if(enemy->getArmor()->getDur()>0)
                        	dmg-=enemy->getArmor()->getDefense();
                        if(chance<=15){
                                enemy->Freeze(true);
                        }
                }else{
			if(enemy->getArmor()->getDur()>0)
                        	dmg-=(enemy->getArmor()->getDefense()-10);
                }
                if((enemy->getCurrHP()-dmg)>0){
                        enemy->setCurrHP(enemy->getCurrHP()-dmg);
                }else{
                        enemy->setCurrHP(0);
                }
                weapon->setCurrDur(weapon->getCurrDur()-5);
		if(enemy->getArmor()->getDur()>0)
                	enemy->getArmor()->setCurrDur(enemy->getArmor()->getCurrDur()-5);
                return true;
        }else{
                return false;
        }

}

/*
mago::mago(soldado* m){
	this->name=m->getName();
	this->weapon=m->getWeapon();
	this->armor=m->getArmor();
	this->hp=m->getHP();
	this->currHP=m->getCurrHP();
	this->alive=m->isAlive();
	this->frozen=m->isFrozen();
	this->burned=m->isBurned();
}*/

string mago::toString()const{
	stringstream ss;
	ss<<name<<" - Mage: "<<currHP<<"/"<<hp<<" HP "; //\n\t"<<weapon->toString()<<"\n\t"<<armor->toString();
	return ss.str();
}
