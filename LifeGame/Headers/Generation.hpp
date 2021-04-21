#pragma once

#include <cstdlib>
#include <ctime>

// VARIABLES GLOBALES
const int MAXX = 300;
const int MAXY = 300;

// FONCTIONS
// Permet de faire des tests et des mesures sur la première itération
void damier (int * tableau)
{
	for (int i = 1; i < MAXY - 1; i++)
		for (int j = 1; j < MAXX - 1; j++)
		{
			if (i % 2 == 0)
				j % 2 == 0 ? tableau [i * MAXY + j] = 2 : tableau [i * MAXY + j] = 3;
			else
				j % 2 == 0 ? tableau [i * MAXY + j] = 3 : tableau [i * MAXY + j] = 2;
		}
}

void generationAleatoire (int * tableau)
{
	for (int i = 1; i < MAXY - 1; i++)
		for (int j = 1; j < MAXX - 1; j++)
		{
			tableau [i * MAXX + j] = rand () % 10 == 1 ? 1 : 0;
		}
}

void prototypeCarreDeux (int * tableau, int x = 0, int y = 0)
{
	tableau [(x)* MAXY + (y)] = 1;
	tableau [(x)* MAXY + (y + 1)] = 1;
	tableau [(x + 1) * MAXY + (y)] = 1;
	tableau [(x + 1) * MAXY + (y + 1)] = 1;
}

void prototypeCanonPlaneur30 (int * tableau, int x = 0, int y = 0)
{
	if (x >= MAXY - 20)
		x = 0;

	if (y >= MAXX - 45)
		y = 0;

	prototypeCarreDeux (tableau, 7 + x, 2 + y);
	prototypeCarreDeux (tableau, 5 + x, 36 + y);

	tableau [(x + 3) * MAXY + (y + 32)] = 1;
	tableau [(x + 4) * MAXY + (y + 32)] = 1;

	tableau [(x + 4) * MAXY + (y + 15)] = 1;
	tableau [(x + 5) * MAXY + (y + 14)] = 1;
	tableau [(x + 5) * MAXY + (y + 16)] = 1;
	tableau [(x + 6) * MAXY + (y + 13)] = 1;
	tableau [(x + 6) * MAXY + (y + 17)] = 1;
	tableau [(x + 6) * MAXY + (y + 18)] = 1;
	tableau [(x + 7) * MAXY + (y + 13)] = 1;
	tableau [(x + 7) * MAXY + (y + 17)] = 1;
	tableau [(x + 7) * MAXY + (y + 18)] = 1;
	tableau [(x + 8) * MAXY + (y + 13)] = 1;
	tableau [(x + 8) * MAXY + (y + 17)] = 1;
	tableau [(x + 8) * MAXY + (y + 18)] = 1;
	tableau [(x + 9) * MAXY + (y + 14)] = 1;
	tableau [(x + 9) * MAXY + (y + 16)] = 1;
	tableau [(x + 10) * MAXY + (y + 15)] = 1;

	tableau [(x + 2) * MAXY + (y + 27)] = 1;
	tableau [(x + 3) * MAXY + (y + 24)] = 1;
	tableau [(x + 3) * MAXY + (y + 25)] = 1;
	tableau [(x + 3) * MAXY + (y + 26)] = 1;
	tableau [(x + 3) * MAXY + (y + 27)] = 1;
	tableau [(x + 4) * MAXY + (y + 23)] = 1;
	tableau [(x + 4) * MAXY + (y + 24)] = 1;
	tableau [(x + 4) * MAXY + (y + 25)] = 1;
	tableau [(x + 4) * MAXY + (y + 26)] = 1;
	tableau [(x + 5) * MAXY + (y + 23)] = 1;
	tableau [(x + 5) * MAXY + (y + 26)] = 1;
	tableau [(x + 6) * MAXY + (y + 23)] = 1;
	tableau [(x + 6) * MAXY + (y + 24)] = 1;
	tableau [(x + 6) * MAXY + (y + 25)] = 1;
	tableau [(x + 6) * MAXY + (y + 26)] = 1;
	tableau [(x + 7) * MAXY + (y + 24)] = 1;
	tableau [(x + 7) * MAXY + (y + 25)] = 1;
	tableau [(x + 7) * MAXY + (y + 26)] = 1;
	tableau [(x + 7) * MAXY + (y + 27)] = 1;
	tableau [(x + 8) * MAXY + (y + 27)] = 1;
}

// Ne fonctionne pas
void prototypeCanonPlaneur46 (int * tableau, int x = 5, int y = 5)
{

	if (x >= MAXY - 30 && x < 5)
		x = 5;

	if (y >= MAXX - 50 && y < 5)
		y = 5;

	prototypeCarreDeux (tableau, 2 + x, 2 + y);
	prototypeCarreDeux (tableau, 9 + x, 2 + y);
	prototypeCarreDeux (tableau, 7 + x, 33 + y);
	prototypeCarreDeux (tableau, 34 + x, 26 + y);
	prototypeCarreDeux (tableau, 34 + x, 33 + y);

	tableau [(x + 2) * MAXY + (y + 18)] = 1;
	tableau [(x + 2) * MAXY + (y + 19)] = 1;
	tableau [(x + 2) * MAXY + (y + 20)] = 1;
	tableau [(x + 3) * MAXY + (y + 16)] = 1;
	tableau [(x + 3) * MAXY + (y + 20)] = 1;
	tableau [(x + 4) * MAXY + (y + 15)] = 1;
	tableau [(x + 4) * MAXY + (y + 20)] = 1;
	tableau [(x + 5) * MAXY + (y + 15)] = 1;
	tableau [(x + 5) * MAXY + (y + 19)] = 1;
	tableau [(x + 7) * MAXY + (y + 15)] = 1;
	tableau [(x + 7) * MAXY + (y + 19)] = 1;
	tableau [(x + 8) * MAXY + (y + 15)] = 1;
	tableau [(x + 8) * MAXY + (y + 20)] = 1;
	tableau [(x + 9) * MAXY + (y + 16)] = 1;
	tableau [(x + 9) * MAXY + (y + 20)] = 1;
	tableau [(x + 10) * MAXY + (y + 18)] = 1;
	tableau [(x + 10) * MAXY + (y + 19)] = 1;
	tableau [(x + 10) * MAXY + (y + 20)] = 1;

	tableau [(x + 16) * MAXY + (y + 27)] = 1;
	tableau [(x + 16) * MAXY + (y + 33)] = 1;
	tableau [(x + 17) * MAXY + (y + 26)] = 1;
	tableau [(x + 17) * MAXY + (y + 27)] = 1;
	tableau [(x + 17) * MAXY + (y + 28)] = 1;
	tableau [(x + 17) * MAXY + (y + 32)] = 1;
	tableau [(x + 17) * MAXY + (y + 33)] = 1;
	tableau [(x + 17) * MAXY + (y + 34)] = 1;
	tableau [(x + 18) * MAXY + (y + 25)] = 1;
	tableau [(x + 18) * MAXY + (y + 26)] = 1;
	tableau [(x + 18) * MAXY + (y + 28)] = 1;
	tableau [(x + 18) * MAXY + (y + 32)] = 1;
	tableau [(x + 18) * MAXY + (y + 34)] = 1;
	tableau [(x + 18) * MAXY + (y + 35)] = 1;
	tableau [(x + 21) * MAXY + (y + 28)] = 1;
	tableau [(x + 21) * MAXY + (y + 32)] = 1;
	tableau [(x + 22) * MAXY + (y + 28)] = 1;
	tableau [(x + 22) * MAXY + (y + 32)] = 1;
}