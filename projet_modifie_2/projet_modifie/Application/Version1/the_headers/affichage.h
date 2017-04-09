#include <stdio.h>
#include <stdlib.h>
#include "fonc_carac.h"
#include "vt100.h"
#include "coups.h"

/*Fonctions qui affiche la piece correspondante au caractere c à l'écran*/
void afficher_piece(char c, affiche_func_param_t p);

/*Fonctions qui affiche l'échiquier e grace à la librairie vt100.so*/
void afficher_echiquier_vt(echiquier_t e);

/*Affiche l'échiquier e dans la console */
void afficher_echiquier_console(echiquier_t e);

/*Affiche à la console tout les échiquier présent dans la liste de coup lc*/
void afficher_echiquier_liste(liste_coup lc);

/*Joue la partie dont les coups sont ecrit dans le fichier nomFich et renvoi une indication si il y a eu un probleme*/
int jouerPartie_fichier(char* nomFich);