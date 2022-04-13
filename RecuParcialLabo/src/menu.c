#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "menu.h"
#include "servicio.h"
#include "trabajo.h"
#include "informes.h"

void menu(Servicio arrayServicios[], Trabajo arrayTrabajos[], int tamanio)
{
	int opcionRetornada;
	char opcion;
	int idTrabajoAModificar=0;
	int idServicios=19999;
	int idTrabajos=0;
	int banderaTrabajos=0;
	char conoceIdTrabajos;
	int totalPrecio;



//	inicializarIdTrabajos(arrayTrabajos, tamanio);//inicializo los id de los trabajos en 0
	inicializarTrabajos(arrayTrabajos, tamanio);
//	inicializarIdServicios(arrayServicios, tamanio);//inicializo los id de los trabajos en 20000
	inicializarServicios(arrayServicios, tamanio);


	do{
		printf("\nIngrese la opción que desea.\nA.Alta trabajo.\nB.Modificar trabajo.\nC.Baja trabajo.\nD.Listar trabajos.\nE.Listar servicios.\nF.Total precios.");
		printf("\nG. Informes.\nZ.Salir del programa.\n");
		fflush(stdin);
		scanf("%c", &opcion);
		switch(opcion)
		{
		case 'A':
			opcionRetornada=altaTrabajo(arrayTrabajos, tamanio, &idServicios, &idTrabajos, arrayServicios);
			switch(opcionRetornada)
			{
			case -1:
				printf("\nError. No se pudo ingresar a la función del alta.");
				break;
			case 0:
				printf("\nSe ha cargado exitosamente el nuevo trabajo.");
				banderaTrabajos=1;
				break;
			case 1:
				printf("\nError. Nombre inválido de marca.");
				break;
			case 2:
				printf("\nError. Formato inválido para el rodado.");
				break;
			case 3:
				printf("\nError. No se encontró ID de servicio.");
				break;
			}
			//alta trabajo
			break;
		case 'B'://modificar trabajo
            if(banderaTrabajos == 1)
            {
                opcionRetornada = modificarTrabajo(arrayTrabajos, tamanio, arrayServicios);
                switch(opcionRetornada)
                {
                case -1:
                    printf("Error. No se encontro el dato.\n");
                    break;
                case 0:
                    printf("El usuario cancelo la accion.\n");
                    break;
                case 1:
                    printf("Se han cargado exitosamente los datos.\n");
                    break;
                }
            }else{
                printf("Debe ingresar al menos un empleado.\n");
            }
            printf("\n");
            system("pause");
            break;
		case 'C':
			//baja trabajo
            if(banderaTrabajos == 1)
            {
                opcionRetornada = bajaTrabajo(arrayTrabajos, tamanio, arrayServicios);
                switch(opcionRetornada)
                {
                case -1:
                    printf("Error. No se pudo completar la accion.\n");
                    break;
                case 0:
                    printf("Se ha eliminado al trabajo de la lista exitosamente.\n");
                    break;
                case 1:
                    printf("El trabajo no existe.\n");
                    break;
                case 2:
                    printf("El usuario cancelo la accion.\n");
                    break;
                }
			}else{
				printf("Error. No hay ningún trabajo cargado.");
			}
			break;
		case 'D':
			//listar trabajos
			if(banderaTrabajos==1)
			{
				listarTrabajos(arrayTrabajos, tamanio, arrayServicios);
			}else{
				printf("Error. No hay ningún trabajo cargado.");
			}
			break;
		case 'E':
			if(banderaTrabajos==1)
			{
				listarServicios(arrayServicios, tamanio);
			}else{
				printf("Error. No hay ningún trabajo cargado.");
			}
			//lista servicios
			break;
		case 'F':
			if(banderaTrabajos==1)
			{
				totalPrecio=precioTotal(arrayServicios, tamanio);
				printf("El precio total de los servicios es $%d", totalPrecio);
			}else{
				printf("Error. No hay ningún trabajo cargado.");
			}
			//total en pesos por los servicios prestados
			break;
		case 'G':
			if(banderaTrabajos==1)
			{
				printf("Elija la opción que desea.\n1.Para ver todos los trabajos realizados ordenados alfabeticamente por marca.\n2.El o los servicios mas realizados.");
				scanf("%d", &opcionRetornada);
				switch(opcionRetornada)
				{
				case 1:
					listarPorMarca(arrayTrabajos, tamanio, arrayServicios);
					break;
				case 2:
					serviciosConMasTrabajos(arrayServicios, tamanio);
					break;
				}

			}else{
				printf("Error. No hay ningún trabajo cargado.");
			}
			break;
		case 'Z':
			printf("Programa cerrado con éxito.");
			break;
		default:
			printf("Ha ingresado una opción incorrecta.\n");
			break;
		}
	}while(opcion!='Z');

}



