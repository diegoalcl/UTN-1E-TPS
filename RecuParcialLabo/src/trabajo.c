#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"
#include "menu.h"
#include "servicio.h"
#include "trabajo.h"
#define MAX 1000

int inicializarIdTrabajos(Trabajo* arrayTrabajos, int tamanio)
{
    int i;
    int retorno = -1;
    if(arrayTrabajos != NULL && tamanio>0){
        for(i=0; i<tamanio; i++){
        	arrayTrabajos[i].id = 0;
            retorno = 0;
        }
    }
    return retorno;
}

int inicializarTrabajos(Trabajo* arrayTrabajos, int tamanio)
{
    int i;
    int retorno = -1;
    if(arrayTrabajos != NULL && tamanio>0)
    {
        for(i=0; i<tamanio; i++)
        {
        	arrayTrabajos[i].isEmpty = 0;
            retorno = 0;
        }
    }
    return retorno;
}

int buscaLibre(Trabajo* arrayTrabajos, int tamanio)
{
	int i;
	int retorno=-1;

	if(arrayTrabajos!= NULL && tamanio>0)
	{
        for(i=0; i<tamanio; i++)
        {
        	if(arrayTrabajos[i].isEmpty==0)
        	{
            retorno = i;
            break;
        	}
        }
	}
	return retorno;
}

int altaTrabajo(Trabajo* arrayTrabajos, int tamanio, int* idServicio, int* idTrabajo, Servicio* arrayServicios)
{
    int retorno = 1;
    //int id;

    Trabajo aux;
    Servicio auxDos;
    int posicion;
    int posicionDos;
    int servicio;

    //int idServicio;

    char confirmacion;
    char opcion_continuar;
    if(arrayTrabajos != NULL && tamanio>0)
    {
        do{
        	posicion=buscaLibre(arrayTrabajos, tamanio);
        	posicionDos=buscaLibreServicio(arrayServicios, tamanio);
        	if(posicion!=-1){
				pedirDatosTrabajo(aux.marcaBicicleta, &aux.rodadoBicicleta, auxDos.descripcion, &aux.fecha[0], &aux.fecha[1], &aux.fecha[2]);
				descripcionAServicio(auxDos.descripcion, &servicio);
				printf("\n");
				printf("Estos son los datos ingresados:\n");
				mostrarTrabajo(aux.marcaBicicleta, aux.rodadoBicicleta, aux.fecha[0], aux.fecha[1], aux.fecha[2], servicio);

				printf("\n");
				confirmacion = getConfirmacion("Ingrese s para cargar los datos o n para no:\n");
				if(confirmacion == 's')
				{
					(*idServicio)++;
					auxDos.precio=fijarPrecio(servicio);
					auxDos.id=*idServicio;
					auxDos.isEmpty=1;
					(*idTrabajo)++;
					aux.id=*idTrabajo;
					aux.idServicio=*idServicio;
					aux.isEmpty=1;
					arrayTrabajos[posicion]=aux;
					arrayServicios[posicionDos]=auxDos;
					retorno=0;

				}
				else if(confirmacion == 'n'){
					retorno = 2;
				}
				printf("\n");
				opcion_continuar = getConfirmacion("Ingrese s para agregar otro trabajo o n para cargar solo los datos ya ingresados:");
				printf("\n");
        	}
        }while(opcion_continuar == 's');
    }
    return retorno;
}

void pedirDatosTrabajo(char marcaBicicleta[], int *rodadoBicicleta, char* descripcion, int *dia, int *mes, int *anio)
{
//	Servicio auxServicios;
	int servicio;

    pedirCadena("Ingrese el nombre de la marca de la bicicleta:\n", marcaBicicleta);
    *rodadoBicicleta = getInt("Ingrese el tamaño de rodado de la bicicleta.Entre 12 y 28:\n");
    while(*rodadoBicicleta<12 || *rodadoBicicleta>28)
    {
    	*rodadoBicicleta=getInt("Error. Ingrese un tamaño de rodado válido. Entre 12 y 28:");
    }
    servicio=getInt("Ingrese que opción de servicio quiere, 1 para limpieza, 2 para parche, 3 para centrado y 4 para cadena:");
    while(servicio<1 || servicio>4)
    {
    	servicio=getInt("Error. Ingrese que opción de servicio quiere, 1 para limpieza, 2 para parche, 3 para centrado y 4 para cadena:");
    }

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

    *dia= getInt("Ingrese el día en formato númerico del 1 al 31:");
    while(*dia <1 || *dia>31)
    {
    	*dia= getInt("Error. Ingrese el día en formato númerico del 1 al 31:");
    }

    *mes= getInt("Ingrese el mes en formato númerico del 1 al 12:");
    while(*mes<1 || *mes>12)
    {
    	*mes= getInt("Error. Ingrese el mes en formato númerico del 1 al 12:");
    }

    *anio= getInt("Ingrese el año en formato númerico del 2019 al 2021:");
    while(*anio<2019 || *anio>2022)
    {
    	*anio= getInt("Error. Ingrese el año en formato númerico del 2019 al 2021:");
    }

}

