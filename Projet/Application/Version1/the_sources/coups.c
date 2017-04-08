#include <stdio.h>
#include <stdlib.h>
//#include "echiquier.h"
#include "coups.h"




//PARTIE GESTION DES COUPS WALLEZ

echiquier_t jouer_coup(echiquier_t e, char* c)
{
	case_t ca;

	int c1 = indice_de_colonne(c[0]);
	int c2 = indice_de_colonne(c[2]);
	int l1 = indice_de_ligne(c[1]);
	int l2 = indice_de_ligne(c[3]);

	get_case(e, l1, c1, &ca);
	set_case(&e, l2, c2, ca);
	set_case(&e, l1, c1, case_t_de_pc(VIDE, APACHE));

	return e;
}

int coup_valide(char* c, echiquier_t e, couleur_t co)
{
	int v0 = char_colonne_valide(c[0]);
	int v1 = char_ligne_valide(c[1]);
	int v2 = char_colonne_valide(c[2]);
	int v3 = char_ligne_valide(c[3]);


	case_t cd, cf;
	get_case(e, indice_de_ligne(c[1]), indice_de_colonne(c[0]), &cd);
	get_case(e, indice_de_ligne(c[3]), indice_de_colonne(c[2]), &cf);


	return (v0 && v1 && v2 && v3 && (c[0] != c[2] || c[1] != c[3]) && cd.P != VIDE && (cf.P == VIDE || (cf.C != cd.C)) && cd.C == co);
}

int creer_coup(liste_coup* lc, char* c)
{
	maillon* m = malloc(sizeof(maillon));
	m->suivant = NULL;
	if (lc->debut == NULL)
	{
		m->element.couleur = BLANC;
		m->element.num_coup = 1;
		echiquier_t e = init_echiquier();
		if (!coup_valide(c, e, m->element.couleur))
		{
			printf("COUP NON VALIDE init \n");
			return -1;
		}
		else
		{
			m->element.echiquier = jouer_coup(e, c);
			lc->debut = m;
			lc->fin = m;
		}
	}

	else
	{
		if (lc->fin->element.couleur == BLANC)
			m->element.couleur = NOIR;
		else
			m->element.couleur = BLANC;

		m->element.num_coup = lc->fin->element.num_coup + 1;
		if (!coup_valide(c, lc->fin->element.echiquier, m->element.couleur))
		{
			printf("COUP NON VALIDE\n");
			return -1;
		}
		else
		{
			m->element.echiquier = jouer_coup(lc->fin->element.echiquier, c);
			lc->fin->suivant = m;
			lc->fin = m;
		}
	}

	return 0;
}