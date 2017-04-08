#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "fonc_carac.h"
#include "vt100.h"
#include "coups.h"


void afficher_echiquier_console(echiquier_t e);
void afficher_echiquier_liste(liste_coup lc);
int jouerPartie_fichier(char* nomFich);