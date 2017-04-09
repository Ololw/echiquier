/*
	ECHEVET Theo
	CUZIN Florian
*/
#include <stdio.h>
#include <stdlib.h>
#include "pieces.h"

typedef struct
{
    piece_t P;
    couleur_t C;
} case_t;

typedef struct
{
   case_t ECHIQUIER[8][8];
} echiquier_t;

//Cree une case_t contenant la piece_t p et la couleur_t c
case_t case_t_de_pc(piece_t p, couleur_t c);

//Mets une case dans l'echiquier à l'indice [i][j] de valeur ca
void set_case(echiquier_t* e, int i, int j, case_t ca);

//Renvoie un echiquier initialise (debut de partie)
echiquier_t init_echiquier();

//Renvoie la piece_t contenue dans la case ca
piece_t piece_t_de_case_t (case_t ca);

//Renvoie la couleur_t contenue dans la case ca
couleur_t couleur_t_de_case_t (case_t ca);

//Recupere la valeur de la case_t à l'indice [i][j] dans l'echiquier, et la stocke dans ca
void get_case(echiquier_t e, int i, int j,case_t* ca);

//Convertit le caractere a en indice de ligne pour l'echiquier
int indice_de_ligne(char a);

//Convertit l'indice de ligne i pour l'echiquier en caractere
char ligne_de_indice(int i);

//Convertit le caractere a en indice de colonne pour l'echiquier
int indice_de_colonne(char a);

//Convertit l'indice de colonne j pour l'echiquier en caractere
char colonne_de_indice(int i);

//Verifie que le caractere a est un caractere valide de ligne pour l'echiquier
int char_ligne_valide(char a);

//Verifie que le caractere a est un caractere valide de colonne pour l'echiquier
int char_colonne_valide(char a);
