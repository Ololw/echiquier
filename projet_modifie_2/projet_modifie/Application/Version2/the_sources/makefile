H_v1 = -I../the_headers/
B_v1 = ../bin/
L_v1 = -L../../../lib

cible : version2 clean

version2 : main.o pieces.o echiquier.o coups.o affichage.o
	gcc -o $(B_v1)version2 main.o pieces.o echiquier.o coups.o affichage.o $(H_v1) $(L_v1) -lvt100
	
main.o : main.c
	gcc -o main.o -c $(H_v1) main.c 

affichage.o : affichage.c 
	gcc -o affichage.o -c $(H_v1) affichage.c $(L_v1)libvt100.so
	
echiquier.o : echiquier.c 
	gcc -o echiquier.o -c $(H_v1) echiquier.c 
	
pieces.o : pieces.c 
	gcc -o pieces.o -c pieces.c
	
coups.o : coups.c 
	gcc -o coups.o -c $(H_v1) coups.c

clean :
	rm *.o
