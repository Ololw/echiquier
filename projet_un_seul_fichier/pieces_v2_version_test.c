#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef enum { BLANC, NOIR } couleur_t;
typedef enum { VIDE,K, Q, B, N, R, p, AUTRE } piece_t;

//int compteur = 0;

// PARTIE PIECES TMTC

char P[8] = { ' ','K','Q','B','N','R','p','*' };

piece_t piece_de_lettre(char a)
{
	int i = 0;
	while (i<7 && P[i] != a)
	{
		i++;
	}
	return i;
}

char lettre_de_piece(piece_t p)
{
	return P[p];
}

//PARTIE ECHIQUIER V2 LAWL
typedef struct
{
	int entier;
} case_t;

typedef struct
{
	uint32_t ECHIQUIER[8];
} echiquier_t;

case_t case_t_de_pc(piece_t p, couleur_t c)
{
	case_t ca;
	ca.entier = p << 1;
	ca.entier = ca.entier + c;
	return ca;
}

void set_case(echiquier_t* e, int i, int j, case_t ca)
{
	uint32_t nouveau_entier;
	uint32_t masque, quinze,ca_32;
//	compteur++;

	masque = UINT32_MAX;
	quinze = 15;
	ca_32 = ca.entier;

	masque = masque - (quinze << (4*j));

	nouveau_entier = e->ECHIQUIER[i];
	nouveau_entier = masque & nouveau_entier;

//	printf("\nValeur ca_32 : %zu (%i)", ca_32,compteur);

	e->ECHIQUIER[i] = nouveau_entier + (ca_32 << (4 * j));


	/*uint32_t nouveau_e;

	nouveau_e = e->ECHIQUIER[i] << (4 * (7 - j));
	nouveau_e = nouveau_e >> 28;
	nouveau_e = nouveau_e << (28 - 4 * (7 - j));

	e->ECHIQUIER[i] = e->ECHIQUIER[i] - nouveau_e;

	nouveau_e = ca.entier;
	nouveau_e = nouveau_e << (28 - 4 * (7 - j));

	e->ECHIQUIER[i] = e->ECHIQUIER[i] + nouveau_e;
	return;*/
}

echiquier_t init_echiquier()
{
	int i, j;
	case_t vide;
	vide.entier = 0;
	echiquier_t e;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j<8; j++)
		{
			set_case(&e, i, j, vide);
		}
	}

	for (i = 0; i < 8; i++)
	{
		set_case(&e, 1, i, case_t_de_pc(p, BLANC));
		set_case(&e, 6, i, case_t_de_pc(p, NOIR));
	}

	set_case(&e, 0, 0, case_t_de_pc(R, BLANC));
	set_case(&e, 7, 0, case_t_de_pc(R, NOIR));

	set_case(&e, 0, 1, case_t_de_pc(N, BLANC));
	set_case(&e, 7, 1, case_t_de_pc(N, NOIR));

	set_case(&e, 0, 2, case_t_de_pc(B, BLANC));
	set_case(&e, 7, 2, case_t_de_pc(B, NOIR));

	set_case(&e, 0, 3, case_t_de_pc(Q, BLANC));
	set_case(&e, 7, 3, case_t_de_pc(Q, NOIR));

	set_case(&e, 0, 4, case_t_de_pc(K, BLANC));
	set_case(&e, 7, 4, case_t_de_pc(K, NOIR));

	set_case(&e, 0, 5, case_t_de_pc(B, BLANC));
	set_case(&e, 7, 5, case_t_de_pc(B, NOIR));

	set_case(&e, 0, 6, case_t_de_pc(N, BLANC));
	set_case(&e, 7, 6, case_t_de_pc(N, NOIR));

	set_case(&e, 0, 7, case_t_de_pc(R, BLANC));
	set_case(&e, 7, 7, case_t_de_pc(R, NOIR));

	return e;
}



piece_t piece_t_de_case_t(case_t ca)
{
	piece_t p;
	p = (ca.entier >> 1);
	return p;
}

couleur_t couleur_t_de_case_t(case_t ca)
{
	couleur_t co;
	int masque = 1;
	co = ca.entier & masque;
	return co;
}



