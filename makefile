guerra:	arma.o armadura.o soldado.o main.o
	g++ arma.cpp armadura.o soldado.o main.cpp -o guerra

main.o:	main.cpp arma.h armadura.h
	g++ -c main.cpp

soldado.o:	soldado.cpp soldado.h arma.h armadura.h
	g++ -c soldado.cpp

armadura.o:	armadura.cpp armadura.h
	g++ -c armadura.cpp

arma.o:	arma.cpp arma.h
	g++ -c arma.cpp
