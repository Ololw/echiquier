#include <stdio.h>
#include <stdlib.h>


typedef enum {BLANC,NOIR,APACHE} couleur_t;
typedef enum  {K,Q,B,N,R,p,VIDE,AUTRE} piece_t;

piece_t piece_de_lettre (char a);
char lettre_de_piece ( piece_t p);
