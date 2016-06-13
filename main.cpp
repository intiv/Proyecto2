#include "arma.h"
#include "armadura.h"
#include "soldado.h"
#include "lanza.h"
#include "espada.h"
#include "magia.h"
#include "robe.h"
#include "mago.h"
#include "ligera.h"
#include "lancero.h"
#include "pesada.h"
#include "espadachin.h"
#include<cstring>
#include<ncurses.h>
#include<iostream>

using namespace std;

void ClearScreen();

int main(int argc, char* argv[]){
	initscr();
	soldado* pj=0;
	arma* w=0;
	armadura* a=0;
	int ch;
	while((ch=getch())!=27){
		move(10,10);
		printw("Keycode: %d     ",ch);
		move(0,0);
		printw("Letra: ");
		refresh();
	}
	noecho();
	ClearScreen();
	printw("Seleccione su personaje:\n1.- Aran (lancero)\n2.- Soren (mago)\n3.- Mia(espadachin)");
	int op=getch();
	ClearScreen();
	if(op==49){
		w=new lanza("None",70);
		a=new pesada("Hielo",100);
		pj=new lancero("Aran",w,a,800);
	}else if(op==50){
		w=new magia("Fuego",100);
		a=new robe("N/A",50);
		pj=new mago("Soren",w,a,500);
	}else if(op==51){
		w=new espada("Luz",60);
		a=new ligera("Luz",70);
		pj=new espadachin("Ike",w,a,650);
	}
	printw(pj->toString().c_str());
	getch();	
	delete pj;
	endwin();
	return 0;
}

void ClearScreen(){
	int x, y;
	getmaxyx(stdscr,y,x);
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			mvprintw(i,j," ");
		}
	}
	move(0,0);
}
