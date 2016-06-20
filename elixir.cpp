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

elixir::elixir(int uses, double price):item(uses,price,100){
}

string elixir::toString()const{
	stringstream ss;
	ss<<"Elixir: Potent healing item. Heals up to "<<value*6<<" HP and repairs your equipment by up to "<<value<<" durability, Removes burn. "<<currUses<<"/"<<uses;
	return ss.str();
}

void elixir::function(soldado* pj){
	if((pj->getCurrHP()+value*7)>=pj->getHP()){
		pj->setCurrHP(pj->getHP());
	}else{
		pj->setCurrHP(pj->getCurrHP()+value*7);
	}

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
