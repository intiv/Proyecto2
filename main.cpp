#include "arma.h"
#include "armadura.h"
#include "soldado.h"
#include "lanza.h"
#include "espada.h"
#include "magia.h"
#include "robe.h"
#include "mago.h"
#include<iostream>

using namespace std;

int main(int argc, char* argv[]){
	arma* weap;
	armadura* arm;
	espada c("None",120);
	lanza d("none",100);
	magia e("Fuego",150);
	weap=new magia("fuego",150);
	arm=new robe("asdasdasd",50);
	cout<<weap->toString()<<endl;
	cout<<arm->toString()<<endl;
	cout<<c.toString()<<endl;
	cout<<d.toString()<<endl;
	cout<<e.toString()<<endl<<endl;
	if(dynamic_cast<magia*>(weap)!=0){
		cout<<"Holis"<<endl;
	}else{
		cout<<"Kek"<<endl;
	}
	soldado* hola=new mago("Soren",weap,arm,500);
	cout<<endl<<hola->toString()<<endl;
	delete hola;
	weap=NULL;
	arm=NULL;
	return 0;
}
