#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void menu()
{

	char salir='n';
	int opcionNumerica;
	int banderaKm;
	int banderaPrecios;
	int banderaCostosCalculados;
	float km;
	float precioAerolineas;
	float precioLatam;
	float precioAerolineasDebito;
	float precioLatamDebito;
	float precioAerolineasCredito;
	float precioLatamCredito;
	float precioAerolineasBitcoin;
	float precioLatamBitcoin;
	float precioKmAerolineas;
	float precioKmLatam;
	float diferencia;
	int opcionRetornada;

	do{
		printf("\nElija la opci�n que desea:\n1.Ingresar kil�metros.\n2.Ingresar precio de vuelos.\n3.Calcular todos los costos.\n4.Informar resultados.\n");
		printf("5.Carga forzada de datos.\n6.Salir.");
		fflush(stdin);
		scanf("%d", &opcionNumerica);

		switch(opcionNumerica)
		{
			case 1:
				do{
					printf("\nIngrese la cantidad de kil�metros:");
					scanf("%f", &km);
					if(km>0)
					{
					printf("La cantidad de kil�metros ingresada es %.2f.", km);
					banderaKm=1;
					}else{
						printf("La cantidad de kil�metros debe ser mayor a 0.");
					}
				}while(km<0);
				break;
			case 2:
				if(banderaKm==1)
				{
					do{
						printf("\nIngrese el precio del vuelo de Aerol�neas:");
						scanf("%f", &precioAerolineas);
						if(precioAerolineas>0)
						{
						printf("El precio ingresado de Aerol�neas es $%.2f.", precioAerolineas);
						}else{
							printf("El precio debe ser mayor a $0.");
						}
					}while(precioAerolineas<=0);
					do{
						printf("\nIngrese el precio del vuelo de Latam:");
						scanf("%f", &precioLatam);
						if(precioLatam>0){
						printf("El precio ingresado de Latam es $%.2f.", precioLatam);
						}else{
							printf("El precio debe ser mayor a $0.");
						}
					}while(precioLatam<=0);
					banderaPrecios=1;
				}else{
					printf("Error. Debe ingresar la cantidad de kil�metros del vuelo.");
				}
				break;
			case 3:
				if(banderaKm==1 && banderaPrecios==1)
				{
					printf("Calculando costos...");
					banderaCostosCalculados=1;
					system("pause");
					opcionRetornada=costoDebito(&precioAerolineasDebito, precioAerolineas, &precioLatamDebito, precioLatam);
					switch(opcionRetornada)
					{
						case 0:
							printf("No se pudo calcular el costo realizado con tarjeta de d�bito.\n");
							break;
						case 1:
							printf("Costo de tarjeta de d�bito calculado exitosamente.\n");
							break;
					}
					opcionRetornada=costoCredito(&precioAerolineasCredito, precioAerolineas, &precioLatamCredito, precioLatam);
					switch(opcionRetornada)
					{
						case 0:
							printf("No se pudo calcular el costo realizado con tarjeta de cr�dito.\n");
							break;
						case 1:
							printf("Costo de tarjeta de cr�dito calculado exitosamente.\n");
							break;
					}
					opcionRetornada=costoBitcoin(&precioAerolineasBitcoin, precioAerolineas, &precioLatamBitcoin, precioLatam);
					switch(opcionRetornada)
					{
						case 0:
							printf("No se pudo calcular el costo realizado con Bitcoins.\n");
							break;
						case 1:
							printf("Costo con Bitcoins calculado exitosamente.\n");
							break;
					}
					opcionRetornada=precioPorKm(&precioKmAerolineas, precioAerolineas, &precioKmLatam, precioLatam, km);
					switch(opcionRetornada)
					{
						case 0:
							printf("No se pudo calcular el precio por kil�metro.\n");
							break;
						case 1:
							printf("Precio por kil�metro calculado exitosamente.\n");
							break;
					}
					opcionRetornada=diferenciaPrecio(&diferencia, precioAerolineas, precioLatam);
					switch(opcionRetornada)
					{
						case 0:
							printf("No se pudo calcular la diferencia de precio.\n");
							break;
						case 1:
							printf("Diferencia de precio calculada exitosamente.\n");
							break;
					}
				}else{
					printf("Error. Debe ingresar la cantidad de kil�metros y el precio del vuelo.");
				}
				break;
			case 4:
				if(banderaKm==1 && banderaPrecios==1 && banderaCostosCalculados==1)
				{
					informarResultados(km, precioAerolineas, precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin, precioKmAerolineas, precioLatam,
					precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioKmLatam, diferencia);
				}else{
					printf("Error. Debe estar ingresados la cantidad de kil�metros, el precio del vuelo y haber utilizado la funci�n de calcular costos.");
				}
				break;
			case 5:
				km=7090;
				precioAerolineas=162965;
				precioLatam=159339;
				costoDebito(&precioAerolineasDebito, precioAerolineas, &precioLatamDebito, precioLatam);
				costoCredito(&precioAerolineasCredito, precioAerolineas, &precioLatamCredito, precioLatam);
				costoBitcoin(&precioAerolineasBitcoin, precioAerolineas, &precioLatamBitcoin, precioLatam);
				precioPorKm(&precioKmAerolineas, precioAerolineas, &precioKmLatam, precioLatam, km);
				diferenciaPrecio(&diferencia, precioAerolineas, precioLatam);
				informarResultados(km, precioAerolineas, precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin, precioKmAerolineas, precioLatam,
				precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioKmLatam, diferencia);
				break;
			case 6:
				salir='s';
				break;
	        default:
	            printf("Opci�n inv�lida.\n");
	            printf("\n");
	            break;
		}

	}while(salir=='n');

	printf("Programa cerrado con �xito.");
}
