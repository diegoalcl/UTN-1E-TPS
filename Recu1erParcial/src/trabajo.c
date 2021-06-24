#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Servicios.h"
#include "Input.h"
#include "Trabajo.h"

void altaTrabajo(Trabajo* arrayTrabajos, int* idTrabajos, int* idServicio)
{
	char marca[50];
	int rodado=-1;
	int auxIdServicio;
	int auxDia=0;
	int auxMes=0;
	int auxAnio=0;
	int auxId=0;
	int cargaOk=0;
	char servicio;

	Servicio auxiliarServicio;

	Trabajo auxiliar;

	*idTrabajos=*idTrabajos+1;
	auxiliar.id=*idTrabajos;
	auxId=*idTrabajos;

	auxiliarServicio.id=*idServicio;
	auxIdServicio=*idServicio;


		printf("\nIngrese la marca de la nueva bicicleta:");
		fflush(stdin);
		scanf("%s", marca);
		if(verificarPalabra(marca))
		{
			printf("\nError. Nombre inválido de marca.");
		}else{
			strcpy(auxiliar.marcaBicicleta,marca);
			printf("\nIngrese el tamaño de rodado de la bicicleta:");
			fflush(stdin);
			scanf("%d", &rodado);

			if(!verificarRodado(rodado))
			{
				printf("\nError. Formato inválido para el rodado.");
			}else{
				auxiliar.rodadoBicicleta=rodado;
				if(!verificarIdServicio(*idServicio))
				{
					printf("\nError. No se encontró ID de servicio.");
				}else{
					printf("\nEl id correspondiente a su trabajo es %d.\n", auxIdServicio);
					printf("\n¿Que servicio desea realizarle?L para limpieza, P para parche, C para centrado y K para cadena:");
					scanf("%c", &servicio);
					altaServicios(servicio, auxIdServicio);
					printf("\nIngrese en formato de número entero el día:");
					fflush(stdin);
					scanf("%d", &auxDia);
					if(!verificarDia(auxDia))
					{
						printf("\nError. Día inválido.");
					}else{
						auxiliar.fecha[0]=auxDia;
						printf("\nIngrese en formato de número entero el mes:");
						fflush(stdin);
						scanf("%d", &auxMes);
						if(!verificarMes(auxMes))
						{
							printf("\nError. Mes inválido.");
						}else{
							auxiliar.fecha[1]=auxMes;
							printf("\nIngrese en formato de número entero el anio(entre 1900 y 2040):");
							fflush(stdin);
							scanf("%d", &auxAnio);
							if(!verificarAnio(auxAnio))
							{
								printf("\nError. Anio inválido.");
							}
							else{
								printf("\nSe ha cargado exitosamente el nuevo trabajo.");
								*idServicio=*idServicio+1;// no estoy seguro que se tengan que aumentar asi las id de servicio
								auxiliarServicio.id=*idServicio;
								auxiliar.fecha[2]=auxAnio;
								cargaOk=1;
							}
						}
					}
				}

			}
		}

	fflush(stdin);
	if(cargaOk==1)
	{
	arrayTrabajos[auxId]=auxiliar;
	printf("\nId: %d Marca : %s Rodado : %d Dia : %d Mes : %d Anio: %d", arrayTrabajos[auxId].id, arrayTrabajos[auxId].marcaBicicleta,
	arrayTrabajos[auxId].rodadoBicicleta,arrayTrabajos[auxId].fecha[0],arrayTrabajos[auxId].fecha[1],arrayTrabajos[auxId].fecha[2]);
	}else{
		*idTrabajos=*idTrabajos-1;
		auxiliar.id=*idTrabajos;
	}
}


void bajaTrabajo(Trabajo* arrayTrabajos, int idADarDeBaja, int* idTrabajos)
{
	int auxIdTrabajos=0;
	char opcion;

	Trabajo auxiliar;

	auxIdTrabajos=*idTrabajos;//fijar para usar puntero directamente

	if(idADarDeBaja>0 && idADarDeBaja>auxIdTrabajos)
	{
		printf("Error.No hay trabajo con ese Id.");
	}else{
		printf("La Id es válida.");
		printf("El trabajo a modificar es \nId: %d Marca : %s Rodado : %d Dia : %d Mes : %d Anio: %d", arrayTrabajos[auxIdTrabajos].id,
	arrayTrabajos[auxIdTrabajos].marcaBicicleta,arrayTrabajos[auxIdTrabajos].rodadoBicicleta,arrayTrabajos[auxIdTrabajos].fecha[0],
	arrayTrabajos[auxIdTrabajos].fecha[1],arrayTrabajos[auxIdTrabajos].fecha[2]);{
		printf("\n¿Esta segur@ que desea darlo de baja?S/N");
		}
		fflush(stdin);
		scanf("%c", &opcion);
		if(opcion=='S' || opcion == 'N' || opcion == 's' || opcion=='n')
		{
			if(opcion=='S' || opcion=='s')
			{
				auxiliar.id=-1;
				arrayTrabajos[idADarDeBaja]=auxiliar;
			}else{
				printf("No se ha dado nada de baja.");
			}
		}else{
			while(opcion!='S' || opcion!='N' || opcion!='s' || opcion!='n')
			printf("Opcion inválida.Escriba S para darlo de baja o N para no darlo de baja.");
			fflush(stdin);
			scanf("%c", &opcion);
			}
		}

}

