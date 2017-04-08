#include <stdio.h>
#include <stdlib.h>
#include "echiquier.h"
//#include "pieces.h"
#include "coups.h"


void afficher_echiquier_console(echiquier_t e);
void afficher_echiquier_liste(liste_coup lc);
int jouerPartie_fichier(char* nomFich);