#include <stdio.h>
#include <stdlib.h>
#include "pieces.h"
#include "echiquier.h"

typedef struct
{
    int num_coup;
    couleur_t couleur;
    echiquier_t echiquier;
    char* chaine;
}   coup_t;

typedef struct maillon maillon;
struct maillon
{
    coup_t element;
    maillon* suivant;
};

typedef struct
{
    maillon *debut;
    maillon *fin;
} liste_coup;

void creer_coup(liste_coup lc, char* c);