//int getNewId(Trabajo* arrayTrabajos, int tamanio)
//{
//    int retorno = -1;
//    int flag = 0;
//    int newId;
//    if(arrayTrabajos != NULL && tamanio>0){
//        int i;
//        for(i=0;i<tamanio;i++){
//            if(flag == 0 || arrayTrabajos[i].id>newId){
//                newId = arrayTrabajos[i].id;
//                flag = 1;
//            }
//        }
//        retorno = newId;
//    }
//    return retorno;
//}
void mostrarTrabajo(char marcaBicicleta[], int rodadoBicicleta, int dia, int mes, int anio, int servicio)
{
    printf("\n");
    printf("Marca de la bicicleta: %s\n", marcaBicicleta);
    printf("Tamaño de rodado %d\n", rodadoBicicleta);
    printf("Día: %d\n", dia);
    printf("Mes: %d\n", mes);
    printf("Año: %d\n", anio);
    switch(servicio){
    case 1:
    	printf("\tLimpieza");
    	break;
    case 2:
    	printf("\tParche");
    	break;
    case 3:
    	printf("\tCentrado");
    	break;
    case 4:
    	printf("\tCadena");
    	break;
    }

}

//int agregarTrabajo(Trabajo* arrayTrabajos, int tamanio, int id, int idServicio, char marcaBicicleta[], int rodadoBicicleta, int dia, int mes, int anio)
//{
//    int retorno = -1;
//    int nuevaId = agregarId(arrayTrabajos, tamanio);
//
//    if(nuevaId!= -1)
//    {
//    	arrayTrabajos[nuevaId].id = id;
//        strcpy(arrayTrabajos[nuevaId].marcaBicicleta, marcaBicicleta);
//        arrayTrabajos[nuevaId].rodadoBicicleta = rodadoBicicleta;
//        arrayTrabajos[nuevaId].idServicio=idServicio;
//        arrayTrabajos[nuevaId].fecha[0] = dia;
//        arrayTrabajos[nuevaId].fecha[1] = mes;
//        arrayTrabajos[nuevaId].fecha[2] = anio;
//        arrayTrabajos[nuevaId].isEmpty = 1;
//
//        retorno = 0;
//    }
//    return retorno;
//}

