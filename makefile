guerra:	arma.o armadura.o soldado.o lanza.o espada.o magia.o robe.o mago.o main.o
	g++ arma.cpp armadura.o soldado.o lanza.o espada.o magia.o robe.o mago.o main.cpp -o guerra

main.o:	main.cpp arma.h armadura.h
	g++ -c main.cpp

mago.o:	mago.cpp mago.h soldado.h
	g++ -c mago.cpp

robe.o:	robe.cpp robe.h armadura.h
	g++ -c robe.cpp

magia.o:	magia.cpp magia.h arma.h
	g++ -c magia.cpp

espada.o:	espada.cpp espada.h arma.h
	g++ -c espada.cpp

lanza.o:	lanza.cpp lanza.h arma.h
	g++ -c lanza.cpp

soldado.o:	soldado.cpp soldado.h arma.h armadura.h
	g++ -c soldado.cpp

armadura.o:	armadura.cpp armadura.h
	g++ -c armadura.cpp

arma.o:	arma.cpp arma.h
	g++ -c arma.cpp
