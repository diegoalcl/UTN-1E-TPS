/* Alderete Diego Fernando TP N2*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "menu.h"

#define TAMANIO 2000

int main(void)
{
	setbuf(stdout, NULL);

    Passenger lista[TAMANIO];

    menu(lista, TAMANIO);

	return EXIT_SUCCESS;
}
