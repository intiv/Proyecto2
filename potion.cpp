#include "potion.h"
#include<string>
#include<sstream>
#include "soldado.h"

using std::string;
using std::stringstream;

potion::potion(){
}

potion::~potion(){
}

potion::potion(int uses,double price):item(uses,price,300){
	
}

string potion::toString()const{
	stringstream ss;
	ss<<"Potion: Heals up to "<<value<<" HP. "<<currUses<<"/"<<uses;
	return ss.str(); 
}

void potion::function(soldado* pj){
	if((pj->getCurrHP()+value)>=pj->getHP()){
		pj->setCurrHP(pj->getHP());
	}else{
		pj->setCurrHP(pj->getCurrHP()+value);
	}
	currUses--;
}
