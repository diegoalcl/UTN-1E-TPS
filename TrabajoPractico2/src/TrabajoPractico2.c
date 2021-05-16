/*TP2 Alderete Diego Fernando 1E
 * Una empresa requiere un sistema para administrar su nómina de empleados.
 * Se sabe quedicha nómina bajo ninguna circunstancia superara los 1000 empleados.
 * El sistema deberá tener el siguiente menú de opciones:
 * 1.ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número de Id.
 * El resto de los campos se le pedirá al usuario.
 * 2.MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellidoo Salario o Sector
 * 3.BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
 * 4.INFORMAR: 1.Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
 * 2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 * NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
 * Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la carga de algún empleado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#define MAX 1000

int main(void)
{
	setbuf(stdout,NULL);

	int opcion;
	char respuesta;
	int altas;
	int modificar;
	int bajas;
	int informar;
	int inicializar;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int id;
	int flagAlMenosUnEmpleado;//para evitar entrar a otra opcion si no tengo empleados cargados
	int buscarId;
	int ordenar;
	int contadorEmpleados;

	id=0;
	flagAlMenosUnEmpleado=0;
	contadorEmpleados=0;

	Employee arrayEmpleados[MAX];

	inicializar=initEmployees(arrayEmpleados, MAX);

	if(inicializar)
	{
		do{
		printf("Ingrese la opción que desea\n1.Altas.\n2.Modificar.\n3.Bajas.\n4.Ordenar.\n5.Mostrar lista.");
		scanf("%d", &opcion);
			switch(opcion)
			{
			case 1:
				fflush(stdin);
				printf("Ingrese el nombre del empleado con Id %d:", id);
				scanf("%d", &id);
				scanf("%s", &nombre);
				printf("Ingrese el apellido:");
				scanf("%s", &apellido);
				printf("Ingrese el salario:");
				scanf("%f", &salario);
				printf("Ingrese el sector:");
				scanf("%d", &sector);

				if(addEmployee(arrayEmpleados, MAX, id, nombre, apellido, salario, sector)==1)
				{
					flagAlMenosUnEmpleado=1;
					printf("Se ha cargado exitosamente al empleado.");
					id++;
					contadorEmpleados++;
				}
				else
				{
					printf("Error. No se ha cargado al empleado.");
				}
				break;
			case 2:
				if(flagAlMenosUnEmpleado)
				{
					printf("Ingrese la Id del empleado que desea modificar:", buscarId);
					scanf("%d", &buscarId);
					modificar=findEmployeeById(arrayEmpleados, MAX, buscarId);
				}
				break;
			case 3:
				if(flagAlMenosUnEmpleado)
				{
					printf("Ingrese la Id del empleado que desea dar de baja:", buscarId);
					scanf("%d", &buscarId);
					bajas=removeEmployee(arrayEmpleados, MAX, buscarId);
				}
				break;
			case 4:
				if(flagAlMenosUnEmpleado)
				{
					printf("Ingrese 1 para ordenar a los empleados alfabeticamente por apellido.");
					scanf("%d", &ordenar);
					informar=sortEmployees(arrayEmpleados, contadorEmpleados, ordenar);
				}
				break;
			case 5:
				if(flagAlMenosUnEmpleado)
				{
					printEmployees(arrayEmpleados, contadorEmpleados);
				}
				break;

			}
		fflush(stdin);
		printf("¿Desea seguir usando el programa?s/n");
		scanf("%c", &respuesta);
		}while(respuesta=='s');//se termina el do while
	}

	return EXIT_SUCCESS;
}
