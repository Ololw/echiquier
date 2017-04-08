#include <stdio.h>
#include <stdlib.h>
#include "echiquier.h"




echiquier_t jouer_coup(echiquier_t e, char* c)
{
	echiquier_t e2;
	e2 = e;

	case_t ca;

	int c1 = indice_de_colonne(c[0]);
	int c2 = indice_de_colonne(c[2]);
	int l1 = indice_de_ligne(c[1]);
	int l2 = indice_de_ligne(c[3]);

	get_case(e, c1, l1, &ca);
	set_case(e2, c2, l2, ca);
	set_case(e2,c1 , l1, case_t_de_pc(VIDE, APACHE));

	return e2;
}

int coup_valide(char* c,echiquier_t e)
{
	printf("test coup_valide1\n");
	int v0 = char_colonne_valide(c[0]);
	int v1 = char_ligne_valide(c[1]);
	int v2 = char_colonne_valide(c[2]);
	int v3 = char_ligne_valide(c[3]);

	case_t cd, cf;
	get_case(e, indice_de_ligne(c[1]), indice_de_colonne(c[0]), &cd);
	get_case(e, indice_de_ligne(c[3]), indice_de_colonne(c[2]), &cf);


	if (v0 && v1 && v2 && v3 && (c[0] != c[2] || c[1] != c[3]) && cd.P != VIDE && (cf.P == VIDE || (cf.C != cd.C)))
		return 1;
	else
		return 0;


}

void creer_coup(liste_coup lc, char* c)
{
		 maillon* m = malloc(sizeof(maillon));

		if (lc.debut ==  NULL)
		{
			m->element.couleur = BLANC;
			m->element.num_coup = 1;
			echiquier_t e = init_echiquier();
			if (!coup_valide(c,e))
			{
				printf("COUP NON VALIDE\n");
			}
			else
			{
				m->element.echiquier = jouer_coup(e, c);
				lc.debut = m;
				lc.fin = m;
			}
		}

		else
		{
			if (lc.fin->element.couleur == BLANC)
				m->element.couleur = NOIR;
			else
				m->element.couleur = BLANC;

			m->element.num_coup = lc.fin->element.num_coup+1;
			if (!coup_valide(c, lc.fin->element.echiquier))
			{
				printf("COUP NON VALIDE\n");
			}
			else
			{
				m->element.echiquier = jouer_coup(lc.fin->element.echiquier, c);
				lc.fin->suivant = m;
				lc.fin = m;
			}
		}

	return;
}
