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

powder::powder(double price):item(2,price,40){
}

string powder::toString(int op)const{
	stringstream ss;
	ss<<"Powder - "<<currUses<<"/"<<uses;
	if(op==1){
		ss<<" "<<item::toString(1);
	}
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
