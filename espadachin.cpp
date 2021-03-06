#include "soldado.h"
#include "arma.h"
#include "armadura.h"
#include "espadachin.h"
#include "pesada.h"
#include<string>
#include<sstream>
#include<cstdlib>
#include<typeinfo>

using std::string;
using std::stringstream;

espadachin::espadachin(string name,arma* weapon,armadura* armor,double hp):soldado(name,weapon,armor,hp){
}

espadachin::~espadachin(){
}

bool espadachin::atacar(soldado* enemy,int hit){
	if(hit>0){
		double dmg=this->weapon->getDamage();
		int chance=rand()%101;
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
			if(enemy->getArmor()->getCurrDur()>0)
				dmg-=enemy->getArmor()->getDefense();	
			if(enemy->getArmor()->getAtribute().compare("Electricity")==0){
				dmg-=15;
			}else{
				dmg+=50;
			}
			if(enemy->getArmor()->getCurrDur()>10)
				enemy->getArmor()->setCurrDur(enemy->getArmor()->getCurrDur()-10);
			else
				enemy->getArmor()->setCurrDur(0);
			
			if(enemy->getWeapon()->getCurrDur()>5)
				enemy->getWeapon()->setCurrDur(enemy->getWeapon()->getCurrDur()-5);
			else
				enemy->getWeapon()->setCurrDur(0);

			
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
			
			if(enemy->getArmor()->getCurrDur()>0)
				dmg-=enemy->getArmor()->getDefense();
		}else if(weapon->getAtribute().compare("Ice")==0){
			if(enemy->getArmor()->getCurrDur()>0)
				dmg-=enemy->getArmor()->getDefense();
			if(chance<=15){
				enemy->Freeze(true);
			}	
		}else{
			if(enemy->getArmor()->getCurrDur()>0)
				dmg-=(enemy->getArmor()->getDefense()-10);
		}
		if(enemy->getArmor()->getCurrDur()>0&&(typeid(*enemy->getArmor())==typeid(pesada))){
			if(dmg>30){
				dmg-=30;
			}else{
				dmg=0;
			}
		}
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

string espadachin::toString()const{
	stringstream ss;
	ss<<name<<" - Swordmaster: "<<currHP<<"/"<<hp<<" HP";
	//ss<<"\n\t\t\t\t\t\t\t\t\t"<<weapon->toString()<<"\n\t\t\t\t\t\t\t\t"<<armor->toString();
	return ss.str();
}