int agregarId(Trabajo* arrayTrabajos, int len)
{
    int i;
    int retorno = -1;
    if(arrayTrabajos != NULL && len>0){
        for(i=0; i<len; i++){
            if(arrayTrabajos[i].id == 0){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int modificarTrabajo(Trabajo* arrayTrabajos, int tamanio, Servicio* arrayServicios)
{
    int retorno = -1;
    int id;
    int indice;
    Trabajo aux;
    Servicio auxServicios;
    int opcion;
    char confirmacion = 's';
    char cargar = 'n';
    int nuevoServicio;
    char descripcion[25];
    int indiceServicio;

    listarTrabajos(arrayTrabajos, tamanio, arrayServicios);

    id = getInt("\nIngrese el Id del trabajo a modificar:");
    indice = buscarTrabajoPorId(arrayTrabajos, tamanio, id);

    if(indice != -1){
        aux = arrayTrabajos[indice];
        do{
            fflush(stdin);
            opcion = getInt("\nIngrese que desea modificar.\n1.Marca de la bicicleta.\n2.Servicio.\n3.Volver al menú principal.");
            switch(opcion){
            case 1:
                pedirCadena("Ingrese una marca:", aux.marcaBicicleta);
                confirmacion = getConfirmacion("\n¿Desea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                printf("\n");
                system("pause");
                break;
            case 2:
            	fflush(stdin);
            	indiceServicio=buscarServicioPorId(arrayServicios, tamanio, aux.idServicio);
            	auxServicios=arrayServicios[indiceServicio];
                nuevoServicio=getInt("Ingrese que opción de servicio quiere, 1 para limpieza, 2 para parche, 3 para centrado y 4 para cadena:");
                while(nuevoServicio<1 || nuevoServicio>4)
                {
                	nuevoServicio=getInt("Error. Ingrese que opción de servicio quiere, 1 para limpieza, 2 para parche, 3 para centrado y 4 para cadena:");
                }
                servicioADescripcion(nuevoServicio, descripcion);
                strcpy(auxServicios.descripcion, descripcion);
                auxServicios.precio=fijarPrecio(nuevoServicio);

                arrayServicios[indiceServicio]=auxServicios;

                confirmacion = getConfirmacion("\n¿Desea seguir ingresando datos? Ingrese s para SI o n para NO:");
                printf("\n");
                system("pause");
                break;
            case 3:
                confirmacion='n';
                printf("\n");
                system("pause");
                break;
            default:
                printf("Opción inválida.\n");
                printf("\n");
                system("pause");
                break;
            }
        }while(confirmacion == 's');

//        traerDescripcionServicio(arrayServicios, tamanio, int buscar, char* descripcion)
        switch(nuevoServicio)
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
        printf("Este es el trabajo:\n");
        printf("\n");
        mostrarUnTrabajo(aux, descripcion);
        printf("\n");
        cargar = getConfirmacion("\n¿Desea cargar los datos? Ingrese s para SI o n para NO:");
        if(cargar == 's'){
            arrayTrabajos[indice]=aux;
            retorno = 1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}

int listarTrabajos(Trabajo* arrayTrabajos, int tamanio, Servicio* arrayServicios)//creo que ahora si anda
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


void mostrarUnTrabajo(Trabajo arrayTrabajos, char* descripcion)
{
    printf("\n");
    printf("%03d", arrayTrabajos.id);
    printf("%17s", arrayTrabajos.marcaBicicleta);
    printf("%18d", arrayTrabajos.rodadoBicicleta);
    printf("%17d", arrayTrabajos.idServicio);
    printf("%10d", arrayTrabajos.fecha[0]);
    printf("%7d", arrayTrabajos.fecha[1]);
    printf("%7d", arrayTrabajos.fecha[2]);
    printf("%10s", descripcion);
}

int bajaTrabajo(Trabajo* arrayTrabajos, int tamanio, Servicio* arrayServicios)
{
    int retorno = -1;
    int id = 0;
    int index = 0;
    char confirmacion;
    char descripcion[25];

    if(arrayTrabajos != NULL && tamanio>0)
    {
        printf("Estos son los trabajos:\n");
        listarTrabajos(arrayTrabajos, tamanio, arrayServicios);
        id = getInt("\nIngrese el Id del trabajo que desea dar de baja:");
        printf("\n");
        index = buscarTrabajoPorId(arrayTrabajos, tamanio, id);
        if(index == -1){
            retorno = 1;
        }else{
        	traerDescripcionServicio(arrayServicios, tamanio, arrayTrabajos[index].idServicio, descripcion);
            mostrarUnTrabajo(arrayTrabajos[index], descripcion);
            confirmacion = getChar("\nIngrese s para eliminar el trabajo o n para conservarlo:");
            if(confirmacion == 's')
            {
                if(eliminarTrabajo(arrayTrabajos, tamanio, id)==0 && eliminarServicio(arrayServicios, tamanio, arrayTrabajos[index].idServicio)==0)
                {
                	retorno=0;
                }
            }else if(confirmacion == 'n'){
                retorno = 2;
            }
       }
    }
    return retorno;
}

int eliminarTrabajo(Trabajo* arrayTrabajos, int tamanio, int id)
{
    int retorno = -1;
    int i;
    if(arrayTrabajos != NULL && tamanio>0){
        for(i=0;i<tamanio;i++){
            if(arrayTrabajos[i].isEmpty == 1){
                if(arrayTrabajos[i].id == id){
                	arrayTrabajos[i].isEmpty = 0;
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int buscarTrabajoPorId(Trabajo* arrayTrabajos, int tamanio, int id)
{
    int retorno = -1;
    int i;
    if(arrayTrabajos != NULL && tamanio>0){
        for(i=0;i<tamanio;i++)
        {
            if(arrayTrabajos[i].isEmpty == 1)
            {
                if(arrayTrabajos[i].id == id)
                {
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}
