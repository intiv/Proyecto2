#include "item.h"
#include "powder.h"
#include "soldado.h"
#include<string>
#include<sstream>

using std::string;
using std::stringstream;

powder::powder(){
}

powder::~powder(){
}

powder::powder(int uses,double price):item(uses,price,40){
}

string powder::toString()const{
	stringstream ss;
	ss<<"Repair Powder: Repairs up to "<<value<<" durability to your equipment. "<<currUses<<"/"<<uses;
	return ss.str();
}

void powder::function(soldado* pj){
	if((pj->getWeapon()->getCurrDur()+value)>=pj->getWeapon()->getDurability()){
                pj->getWeapon()->setCurrDur(pj->getWeapon()->getDurability());
        }else{
                pj->getWeapon()->setCurrDur(pj->getWeapon()->getCurrDur()+value);
        }

        if((pj->getArmor()->getCurrDur()+value)>=pj->getArmor()->getDur()){
                pj->getArmor()->setCurrDur(pj->getArmor()->getDur());
        }else{
                pj->getWeapon()->setCurrDur(pj->getWeapon()->getCurrDur()+value);
        }
	currUses--;
}
