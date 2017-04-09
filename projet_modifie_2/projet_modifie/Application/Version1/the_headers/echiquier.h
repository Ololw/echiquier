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

case_t case_t_de_pc(piece_t p, couleur_t c);
void set_case(echiquier_t* e, int i, int j, case_t ca);
echiquier_t init_echiquier();
piece_t piece_t_de_case_t (case_t ca);
couleur_t couleur_t_de_case_t (case_t ca);
void get_case(echiquier_t e, int i, int j,case_t* ca);
int indice_de_ligne(char a);
char ligne_de_indice(int i);
int indice_de_colonne(char a);
char colonne_de_indice(int i);
int char_ligne_valide(char a);
int char_colonne_valide(char a);
