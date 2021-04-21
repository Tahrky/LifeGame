#pragma once

#include "Generation.hpp"

// VARIABLES GLOBALES
int * tempTab = new int [MAXY * MAXX];

// FONCTIONS
void jeuDeLaVie (int * tableau)
{
	int count = 0;

	for (int i = 1; i < MAXY - 1; i++)
		for (int j = 1; j < MAXX - 1; j++)
			tempTab [i * MAXY + j] = tableau [i * MAXY + j];

	for (int i = 1; i < MAXY - 1; i++)
		for (int j = 1; j < MAXX - 1; j++)
		{
			count += tempTab [(i - 1) * MAXY + (j - 1)];
			count += tempTab [(i - 1) * MAXY + (j)];
			count += tempTab [(i - 1) * MAXY + (j + 1)];
			count += tempTab [i * MAXY + (j - 1)];
			count += tempTab [i * MAXY + (j + 1)];
			count += tempTab [(i + 1) * MAXY + (j - 1)];
			count += tempTab [(i + 1) * MAXY + (j)];
			count += tempTab [(i + 1) * MAXY + (j + 1)];

			// Si la case est vivante avec 2 ou 3 voisins, elle survit
			// Si la case est morte avec 3, elle nait
			tableau [i*MAXY + j] = (count == 3) || (tableau [i*MAXY + j] != 0 && count == 2);

			count = 0;
		}
}

void highLife (int * tableau)
{
	int count = 0;

	for (int i = 1; i < MAXY - 1; i++)
		for (int j = 1; j < MAXX - 1; j++)
			tempTab [i * MAXY + j] = tableau [i * MAXY + j];

	for (int i = 1; i < MAXY - 1; i++)
		for (int j = 1; j < MAXX - 1; j++)
		{
			count += tempTab [(i - 1) * MAXY + (j - 1)];
			count += tempTab [(i - 1) * MAXY + (j)];
			count += tempTab [(i - 1) * MAXY + (j + 1)];
			count += tempTab [i * MAXY + (j - 1)];
			count += tempTab [i * MAXY + (j + 1)];
			count += tempTab [(i + 1) * MAXY + (j - 1)];
			count += tempTab [(i + 1) * MAXY + (j)];
			count += tempTab [(i + 1) * MAXY + (j + 1)];

			// Si la case est vivante avec 2 ou 3 voisins, elle survit
			// Si la case est morte avec 3 ou 6 voisins, elle nait
			tableau [i*MAXY + j] = (count == 3) || (tableau [i*MAXY + j] != 0 && count == 2) || (tableau [i*MAXY + j] != 1 && count == 6);

			count = 0;
		}
}

void jeuDeLaViePlusAleatoire (int * tableau)
{
	int count = 0;

	for (int i = 1; i < MAXY - 1; i++)
		for (int j = 1; j < MAXX - 1; j++)
			tempTab [i * MAXY + j] = tableau [i * MAXY + j];

	for (int i = 1; i < MAXY - 1; i++)
		for (int j = 1; j < MAXX - 1; j++)
		{
			count += tempTab [(i - 1) * MAXY + (j - 1)];
			count += tempTab [(i - 1) * MAXY + (j)];
			count += tempTab [(i - 1) * MAXY + (j + 1)];
			count += tempTab [i * MAXY + (j - 1)];
			count += tempTab [i * MAXY + (j + 1)];
			count += tempTab [(i + 1) * MAXY + (j - 1)];
			count += tempTab [(i + 1) * MAXY + (j)];
			count += tempTab [(i + 1) * MAXY + (j + 1)];

			tableau [i * MAXY + j] = (count == 3) || (tableau [i * MAXY + j] != 0 && count == 2);
			if (rand () % (MAXY * 2) == 0)
				tableau [i*MAXY + j] = 1;

			count = 0;
		}
}

void isAlive (int * tableau, int numRegle = 0)
{
	int count = 0;

	for (int i = 1; i < MAXY - 1; i++)
		for (int j = 1; j < MAXX - 1; j++)
			tempTab [i * MAXY + j] = tableau [i * MAXY + j];

	for (int i = 1; i < MAXY - 1; i++)
		for (int j = 1; j < MAXX - 1; j++)
		{
			count += tempTab [(i - 1) * MAXY + (j - 1)];
			count += tempTab [(i - 1) * MAXY + (j)];
			count += tempTab [(i - 1) * MAXY + (j + 1)];
			count += tempTab [i * MAXY + (j - 1)];
			count += tempTab [i * MAXY + (j + 1)];
			count += tempTab [(i + 1) * MAXY + (j - 1)];
			count += tempTab [(i + 1) * MAXY + (j)];
			count += tempTab [(i + 1) * MAXY + (j + 1)];

			switch (numRegle)
			{
				case 0:
					if (count == 2 || count == 3)
						tableau [i * MAXY + j] = 1;
					else
						tableau [i * MAXY + j] = 0;
					break;
				case 1:
					if (count == 3 || count == 4)
						tableau [i * MAXY + j] = 1;
					else
						tableau [i * MAXY + j] = 0;
					break;
				case 2:
					if (count == 4 || count == 5)
						tableau [i * MAXY + j] = 0;
					else
						tableau [i * MAXY + j] = 1;
					break;
				default: // Correspond aux règles standards du jeu de la vie
					tableau [i * MAXY + j] = (count == 3) || (tableau [i * MAXY + j] != 0 && count == 2);
			}

			count = 0;
		}

}