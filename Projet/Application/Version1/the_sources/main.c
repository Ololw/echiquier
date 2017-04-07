#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("\nErreur Syntaxe: commande nom_fichier\n\n");
		return -1;
	}

	jouerPartie_fichier(argv[1]);
	return 0;
}
