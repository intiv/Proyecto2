#include "soldado.h"
#include "lancero.h"
#include "arma.h"
#include "armadura.h"
#include "ligera.h"
#include "robe.h"
#include<string>
#include<sstream>
#include<cstdlib>
#include<typeinfo>

using std::string;
using std::stringstream;

lancero::lancero(string name, arma* weapon, armadura* armor, double hp):soldado(name,weapon,armor,hp){
}

lancero::~lancero(){
}

bool lancero::atacar(soldado* enemy,int hit){
       	int chance=rand()%101;
	if(typeid(*enemy->getArmor())==typeid(ligera)){
		hit-=25;
	}else if(typeid(*enemy->getArmor())==typeid(robe)){
		hit-=10;
	}
	if(chance<=hit){//Poli: hit% afecta al calcular si ataque conecta o falla
                double dmg=this->weapon->getDamage();
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
			if(enemy->getArmor()->getCurrDur()>0)
                        	dmg-=enemy->getArmor()->getDefense();
                        
			if(enemy->getArmor()->getAtribute().compare("Electricity")==0){
                                dmg-=15;
                        }else{
                                dmg+=50;
                        }
			if(chance<=35){//Poli: Lanceros tienen mas chance activar efectos de electricidad
				if(enemy->getArmor()->getCurrDur()>10)
               		         	enemy->getArmor()->setCurrDur(enemy->getArmor()->getCurrDur()-10);
				else
					enemy->getArmor()->setCurrDur(0);
		
				if(enemy->getWeapon()->getCurrDur()>10)
                        		enemy->getWeapon()->setCurrDur(enemy->getWeapon()->getCurrDur()-10);
				else
					enemy->getWeapon()->setCurrDur(0);
			}
                }else if(weapon->getAtribute().compare("Fire")==0){
                        if(enemy->getArmor()->getAtribute().compare("Ice")==0){
                                if(chance<=15){
                                        enemy->Burn(true);
                                }
                                dmg+=100;
                        }else if(enemy->getArmor()->getAtribute().compare("Fire")==0){
                                dmg-=20;
                        }else{
                                if(chance<=20){//en cambio, tienen 5% menos chance de quemar
                                        enemy->Burn(true);
                                }
                                dmg+=30;
                        }
			if(enemy->getArmor()->getCurrDur()>0)
                        	dmg-=enemy->getArmor()->getDefense();
		}else if(weapon->getAtribute().compare("Ice")==0){
			if(enemy->getArmor()->getCurrDur()>0)
                        	dmg-=enemy->getArmor()->getDefense();
                        if(chance<=20){
                                enemy->Freeze(true);
                        }
                }else{	
			if(enemy->getArmor()->getCurrDur()>0)
                        	dmg-=(enemy->getArmor()->getDefense()-10);
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
		if(enemy->getArmor()->getDur()>0)
                	enemy->getArmor()->setCurrDur(enemy->getArmor()->getCurrDur()-5);
                return true;
        }else{
                return false;
        }

}

string lancero::toString()const{
	stringstream ss;
	ss<<name<<" - Halberdier: "<<currHP<<"/"<<hp<<" HP";

	//ss<<"\n\t\t\t\t\t\t\t\t\t"<<weapon->toString()<<"\n\t\t\t\t\t\t\t\t\t"<<armor->toString();
	return ss.str();
}