void modificarTrabajo(Trabajo* arrayTrabajos, int idAModificar, int* idTrabajos)
{
	int auxIdTrabajos=0;
	char opcion;
	char marca[50];
	char servicio;//no se si se refiere a esto el enunciado

	Trabajo auxiliar;

	auxIdTrabajos=*idTrabajos;//fijar para usar puntero directamente

	if(idAModificar>0 && idAModificar>auxIdTrabajos)
	{
		printf("Error.No hay trabajo con ese Id.");
	}else{
		printf("La Id es válida.");
		printf("El trabajo a modificar es \nId: %d Marca : %s Rodado : %d Dia : %d Mes : %d Anio: %d", arrayTrabajos[auxIdTrabajos].id,
	arrayTrabajos[auxIdTrabajos].marcaBicicleta,arrayTrabajos[auxIdTrabajos].rodadoBicicleta,arrayTrabajos[auxIdTrabajos].fecha[0],
	arrayTrabajos[auxIdTrabajos].fecha[1],arrayTrabajos[auxIdTrabajos].fecha[2]);
		do{
			printf("\nIngrese que desea modificar.\nA.Marca de la bicicleta.\nB.Servicio.\n Z.Volver al menú principal.");
			scanf(" %c", &opcion);
			switch(opcion)
			{
			case 'A':
				printf("¿Que nueva marca desea asignar?");
				fflush(stdin);
				scanf("%s", marca);
				if(verificarPalabra(marca))
				{
					printf("Error. Marca inválida.");
				}else{
					strcpy(auxiliar.marcaBicicleta,marca);
					arrayTrabajos[idAModificar]=auxiliar;
					printf("Nueva marca cargada exitosamente.");
				}
				break;
			case 'B':
				printf("¿Que nuevo servicio desea asignar?Ingrese L para limpieza, P para parche, C para centrado y K para cadena.");
				fflush(stdin);
				scanf("%c", &servicio);
				if(servicio!= 'L' && servicio!= 'P' && servicio!= 'C' && servicio!= 'K' && servicio!= 'l' && servicio!= 'p' && servicio!='c' && servicio!= 'k')
				{
					printf("Error. Servicio inválido.");
				}else{
					//strcpy(auxiliar.marcaBicicleta,marca); no se que se hace con estos servicios
					//arrayTrabajos[idAModificar]=auxiliar; no se que se hace con estos servicios
					printf("Nuevo servicio cargada exitosamente.");
				}
				break;
			case 'Z':
				printf("Submenú cerrado exitosamente.");
				break;
			default:
				printf("Error.\nIngrese que desea modificar.\nA.Marca de la bicicleta.\nB.Servicio.\n Z.Volver al menú principal.");
				break;
			}
		}while(opcion!='A' && opcion !='B' && opcion !='C');
	}

}


int listarTrabajo(Trabajo* arrayTrabajos, int idTrabajos)
{
	int i=0;
	int retorno=-1;
	int j=0;
	int k=0;
	int limite=idTrabajos+1;

	Trabajo auxAnio;
	Trabajo auxMarca;

	/*for(j=1;j<limite;j++)
		{
			printf("\nId: %d Marca : %s Rodado : %d Dia : %d Mes : %d Anio: %d", arrayTrabajos[j].id, arrayTrabajos[j].marcaBicicleta,
			arrayTrabajos[j].rodadoBicicleta,arrayTrabajos[j].fecha[0],arrayTrabajos[j].fecha[1],arrayTrabajos[j].fecha[2]);
		}*/
	//me muestra el array previo a ser ordenado


	if(arrayTrabajos != NULL && limite > 0)
	{
		retorno=1;
		for (i=1;i<limite-1; i++)
		{
			for (j=i+1;j<limite;j++)
			{
				if(arrayTrabajos[i].fecha[2] < arrayTrabajos[j].fecha[2])
				{
					auxAnio= arrayTrabajos[i];
					arrayTrabajos[i] = arrayTrabajos[j];
					arrayTrabajos[j] = auxAnio;
				}
				if(arrayTrabajos[i].fecha[2] == arrayTrabajos[j].fecha[2])
				{
					if(strcmp(arrayTrabajos[i].marcaBicicleta,arrayTrabajos[j].marcaBicicleta)>0)
					{
						auxMarca=arrayTrabajos[j];
						arrayTrabajos[j]=arrayTrabajos[i];
						arrayTrabajos[i]=auxMarca;
					}
				}
			}
		}//FIN FOR i
	}else{
		retorno=0;
	}

	for(k=1;k<limite;k++)
	{
		printf("\nId: %d Marca : %s Rodado : %d Dia : %d Mes : %d Anio: %d", arrayTrabajos[k].id, arrayTrabajos[k].marcaBicicleta,
		arrayTrabajos[k].rodadoBicicleta,arrayTrabajos[k].fecha[0],arrayTrabajos[k].fecha[1],arrayTrabajos[k].fecha[2]);
	}
	return retorno;
}
