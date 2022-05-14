#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "inputs.h"

void menu(Passenger list[],int tamanio)
{
	int opcion;
	int retorno;
	int seCargoUnPasajero=0;
	int cantidadPasajeros=0;

	initPassengers(list, tamanio);
    initIds(list, tamanio);
	do{
		printf("\nIngrese la opción que desea:\n1.Alta de pasajero.\n2.Modificar información de pasajero.\n3.Baja de pasajero.\n4.Informes de pasajeros.");
		printf("\n5.Hardcodeo de pasajeros.\n6.Cerrar programa.\n");
		fflush(stdin);
		scanf("%d",& opcion);
		switch(opcion)
		{
			case 1: //Alta: Hecho
	            retorno = loadPassenger(list, tamanio);
	            switch(retorno){
	            case -1:
	                printf("No hay lugar disponible en la lista para guardar un pasajero nuevo.\n");
	                break;
	            case 0:
	                printf("Se ha cargado exitosamente al pasajero.\n");
	                seCargoUnPasajero = 1;
	                cantidadPasajeros=cantidadPasajeros+1;
	                break;
	            case 1:
	                printf("Error. No se ha cargado al pasajero.\n");
	                break;
	            case 2:
	                printf("El usuario cancelo la carga.\n");
	                break;
	            }
	            printf("\n");
				break;
			case 2: //Modificar: hecho
	            if(seCargoUnPasajero == 1){
	                retorno = modificarPasajero(list, tamanio);
	                switch(retorno){
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
	                printf("Debe ingresar al menos un pasajero.\n");
	            }
	            printf("\n");
				break;
			case 3: //Baja=hecho
	            if(seCargoUnPasajero == 1){
	                retorno = deletePassenger(list, tamanio);
	                switch(retorno){
	                case -1:
	                    printf("Error. No se pudo completar la accion.\n");
	                    break;
	                case 0:
	                    printf("Se ha eliminado al pasajero de la lista exitosamente.\n");
	                    break;
	                case 1:
	                    printf("El pasajero no existe.\n");
	                    break;
	                case 2:
	                    printf("El usuario cancelo la accion.\n");
	                    break;
	                }
	            }else{
	                printf("Debe ingresar al menos un pasajero.\n");
	            }
	            printf("\n");
				break;
			case 4: //Infomes=hecho
				if(seCargoUnPasajero == 1){
					retorno = informarPasajeros(list, tamanio, cantidadPasajeros);
					switch(retorno){
					case -1:
						printf("Error. No se puede acceder a la lista de pasajeros.\n");
						break;
					case 1:
						printf("Error. No se pudo realizar el ordenamiento.\n");
						break;
					}
				}else{
					printf("Debe ingresar al menos un pasajero.\n");
				}
				printf("\n");
				break;
			case 5:
				hardcodeoPasajeros(list);
				seCargoUnPasajero = 1;
				printf("Hardcodeo realizado.");
				cantidadPasajeros=cantidadPasajeros+6;
				break;
			case 6:
				printf("Programa cerrado exitosamente.");
				break;
			default:
				printf("Opción inválida.");
				break;
		}
	}while(opcion!=6);
}
