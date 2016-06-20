#include "item.h"
#include<string>
#include<sstream>

using std::string;
using std::stringstream;

item::item(){	
}

item::~item(){
}

item::item(int uses,double price,int value):uses(uses),price(price),value(value),currUses(uses){
}

int item::getUses()const{
	return this->uses;
}

int item::getCurrUses()const{
	return this->currUses;
}

double item::getPrice()const{
	return this->price;
}
