#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "menu.h"
#include "servicio.h"
#include "trabajo.h"
#include "informes.h"

int listarPorMarca(Trabajo* arrayTrabajos, int tamanio, Servicio* arrayServicios)//creo que ahora si anda
{
    int retorno = -1;
    int i;
    int j;
    char auxDescripcion[25];

    Trabajo auxAnio;
    Trabajo auxMarca;
    if(arrayTrabajos != NULL && tamanio > 0)
   	{
    	retorno=1;
    	for (i=0;i<tamanio-1; i++)
    	{
    		for (j=i+1;j<tamanio;j++)
    		{
    			if(strcmp(arrayTrabajos[i].marcaBicicleta,arrayTrabajos[j].marcaBicicleta)>0)
				{
					auxMarca=arrayTrabajos[j];
					arrayTrabajos[j]=arrayTrabajos[i];
					arrayTrabajos[i]=auxMarca;
				}
    		}
    	}//FIN FOR i
    }

    if(arrayTrabajos != NULL && tamanio>0)
    {
        printf("Id-----Marca de Bicicleta--Tamaño de rodado--Id de Servicio---Dia---Mes---Año---Servicio");
        for(i=0; i<tamanio; i++)
        {
            if(arrayTrabajos[i].isEmpty != 0)
            {
                retorno = 1;
                traerDescripcionServicio(arrayServicios, tamanio, arrayTrabajos[i].idServicio, auxDescripcion);
                mostrarUnTrabajo(arrayTrabajos[i], auxDescripcion);
            }
        }
    }
    return retorno;
}

int serviciosConMasTrabajos(Servicio* arrayServicios, int tamanio)
{
	int retorno=0;
	int i;
	int contadorLimpieza=0;
	int contadorParche=0;
	int contadorCentrado=0;
	int contadorCadena=0;

   if(arrayServicios != NULL && tamanio>0){
		for(i=0;i<tamanio;i++){
			if(arrayServicios[i].isEmpty == 1)
			{

				if(stricmp(arrayServicios[i].descripcion,"Limpieza")==0)
				{
					contadorLimpieza++;
				}
				if(stricmp(arrayServicios[i].descripcion,"Parche")==0)
				{
					contadorParche++;
				}
				if(stricmp(arrayServicios[i].descripcion,"Centrado")==0)
				{
					contadorCentrado++;
				}
				if(stricmp(arrayServicios[i].descripcion,"Cadena")==0)
				{
					contadorCadena++;
				}
			}
		}
		if(contadorLimpieza>contadorParche && contadorLimpieza>contadorCentrado && contadorLimpieza>contadorCadena)
		{
			printf("El servicio con mas trabajos es limpieza con %d servicios realizados.\n", contadorLimpieza);
		}else{
			if(contadorParche>contadorCentrado && contadorParche>contadorCadena)
			{
				printf("El servicio con mas trabajos realizados es parche con %d servicios realizados.\n", contadorParche);
			}else{
				if(contadorCentrado>contadorCadena)
				{
					printf("El servicio con mas trabajos realizados es centrado con %d servicios realizados.\n", contadorCentrado);
				}else{
					if(contadorCadena>0)
					{
						printf("El servicio con mas trabajos realizados es cadena con %d servicios realizados.\n", contadorCadena);
					}
				}
			}
		}
	}

	return retorno;
}
