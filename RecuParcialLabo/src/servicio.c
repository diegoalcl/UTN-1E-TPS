#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "menu.h"
#include "servicio.h"
#include "trabajo.h"

void listarServicios(Servicio* arrayServicios, int tamanio)
{
	int i;
	if(arrayServicios!=NULL && tamanio>0)
	{
		printf("Id del servicio-----Descripción----Precio");//emprolijar
		for(i=0;i<tamanio;i++)
		{
			if(arrayServicios[i].isEmpty==1)
			{
				printf("\n");
				printf("%5d", arrayServicios[i].id);
				printf("%10s\t", arrayServicios[i].descripcion);
				printf("$");
				printf("%d", arrayServicios[i].precio);
			}
		}
	}
}

int inicializarIdServicios(Servicio* arrayServicios, int tamanio)
{
    int i;
    int retorno = -1;
    if(arrayServicios != NULL && tamanio>0)
    {
        for(i=0; i<tamanio; i++){
        	arrayServicios[i].id = 0;
            retorno = 0;
        }
    }

   // printf("%d", auxId.id);

    return retorno;

}

int inicializarServicios(Servicio* arrayServicios, int tamanio)
{
    int i;
    int retorno = -1;
    if(arrayServicios != NULL && tamanio>0)
    {
        for(i=0; i<tamanio; i++)
        {
        	arrayServicios[i].isEmpty = 0;
            retorno = 0;
        }
    }
    return retorno;
}

int conseguirIdServicio(Servicio* arrayServicios, int tamanio)
{
    int retorno = -1;
    int flag = 0;
    int newId;
    if(arrayServicios != NULL && tamanio>0){
        int i;
        for(i=0;i<tamanio;i++)
		{
            if(flag == 0 || arrayServicios[i].id>newId)
            {
                newId = arrayServicios[i].id;
                flag = 1;
                printf("\n%d\n", newId);
            }
        }
        retorno = newId;
    }
    return retorno;
}

int fijarPrecio(int servicio)
{
	int retorno=-1;

		switch(servicio)
		{
		case 1:
			retorno=250;
			break;
		case 2:
			retorno=300;
			break;
		case 3:
			retorno=400;
			break;
		case 4:
			retorno=350;
			break;
		}

	return retorno;
}
int buscaLibreServicio(Servicio* arrayServicios, int tamanio)
{
	int i;
	int retorno=-1;

	if(arrayServicios!= NULL && tamanio>0)
	{
        for(i=0; i<tamanio; i++)
        {
        	if(arrayServicios[i].isEmpty==0)
        	{
            retorno = i;
            break;
        	}
        }
	}
	return retorno;
}

int traerDescripcionServicio(Servicio* arrayServicios, int tamanio, int buscar, char* descripcion)
{
	int i;
	int retorno = -1;

	for(i=0; i<tamanio; i++)
	{
		if(arrayServicios[i].id==buscar && arrayServicios[i].isEmpty==1)
		{
			strcpy(descripcion, arrayServicios[i].descripcion);
			retorno=0;
		}
	}
	return retorno;
}

int buscarServicioPorId(Servicio* arrayServicios, int tamanio, int id)
{
    int retorno = -1;
    int i;
    if(arrayServicios != NULL && tamanio>0){
        for(i=0;i<tamanio;i++)
        {
            if(arrayServicios[i].isEmpty == 1)
            {
                if(arrayServicios[i].id == id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}

int servicioADescripcion(int servicio, char* descripcion)
{
	int retorno=0;

	if(descripcion!=NULL && servicio<5 && servicio>0)
	{
		retorno=1;
			switch(servicio)
			{
				case 1:
					strcpy(descripcion, "Limpieza");
					break;
				case 2:
					strcpy(descripcion, "Parche");
					break;
				case 3:
					strcpy(descripcion, "Centrado");
					break;
				case 4:
					strcpy(descripcion, "Cadena");
					break;
			}
	}

	return retorno;
}

int eliminarServicio(Servicio* arrayServicios, int tamanio, int id)
{
    int retorno = -1;
    int i;
    if(arrayServicios != NULL && tamanio>0){
        for(i=0;i<tamanio;i++){
            if(arrayServicios[i].isEmpty == 1){
                if(arrayServicios[i].id == id){
                	arrayServicios[i].isEmpty = 0;
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int precioTotal(Servicio* arrayServicios, int tamanio)
{
	int retorno=0;
	int i;

   if(arrayServicios != NULL && tamanio>0){
		for(i=0;i<tamanio;i++){
			if(arrayServicios[i].isEmpty == 1)
			{
				retorno=retorno+arrayServicios[i].precio;

			}
		}
	}
	return retorno;
}

int descripcionAServicio(char* descripcion, int* servicio)
{
	int retorno=0;

	if(descripcion!=NULL && servicio!=NULL){
		if(stricmp(descripcion,"Limpieza")==0)
		{
			*servicio=1;
			retorno=1;
		}
		if(stricmp(descripcion,"Parche")==0)
		{
			*servicio=2;
			retorno=1;
		}
		if(stricmp(descripcion,"Centrado")==0)
		{
			*servicio=3;
			retorno=1;
		}
		if(stricmp(descripcion,"Cadena")==0)
		{
			*servicio=4;
			retorno=1;
		}
	}
	return retorno;
}


