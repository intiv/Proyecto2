#include "arma.h"
#include "armadura.h"
#include "soldado.h"
#include<iostream>

using namespace std;

int main(int argc, char* argv[]){
	arma a("none",100);
	cout<<a.toString()<<endl;
	armadura b("Hielo",200,150);
	cout<<b.toString()<<endl;
	soldado hola("Ike",a,b,500);
	cout<<hola.toString()<<endl;
	return 0;
}
