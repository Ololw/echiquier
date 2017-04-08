#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "coups.h"


//Partie affichage console

void afficher_echiquier_console(echiquier_t e)
{
	int i, j;
	case_t ca;

	for (i = 7; i >= 0; i--)
	{
		printf("\n");
		for (j = 0; j < 8; j++)
		{
			get_case(e, i, j, &ca);
			printf("| %c ", lettre_de_piece(piece_t_de_case_t(ca)));
		}
		printf("|");
	}

	printf("\n\n");
	return;
}

void afficher_echiquier_liste(liste_coup lc)
{
	maillon* m;
	if (lc.debut != NULL)
	{
		m = lc.debut;
		while (m != NULL)
		{
			afficher_echiquier_console(m->element.echiquier);
			m = m->suivant;
		}
	}

	else
		printf("\ntest lc.debut = NULL\n");
	return;
}

int jouerPartie_fichier(char* nomFich)
{
	FILE* fichier = NULL;
	int i;

	if (NULL == (fichier = fopen(nomFich, "r+")))
	{
		printf("Probleme fichier introuvable\n\n");
		return -1;
	}
	liste_coup lc;
	lc.debut = NULL;
	lc.fin = NULL;

	char c;
	char coup[10];
	while (fgets(coup, 10, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
	{
		if (!creer_coup(&lc, coup))
			afficher_echiquier_console(lc.fin->element.echiquier);
	}

	//   afficher_echiquier_liste(lc);
	return 0;
}