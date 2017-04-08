//taunpb
#include <stdio.h>
#include <stdlib.h>
//#include "pieces.h"
#include "echiquier.h"


//PARTIE ECHIQUIER V1 LAWL


case_t case_t_de_pc(piece_t p, couleur_t c)
{
	case_t ca;
	ca.P = p;
	ca.C = c;
	return ca;
}

void set_case(echiquier_t e, int i, int j, case_t ca)
{
	e.ECHIQUIER[i][j] = ca;
	return;
}

echiquier_t init_echiquier()
{
	int i, j;
	case_t vide;
	vide.P = VIDE;
	vide.C = APACHE;
	echiquier_t e = { vide };

	for (i = 0; i < 8; i++)
	{
		set_case(e,1,i,case_t_de_pc(p,BLANC));
		set_case(e, 6, i, case_t_de_pc(p, NOIR));
	}

	set_case(e, 0, 0, case_t_de_pc(R, BLANC));
	set_case(e, 7, 0, case_t_de_pc(R, NOIR));

	set_case(e, 0, 1, case_t_de_pc(N, BLANC));
	set_case(e, 7, 1, case_t_de_pc(N, NOIR));

	set_case(e, 0, 2, case_t_de_pc(B, BLANC));
	set_case(e, 7, 2, case_t_de_pc(B, NOIR));

	set_case(e, 0, 3, case_t_de_pc(Q, BLANC));
	set_case(e, 7, 3, case_t_de_pc(Q, NOIR));

	set_case(e, 0, 4, case_t_de_pc(K, BLANC));
	set_case(e, 7, 4, case_t_de_pc(K, NOIR));

	set_case(e, 0, 5, case_t_de_pc(B, BLANC));
	set_case(e, 7, 5, case_t_de_pc(B, NOIR));

	set_case(e, 0, 6, case_t_de_pc(N, BLANC));
	set_case(e, 7, 6, case_t_de_pc(N, NOIR));

	set_case(e, 0, 7, case_t_de_pc(R, BLANC));
	set_case(e, 7, 7, case_t_de_pc(R, NOIR));

	return e;
}



piece_t piece_t_de_case_t (case_t ca)
{
    return ca.P;
}

couleur_t couleur_t_de_case_t (case_t ca)
{
    return ca.C;
}



void get_case(echiquier_t e, int i, int j,case_t* ca)
{
    *ca = e.ECHIQUIER[i][j];
}

int indice_de_ligne(char a)
{
    return a-'1';
}

char ligne_de_indice(int i)
{
    return i + '1';
}

int indice_de_colonne(char a)
{
    return a-'a';
}

char colonne_de_indice(int i)
{
    return i + 'a';
}

int char_ligne_valide(char a)
{
    if (a <='8' && a>='1')
        return 1;
    else
        return 0;
}

int char_colonne_valide(char a)
{
    if (a <='H' && a>='A')
        return 1;
    else
        return 0;
}
