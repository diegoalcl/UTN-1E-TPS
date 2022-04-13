#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "menu.h"
#include "servicio.h"
#include "trabajo.h"
#define MAX 1000

int main(void)
{
	setbuf(stdout, NULL);

	Servicio arrayServicios[MAX];
	Trabajo arrayTrabajos[MAX];

	menu(arrayServicios, arrayTrabajos, MAX);

	void menu();


	return EXIT_SUCCESS;
}
