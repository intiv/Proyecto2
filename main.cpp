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
#include "item.h"
#include "potion.h"
#include "powder.h"
#include "elixir.h"
#include<cstring>
#include<ncurses.h>
#include<sstream>
#include<typeinfo>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<iostream>
#include<fstream>

using std::ofstream;
using std::ifstream;
using std::string;
using std::stringstream;
using std::vector;
using std::stoi;

void ClearScreen(int&,int&);
void printPJ(soldado*,int&,int&);
void press();
void heal(soldado*);
int menu();
int chartoint(int);
void printcity(int);
void pueblo(int&,int&,soldado*,int,vector<item*>&,int*);
bool FileExists(const char*);
void save(int,int*,int,int);

int main(int argc, char* argv[]){
	initscr();	
	int x,y,weapUps=0,armorUps=0;
	int vs=0;
	bool play=true;
	vector<soldado*> enemies(6);
	vector<item*> shop;
	int datosShop[7]={0,0,0,0,0,0,0};
	int cont=0;
	const string atrs[6]={"N/A","Fire","Ice","Electricity","Light","Dark"};
	soldado* pj=0;
	arma* weap=0;
	armadura* arm=0;
	weap=new espada(atrs[4],120);
	weap->setDurability(200);
	arm=new ligera(atrs[0],60);
	pj=new espadachin("Shie",weap,arm,650);
	enemies.at(0)=new espadachin("Von",new espada(atrs[0],150),new ligera(atrs[0],60),650);
	enemies.at(1)=new mago("Ilya",new magia(atrs[1],200),new robe(atrs[0],60),800);
	enemies.at(2)=new lancero("Aran",new lanza(atrs[2],220),new pesada(atrs[2],150),1600);
	enemies.at(2)->getWeapon()->setDurability(160);
	enemies.at(2)->getArmor()->setDur(200);
	enemies.at(2)->getWeapon()->setCurrDur(160);
        enemies.at(2)->getArmor()->setCurrDur(200);
	enemies.at(3)=new mago("Lugh",new magia(atrs[5],200),new robe(atrs[5],110),1700);
	enemies.at(4)=new lancero("Raiden",new lanza(atrs[3],430),new pesada(atrs[1],280),2500);
	enemies.at(4)->getWeapon()->setDurability(200);
        enemies.at(4)->getArmor()->setDur(200);
	enemies.at(4)->getWeapon()->setCurrDur(200);
        enemies.at(4)->getArmor()->setCurrDur(200);
	enemies.at(5)=new espadachin("Jean",new espada(atrs[5],400),new ligera(atrs[5],320),3000);
	enemies.at(5)->getWeapon()->setDurability(500);
        enemies.at(5)->getArmor()->setDur(500);
	enemies.at(5)->getWeapon()->setCurrDur(500);
        enemies.at(5)->getArmor()->setCurrDur(500);
	if(FileExists("Shop.txt")){
	}
	noecho();
	curs_set(0);
	getmaxyx(stdscr,y,x);
	start_color();
	init_color(COLOR_YELLOW,555,455,0);
	init_color(COLOR_CYAN,700,700,50);
	init_color(COLOR_WHITE,1000,1000,1000);
	init_color(COLOR_BLACK,100,100,100);
	init_color(COLOR_MAGENTA,300,300,300);
	init_pair(1,COLOR_YELLOW,COLOR_BLACK);
	init_pair(2,COLOR_WHITE,COLOR_BLACK);
	init_pair(3,COLOR_BLUE,COLOR_BLACK);
	init_pair(4,COLOR_RED,COLOR_BLACK);
	init_pair(5,COLOR_CYAN,COLOR_BLACK);
	init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
	init_pair(7,COLOR_GREEN,COLOR_BLACK);
	attron(COLOR_PAIR(2));
	if(x<165||y<40){
		while(x<165||y<40){
			mvprintw(0,0,"!!!Please expand your game window to get the full experience!!!");
			mvprintw(1,0,"!!!and avoid problems with the game's text!!!");
			mvprintw(2,0,"Once you have made the window bigger:");
			mvprintw(3,0,"      press X to continue");
			press();
			getmaxyx(stdscr,y,x);
		}
	}
	if(!has_colors()){
		ClearScreen(y,x);
		mvprintw(y/2-20,x/2-25,"Your terminal does not support colors, you will not be able to live the game's full experience");	
		press();
	}
	ClearScreen(y,x);
	vector<string> datos;
	while(true){	
		ClearScreen(y,x);
		attron(COLOR_PAIR(1));
		mvprintw(y/2-6,x/2-30,"^^^^^^^^^^^^^^^^^^^^");
		mvprintw(y/2-5,x/2-30,"& ~ Crystal Oath ~ &");
		mvprintw(y/2-4,x/2-30,"&   ------------   &");
		mvprintw(y/2-3,x/2-30,"& 1.- New Game     &");
		mvprintw(y/2-2,x/2-30,"& 2.- Load Game    &");
		mvprintw(y/2-1,x/2-30,"& 3.- Quit         &");
		mvprintw(y/2,x/2-30,"^^^^^^^^^^^^^^^^^^^^");
		attroff(COLOR_PAIR(1));
		int mainm=getch();
		if(mainm==49){
			ofstream salida;
			if(FileExists("Datos.txt")){
				salida.open("Datos.txt",std::ios::out|std::ios::trunc);
				salida<<"No,200,0,0,0";
				salida.close();
			}
			if(FileExists("Shop.txt")){
				salida.open("Shop.txt",std::ios::out|std::ios::trunc);
				salida<<"0,0,0,0,0,0,0";
				salida.close();
			}
			for(int j=0;j<7;j++){
				datosShop[j]=0;
			}
			vs=0;
			
			break;
		}else if(mainm==50){
			if(FileExists("Datos.txt")){
				datos.clear();
				ifstream reader("Datos.txt");
				string line;
				getline(reader,line);
				stringstream ss(line);
				while(ss.good()){
					string sub;
					getline(ss,sub,',');
					datos.push_back(sub);
				}
				reader.close();
			}
			if(datos.size()>0){	
				if(datos.at(0)=="Si"){
					if(FileExists("Shop.txt")){
						ifstream reader("Shop.txt");
						string line;
						getline(reader,line);
						stringstream ss(line);
						while(ss.good()){
							string sub;
							getline(ss,sub,',');
							datosShop[cont]=stoi(sub,NULL,0);
							cont++;
						}
						reader.close();
					}
					vs=stoi(datos.at(1),NULL,0);
					pj->earn(stoi(datos.at(2),NULL,0)-200);
					weapUps=stoi(datos.at(3),NULL,0);
					armorUps=stoi(datos.at(4),NULL,0);
					for(int i=0;i<weapUps;i++){
						pj->getWeapon()->upgrade();
						pj->getWeapon()->setDamage(pj->getWeapon()->getDamage()+35);
						pj->getWeapon()->setDurability(pj->getWeapon()->getDurability()+35);
					}
					for(int j=0;j<armorUps;j++){
						pj->getArmor()->upgrade();
						pj->getArmor()->setDefense(pj->getArmor()->getDefense()+25);
						pj->getArmor()->setDur(pj->getArmor()->getDur()+25);
					}
					pj->getWeapon()->setCurrDur(pj->getWeapon()->getDurability());
					pj->getArmor()->setCurrDur(pj->getArmor()->getDur());
					pj->setHP(pj->getHP()+vs*200);
					pj->setCurrHP(pj->getHP());
					ClearScreen(y,x);
					mvprintw(y/2-3,x/2-30,"Game loaded succesfully!");
					press();
					break;
				}else{
					break;
				}
			}else{
				mvprintw(y/2-3,x/2-30,"Something went wrong while loading the game!");
				press(); 
				break;
			}
		}else if(mainm==51){
			ClearScreen(y,x);
			mvprintw(y/2,x/2,"Thanks for playing!");
			getch();
			for(int i=0;i<enemies.size();i++){
				delete enemies[i];
			}
			delete pj;
			erase();
			echo();
			return 0;
		}
	}
	if(datosShop[0]==0)
		shop.push_back(new potion(150));
	else
		pj->addItem(new potion(150));
	if(datosShop[1]==0)
		shop.push_back(new potion(150));
	else
		pj->addItem(new potion(150));
	if(datosShop[2]==0)	
		shop.push_back(new potion(150));
	else
		pj->addItem(new potion(150));
	if(datosShop[3]==0)
		shop.push_back(new powder(200));
	else
		pj->addItem(new powder(200));

	if(datosShop[4]==0)
		shop.push_back(new powder(200));
	else
		pj->addItem(new powder(200));
	
	if(datosShop[5]==0)
		shop.push_back(new elixir(500));
	else
		pj->addItem(new elixir(500));

	if(datosShop[6]==0)
		shop.push_back(new elixir(500));
	else
		pj->addItem(new elixir(500));
	/*short int r,g,b;
	color_content(3,&r,&g,&b);
	mvprintw(0,0,"Rojo: %d, verde: %d, azul: %d",r,g,b);
	press();*/
	/*int ch;
	while((ch=getch())!=27){
		move(1,1);
		printw("Keycode: %d     ",ch);
		move(0,0);
		printw("Letra: %c",ch);
		refresh();
	}*/

	/*for(int i=0;i<enemies.size();i++){
		ClearScreen(y,x);
		printPJ(enemies[i],y,x);
		press();
	}*/
	move(0,0);
	ClearScreen(y,x);
	if(vs==0){
	mvprintw(y/2-3,x/2-65,"Shie, 18 years old, is a master of the sword and a princess; Daughter of the missing king of the Baste kingdom, Marcus III.");
	mvprintw(y/2-2,x/2-65,"After hearing of the sudden disappearance of her father, she took the sacred royal blade of light, Darkbane, and set out to find the king");
	mvprintw(y/2-1,x/2-65,"This is her story, as she fights fierce warriors and discovers crushing revelations along her journey to find her father");
	mvprintw(y/2,x/2-65,"With no fear of what awaits her, she sets out to the town of Tir, where rumours say the king was last sighted");
	press();
	ClearScreen(y,x);
	mvprintw(y/2-3,x/2-20,"~Chapter 1: Cross-road Encounter~");
	mvprintw(y/2-2,x/2-20,"---------------------------------");
	press();
	mvprintw(y/2,x/2-40,"Shie: I've asked all around, but it seems as though no one knows about my father...");
	press();
	mvprintw(y/2+2,x/2-40,"Mysterious man: I know where your father, the king, is.");
	press();
	mvprintw(y/2+4,x/2-40,"Shie: Really!? Where? I must go to him immediately!");
	press();
	mvprintw(y/2+6,x/2-40,"Mysterious man: Oh, don't worry...You'll both be reunited soon enough...IN THE AFTER LIFE!");
	press();
	ClearScreen(y,x);
	mvprintw(y/2-3,x/2-20,"~Chapter 1: Cross-road Encounter~");
	mvprintw(y/2-2,x/2-20,"---------------------------------");
	mvprintw(y/2,x/2-40,"Shie: What!? Who are you!?");
	press();
	mvprintw(y/2+2,x/2-40,"Mysterious man: My name is Von, I'm an assassin sent to kill you, oh pitiful princess!");
	press();
	mvprintw(y/2+4,x/2-40,"Shie: We'll see about that! En garde!");
	press();
	}
	attroff(COLOR_PAIR(2));
	int turno=1;
	ClearScreen(y,x);
	mvprintw(0,0,"Chapter 1");
	printPJ(pj,y,x);
        printPJ(enemies.at(vs),y,x);
	pj->addItem(new potion(100));
	while(play){
		ClearScreen(y,x);
		mvprintw(13,0,"<Status>");
		mvprintw(14,0," ------ ");
		if(pj->isFrozen()){
			mvprintw(15,0,"-Shie is frozen! You can't take any action this turn");
		}
		if(enemies.at(vs)->isFrozen()){
			mvprintw(16,0,"-%s is frozen! %s's turn will be skipped!",enemies.at(vs)->getName(),enemies.at(vs)->getName());
		}
		if(vs==0){
			mvprintw(0,40,"Tip - Menu options: Attack deals damage to enemy based on several factors. Inventory lets you use items if you have any");
		}else if(vs==1){
			mvprintw(0,40,"Tip - Mages deal alot of damage, Plus fire weapons can burn your extra damage. Heal often and defeat your enemy quickly!");
		}else if(vs==2){
			mvprintw(0,40,"Tip - Halberdiers have high defense but have low damage and hit chance. Make sure to keep an eye on your equipment's durability");
		}else if(vs==3){
			mvprintw(0,40,"Tip - Dark weapons deal huge amounts of damage and heal the enemy for half the damage dealt. Defeat your enemy quickly!");
		}else if(vs==4){
			mvprintw(0,40,"Tip - Electric weapons can reduce your equipment's durability. Use powders or elixirs to repair them!");
		}else if(vs==5){
			mvprintw(0,40,"Tip - This is your final fight! Use everything you've learned in your past battles and use any items you may need. Don't hold anything back!");
		}	
		printcity(vs);
		if(turno==1){
			if(pj->isFrozen()){
				pj->Freeze(false);
				printPJ(pj,y,x);
                                printPJ(enemies.at(vs),y,x);
				press();
			}else{
				printPJ(pj,y,x);
				printPJ(enemies.at(vs),y,x);
				printcity(vs);
				bool opValida=false;
				while(!opValida){
					int m=menu();
					if(m==50){
						ClearScreen(y,x);
						if(pj->invSize()>0){
							printPJ(pj,y,x);
							printPJ(enemies.at(vs),y,x);
							mvprintw(4,0,"Inventory: ");
							mvprintw(5,0,"----------");		
							for(int i=0;i<pj->invSize();i++){
								mvprintw(6+i,0,"%d.- %s",i,pj->getInv().at(i)->toString(0).c_str());
							}
							mvprintw(6+pj->invSize(),0,"%d.- Cancel",pj->invSize());
							bool itemValido=false;
							while(!itemValido){
								int index=getch();
								if(index>=48&&index<=(47+pj->invSize())){
									pj->getInv().at(chartoint(index))->function(pj);
									itemValido=true;
									opValida=true;
								}else if(index==48+pj->invSize()){
									ClearScreen(y,x);
									printPJ(pj,y,x);
									printPJ(enemies.at(vs),y,x);
									itemValido=true;
								}
							}
						}else{
							mvprintw(y/2-3,x/2-40,"You have no items!");
							press();
						}
					}else if(m==49){
						if(pj->atacar(enemies.at(vs),100)){
							printPJ(pj,y,x);
							printPJ(enemies.at(vs),y,x);
						}else{
							mvprintw(y/2,x/2,"Miss!!!");
						}
						opValida=true;
					}
				}
				turno=2;
			}
		}else if(turno==2){
			//if(enemies.at(vs)->getCurrHP()>=enemies.at(vs)->getHP()*0.5||enemies.at(vs)->invSize()==0){
				if(enemies.at(vs)->atacar(pj,100)){
                               		printPJ(pj,y,x);
                                	printPJ(enemies.at(vs),y,x);
                        	}else{
                       	        	mvprintw(y/2,x/2,"Miss!!!");
                       		}
			//}else{

		//	}
			turno=1;
		}
		ClearScreen(y,x);
		mvprintw(13,0,"<Status>");
		mvprintw(14,0," ------ ");
		if(enemies.at(vs)->getCurrHP()>0){
			pj->state();
		}
		if(pj->getCurrHP()>0){
			enemies.at(vs)->state();
		}
		printcity(vs);
		if(pj->isFrozen()){
			mvprintw(17,0,"-Shie is frozen! Your next turn will be skipped!");
		}
		if(enemies.at(vs)->isFrozen()){
			mvprintw(18,0,"-%s is frozen! %s's next turn will be skipped!",enemies.at(vs)->getName(),enemies.at(vs)->getName());
		}
		if(pj->isBurned()){
			mvprintw(19,0,"-Shie is burned! You receive %0.2f damage!",pj->getHP()*0.05);
		}
		if(enemies.at(vs)->isBurned()){
			mvprintw(20,0,"-%s is burned! %s receives %0.2f damage!",enemies.at(vs)->getName(),enemies.at(vs)->getName(),enemies.at(vs)->getHP()*0.05);
		}
		if(pj->getWeapon()->getAtribute().compare("Light")==0&&pj->getCurrHP()>0){
			mvprintw(15,0,"Shie heals %0.2f thanks to her Darkbane!",pj->getHP()*0.03);
		}
		if(pj->getArmor()->getAtribute()=="Light"&&pj->getCurrHP()>0){
			mvprintw(16,0,"Shie heals %0.2f thanks to her Blessed Armor!",pj->getHP()*0.03);
		}
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
			pj->getWeapon()->setDamage(pj->getWeapon()->getDamage()+20);
			pj->Burn(false);
			ClearScreen(y,x);
			mvprintw(y/2-3,x/2-30,"Level up! Max HP + 200, Attack + 20!");
			press();
			attron(COLOR_PAIR(2));
			if(vs==1){
				pj->earn(500);
				mvprintw(y/2,x/2-40,"Shie: *pant* Who sent you to kill me!? Where is my father!?");
				press();
				mvprintw(y/2+2,x/2-40,"Von: Heh, you fool...Lord Raiden will have..your head...");
				press();
				mvprintw(y/2+4,x/2-40,"Shie: Did...did you just say Raiden? As in Sir Raiden, personal knight of the king?");
				press();
				mvprintw(y/2+6,x/2-40,"Von: You really are...just a dumb girl. You don't know...what you are facing...ungh!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2,x/2-40,"Shie: Wait, don't die! Tell me where my father is!");
				press();
				mvprintw(y/2+2,x/2-40,"Von: ...");
				press();
				mvprintw(y/2+3,x/2-40,"*An old lady approached the princess, trying to comfort the confused girl*");
				mvprintw(y/2+4,x/2-40,"Old lady: Young girl, you really are the princess right? You should come with me, i'm this town's elder");
				press();
				mvprintw(y/2+6,x/2-40,"Shie: ...Very well, I shall go with you");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 2: Intervention~");
				mvprintw(y/2-2,x/2-20,"-------------------------");
				mvprintw(y/2,x/2-40,"*At the old lady's house*");
				mvprintw(y/2+2,x/2-40,"Old lady: I heard what that man said, I'm afraid it's true...");
				press();
				mvprintw(y/2+4,x/2-40,"Shie: He mentioned the holy knight Sir Raiden, my father's personal guard");
				press();
				mvprintw(y/2+6,x/2-40,"Old lady: Yes, he did. I had heard rumors of him betraying the kingdom, so I hired this spy to get information");
				mvprintw(y/2+7,x/2-40,"Old lady: It seems it is true. Many say he killed many soldiers to kidnap the king");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 2: Intervention~");
				mvprintw(y/2-2,x/2-20,"-------------------------");
				mvprintw(y/2,x/2-40,"Shie: That can't be! Sir Raiden is an excellent knight and a man my father trusted very much!");
				mvprintw(y/2+2,x/2-40,"Shie: Plus, had that happened, it would be known through out all of Baste");
				press();
				mvprintw(y/2+4,x/2-40,"Spy: It's all true. The senate is doing their best to keep this a secret, only saying the king disappeared");
				press();
				mvprintw(y/2+6,x/2-40,"Shie: What should I do...");
				press();
				ClearScreen(y,x);	
				mvprintw(y/2-3,x/2-20,"~Chapter 2: Intervention~");
				mvprintw(y/2-2,x/2-20,"-------------------------");
				mvprintw(y/2,x/2-40,"Spy: Go to the White Forest, someone awaits you there.");
				press();
				pueblo(y,x,pj,vs,shop,datosShop);
				mvprintw(y/2+2,x/2-40,"And so, Shie set out for the White Forest, a huge maze of enchanted trees");
				mvprintw(y/2+3,x/2-40,"There, she found a fire mage who seemed like she had been meditating; as though waiting for someone");
				mvprintw(y/2+4,x/2-40,"Unfortunately, upon seeing Shie, the mage attacked without giving her a chance to even speak!");
				press();
			}else if(vs==2){
				pj->earn(900);
				mvprintw(y/2,x/2-40,"Mage: Enough! You have proven yourself. I am an ally of king Marcus!");
				press();
				mvprintw(y/2+2,x/2-40,"Shie: Huh? How can I know you are saying the truth?");
				press();
				mvprintw(y/2+4,x/2-40,"Mage: My name is Ilya, you might remember me. I used to take care of you when you were little");
				press();
				mvprintw(y/2+6,x/2-40,"Shie: It can't be, Aunt Ilya? You're still alive! I haven't seen you in years!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"Chapter 3: Honor, Death, Glory");
				mvprintw(y/2-2,x/2-20,"------------------------------");
				press();
				mvprintw(y/2,x/2-40,"Ilya: It's good to see you are well, unfortunately we don't have time to dawdle on our reunion");
				mvprintw(y/2+1,x/2-40,"Ilya: I'm sure you've heard, the king was kidnapped by Raiden. I know where they are.");
				mvprintw(y/2+2,x/2-40,"Ilya: He is being held captive in an abandoned tower to the north.");
				press();
				mvprintw(y/2+4,x/2-40,"Shie: Then we must waste no time! We must go there immediately!");
				press();
				mvprintw(y/2+6,x/2-40,"Ilya: Not so fast, I saw Raiden with a young man who was enveloped in dark magic");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"Chapter 3: Honor, Death, Glory");
				mvprintw(y/2-2,x/2-20,"------------------------------");
				mvprintw(y/2,x/2-40,"Ilya: Your sword, Darkbane, would help you; but it is not enough");
				press();
				mvprintw(y/2+2,x/2-40,"Shie: So what do we do?");
				press();
				mvprintw(y/2+4,x/2-40,"Ilya: We shall go to the Holy Cathedral of Krast, I'm sure Great Priest Owain can help us");
				press();
				mvprintw(y/2+6,x/2-40,"Shie: Very well, let's split up to not risk getting caught. We'll meet at the cathedral!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 3: Honor, Death, Glory~");
				mvprintw(y/2-2,x/2-20,"--------------------------------");
				mvprintw(y/2,x/2-40,"However, the city of Krast had been ocupied by unknown soldiers, commanded by a tall Halberdier");
				press();
				pueblo(y,x,pj,vs,shop,datosShop);
				mvprintw(y/2-3,x/2-20,"~Chapter 3: Honor, Death, Glory~");
				mvprintw(y/2-2,x/2-20,"--------------------------------");
				mvprintw(y/2+1,x/2-40,"Shie managed to sneak past many soldiers, but was stopped in front of the cathedral by the commander, Aran!");
				press();
				mvprintw(y/2+2,x/2-40,"Aran: I commend you for getting this far, my dear Princess, but your journey ends now!");
				press();
				mvprintw(y/2+4,x/2-40,"Shie: I won't stop until I find my father, no matter who stands in my way!");
				press();
				mvprintw(y/2+6,x/2-40,"Aran: Very well then, let us have a honorable battle! Me and my Ice equipment are undefeated!");
				press();
			}else if(vs==3){
				pj->earn(800);
				mvprintw(y/2,x/2-40,"Aran: Hng! You are a master of the sword...but you are far too late...Priest Owain will be...");
				press();
				mvprintw(y/2+2,x/2-40,"Shie: No, I must save the Priest! Hang on, I'm coming!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 4: Evil Omen~");
				mvprintw(y/2-2,x/2-20,"----------------------");
				press();
				mvprintw(y/2,x/2-40,"Priest Owain: You are not welcome in this cathedral. Begone, evildoers!");
				press();
				mvprintw(y/2+2,x/2-40,"Lugh: Oh, please! your cathedrals mean nothing to a dark mage like me!");
				press();
				mvprintw(y/2+4,x/2-40,"Priest Owain: May God forgive your sins on the day of your death, lost soul");
				press();
				mvprintw(y/2+6,x/2-40,"Lugh: you bastard! How dare you curse me like that, I will kill you before you can bless the princess!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 4: Evil Omen~");
				mvprintw(y/2-2,x/2-20,"----------------------");
				mvprintw(y/2,x/2-40,"Shie: Not so fast! I won't allow you to harm the priest!");
				press();
				mvprintw(y/2+2,x/2-40,"Ilya: Shie! I arrived just in time, I will keep the soldiers busy.");
				mvprintw(y/2+4,x/2-40,"Ilya: Use your blade to defeat that dark mage!");
				press();
				mvprintw(y/2+6,x/2-40,"Shie: Yes, I'll defeat you with my holy blade, Darkbane!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 4: Evil Omen~");
				mvprintw(y/2-2,x/2-20,"----------------------");
				mvprintw(y/2,x/2-40,"Lugh: Disgusting, how can you rely on such weak magic as Light! I'll show you true power!");
				press();
				heal(pj);
				mvprintw(y/2+2,x/2-40,"Priest Owain: Princess! I have healed you and blessed your equipment, it should be as good as new!");
				press();
				mvprintw(y/2+4,x/2-40,"Shie: Thank you Great Priest, I shall use your blessing to defeat these malicious magician!");
				press();
			}else if(vs==4){
				pj->earn(1000);
				mvprintw(y/2,x/2-40,"Lugh: Damn your light magic...DAMN YOU PRINCESS!!");
				press();
				mvprintw(y/2+2,x/2-40,"Shie: Repent and pray, Maybe then God will have mercy on your soul!");
				press();
				mvprintw(y/2+4,x/2-40,"A strong light came out from Darkbane as Shie spoke those words");
				mvprintw(y/2+6,x/2-40,"With this new power, she struck down the dark mage who burned to death when hit by the holy light");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 5: Revelations~");
				mvprintw(y/2-2,x/2-20,"------------------------");
				press();
				mvprintw(y/2,x/2-40,"Priest Owain: Thanks for saving this cathedral. I have heard of your journey to find the king.");
				mvprintw(y/2+2,x/2-40,"Priest Owain: I shall bless your armor so you can fight these heathens who embrace Darkness");
				press();
				mvprintw(y/2+4,x/2-40,"The priest began channeling holy power, using his magic he blessed Shie's armor");
				mvprintw(y/2+6,x/2-40,"As the holy light embraced Shie, her armor transformed into Armor of Light!");
				mvprintw(y/2+7,x/2-40,"This new armor has the same healing effect as Darkbane and better defense/durability!");
				pj->getArmor()->setAtribute(atrs[4]);
				pj->getArmor()->setDefense(pj->getArmor()->getDefense()+50);
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 5: Revelations~");
				mvprintw(y/2-2,x/2-20,"------------------------");
				mvprintw(y/2,x/2-40,"Shie: Thank you, Priest. I shall use this power to rescue my father!");
				press();
				mvprintw(y/2+2,x/2-40,"Ilya: Very well! We can now fight Raiden and res---");
				mvprintw(y/2+4,x/2-40,"Ilya was violently interrupted, as she was stabbed from behind by a Spear infused with electric magic");
				mvprintw(y/2+6,x/2-40,"Raiden: Were you talking about me? Why, I'm honored!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 5: Revelations~");
				mvprintw(y/2-2,x/2-20,"------------------------");
				mvprintw(y/2,x/2-40,"Shie: Aunt Ilya, NOOOOO!!!");
				mvprintw(y/2+2,x/2-40,"Her aunt fell to her death, as the man who killed her was revealed behind her. It was Raiden!");
				press();
				mvprintw(y/2+4,x/2-40,"Raiden: This is a formal invitation to you, My Princess. From your beloved brother, Jean!");
				press();
				mvprintw(y/2+6,x/2-40,"Shie: Did you just say Jean!? That's impossible, he died when he was 8!");
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 5: Revelations~");
				mvprintw(y/2-2,x/2-20,"------------------------");
				mvprintw(y/2,x/2-40,"Raiden: Believe what you want. Come to Mailfaisance Tower and all your questions shall be answered");
				press();
				mvprintw(y/2+2,x/2-40,"Shie: Wait, please explain yourself! Where is my father!?");
				press();
				mvprintw(y/2+4,x/2-40,"Raiden: Didn't I just tell you? Come, accept our invitation. Jean wishes for a lovely family reunion!");
				press();
				mvprintw(y/2+6,x/2-40,"Before Shie could draw her blade, a thunder fell on Raiden and he disappeared immeadiately");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 5: Revelations~");
				mvprintw(y/2-2,x/2-20,"------------------------");
				mvprintw(y/2,x/2-40,"Shie: I will go. I'm coming, RAIDEN! JEAN!");
				press();
				pueblo(y,x,pj,vs,shop,datosShop);
				mvprintw(y/2+1,x/2-40,"The princess set out for the Mailfaisance Tower");
				mvprintw(y/2+2,x/2-40,"Lots of questions spiraled her mind. Why did Raiden betray the king?");
				mvprintw(y/2+3,x/2-40,"Is her father at the tower? Is he truly alive? But most of all");
				press();
				mvprintw(y/2+4,x/2-40,"The fact that her supposed dead brother was not only alive, but he planned this whole scheme");
				press();
				mvprintw(y/2+6,x/2-40,"Every time she thought about it, it sent chills down her spine...");
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 5: Revelations~");
				mvprintw(y/2-2,x/2-20,"------------------------");
				mvprintw(y/2,x/2-40,"Shie got to the tower. she saw no one guarding the tower; nor did she hear anyone inside it, so she went inside");
				press();
				mvprintw(y/2+2,x/2-40,"Shie: Raiden, I'm here! Come forth and face me, you coward!");
				press();
				mvprintw(y/2+4,x/2-40,"A lightning suddenly struck the ground, and out of thin air, Raiden appeared before the Shie");
				mvprintw(y/2+5,x/2-40,"Raiden: Did you call, dear Princess? I'm glad you accepted our humble request, we're happy to be your hosts!");
				press();
				mvprintw(y/2+6,x/2-40,"Jean: Yes, we really are happy, my sister!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"~Chapter 5: Revelations~");
				mvprintw(y/2-2,x/2-20,"------------------------");
				mvprintw(y/2,x/2-40,"Shie: Brother! So you ARE alive! Where is father, what have you done to him!?");
				press();
				mvprintw(y/2+2,x/2-40,"Jean: Do not worry, he is asleep inside his magic cage in the second floor. You can come see him...");
				mvprintw(y/2+4,x/2-40,"Raiden: ...If you can get through me!");
				press();
				mvprintw(y/2+6,x/2-40,"Shie: Very well! I shall defeat you, traitor!");
				press();
			}else if(vs==5){
				mvprintw(y/2,x/2-40,"As Shie swung the last strike to defeat Raiden, a dark fog came out of his body");
				press();
				mvprintw(y/2+2,x/2-40,"Raiden: Thank you...princess. You released me from my agony...");
				press();
				mvprintw(y/2+4,x/2-40,"Shie: Raiden? It's really you, isn't it!?");
				press();
				mvprintw(y/2+6,x/2-40,"Raiden: Jean cast an evil curse...upone me. He forced me to...take the king to him. Please, save the king...");
				press();
				ClearScreen(y,x);
				mvprintw(y/2,x/2-40,"Shie: No...Raiden, not you too! I knew it couldn't be possible, you're the best knight in Baste!");
				press();
				mvprintw(y/2+2,x/2-40,"She felt Raiden's remaining strength pass to her body, as he turned cold and pale...");
				press();
				mvprintw(y/2+4,x/2-40,"Shie: ...Don't worry, Raiden, I will. I will save father, and I WILL avenge you! Did you hear me, Brother!?");
				mvprintw(y/2+6,x/2-40,"Raiden has entrusted you with his last wish. His remaining power has healed you and repaired your equipment!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-4,x/2-20,"*~~~~~~~~~~~~~~~~~~~~~~~~~*");
				mvprintw(y/2-3,x/2-20,"*~Final Chapter - Freedom~*");
				mvprintw(y/2-2,x/2-20,"*~~~~~~~~~~~~~~~~~~~~~~~~~*");
				press();
				mvprintw(y/2,x/2-40,"Jean: Oh, father. You look so weak, so pathetic, as you always have. But don't worry, soon you will give me infinite power!");
				press();
				mvprintw(y/2+1,x/2-40,"Jean: I will revive the demon tribe and obtain their power! All I need is a bit of my dark magic, your blood, my blood and...");
				press();
				mvprintw(y/2+2,x/2-40,"Shie: My blood, right? *Said Shie, as she enterded the room from the stairs*");
				press();
				mvprintw(y/2+4,x/2-40,"Jean: Ah, yes! The blood of a royal wench! All you care about is you dear, useless father!");
				press();
				mvprintw(y/2+5,x/2-40,"Jean: Can't you see we form part of something bigger!? A prophecy, which says our royal blood can revive powerful demons!");
				press();
				mvprintw(y/2+6,x/2-40,"Shie: I don't care. I don't care about anything you say, you're supposed to be dead!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2,x/2-40,"Shie: And I'll make sure things go back to normal...Prepare yourself, I will give you no mercy!");
				press();
			}else{
				break;
			}
			attroff(COLOR_PAIR(2));
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
		mvprintw(y/2+1,x/2-65,"So that no one goes through the pain she suffered on her journey...");
		press();
		
	}else{
		mvprintw(y/2,x/2,"GAME OVER");
	}
	press();
	endwin();
	
	ofstream salida;
	if(FileExists("Datos.txt")){
		salida.open("Datos.txt",std::ios::out|std::ios::trunc);
		salida<<"No,200,0,0,0";
		salida.close();
	}
	if(FileExists("Shop.txt")){
		salida.open("Shop.txt",std::ios::out|std::ios::trunc);
		salida<<"0,0,0,0,0,0,0";
		salida.close();
	}

	for(int i=0;i<enemies.size();i++){
		delete enemies[i];
	}	
	delete pj;
	return 0;
}

void printcity(int vs){
	if(vs==0){
		mvprintw(0,0,"~ Town of Tir~");
		mvprintw(1,0,"**************");
	}else if(vs==1){
		mvprintw(0,0,"~White Forest~");
		mvprintw(1,0,"**************");
	}else if(vs==2){
		mvprintw(0,0,"~City of Krast~");
		mvprintw(1,0,"***************");
	}else if(vs==3){
		mvprintw(0,0,"~Krast's Great Cathedral~");
		mvprintw(1,0,"*************************");
	}else if(vs==4){
		mvprintw(0,0,"~Mailfaisance Tower~");
		mvprintw(1,0,"********************");
	}else if(vs==5){
		mvprintw(0,0,"~Ritual Chamber~");
		mvprintw(1,0,"****************");
	}
}

void ClearScreen(int& y,int& x){
	for(int i=0;i<y;i++){
		for(int j=0;j<x;j++){
			mvprintw(i,j," ");
		}
	}
	move(0,0);
}


int chartoint(int index){
	switch(index){
		case 48: return 0;
		case 49: return 1;
		case 50: return 2;
		case 51: return 3;
		case 52: return 4;
		case 53: return 5;
		case 54: return 6;
		case 55: return 7;
	}
}
void printPJ(soldado* pj, int& y, int& x){
	if(pj->getName().compare("Shie")==0){
		attron(COLOR_PAIR(2));
		mvprintw(y/2-22,x/2-10,"Character Window:");
		mvprintw(y/2-20,x/2-10,pj->toString().c_str());
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(1));
		mvprintw(y/2-19,x/2-9,pj->getWeapon()->toString().c_str());
		attroff(COLOR_PAIR(1));
		if(pj->getArmor()->getAtribute()=="Light"){
			attron(COLOR_PAIR(1));
		}else{
			attron(COLOR_PAIR(2));
		}
		mvprintw(y/2-18,x/2-9,pj->getArmor()->toString().c_str());
		if(pj->getArmor()->getAtribute()=="Light"){
			attroff(COLOR_PAIR(1));
		}else{
			attroff(COLOR_PAIR(2));
		}
		attron(COLOR_PAIR(1));
		mvprintw(y/2-16,x/2-10,"      O");
		mvprintw(y/2-15,x/2-10,"      |");
		mvprintw(y/2-14,x/2-10,"O{XXX}<>============>");
		mvprintw(y/2-13,x/2-10,"      |");
		mvprintw(y/2-12,x/2-10,"      O");
		attroff(COLOR_PAIR(1));
	}else{
		attron(COLOR_PAIR(2));
		mvprintw(y/2,x/2-10,"Enemy Window:");
		
                mvprintw(y/2+2,x/2-10,pj->toString().c_str());
		attroff(COLOR_PAIR(2));
		if(pj->getWeapon()->getAtribute()=="Ice"){
			attron(COLOR_PAIR(3));
		}else if(pj->getWeapon()->getAtribute()=="Fire"){
			attron(COLOR_PAIR(4));
		}else if(pj->getWeapon()->getAtribute()=="Electricity"){
			attron(COLOR_PAIR(5));
		}else if(pj->getWeapon()->getAtribute()=="Light"){
			attron(COLOR_PAIR(1));
		}else if(pj->getWeapon()->getAtribute()=="Dark"){
			attron(COLOR_PAIR(6));
		}else{
			attron(COLOR_PAIR(2));
		}
                mvprintw(y/2+3,x/2-9,pj->getWeapon()->toString().c_str());
		if(typeid(*pj)==typeid(espadachin)){	
			mvprintw(y/2+6,x/2-9,"             O      ");
			mvprintw(y/2+7,x/2-9,"             |      ");
			mvprintw(y/2+8,x/2-9,"<===========<>{XXX}O");
			mvprintw(y/2+9,x/2-9,"             |      ");
			mvprintw(y/2+10,x/2-9,"             O      ");
		}else if(typeid(*pj)==typeid(mago)){		
			mvprintw(y/2+6,x/2-9," _______________       ");
			mvprintw(y/2+7,x/2-9," |___-----------|      ");
			mvprintw(y/2+8,x/2-9," ||| |  MAGIC   |      ");
			mvprintw(y/2+9,x/2-9," ||| |    /\\    |      ");
			mvprintw(y/2+10,x/2-9," ||| |  --  --  |      ");
			mvprintw(y/2+11,x/2-9," ||| |  \\    /  |      ");
			mvprintw(y/2+12,x/2-9," ||| |   \\  /   |      ");
			mvprintw(y/2+13,x/2-9," ||| |    \\/    |      ");
			mvprintw(y/2+14,x/2-9," ||| |          |      ");
			mvprintw(y/2+15,x/2-9," ----------------      ");
		}else if(typeid(*pj)==typeid(lancero)){
			mvprintw(y/2+6,x/2-9,"                    ");
			mvprintw(y/2+7,x/2-9,"             /\\      ");
			mvprintw(y/2+8,x/2-9,"<O===========()<>");
			mvprintw(y/2+9,x/2-9,"             \\/      ");
			mvprintw(y/2+10,x/2-9,"                    ");
		}
		if(pj->getWeapon()->getAtribute()=="Ice"){
                        attroff(COLOR_PAIR(3));
                }else if(pj->getWeapon()->getAtribute()=="Fire"){
                        attroff(COLOR_PAIR(4));
                }else if(pj->getWeapon()->getAtribute()=="Electricity"){
                        attroff(COLOR_PAIR(5));
                }else if(pj->getWeapon()->getAtribute()=="Light"){
                        attroff(COLOR_PAIR(1));
                }else if(pj->getWeapon()->getAtribute()=="Dark"){
                        attroff(COLOR_PAIR(6));
                }else{
                        attroff(COLOR_PAIR(2));
                }

		if(pj->getArmor()->getAtribute()=="Ice"){
			attron(COLOR_PAIR(3));
		}else if(pj->getArmor()->getAtribute()=="Fire"){
			attron(COLOR_PAIR(4));
		}else if(pj->getArmor()->getAtribute()=="Electricity"){
			attron(COLOR_PAIR(5));
		}else if(pj->getArmor()->getAtribute()=="Light"){
			attron(COLOR_PAIR(1));
		}else if(pj->getArmor()->getAtribute()=="Dark"){
			attron(COLOR_PAIR(6));
		}else{
			attron(COLOR_PAIR(2));
		}
                mvprintw(y/2+4,x/2-9,pj->getArmor()->toString().c_str());
		 if(pj->getArmor()->getAtribute()=="Ice"){
                        attroff(COLOR_PAIR(3));
                }else if(pj->getArmor()->getAtribute()=="Fire"){
                        attroff(COLOR_PAIR(4));
                }else if(pj->getArmor()->getAtribute()=="Electricity"){
                        attroff(COLOR_PAIR(5));
                }else if(pj->getArmor()->getAtribute()=="Light"){
                        attroff(COLOR_PAIR(1));
                }else if(pj->getArmor()->getAtribute()=="Dark"){
                        attroff(COLOR_PAIR(6));
                }else{
                        attroff(COLOR_PAIR(2));
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

int menu(){
	attron(COLOR_PAIR(2));
	mvprintw(3,0,"*****************");
	mvprintw(4,0,"* 1- Atack      *");
	mvprintw(5,0,"* 2- Inventory  *");
	mvprintw(6,0,"*               *");
	mvprintw(7,0,"*****************");	
	attroff(COLOR_PAIR(2));
	while(true){
		int key=getch();
		if(key==49||key==50||key==51){
			return key;
		}	
	}
	return 1;
}

void pueblo(int& y,int& x,soldado* pj,int vs,vector<item*>& shop,int* datosShop){
	bool town=true;
	while(town){
		ClearScreen(y,x);
		attron(COLOR_PAIR(5));
		mvprintw(y/2-7,x/2-30,"Money: %dg",pj->getMoney());
		attroff(COLOR_PAIR(5));
		if(vs==1){
			attron(COLOR_PAIR(3));
			mvprintw(y/2-5,x/2-30,"*         -Town of Tir-         *");
		}else if(vs==2){
			attron(COLOR_PAIR(4));
			mvprintw(y/2-5,x/2-30,"*         -Krast City-          *");
		}else if(vs==3){
			attron(COLOR_PAIR(4));
			mvprintw(y/2-5,x/2-30,"*         -Krast City-          *");
		}else{
			attron(COLOR_PAIR(1));
			mvprintw(y/2-5,x/2-30,"*         -Last City-           *");
		}
		mvprintw(y/2-6,x/2-30,"*********************************");
		
			mvprintw(y/2-2,x/2-30,"*                               *");
		mvprintw(y/2-4,x/2-30,"*  1.- Sleep at the Inn (100g)  *");
		mvprintw(y/2-3,x/2-30,"*  2.- Repair Equipment (100g)  *");
		mvprintw(y/2-2,x/2-30,"*  3.- Upgrade Weapon   (200g)  *");
		mvprintw(y/2-1,x/2-30,"*  4.- Upgrade Armor    (200g)  *");
		mvprintw(y/2,x/2-30,"*  5.- Item Shop                *");
		mvprintw(y/2+1,x/2-30,"*  6.- Save Game                *");
		mvprintw(y/2+2,x/2-30,"*  7.- Leave Town (Fight)       *");
		mvprintw(y/2+3,x/2-30,"*  8.- Quit game                *");
		mvprintw(y/2+4,x/2-30,"*********************************");
		if(vs==1){
			attroff(COLOR_PAIR(3));
		}else if(vs==2){
			attroff(COLOR_PAIR(4));
		}else if(vs==3){
			attroff(COLOR_PAIR(4));
		}else{
			attroff(COLOR_PAIR(1));
		}
		int key;
		bool input=false;
		while(!input){
			key=getch();
			if(key==49||key==50||key==51||key==52||key==53||key==54||key==55||key==56){
				input=true;
			}
		}
		int op=key-48;
		ClearScreen(y,x);
		if(op==1){
			if(pj->getMoney()>=100){
				if(pj->getCurrHP()==pj->getHP()){
					mvprintw(y/2-3,x/2-30,"You are already fully healed!");
					press();
				}else{
					pj->setCurrHP(pj->getHP());
					pj->pay(100);
					mvprintw(y/2-3,x/2-30,"Sweet dreams Zzz...");
					mvprintw(y/2-2,x/2-30,"HP fully restored!");
					press();
				}
			}else{
				mvprintw(y/2-3,x/2-30,"Not enough money!");
				press();
			}
		}else if(op==2){
			if(pj->getMoney()>=100){
				if(pj->getWeapon()->getCurrDur()==pj->getWeapon()->getDurability()&&pj->getArmor()->getCurrDur()==pj->getArmor()->getDur()){
					mvprintw(y/2-3,x/2-30,"Your equipment is already in the best condition!");
					press();
				}else{
					pj->getArmor()->setCurrDur(pj->getArmor()->getDur());
					pj->getWeapon()->setCurrDur(pj->getWeapon()->getDurability());
					mvprintw(y/2-3,x/2-30,"Blacksmith: Very well, I'll leave your equipment like new!");
					mvprintw(y/2-2,x/2-30,"Weapon and Armor repaired to max Durability!");
					pj->pay(100);
					press();
				}
			}else{
                                mvprintw(y/2-3,x/2-30,"Not enough money!");
                                press();
                        }
		}else if(op==3){
			if(pj->getMoney()>=200){
				if(pj->getWeapon()->getCurrDur()>0){
					if(pj->getWeapon()->getDamage()<=465){
						if(pj->getWeapon()->getDamage()+35<500){
							pj->getWeapon()->setDamage(pj->getWeapon()->getDamage()+35);
						}else{
							pj->getWeapon()->setDamage(500);

						}
						pj->getWeapon()->setDurability(pj->getWeapon()->getDurability()+35);
						pj->getWeapon()->upgrade();
						mvprintw(y/2-3,x/2-30,"Blacksmith: This'll be the finest blade you'll ever darn see in your life!");
						mvprintw(y/2-2,x/2-30,"+35 Damage and max Durability to Darkbane!");
						pj->pay(200);
						press();
					}else if(pj->getWeapon()->getDamage()==500){
						mvprintw(y/2-3,x/2-30,"Blacksmith: I can't upgrade this blade anymore, its the finest it can be!");
						press();
					}else{
						mvprintw(y/2-3,x/2-30,"Blacksmith: This'll be the finest blade you'll ever darn see in your life!");
						mvprintw(y/2-2,x/2-30,"+35 Damage and max Durability to Darkbane!");
						pj->getWeapon()->setDamage(500);
						pj->getWeapon()->upgrade();
						pj->pay(200);
						press();
					}

				}else{
					mvprintw(y/2,x/2-30,"Your sword is broken! You must repair it before upgrading it!");
					press();
				}
			}else{
				mvprintw(y/2-3,x/2-30,"Not enough money!");
				press();
			}
		}else if(op==4){
			if(pj->getMoney()>=200){
				if(pj->getArmor()->getCurrDur()>0){
					if(pj->getArmor()->getDefense()<=475){
						if(pj->getArmor()->getDefense()+25<500){
							pj->getArmor()->setDefense(pj->getArmor()->getDefense()+25);
						}else{
							pj->getArmor()->setDefense(500);

						}
						pj->getArmor()->setDur(pj->getArmor()->getDur()+25);
						pj->getArmor()->upgrade();
						mvprintw(y/2-3,x/2-30,"Blacksmith: I'll make this armor the shield of your life!");
						mvprintw(y/2-2,x/2-30,"+25 Defense and max Durability to your armor!");
						pj->pay(200);
						press();
					}else if(pj->getArmor()->getDefense()==500){
						mvprintw(y/2-3,x/2-30,"Blacksmith: I can't upgrade this armor anymore, its the finest it can be!");
						press();
					}else{
						mvprintw(y/2-3,x/2-30,"Blacksmith: I'll make this armor the shield of your life!");
						pj->getArmor()->setDefense(500);
						pj->getArmor()->upgrade();
						mvprintw(y/2-2,x/2-30,"+25 Defense and max Durability to your armor!");
						pj->pay(200);
						press();
					}

				}else{
					mvprintw(y/2,x/2-30,"Your armor is broken! You must repair it before upgrading it!");
					press();
				}
			}else{
				mvprintw(y/2-3,x/2-30,"Not enough money!");
				press();
			}
		}else if(op==5){
			attron(COLOR_PAIR(4));
				mvprintw(y/2-4,x/2-30,"***************************");
			if(vs==1){
				mvprintw(y/2-3,x/2-30,"*      -Town of Tir-      *");
			}else if(vs==2){
				mvprintw(y/2-3,x/2-30,"*      -Krast City-       *");
			}else if(vs==3){
				mvprintw(y/2-3,x/2-30,"*      -Krast City-       *");
			}else{
				mvprintw(y/2-3,x/2-30,"*      -Drake City-       *");   
			}
			mvprintw(y/2-2,x/2-30,"*                         *");
			mvprintw(y/2-1,x/2-30,"*     Item  -  Price      *");
			mvprintw(y/2,x/2-30,"*   -------------------   *");
			for(int i=0;i<=shop.size();i++){
			        mvprintw(y/2+1+i,x/2-30,"*                         *");
			}
			attroff(COLOR_PAIR(4));
			for(int j=0;j<shop.size();j++){
				if(typeid(*shop[j])==typeid(elixir)){
					attron(COLOR_PAIR(3));
				}else if(typeid(*shop[j])==typeid(potion)){
					attron(COLOR_PAIR(7));
				}else if(typeid(*shop[j])==typeid(powder)){
					attron(COLOR_PAIR(5));
				}else{
					attron(COLOR_PAIR(1));
				}
				mvprintw(y/2+1+j,x/2-27,"%d.- %s",j,shop[j]->toString(1).c_str());
				if(typeid(*shop[j])==typeid(elixir)){
					attroff(COLOR_PAIR(3));
				}else if(typeid(*shop[j])==typeid(potion)){
					attroff(COLOR_PAIR(7));
				}else if(typeid(*shop[j])==typeid(powder)){
					attroff(COLOR_PAIR(5));
				}else{
					attroff(COLOR_PAIR(1));
				}
			}
			attron(COLOR_PAIR(4));
			mvprintw(y/2+1+shop.size(),x/2-27,"%d.- Exit Shop",shop.size());
	     		mvprintw(y/2+2+shop.size(),x/2-30,"***************************");
			attroff(COLOR_PAIR(4));
			bool compra=false;
			while(!compra){
				bool bought=false;
				int choice=getch();
				if(shop.size()>0){
					choice=chartoint(choice);
					if(choice>=0&&choice<0+shop.size()){
						bought=true;
					}else if(choice==shop.size()){
						compra=true;
					}
					
					if(bought){
						if(shop.at(choice)->getPrice()>pj->getMoney()){
							mvprintw(y/2-6,x/2-30,"Not enough money!");
							press();
						}else{
							mvprintw(y/2-6,x/2-30,"%s added to your inventory!",shop.at(choice)->toString(1).c_str());
							datosShop[choice]=1;
							pj->addItem(shop.at(choice));
							pj->pay(shop.at(choice)->getPrice());
							shop.erase(shop.begin()+choice);
							press();
						}
						compra=true;
					}
				}else{
					ClearScreen(y,x);
					mvprintw(y/2-3,x/2-30,"No more items left in the shop!");
					compra=true;
					press();
				}
			}
		}else if(op==6){
			if(FileExists("Datos.txt")){
				ofstream salida;
				salida.open("Datos.txt",std::ios::out|std::ios::trunc);
				salida<<"Si,"<<vs<<","<<pj->getMoney()<<","<<pj->getWeapon()->getUpgrades()<<","<<pj->getArmor()->getUpgrades();
				salida.close();
				mvprintw(y/2-3,x/2-30,"Game saved with success!");
				press();
			}else{
				mvprintw(y/2-3,x/2-30,"An error occured while saving your game, try again!");
				press();
			}
			if(FileExists("Shop.txt")){
				ofstream salida;
				salida.open("Shop.txt",std::ios::out|std::ios::trunc);
				for(int i=0;i<6;i++){
					salida<<datosShop[i]<<",";
				}
				salida<<datosShop[6];
			}
		}else if(op==7){
			town=false;
		}else if(op==8){
			erase();
			delete pj;
			exit(0);
		}
	
	}	
}

bool FileExists(const char* Archivo){
	if(!ifstream(Archivo)){
		ofstream crear(Archivo);
		if(strcmp(Archivo,"Datos.txt")==0){
			crear<<"No,0,300,0,0";
		}else{
			crear<<"0,0,0,0,0,0,0";
		}
		crear.close();
		return true;
	}else{
		return true;
	}
}
void press(){
	int getkey;
	while((getkey=getch())!=120){
	}
}
