H_v1 = -I../the_headers/
B_v1 = ../bin/

cible : version1

version1 : main.o pieces.o echiquier.o coups.o affichage.o
	gcc -o $(B_v1)version1 main.o pieces.o echiquier.o coups.o affichage.o $(H_v1)
	
main.o : main.c
	gcc -o main.o -c $(H_v1) main.c 

affichage.o : affichage.c 
	gcc -o affichage.o -c $(H_v1) affichage.c -lvt100
	
echiquier.o : echiquier.c 
	gcc -o echiquier.o -c $(H_v1) echiquier.c 
	
pieces.o : pieces.c 
	gcc -o pieces.o -c pieces.c
	
coups.o : coups.c 
	gcc -o coups.o -c $(H_v1) coups.c