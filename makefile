guerra:	arma.o armadura.o item.o soldado.o lanza.o espada.o magia.o robe.o ligera.o pesada.o mago.o espadachin.o lancero.o potion.o powder.o elixir.o main.o
	g++ arma.o armadura.o item.o soldado.o lanza.o espada.o magia.o robe.o ligera.o pesada.o mago.o espadachin.o lancero.o potion.o powder.o elixir.o main.o -lncurses -o guerra

main.o:	main.cpp arma.h armadura.h item.h soldado.h lancero.h espadachin.h mago.h ligera.h robe.h magia.h espada.h lanza.h potion.h powder.h elixir.h
	g++ -c main.cpp -std=c++11

potion.o:	potion.cpp potion.h item.h
	g++ -c potion.cpp

powder.o:	powder.cpp powder.h item.h
	g++ -c powder.cpp

elixir.o:	elixir.cpp elixir.h item.h
	g++ -c elixir.cpp

lancero.o:	lancero.cpp lancero.h soldado.h
	g++ -c lancero.cpp

espadachin.o:	espadachin.cpp espadachin.h soldado.h
	g++ -c espadachin.cpp

mago.o:	mago.cpp mago.h soldado.h
	g++ -c mago.cpp

pesada.o:	pesada.cpp pesada.h armadura.h
	g++ -c pesada.cpp

ligera.o:	ligera.cpp ligera.h armadura.h
	g++ -c ligera.cpp

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

item.o:	item.cpp item.h
	g++ -c item.cpp

armadura.o:	armadura.cpp armadura.h
	g++ -c armadura.cpp

arma.o:	arma.cpp arma.h
	g++ -c arma.cpp

clean:
	rm -f *.o guerra
