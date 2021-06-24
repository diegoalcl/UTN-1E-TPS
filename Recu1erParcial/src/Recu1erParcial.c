#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Servicios.h"
#include "Input.h"
#include "Trabajo.h"
#define MAX_ARRAY 999

int main(void)
{
	setbuf(stdout,NULL);

	char opcion;
	int idTrabajos=0;
	int idServicios=0;
	int idAModificar=0;
	int banderaTrabajos=0;
	int idADarDeBaja=0;
	int serviciosLimpieza;
	int serviciosParche;
	int serviciosCentrado;
	int serviciosCadena;

	Trabajo arrayTrabajos[MAX_ARRAY];
	//Servicio arrayServicios[MAX_ARRAY];

	Servicio auxiliarServicio;

	auxiliarServicio.id=20000;
	strcpy(auxiliarServicio.descripcion[0],"Limpieza");
	strcpy(auxiliarServicio.descripcion[1],"Parche");
	strcpy(auxiliarServicio.descripcion[2],"Centrado");
	strcpy(auxiliarServicio.descripcion[3],"Cadena");
	auxiliarServicio.precio[0]=250;
	auxiliarServicio.precio[1]=300;
	auxiliarServicio.precio[2]=400;
	auxiliarServicio.precio[3]=350;

	idServicios=auxiliarServicio.id;
	do{
		printf("\nIngrese la opción que desea.\nA.Alta trabajo.\nB.Modificar trabajo.\nC.Baja trabajo.\nD.Listar trabajos.\nE.Listar servicios.\nF.Total precios ");
		printf("\nZ.Salir del programa.\n");
		fflush(stdin);
		scanf("%c", &opcion);
		switch(opcion)
		{
		case 'A':
			//alta trabajo
			altaTrabajo(arrayTrabajos,&idTrabajos,&idServicios);
			break;
		case 'B':
			//modificar trabajo
			if(banderaTrabajos==1)
			{
				printf("\nIngrese el Id del trabajo a modificar:");
				fflush(stdin);
				scanf("%d", &idAModificar);
				modificarTrabajo(arrayTrabajos,idAModificar, &idTrabajos);
			}else{
				printf("Error. No hay trabajos cargados.");
			}
			break;
		case 'C':
			//baja trabajo
			if(banderaTrabajos==1)
			{
				printf("\nIngrese el Id del trabajo a dar de baja:");
				fflush(stdin);
				scanf("%d", &idADarDeBaja);
				bajaTrabajo(arrayTrabajos,idADarDeBaja,&idTrabajos);
			}else{
				printf("Error. No hay trabajos cargados.");
			}
			break;
		case 'D':
			//listar trabajos
			if(banderaTrabajos==1)
			{
				if(!listarTrabajo(arrayTrabajos,idTrabajos))
				{
					printf("\nHubo un error al listar los trabajos.");
				}else
				{
					printf("\nTrabajos listados con éxito.");
				}
			}else{
				printf("Error. No hay trabajos cargados.");
			}
			break;
		case 'E':
			//listar servicios
			if(banderaTrabajos==1)
			{
				listarServicios(serviciosLimpieza,serviciosParche,serviciosCentrado,serviciosCadena);
			}else{
				printf("Error. Aún no se han prestado servicios.");
			}
			break;
		case 'F':
			//total en pesos por los servicios prestados
			if(banderaTrabajos==1)
			{
				printf("\n-----En construcción-----\n");
			//	if(totalPrecioServicios)
			//	{
			//
			//	}
			}else{
				printf("Error. Aún no se han prestado servicios.");
			}
			break;
		default:
			printf("Ha ingresado una opción incorrecta.\n");
			break;
		}
	}while(opcion!='Z');

	return 0;

}

