#include "potion.h"
#include "item.h"
#include<string>
#include<sstream>
#include "soldado.h"

using std::string;
using std::stringstream;

potion::potion(){
}

potion::~potion(){
}

potion::potion(double price):item(3,price,500){
	
}

string potion::toString(int op)const{
	stringstream ss;
	ss<<"Potion - "<<currUses<<"/"<<uses;
	if(op==1){
		ss<<" "<<item::toString(1);
	}
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
