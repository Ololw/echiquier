#include <stdio.h>
#include <stdlib.h>
#include "fonc_carac.h"
#include "vt100.h"
#include "coups.h"


void afficher_piece(char c, affiche_func_param_t p)
{
	putchar(c);
}

void afficher_echiquier_vt(echiquier_t e)
{
	int i, j;
	coloris_dessin_t colori;
	couleur_t couleur_case;
	case_t ca;

	definir_coloris(NSN, NOIR, MAGENTA);
	definir_coloris(BSN, BLANC, MAGENTA);

	for (i = 7; i >= 0; i--)
	{
		printf("\n");
		for (j = 0; j < 8; j++)
		{
			get_case(e, i, j, &ca);

			if (i + j % 2 == 0)
			{
				if (couleur_t_de_case_t(ca) == BLANC)
					colori = BSN;
				else
					colori = NSN;
			}
			else
			{
				if (couleur_t_de_case_t(ca) == NOIR)
					colori = NSB;
				else
					colori = NSN;
			}
			dessiner_case(colori, lettre_de_piece(piece_t_de_case_t(ca)), afficher_piece, (affiche_func_param_t)(NULL));
		}
	}
	printf("\n\n");
	return;
}
//Partie affichage console v2

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
			afficher_echiquier_vt(lc.fin->element.echiquier);
	}

	//   afficher_echiquier_liste(lc);
	return 0;
}
