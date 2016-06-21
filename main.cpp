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

using std::string;
using std::stringstream;
using std::vector;

void ClearScreen(int&,int&);
void printPJ(soldado*,int&,int&);
void press();
int hit(const soldado*,const soldado*);
void heal(soldado*);
int menu();
int chartoint(int);

int main(int argc, char* argv[]){
	initscr();	
	int x,y;
	vector<soldado*> enemies(6);
	noecho();
	const string atrs[6]={"N/A","Fire","Ice","Electricity","Light","Dark"};
	soldado* pj=0;
	arma* weap=0;
	armadura* arm=0;
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
	enemies.at(0)=new espadachin("Von",new espada(atrs[0],150),new ligera(atrs[0],60),650);
	enemies.at(1)=new mago("Ilya",new magia(atrs[1],210),new robe(atrs[0],60),1000);
	enemies.at(2)=new lancero("Aran",new lanza(atrs[2],220),new pesada(atrs[2],180),1500);
	enemies.at(2)->getWeapon()->setDurability(160);
	enemies.at(2)->getArmor()->setDur(200);
	enemies.at(2)->getWeapon()->setCurrDur(160);
        enemies.at(2)->getArmor()->setCurrDur(200);
	enemies.at(3)=new mago("Lugh",new magia(atrs[5],200),new robe(atrs[5],130),1600);
	enemies.at(4)=new lancero("Raiden",new lanza(atrs[3],410),new pesada(atrs[1],280),2200);
	enemies.at(4)->getWeapon()->setDurability(200);
        enemies.at(4)->getArmor()->setDur(200);
	enemies.at(4)->getWeapon()->setCurrDur(200);
        enemies.at(4)->getArmor()->setCurrDur(200);
	enemies.at(5)=new espadachin("Jean",new espada(atrs[5],400),new ligera(atrs[5],350),3000);
	enemies.at(5)->getWeapon()->setDurability(500);
        enemies.at(5)->getArmor()->setDur(500);
	enemies.at(5)->getWeapon()->setCurrDur(500);
        enemies.at(5)->getArmor()->setCurrDur(500);
	ClearScreen(y,x);
	/*short int r,g,b;
	color_content(3,&r,&g,&b);
	mvprintw(0,0,"Rojo: %d, verde: %d, azul: %d",r,g,b);
	press();*/
	int ch;
	while((ch=getch())!=27){
		move(1,1);
		printw("Keycode: %d     ",ch);
		move(0,0);
		printw("Letra: %c",ch);
		refresh();
	}

	/*for(int i=0;i<enemies.size();i++){
		ClearScreen(y,x);
		printPJ(enemies[i],y,x);
		press();
	}*/
	move(0,0);
	ClearScreen(y,x);
	weap=new espada(atrs[4],120);
	weap->setDurability(200);
	arm=new ligera(atrs[0],60);
	pj=new espadachin("Shie",weap,arm,650);
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
	attroff(COLOR_PAIR(2));
	int turno=1,vs=0;
	ClearScreen(y,x);
	mvprintw(0,0,"Chapter 1");
	printPJ(pj,y,x);
        printPJ(enemies.at(vs),y,x);
	bool play=true;
	pj->addItem(new potion(3,100));
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
		if(turno==1){
			if(pj->isFrozen()){
				pj->Freeze(false);
				printPJ(pj,y,x);
                                printPJ(enemies.at(vs),y,x);
				press();
			}else{
				printPJ(pj,y,x);
				printPJ(enemies.at(vs),y,x);
				bool opValida=false;
				while(!opValida){
					int m=menu();
					if(m==50){
						ClearScreen(y,x);
						if(pj->invSize()>0){
							printPJ(pj,y,x);
							printPJ(enemies.at(vs),y,x);
							mvprintw(0,0,"Inventory: ");
							mvprintw(1,0,"----------");		
							for(int i=0;i<pj->invSize();i++){
								mvprintw(2+i,0,"%d.- %s",i,pj->getInv().at(i)->toString().c_str());
							}
							mvprintw(2+pj->invSize(),0,"%d.- Cancel",pj->invSize());
							bool itemValido=false;
							while(!itemValido){
								int index=getch();
								if(index>=48&&index<=(47+pj->invSize())){
									pj->getInv().at(chartoint(index))->function(pj);
									itemValido=true;
									opValida=true;
								}else if(index==48+pj->invSize()){
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
					}else if(m==51){
						ClearScreen(y,x);
						play=false;
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
		pj->state();
		enemies.at(vs)->state();
		if(pj->isFrozen()){
			mvprintw(15,0,"-Shie is frozen! Your next turn will be skipped!");
		}
		if(enemies.at(vs)->isFrozen()){
			mvprintw(16,0,"-%s is frozen! %s's next turn will be skipped!",enemies.at(vs)->getName(),enemies.at(vs)->getName());
		}
		if(pj->isBurned()){
			mvprintw(17,0,"-Shie is burned! You receive %f damage!",pj->getHP()*0.05);
		}
		if(enemies.at(vs)->isBurned()){
			mvprintw(18,0,"-%s is burned! %s receives %f damage!",enemies.at(vs)->getName(),enemies.at(vs)->getName(),enemies.at(vs)->getHP()*0.05);
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
			attron(COLOR_PAIR(2));
			if(vs==1){
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
				mvprintw(y/2-2,x/2-20,"-----------------------");
				press();
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
				mvprintw(y/2-2,x/2-20,"-----------------------");
				mvprintw(y/2,x/2-40,"Shie: That can't be! Sir Raiden is an excellent knight and a man my father trusted very much!");
				mvprintw(y/2+2,x/2-40,"Shie: Plus, had that happened, it would be known through out all of Baste");
				press();
				mvprintw(y/2+4,x/2-40,"Spy: It's all true. The senate is doing their best to keep this a secret, only saying the king disappeared");
				press();
				mvprintw(y/2+6,x/2-40,"Shie: What should I do...");
				press();
				ClearScreen(y,x);	
				mvprintw(y/2-3,x/2-20,"~Chapter 2: Intervention~");
				mvprintw(y/2-2,x/2-20,"-----------------------");
				press();
				mvprintw(y/2,x/2-40,"Spy: Go to the White Forest, someone awaits you there.");
				press();
				mvprintw(y/2+2,x/2-40,"And so, Shie set out for the White Forest, a huge maze of enchanted trees");
				mvprintw(y/2+3,x/2-40,"There, she found a fire mage who seemed like she had been meditating; as though waiting for someone");
				mvprintw(y/2+4,x/2-40,"Unfortunately, upon seeing Shie, the mage attacked without giving her a chance to even speak!");
				press();
			}else if(vs==2){
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
				mvprintw(y/2-3,x/2-20,"Chapter 3: Honor, Death, Glory");
				mvprintw(y/2-2,x/2-20,"------------------------------");
				mvprintw(y/2,x/2-40,"However, the city of Krast had been ocupied by unknown soldiers, commanded by a tall Halberdier");
				mvprintw(y/2+1,x/2-40,"Shie managed to sneak past many soldiers, but was stopped in front of the cathedral by the commander, Aran!");
				press();
				mvprintw(y/2+2,x/2-40,"Aran: I commend you for getting this far, my dear Princess, but your journey ends now!");
				press();
				mvprintw(y/2+4,x/2-40,"Shie: I won't stop until I find my father, no matter who stands in my way!");
				press();
				mvprintw(y/2+6,x/2-40,"Aran: Very well then, let us have a honorable battle! Me and my Ice equipment are undefeated!");
				press();
			}else if(vs==3){
				mvprintw(y/2,x/2-40,"Aran: Hng! You are a master of the sword...but you are far too late...Priest Owain will be...");
				press();
				mvprintw(y/2+2,x/2-40,"Shie: No, I must save the Priest! Hang on, I'm coming!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"Chapter 4: Evil Omen");
				mvprintw(y/2-2,x/2-20,"--------------------");
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
				mvprintw(y/2-3,x/2-20,"Chapter 4: Evil Omen");
				mvprintw(y/2-2,x/2-20,"--------------------");
				mvprintw(y/2,x/2-40,"Shie: Not so fast! I won't allow you to harm the priest!");
				press();
				mvprintw(y/2+2,x/2-40,"Ilya: Shie! I arrived just in time, I will keep the soldiers busy.");
				mvprintw(y/2+4,x/2-40,"Ilya: Use your blade to defeat that dark mage!");
				press();
				mvprintw(y/2+6,x/2-40,"Shie: Yes, I'll defeat you with my holy blade, Darkbane!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"Chapter 4: Evil Omen");
				mvprintw(y/2-2,x/2-20,"--------------------");
				mvprintw(y/2,x/2-40,"Lugh: Disgusting, how can you rely on such weak magic as Light! I'll show you true power!");
				press();
				heal(pj);
				mvprintw(y/2+2,x/2-40,"Priest Owain: Princess! I have healed you and blessed your equipment, it should be as good as new!");
				press();
				mvprintw(y/2+4,x/2-40,"Shie: Thank you Great Priest, I shall use your blessing to defeat these malicious magician!");
				press();
			}else if(vs==4){
				mvprintw(y/2,x/2-40,"Lugh: Damn your light magic...DAMN YOU PRINCESS!!");
				press();
				mvprintw(y/2+2,x/2-40,"Shie: Repent and pray, Maybe then God will have mercy on your soul!");
				press();
				mvprintw(y/2+4,x/2-40,"A strong light came out from Darkbane as Shie spoke those words");
				mvprintw(y/2+6,x/2-40,"With this new power, she struck down the dark mage who burned to death when hit by the holy light");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"Chapter 5: Revelations");
				mvprintw(y/2-2,x/2-20,"----------------------");
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
				mvprintw(y/2-3,x/2-20,"Chapter 5: Revelations");
				mvprintw(y/2-2,x/2-20,"----------------------");
				mvprintw(y/2,x/2-40,"Shie: Thank you, Priest. I shall use this power to rescue my father!");
				press();
				mvprintw(y/2+2,x/2-40,"Ilya: Very well! We can now fight Raiden and res---");
				mvprintw(y/2+4,x/2-40,"Ilya was violently interrupted, as she was stabbed from behind by a Spear infused with electric magic");
				mvprintw(y/2+6,x/2-40,"Raiden: Were you talking about me? Why, I'm honored!");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"Chapter 5: Revelations");
				mvprintw(y/2-2,x/2-20,"----------------------");
				mvprintw(y/2,x/2-40,"Shie: Aunt Ilyia, NOOOOO!!!");
				mvprintw(y/2+2,x/2-40,"Her aunt fell to her death, as the man who killed her was revealed behind her. It was Raiden!");
				press();
				mvprintw(y/2+4,x/2-40,"Raiden: This is a formal invitation to you, My Princess. From your beloved brother, Jean!");
				press();
				mvprintw(y/2+6,x/2-40,"Shie: Did you just say Jean!? That's impossible, he died when he was 8!");
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"Chapter 5: Revelations");
				mvprintw(y/2-2,x/2-20,"----------------------");
				mvprintw(y/2,x/2-40,"Raiden: Believe what you want. Come to Mailfaisance Tower and all your questions shall be answered");
				press();
				mvprintw(y/2+2,x/2-40,"Shie: Wait, please explain yourself! Where is my father!?");
				press();
				mvprintw(y/2+4,x/2-40,"Raiden: Didn't I just tell you? Come, accept our invitation. Jean wishes for a lovely family reunion!");
				press();
				mvprintw(y/2+6,x/2-40,"Before Shie could draw her blade, a thunder fell on Raiden and he disappeared immeadiately");
				press();
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"Chapter 5: Revelations");
				mvprintw(y/2-2,x/2-20,"----------------------");
				mvprintw(y/2,x/2-40,"Shie: I will go. I'm coming, RAIDEN! JEAN!");
				press();
				mvprintw(y/2+1,x/2-40,"The princess set out for the Mailfaisance Tower");
				mvprintw(y/2+2,x/2-40,"Lots of questions spiraled her mind. Why did Raiden betray the king?");
				mvprintw(y/2+3,x/2-40,"Is her father at the tower? Is he truly alive? But most of all");
				press();
				mvprintw(y/2+4,x/2-40,"The fact that her supposed dead brother was not only alive, but he planned this whole scheme");
				press();
				mvprintw(y/2+6,x/2-40,"Every time she thought about it, it sent chills down her spine...");
				ClearScreen(y,x);
				mvprintw(y/2-3,x/2-20,"Chapter 5: Revelations");
				mvprintw(y/2-2,x/2-20,"----------------------");
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
				mvprintw(y/2-3,x/2-20,"Chapter 5: Revelations");
				mvprintw(y/2-2,x/2-20,"----------------------");
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


int chartoint(int index){
	switch(index){
		case 48: return 0;
		case 49: return 1;
		case 50: return 2;
		case 51: return 3;
		case 52: return 4;
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
	mvprintw(0,0,"*****************");
	mvprintw(1,0,"* 1- Atacar     *");
	mvprintw(2,0,"* 2- Inventario *");
	mvprintw(3,0,"*               *");
	mvprintw(4,0,"*****************");	
	attroff(COLOR_PAIR(2));
	while(true){
		int key=getch();
		if(key==49||key==50||key==51){
			return key;
		}	
	}
	return 1;
}

void pueblo(soldado* pj){
	
}

void press(){
	int getkey;
	while((getkey=getch())!=120){
	}
}
