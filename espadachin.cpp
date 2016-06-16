#include "soldado.h"
#include "arma.h"
#include "armadura.h"
#include "espadachin.h"
#include<string>
#include<sstream>
#include<cstdlib>
using std::string;
using std::stringstream;

espadachin::espadachin(string name,arma* weapon,armadura* armor,double hp):soldado(name,weapon,armor,hp){
}

espadachin::~espadachin(){
}

bool espadachin::atacar(soldado* enemy,int hit){
	double dmg=this->weapon->getDamage();
	int r1=rand()%101;
	if(hit>=100||hit>0&&r1<=hit){
		bool frz=false,brn=false;
		if(this->weapon->getAtribute().compare("Light")==0){
			dmg-=((enemy->getArmor()->getDefense())*0.75);
		}else if(weapon->getAtribute().compare("Dark")==0){
			dmg+=200;
			dmg-=enemy->getArmor()->getDefense();
		}else if(weapon->getAtribute().compare("Electricity")==0){
			dmg+=50;
			dmg-=enemy->getArmor()->getDefense();	
		}else if(weapon->getAtribute().compare("Fire")==0){
			if(enemy->getArmor()->getAtribute().compare("Ice")==0){
				dmg+=100;
			}else if(enemy->getArmor()->getAtribute().compare("Fire")==0){
				dmg-=20;
			}else{
				dmg+=30;
			}
		}
	
		return true;
	}else{
		return false;
	}
	
	
}

string espadachin::toString()const{
	stringstream ss;
	ss<<name<<" - Espadachin: "<<currHP<<"/"<<hp<<" HP";
	//ss<<"\n\t\t\t\t\t\t\t\t\t"<<weapon->toString()<<"\n\t\t\t\t\t\t\t\t"<<armor->toString();
	return ss.str();
}
