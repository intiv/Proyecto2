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
#include<sstream>
#include<typeinfo>
using std::string;
using std::stringstream;

void ClearScreen(int&,int&);
void printPJ(soldado*,int&,int&);
void press();

int main(int argc, char* argv[]){
	initscr();
	int x,y;
	noecho();
	const string atrs[6]={"N/A","Fire","Ice","Electricity","Light","Dark"};
	soldado* pj=0;
	arma* weap=0;
	armadura* arm=0;
	getmaxyx(stdscr,y,x);
	if(x<165||y<40){
		while(x<165||y<40){
			mvprintw(0,0,"Please expand your game window to get the full experience ");
			mvprintw(1,0,"and avoid problems with the game's text");
			mvprintw(2,0,"Once you have made the window bigger:");
			mvprintw(3,0,"      press X to continue");
			press();
			getmaxyx(stdscr,y,x);
		}
	}
	ClearScreen(y,x);
	/*int ch;
	while((ch=getch())!=27){
		move(10,10);
		printw("Keycode: %d     ",ch);
		move(0,0);
		printw("Letra: ");
		refresh();
	}*/
	move(0,0);
	ClearScreen(y,x);
	weap=new espada(atrs[4],60);
	arm=new ligera(atrs[0],70);
	pj=new espadachin("Shie",weap,arm,650);
	mvprintw(y/2-3,x/2-65,"Shie, 18 years old, is a master of the sword and a princess; Daughter of the missing king of the Baste kingdom, Marcus III.");
	mvprintw(y/2-2,x/2-65,"After hearing of the sudden disappearance of her father, she took the sacred royal blade of light, Darkbane, and set out to find the king");
	mvprintw(y/2-1,x/2-65,"This is her story, as she fights fierce warriors and discovers crushing revelations along her journey to find her father");
	mvprintw(y/2,x/2-65,"With no fear of what awaits her, she sets out to the town of Tir, where rumours say the king was last sighted");
	press();
	ClearScreen(y,x);
	mvprintw(y/2,x/2-20,"Chapter 1: Cross-road Encounter");
	press();	
	delete pj;
	endwin();
	return 0;
}

void ClearScreen(int& y,int& x){
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			mvprintw(i,j," ");
		}
	}
	move(0,0);
}

void printPJ(soldado* pj, int& y, int& x){
	mvprintw(y/2-22,x/2-10,"Informacion del personaje:");
	mvprintw(y/2-20,x/2-10,pj->toString().c_str());
	mvprintw(y/2-19,x/2-9,pj->getWeapon()->toString().c_str());
	mvprintw(y/2-18,x/2-9,pj->getArmor()->toString().c_str());
		mvprintw(y/2-16,x/2-10,"      O");
		mvprintw(y/2-15,x/2-10,"      |");
		mvprintw(y/2-14,x/2-10,"O{XXX}<>============> ");
		mvprintw(y/2-13,x/2-10,"      |");
		mvprintw(y/2-12,x/2-10,"      O");
	}			 
}

void press(){
	int getkey;
	while((getkey=getch())!=120){
	}
}
