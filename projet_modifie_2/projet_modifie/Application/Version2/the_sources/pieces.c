/*
	ECHEVET Theo
	CUZIN Florian
*/
#include <stdio.h>
#include <stdlib.h>
#include "../the_headers/pieces.h"
#include <stdint.h>

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
