#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
	int i;
	int retorno;
	retorno = 0;
	if(list != NULL && len >0)
	{
		for(i=0;i<len;++i)
		{
			list[i].isEmpty=1;
		}
		retorno = 1;
	}
	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{

	int retorno = -1;
	int i;
	if(list != NULL && len > -1)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				strcpy(list[id].name,name);
				strcpy(list[id].lastName,lastName);
				list[id].salary=salary;
				list[id].sector=sector;
				retorno = 1;
				break;
			}
		}
	}
	return retorno;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int retorno=-1;
	int opcion;
			if(list!=NULL && list[id].isEmpty!=0)
			{
				printf("Id= %d - Nombre Completo: %s %s", id, list[id].name, list[id].lastName);
				printf(" - Salario $%.2f - Sector %d.", list[id].salary, list[id].sector);
				printf("\n1-Modificar nombre - 2-Modificar apellido - 3-Modificar salario - 4-Modificar sector");
				scanf("%d", &opcion);
				switch(opcion)
				{
					case 1:
						fflush(stdin);
						printf("Ingrese el nuevo nombre:");
						scanf("%s", list[id].name);
						break;
					case 2:
						fflush(stdin);
						printf("Ingrese el nuevo apellido:");
						scanf("%s", list[id].lastName);
						break;
					case 3:
						fflush(stdin);
						printf("Ingrese el nuevo salario:");
						scanf("%f", &list[id].salary);
						break;
					case 4:
						fflush(stdin);
						printf("Ingrese el nuevo sector:");
						scanf("%d", &list[id].sector);
						break;
				}

			}
			else
			{
				printf("Error. No se encontro un empleado con ese Id.");
			}

	return retorno;
}

int removeEmployee(Employee* list, int len, int id)
{
	int retorno;
	retorno = -1;
	if(list != NULL && len > -1)
	{
		list[id].isEmpty = 0;
	}

	return retorno;
}

int sortEmployees(Employee* list, int len, int order)
{
	int i;
	int j;
	Employee auxiliarLastName;

	for(i=0;i<len-1;i++)
	{
		if(list[i].lastName==-1)
		{
			continue;
		}
		for(j=i+1;j<len;j++)
		{
			if(list[j].lastName==-1)
			{
				continue;
			}
			if(strcmp(list[i].lastName,list[j].lastName)>0)
			{
				auxiliarLastName=list[j];
				list[j]=list[i];
				list[i]=auxiliarLastName;
			}
		}
	}
	return 0;
}
int printEmployees(Employee* list, int length)
{
	int i;
	float totalSalarios;
	float promedioSalarios;
	int id;
	int arribaPromedio;
	int idAux;

	id=0;
	idAux=0;
	totalSalarios=0;
	arribaPromedio=0;

	for(i=0;i<length;i++)
	{
		if(list[length].id!=-1)
		{
			printf("\n%s %s - %d", list[i].name, list[i].lastName, list[i].sector);
		}
	}
	for(i=0;i<length;i++)
	{
		totalSalarios=totalSalarios+list[id].salary;
		id++;
	}
	promedioSalarios=totalSalarios/length;
	printf("\nEl total de los salarios es $%.2f y el promedio total es $%.2f", totalSalarios, promedioSalarios);
	for(i=0;i<length;i++)
	{
		if(list[idAux].salary>promedioSalarios)
		{
			arribaPromedio++;
		}
		idAux++;
	}
	printf("\nLa cantidad de empleados con un salario mayor al promedio es de %d.", arribaPromedio);
	return 0;
}
