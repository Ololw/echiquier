/*
	ECHEVET Theo
	CUZIN Florian
*/
#include <stdio.h>
#include <stdlib.h>


typedef enum {BLANC,NOIR,APACHE} couleur_t;
typedef enum  {K,Q,B,N,R,p,VIDE,AUTRE} piece_t;

//Renvoie la piece_t correspondant au caractere a
piece_t piece_de_lettre (char a);

//Renvoie le caractere correspondant a la piece p
char lettre_de_piece ( piece_t p);