void get_case(echiquier_t e, int i, int j, case_t* ca)
{
	uint32_t nouveau_entier;

//	nouveau_entier = (e.ECHIQUIER[i] << (4 * (7 - j)) >> 28);



	nouveau_entier = e.ECHIQUIER[i];
	nouveau_entier = nouveau_entier >> (4 * j);
	nouveau_entier = nouveau_entier << 28;
	nouveau_entier = nouveau_entier >> 28;


/*	printf("\nValeur echiquier i  : %zu", e.ECHIQUIER[i]);
	printf("\nValeur nouveau_entier : %zu", nouveau_entier);*/
	ca->entier = nouveau_entier;
}

int indice_de_ligne(char a)
{
	return a - '1';
}

char ligne_de_indice(int i)
{
	return i + '1';
}

int indice_de_colonne(char a)
{
	return a - 'A';
}

char colonne_de_indice(int i)
{
	return i + 'A';
}

int char_ligne_valide(char a)
{
	if (a <= '8' && a >= '1')
		return 1;
	else
		return 0;
}

int char_colonne_valide(char a)
{
	if (a <= 'H' && a >= 'A')
		return 1;
	else
		return 0;
}


//PARTIE GESTION DES COUPS WALLEZ
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

echiquier_t jouer_coup(echiquier_t e, char* c)
{
	case_t ca;

	int c1 = indice_de_colonne(c[0]);
	int c2 = indice_de_colonne(c[2]);
	int l1 = indice_de_ligne(c[1]);
	int l2 = indice_de_ligne(c[3]);

	get_case(e, l1, c1, &ca);
	set_case(&e, l2, c2, ca);
	set_case(&e, l1, c1, case_t_de_pc(VIDE, BLANC));

	return e;
}

int coup_valide(char* c, echiquier_t e, couleur_t co)
{
	int v0 = char_colonne_valide(c[0]);
	int v1 = char_ligne_valide(c[1]);
	int v2 = char_colonne_valide(c[2]);
	int v3 = char_ligne_valide(c[3]);


	//	printf("\n%i\n%i\n%i\n%i\n", indice_de_colonne(c[0]), indice_de_ligne(c[1]), indice_de_colonne(c[2]), indice_de_ligne(c[3]));
	case_t cd, cf;
	get_case(e, indice_de_ligne(c[1]), indice_de_colonne(c[0]), &cd);
	get_case(e, indice_de_ligne(c[3]), indice_de_colonne(c[2]), &cf);


	return (v0 && v1 && v2 && v3 && (c[0] != c[2] || c[1] != c[3]) && piece_t_de_case_t(cd) != VIDE && (piece_t_de_case_t(cf) == VIDE || (couleur_t_de_case_t(cf) != couleur_t_de_case_t(cd))));



	/*	if (v0&&v1&&v2&&v3)
	{
	printf("\ncond1\n");

	if (c[0] != c[2] || c[1] != c[3])
	{
	printf("cond2\n");

	if (cd.P != VIDE &&  (cf.C != cd.C))
	{
	printf("cond3\n");
	return 1;
	}

	}
	}*/



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
//PARTIE TEST VU KON C PA SI SA MARCH
int main(int argc, char* argv[])
{
	/*piece_t p;
	p = piece_de_lettre('p');
	printf("%c",lettre_de_piece(p));


	liste_coup lc;
	lc.debut = NULL;
	lc.fin = NULL;

	char c[4];
	c[0] = 'A';
	c[1] = '1';
	c[2] = 'A';
	c[3] = '3';

	creer_coup(&lc, c);
	afficher_echiquier_liste(lc);*/


	/*	echiquier_t e;
	e = init_echiquier();
	set_case(&e, 7, 5, case_t_de_pc(B, NOIR));
	afficher_echiquier_console(e); */
	if (argc != 2)
	{
		printf("\nErreur Syntaxe: commande nom_fichier\n\n");
		return -1;
	}
	jouerPartie_fichier(argv[1]);


	return 0;
}








/*	echiquier_t e = init_echiquier();
	case_t ca;
	ca = case_t_de_pc(p,BLANC);
	printf("\nValeur ca1 entier :  %i  \n", ca.entier);
	get_case(e,4,4, &ca);
	printf("\nValeur echiquier ligne 1 : %zu", e.ECHIQUIER[0]);
	//printf("\nValeur echiquier ligne 4 : %zu", e.ECHIQUIER[4]);
	printf("\nValeur ca2 entier :  %i  \n", ca.entier);
	printf("\nValeur couleur ca : %i \n", couleur_t_de_case_t(ca));
	printf("\nValeur piece ca : %i \n", piece_t_de_case_t(ca));
	printf("\n%c\n%i\n\n", lettre_de_piece(piece_t_de_case_t(ca)), couleur_t_de_case_t(ca));*/
