#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef enum { BLANC, NOIR } couleur_t;
typedef enum { VIDE, K, Q, B, N, R, p, AUTRE } piece_t;


 
//Renvoie la piece_t correspondant au caractere a
piece_t piece_de_lettre (char a);

//Renvoie le caractere correspondant a la piece p
char lettre_de_piece ( piece_t p);
