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
int hit(const soldado*,const soldado*);
void heal(soldado*);

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
	enemies.at(0)=new espadachin("Von",new espada(atrs[0],150),new ligera(atrs[0],60),650);
	enemies.at(1)=new mago("Ilya",new magia(atrs[1],200),new robe(atrs[0],60),750);
	enemies.at(2)=new lancero("Aran",new lanza(atrs[2],200),new pesada(atrs[2],170),1200);
	enemies.at(2)->getWeapon()->setDurability(160);
	enemies.at(2)->getArmor()->setDur(200);
	enemies.at(2)->getWeapon()->setCurrDur(160);
        enemies.at(2)->getArmor()->setCurrDur(200);
	enemies.at(3)=new mago("Lugh",new magia(atrs[5],200),new robe(atrs[5],130),1000);
	enemies.at(4)=new lancero("Raiden",new lanza(atrs[3],320),new pesada(atrs[1],270),2000);
	enemies.at(4)->getWeapon()->setDurability(200);
        enemies.at(4)->getArmor()->setDur(200);
	enemies.at(4)->getWeapon()->setCurrDur(200);
        enemies.at(4)->getArmor()->setCurrDur(200);
	enemies.at(5)=new espadachin("Jean",new espada(atrs[5],450),new ligera(atrs[5],300),3000);
	enemies.at(5)->getWeapon()->setDurability(500);
        enemies.at(5)->getArmor()->setDur(500);
	enemies.at(5)->getWeapon()->setCurrDur(500);
        enemies.at(5)->getArmor()->setCurrDur(500);
	ClearScreen(y,x);
	/*int ch;
	while((ch=getch())!=27){
		move(10,10);
		printw("Keycode: %d     ",ch);
		move(0,0);
		printw("Letra: ");
		refresh();
	}*/

	/*for(int i=0;i<enemies.size();i++){
		ClearScreen(y,x);
		printPJ(enemies[i],y,x);
		press();
	}*/
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
	int turno=1;
	ClearScreen(y,x);
	mvprintw(0,0,"Chapter 1");
	printPJ(pj,y,x);
        printPJ(enemies.at(0),y,x);
	press();
	int vs=0;
	while(/*pj->isAlive()&&enemies.at(vs)->isAlive()*/ true){
		ClearScreen(y,x);
		if(turno==1){
			if(pj->isFrozen()){
				pj->Freeze(false);
			}else{
				int h=hit(pj,enemies.at(vs));
				if(pj->atacar(enemies.at(vs),h)){
					printPJ(pj,y,x);
					printPJ(enemies.at(vs),y,x);
				}else{
					mvprintw(y/2,x/2,"Miss!!!");
				}
			}
			turno=2;
		}else if(turno==2){
			int h=hit(enemies.at(vs),pj);
			if(enemies.at(vs)->atacar(pj,h)){
                                printPJ(pj,y,x);
                                printPJ(enemies.at(vs),y,x);
                        }else{
                                mvprintw(y/2,x/2,"Miss!!!");
                        }
			turno=1;
		}
		press();
		ClearScreen(y,x);
		mvprintw(0,0,"Status:");
		pj->state();
		enemies.at(vs)->state();
		if(pj->isFrozen()){
			mvprintw(1,0,"Shie is frozen! Your next turn will be skipped!");
		}
		if(enemies.at(vs)->isFrozen()){
			mvprintw(2,0,"%s is frozen! %s's next turn will be skipped!",enemies.at(vs)->getName(),enemies.at(vs)->getName());
		}
		if(pj->isBurned()){
			mvprintw(3,0,"Shie is burned! You receive %f damage!",pj->getHP()*0.05);
		}
		if(enemies.at(vs)->isBurned()){
			mvprintw(4,0,"%s is burned! %s receives %f damage!",enemies.at(vs)->getName(),enemies.at(vs)->getName(),enemies.at(vs)->getHP()*0.05);
		}
		/*if(pj->getWeapon()->getAtribute().compare("Light")==0&&pj->getCurrHP>0){
			mvprintw(5,0,"Shie heals %f thanks to her Darkbane!",pj->getHP*0.05);
		}*/
		printPJ(pj,y,x);
                printPJ(enemies.at(vs),y,x);
		press();
		if(pj->isAlive()&&!enemies.at(vs)->isAlive()){
			if(vs<5){
				vs++;
				turno=1;
			}else{
				break;
			}
			pj->setHP(pj->getHP()+200);
			pj->getWeapon()->setDamage(pj->getWeapon()->getDamage()+50);
			pj->getWeapon()->setDurability(pj->getWeapon()->getDurability()+20);
			pj->getArmor()->setDefense(pj->getArmor()->getDefense()+5);
			pj->getArmor()->setDur(pj->getArmor()->getDur()+20);
			heal(pj);
			ClearScreen(y,x);
			if(vs==1){
				mvprintw(y/2,x/2,"Chapter 2: Intervention");
			}else if(vs==2){
				mvprintw(y/2,x/2,"Chapter 3: Honor, Death, Glory");
			}else if(vs==3){
				mvprintw(y/2,x/2,"Chapter 4: Evil Omen");
			}else if(vs==4){
				pj->getArmor()->setAtribute(atrs[4]);
				mvprintw(y/2,x/2,"Chapter 5: Revelations");
			}else if(vs==5){
				mvprintw(y/2,x/2,"Final Chapter - Vengeance");
			}else{
				break;
			}
                        press();
			
		}else if(!pj->isAlive()){
			break;
		}
	}
	ClearScreen(y,x);
	if(pj->isAlive()){
		mvprintw(y/2-3,x/2-65,"Shie: Die, Brother! May God have mercy on your soul!  ");
		press();
 	        mvprintw(y/2-2,x/2-65,"Jean: You fool, You would...throw away my efforts...for perfection...");
		press();
        	mvprintw(y/2,x/2-65,"As Jean gave his last breath, he fell to the ground; his last moments spent hating his sister until the very moment he died");
		press();
       		mvprintw(y/2+1,x/2-65,"With Jean's plan faltered and his powers gone, the magical cage of the king was broken");
		press();
		ClearScreen(y,x);
		mvprintw(y/2-3,x/2-65,"King Marcus III: Oh, Shie, my daughter...");
		press();
		mvprintw(y/2-2,x/2-65,"Shie: Don't talk father, keep your self together!");
		press();
		mvprintw(y/2-1,x/2-65,"King Marcus III: You've become...such a fine woman...and a master of the sword...");
		press();
		mvprintw(y/2,x/2-65,"Shie: Father, please! You mustn't speak, I will get you out of here...please, dont leave me!");
		press();
		ClearScreen(y,x);
		mvprintw(y/2-3,x/2-65,"King Marcus III: Take your...rightful place, as queen...know...that I will always...love...");
		press();
		mvprintw(y/2-1,x/2-65,"And so, the last of the king's remaining strength left him; His eyes closed, yet a smile remained on his face");
		mvprintw(y/2,x/2-65,"Shie: Father...I love you too...");
		press();
		ClearScreen(y,x); 
		mvprintw(y/2-3,x/2-65,"From that day forth, tales were told of Queen Shie and her crusade;");
		mvprintw(y/2-2,x/2-65,"Tales of how she saved the kingdom from the revival of the demons.");
		mvprintw(y/2-1,x/2-65,"Some say that, to this day, the Queen wanders the kingdom of Baste");
		mvprintw(y/2,x/2-65,"in search of any who wish to repeat such an atrocity, in hopes of defeating them");
		mvprintw(y/2+1,x/2-65,"So that no one goes through the pain she suffered that ill-fated day...");
		press();
		
	}else{
		mvprintw(y/2,x/2,"GAME OVER");
	}
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
                mvprintw(y/2+2,x/2-10,pj->toString().c_str());
                mvprintw(y/2+3,x/2-9,pj->getWeapon()->toString().c_str());
                mvprintw(y/2+4,x/2-9,pj->getArmor()->toString().c_str());
		if(typeid(*pj)==typeid(espadachin)){
			
		}else if(typeid(*pj)==typeid(mago)){

		}else if(typeid(*pj)==typeid(lancero)){

		}
	}
				 
}

void heal(soldado* pj){
	pj->setCurrHP(pj->getHP());
	pj->getWeapon()->setCurrDur(pj->getWeapon()->getDurability());
	pj->getArmor()->setCurrDur(pj->getArmor()->getDur());
	pj->Freeze(false);
	pj->Burn(false);
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
