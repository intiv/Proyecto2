#include "item.h"
#include "elixir.h"
#include "soldado.h"
#include<string>
#include<sstream>

using std::string;
using std::stringstream;

elixir::elixir(){
}

elixir::~elixir(){
}

elixir::elixir(double price):item(1,price,200){
}

string elixir::toString(int op)const{
	stringstream ss;
	ss<<"Elixir - "<<currUses<<"/"<<uses;
	if(op==1){
		ss<<" "<<item::toString(1);
	}
	return ss.str();
}

void elixir::function(soldado* pj){
	pj->setCurrHP(pj->getHP());
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

	if(pj->isBurned()){
		pj->Burn(false);
	}
	currUses--;

}
