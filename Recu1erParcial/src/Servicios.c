#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicios.h"
#include "Input.h"
#include "Trabajo.h"

int altaServicios(char servicio, int idServicio)
{
	char servicioElegido;
	int servicioL=0;
	int servicioP=0;
	int servicioC=0;
	int servicioK=0;

	if(servicio!='L' && servicio!='P' && servicio!='C' && servicio!='K' && servicio!='l' && servicio!='p' && servicio!='c' && servicio!='k')
	{
		servicioElegido=verificarServicio(&servicio);
	}
	if(servicio=='L' || servicio=='l')
	{
		servicioL=servicioL+1;
	}
	if(servicio=='P' || servicio=='p')
	{
		servicioP=servicioP+1;
	}
	if(servicio=='C' || servicio=='c')
	{
		servicioC=servicioC+1;
	}
	if(servicio=='K' || servicio=='k')
	{
		servicioK=servicioK+1;
	}

	return servicioElegido;
}

/*
int bajaServicios
{
	int retorno=-1;

	return retorno;
}


int modificarServicios
{
	int retorno=-1;

	return retorno;
}
*/

void listarServicios(int serviciosLimpieza, int serviciosParche, int serviciosCentrado, int serviciosCadena)
{

	printf("Se han listado %d servicios de limpieza, %d servicios de parche, %d servicios de centrado y %d servicios decadena.", serviciosLimpieza, serviciosParche, serviciosCentrado, serviciosCadena);
}
