H_v1 = -I/Version1/the_headers/
S_v1 = /Version1/the_sources/
B_v1 = /Version1/bin/

cible : version1

version1 : $(S_v1)main.o $(S_v1)pieces.o $(S_v1)echiquier.o $(S_v1)coups.o $(S_v1)affichage.o
	gcc -o $(B_v1)version1 $(S_v1)main.o $(S_v1)pieces.o $(S_v1)echiquier.o $(S_v1)coups.o $(S_v1)affichage.o $(H_v1)
	
main.o : $(S_v1)main.c
	gcc -o $(S_v1)main.o -c $(H_v1) $(S_v1)main.c 

affichage.o : $(S_v1)affichage.c 
	gcc -o $(S_v1)affichage.o -c $(H_v1) $(S_v1)affichage.c 
	
echiquier.o : $(S_v1)echiquier.c 
	gcc -o $(S_v1)echiquier.o -c $(H_v1) $(S_v1)echiquier.c 
	
pieces.o : $(S_v1)pieces.c 
	gcc -o $(S_v1)pieces.o -c $(S_v1)pieces.c
	
coups.o : $(S_v1)coups.c 
	gcc -o $(S_v1)coups.o -c $(H_v1) $(S_v1)coups.c