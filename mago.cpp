#include<string>
#include "mago.h"
#include "robe.h"
#include "soldado.h"
#include "magia.h"
#include<sstream>
#include<cstdlib>
#include<typeinfo>
using std::string;
using std::stringstream;

mago::mago(string name,arma* magic,armadura* armor,double hp):soldado(name,magic,armor,hp){
}

mago::~mago(){

}

bool mago::atacar(soldado* enemy,int hit){
 
        int chance=rand()%101;
	if(typeid(*enemy)==typeid(mago)){
		hit-=10;
	}
	if(chance<=hit){//poli: El hit% si afecta al momento de calcular si el golpe conecta o falla
                double dmg=this->weapon->getDamage();
                if(this->weapon->getAtribute().compare("Light")==0){
			if(enemy->getArmor()->getCurrDur()>0)
                        	dmg-=((enemy->getArmor()->getDefense())*0.75);
                }else if(weapon->getAtribute().compare("Dark")==0){
                        if(armor->getAtribute().compare("Dark")==0){
                                dmg+=200;
				if(enemy->getArmor()->getCurrDur()>0)
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
			
			if(enemy->getArmor()->getCurrDur()>0)
                        	enemy->getArmor()->setCurrDur(enemy->getArmor()->getCurrDur()-10);
			
			if(enemy->getWeapon()->getDurability()>0)
                        	enemy->getWeapon()->setCurrDur(enemy->getWeapon()->getCurrDur()-5);
			if(enemy->getArmor()->getCurrDur()>0)
                        	dmg-=enemy->getArmor()->getDefense();
		}else if(weapon->getAtribute().compare("Fire")==0){
                        if(enemy->getArmor()->getAtribute().compare("Ice")==0){
                                if(chance<=30){//Poli: Doble chance de quemar/congelar
                                        enemy->Burn(true);
                                }
                                dmg+=100;
                        }else if(enemy->getArmor()->getAtribute().compare("Fire")==0){
                                dmg-=20;
                        }else{
                                if(chance<=30){
                                        enemy->Burn(true);
                                }
                                dmg+=30;
                        }	
			if(enemy->getArmor()->getCurrDur()>0)
                        	dmg-=enemy->getArmor()->getDefense();
                }else if(weapon->getAtribute().compare("Ice")==0){
			if(enemy->getArmor()->getCurrDur()>0)
                        	dmg-=enemy->getArmor()->getDefense();
                        if(chance<=30){//Poli: Doble chance de quemar/congelar
                                enemy->Freeze(true);
                        }
                }else{
			if(enemy->getArmor()->getCurrDur()>0)
                        	dmg-=(enemy->getArmor()->getDefense()-10);
                }
		
		//polimorfismo
		if(typeid(*enemy->getArmor())==typeid(robe)&&enemy->getArmor()->getCurrDur()>0){
			if(dmg>=30){
				dmg-=30;
			}else{
				dmg=0;
			}
		}else if(enemy->getArmor()->getCurrDur()>0){
			dmg+=20;
		}
		//
		if(dmg<0){
			dmg=0;
		}
                if((enemy->getCurrHP()-dmg)>0){
                        enemy->setCurrHP(enemy->getCurrHP()-dmg);
                }else{
                        enemy->setCurrHP(0);
                }
                weapon->setCurrDur(weapon->getCurrDur()-5);
		if(enemy->getArmor()->getCurrDur()>0)
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
