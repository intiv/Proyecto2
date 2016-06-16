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
#include<cstdlib>
#include<ctime>
#include<vector>

using std::string;
using std::stringstream;
using std::vector;

void ClearScreen(int&,int&);
void printPJ(soldado*,int&,int&);
void press();
int Hit(const soldado*,const soldado*);

int main(int argc, char* argv[]){
	initscr();	
	int x,y,enemigo=0;
	vector<soldado*> enemies(6);
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
	enemies.at(0)=new espadachin("Von",new espada(atrs[0],100),new ligera(atrs[0],60),500);
	enemies.at(1)=new mago("Ilya",new magia(atrs[1],150),new robe(atrs[0],30),550);
	enemies.at(2)=new lancero("Aran",new lanza(atrs[2],100),new pesada(atrs[2],160),1000);
	enemies.at(3)=new mago("Lugh",new magia(atrs[5],130),new robe(atrs[5],130),1000);
	enemies.at(4)=new lancero("Raiden",new lanza(atrs[3],190),new pesada(atrs[1],240),1800);
	enemies.at(5)=new espadachin("Jean",new espada(atrs[5],170),new ligera(atrs[5],200),2600);
	ClearScreen(y,x);
	/*int ch;
	while((ch=getch())!=27){
		move(10,10);
		printw("Keycode: %d     ",ch);
		move(0,0);
		printw("Letra: ");
		refresh();
	}*/

	for(int i=0;i<enemies.size();i++){
		ClearScreen(y,x);
		printPJ(enemies[i],y,x);
		press();
	}
	move(0,0);
	ClearScreen(y,x);
	weap=new espada(atrs[4],100);
	arm=new ligera(atrs[0],60);
	pj=new espadachin("Shie",weap,arm,650);
	mvprintw(y/2-3,x/2-65,"Shie, 18 years old, is a master of the sword and a princess; Daughter of the missing king of the Baste kingdom, Marcus III.");
	mvprintw(y/2-2,x/2-65,"After hearing of the sudden disappearance of her father, she took the sacred royal blade of light, Darkbane, and set out to find the king");
	mvprintw(y/2-1,x/2-65,"This is her story, as she fights fierce warriors and discovers crushing revelations along her journey to find her father");
	mvprintw(y/2,x/2-65,"With no fear of what awaits her, she sets out to the town of Tir, where rumours say the king was last sighted");
	press();
	ClearScreen(y,x);
	mvprintw(y/2,x/2-20,"Chapter 1: Cross-road Encounter");
	press();
	endwin();
	for(int i=0;i<enemies.size();i++){
		delete enemies[i];
	}	
	delete pj;
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
	if(pj->getName().compare("Shie")==0){
		mvprintw(y/2-22,x/2-10,"Informacion del personaje:");
		mvprintw(y/2-20,x/2-10,pj->toString().c_str());
		mvprintw(y/2-19,x/2-9,pj->getWeapon()->toString().c_str());
		mvprintw(y/2-18,x/2-9,pj->getArmor()->toString().c_str());
		mvprintw(y/2-16,x/2-10,"      O");
		mvprintw(y/2-15,x/2-10,"      |");
		mvprintw(y/2-14,x/2-10,"O{XXX}<>============> ");
		mvprintw(y/2-13,x/2-10,"      |");
		mvprintw(y/2-12,x/2-10,"      O");
	}else{
		mvprintw(y/2,x/2-10,"Informacion del Enemigo:");
                mvprintw(y/2+1,x/2-10,pj->toString().c_str());
                mvprintw(y/2+2,x/2-9,pj->getWeapon()->toString().c_str());
                mvprintw(y/2+3,x/2-9,pj->getArmor()->toString().c_str());
	}
				 
}

int hit(const soldado* p1,const soldado* p2){
	int chance;
	if(typeid(*p1)==typeid(espadachin)){
		chance=105;
	}else if(typeid(*p1)==typeid(mago)){
		chance=95;
	}else{
		chance=90;
	}
	if(p1->getWeapon()->getCurrDur()>0&&p2->getArmor()->getCurrDur()>0){
	
		if(typeid(*p2)==typeid(espadachin)){
       	        	chance-=20;
		}else if(typeid(*p1)==typeid(mago)){
       	        	chance-=10;
       	 	}else{
                	chance+=5;
        	}
	
		if(p2->getArmor()->getAtribute().compare("Electricity")==0){
			chance-=20;
		}
		return chance;
	}else if(p1->getWeapon()->getCurrDur()<=0&&p2->getArmor()->getCurrDur()>0){
		return 0;
	}else if(p1->getWeapon()->getCurrDur()>0&&p2->getArmor()->getCurrDur()<=0){
		return chance;	
	}
}

void press(){
	int getkey;
	while((getkey=getch())!=120){
	}
}
