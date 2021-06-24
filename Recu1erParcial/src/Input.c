#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Servicios.h"
#include "Input.h"
#include "Trabajo.h"

int verificarPalabra(char cadena[])
{
    int i;
    int bandera = 0;
    int esEspacio = 0;
    int tam = strlen(cadena);
    for(i=0; i<tam; i++)
    {
        if(cadena[i] != '\0')
        {
            if ((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A'||cadena[i]>'Z') && cadena[i]!=' ')
            {
                bandera=-1;
            }
            if(cadena[i]!=' ')
            {
                esEspacio = -1;
            }
        }
    }
    if(esEspacio == 0)
    {
        bandera=-1;
    }
    return bandera;
}

int verificarRodado(int numero)
{
	int retorno=0;
	if(!isdigit(numero))
	{
		if(numero>11 && numero <31)
		{
		retorno=1;
		}
	}
    return retorno;
}

int verificarDia(int numero)
{
	int retorno=-1;
	if(!isdigit(numero))
	{
		if(numero>0 && numero<32)
		{
			retorno=1;
		}else{
			retorno=0;
		}
	}
	return retorno;
}

int verificarMes(int numero)
{
	int retorno=-1;

	if(!isdigit(numero))
	{
		if(numero>0 && numero<13)
		{
			retorno=1;
		}else{
			retorno=0;
		}
	}

	return retorno;
}

int verificarAnio(int numero)
{
	int retorno=-1;

	if(!isdigit(numero))
	{
		if(numero>1899 && numero<2041)
		{
			retorno=1;
		}else{
			retorno=0;
		}
	}

	return retorno;
}

int verificarIdServicio(int numero)
{
	int retorno=-1;

	if(!isdigit(numero))
	{
		if(numero>19999)
		{
			retorno=1;
		}else{
			retorno=0;
		}
	}

	return retorno;

}

char verificarServicio(char* eleccionServicio)
{
    char servicio;
    fflush(stdin);
    scanf("%c", &servicio);
    while(servicio!='L' && servicio!='P' && servicio!='C' && servicio!='K' && servicio!='l' && servicio!='p' && servicio!='c' && servicio!='k')
    {
        printf("\nError. L para limpieza, P para parche, C para centrado y K para cadena.\n");
        fflush(stdin);
        scanf("%c", &servicio);
    }
    return servicio;
}

