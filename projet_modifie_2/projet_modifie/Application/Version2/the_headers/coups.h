/*
	ECHEVET Theo
	CUZIN Florian
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
//#include "pieces.h"
#include "echiquier.h"


/* Structure représentant un coup sur l'échiquier */
typedef struct
{
	int num_coup;
	couleur_t couleur;
	echiquier_t echiquier;
	char* chaine;
}   coup_t;


/* Définition de la liste chainée de coup */
typedef struct maillon maillon;
struct maillon
{
	coup_t element;
	maillon* suivant;
};

/* Structure rassemblant l'élement de tête et de fin de la liste chainee */
typedef struct
{
	maillon *debut;
	maillon *fin;
} liste_coup;

/* Fonction qui joue un coup c (tableau de caractere) sur l'échiquier e et qui renvoie l'echiquier modifie */
echiquier_t jouer_coup(echiquier_t e, char* c);

/* Fonction qui renvoie un int (correspondant à un booléen) indiquant si le coup c par le joueur de couleur co est valide dan l'échiquier e  */
int coup_valide(char* c, echiquier_t e, couleur_t co);

/* Fonction qui ajoute un coup dans la liste de coup lc en vérifiant si le coup est valide et renvoi un booleen qui indique le bon fonctionnement de la fonction */
int creer_coup(liste_coup* lc, char* c);