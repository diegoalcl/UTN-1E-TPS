#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "menu.h"
#include "ArrayPassenger.h"
#include "inputs.h"
#define true 1
#define false 0

int initPassengers(Passenger* list, int len){
    int i;
    int retorno = -1;
    if(list != NULL && len>0){
        for(i=0; i<len; i++){
            list[i].isEmpty = false;
            retorno = 0;
        }
    }
    return retorno;
}

int initIds(Passenger* list, int len){
    int i;
    int retorno = -1;
    if(list != NULL && len>0){
        for(i=0; i<len; i++){
            list[i].id = 0;
            retorno = 0;
        }
    }
    return retorno;
}

int loadPassenger(Passenger* list, int len){
    int retorno = 1;
    char name[51];
    char lastName[51];
    float price;
    int typePassenger;
    char flyCode[10];
    int id;
    char confirmacion;
    char opcion_continuar;
    if(list != NULL && len>0){
        do{
            getDataPassenger(name, lastName, &price, &typePassenger, flyCode);
            printf("\n");
            printf("Estos son los datos ingresados:\n");
            showData(name, lastName, price, typePassenger, flyCode);
            printf("\n");
            confirmacion = getConfirmacion("Ingrese s para cargar los datos o n para no:\n");
            if(confirmacion == 's'){
                id = getNewId(list, len);
                id++;
                retorno = addPassenger(list, len, id, name, lastName, price, typePassenger, flyCode);
            }
            else if(confirmacion == 'n'){
                retorno = 2;
            }
            printf("\n");
            opcion_continuar = getConfirmacion("Ingrese s para agregar otro pasajero o n para cargar solo los datos ya ingresados:");
            printf("\n");
        }while(opcion_continuar == 's');
    }
    return retorno;
}

void getDataPassenger(char name[],char lastName[],float* price,int* typePassenger,char flyCode[]){
    pedirCadena("Nombre del pasajero:\n", name);
    pedirCadena("Apellido del pasajero:\n", lastName);
    *price = getFloat("Precio del vuelo:\n");
    *typePassenger = getInt("Tipo de pasajero:\n");
    pedirCadena("Código del vuelo:\n", flyCode);
}

void showData(char name[],char lastName[],float price,int typePassenger,char flyCode[]){
    printf("\n");
    printf("Nombre: %s\n", name);
    printf("Apellido: %s\n", lastName);
    printf("Precio del vuelo: $%.2f\n", price);
    printf("Tipo de pasajero: %d\n", typePassenger);
    printf("Código del vuelo: %s\n", flyCode);
}

int getNewId(Passenger* list, int len){
    int retorno = -1;
    int flag = 0;
    int newId;
    if(list != NULL && len>0){
        int i;
        for(i=0;i<len;i++){
            if(flag == 0 || list[i].id>newId){
                newId = list[i].id;
                flag = 1;
            }
        }
        retorno = newId;
    }
    return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[])
{
    int retorno = -1;
    int lugar_Disponible = getIsEmpty(list, len);
    if(lugar_Disponible!= -1){
        list[lugar_Disponible].id = id;
        strcpy(list[lugar_Disponible].name, name);
        strcpy(list[lugar_Disponible].lastName, lastName);
        list[lugar_Disponible].price = price;
        list[lugar_Disponible].typePassenger = typePassenger;
        strcpy(list[lugar_Disponible].flyCode, flyCode);
        list[lugar_Disponible].isEmpty = true;
        retorno = 0;
    }
    return retorno;
}

int getIsEmpty(Passenger* list, int len){
    int i;
    int retorno = -1;
    if(list != NULL && len>0){
        for(i=0; i<len; i++){
            if(list[i].isEmpty == false){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int modificarPasajero(Passenger* list, int len){
    int retorno = -1;
    int id;
    int indice;
    Passenger aux;
    int opcion;
    char confirmacion = 's';
    char cargar = 'n';

    printPassengers(list, len);

    id = getInt("\nIngrese el ID del pasajero a modificar:");
    indice = findPassengerById(list, len, id);

    if(indice != -1){
        aux = list[indice];
        do{
            fflush(stdin);
            opcion = getInt("Ingrese una opcion:\n1. Cambiar nombre.\n2. Cambiar apellido.\n3. Cambiar precio de vuelo.\n"
            		"4. Cambiar tipo de pasajero.\n5. Cambiar código de vuelo.\n6. Salir al menú principal.\n");
            switch(opcion){
            case 1:
                pedirCadena("Ingrese el nuevo nombre:", aux.name);
                confirmacion = getConfirmacion("\n¿Desea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                printf("\n");
                break;
            case 2:
                pedirCadena("Ingrese el nuevo apellido:", aux.lastName);
                confirmacion = getConfirmacion("\n¿Desea seguir ingresando datos? Ingrese s para SI o n para NO:");
                printf("\n");
                break;
            case 3:
                aux.price = getFloat("Ingrese el precio nuevo:");
                confirmacion = getConfirmacion("\n¿Desea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                printf("\n");
                break;
            case 4:
                aux.typePassenger = getInt("Ingrese el nuevo tipo de pasajero:");
                confirmacion = getConfirmacion("\n¿Desea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                printf("\n");
                break;
            case 5:
                pedirCadena("Ingrese el nuevo código de vuelo:", aux.flyCode);
                confirmacion = getConfirmacion("\n¿Desea seguir ingresando datos? Ingrese s para SI o n para NO:");
                printf("\n");
                break;
            case 6:
                confirmacion='n';
                printf("\n");
                break;
            default:
                printf("Opción inválida.\n");
                printf("\n");
                system("pause");
                break;
            }
        }while(confirmacion == 's');

        printf("Este es el pasajero:\n");
        printf("\n");
        showOnePassenger(aux);
        printf("\n");
        cargar = getConfirmacion("\n¿Desea cargar los datos? Ingrese s para SI o n para NO:");
        if(cargar == 's'){
            list[indice]=aux;
            retorno = 1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}

int printPassengers(Passenger* list, int len){
    int retorno = -1;
    int i;
    if(list != NULL && len>0){
        printf("Id:\tNombre:\t\tApellido:\t\tPrecio del vuelo:\t\t\t\tTipo de pasajero:\t\t\tCódigo de vuelo::\n");
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty != false)
            {
                retorno = 1;
                showOnePassenger(list[i]);
            }
        }
    }
    return retorno;
}

void showOnePassenger(Passenger sPassenger){
    printf("\n");
    printf("%03d", sPassenger.id);
    printf("%12s", sPassenger.name);
    printf("%18s", sPassenger.lastName);
    printf("%22.2f", sPassenger.price);
    printf("%23d", sPassenger.typePassenger);
    printf("%12s\n", sPassenger.flyCode);
}

int findPassengerById(Passenger* list, int len,int id){
    int retorno = -1;
    int i;
    if(list != NULL && len>0){
        for(i=0;i<len;i++){
            if(list[i].isEmpty == true){
                if(list[i].id == id){
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}

int deletePassenger(Passenger* list, int len){
    int retorno = -1;
    int id = 0;
    int index = 0;
    char confirmacion;
    if(list != NULL && len>0){
        printf("Estos son los pasajeros:\n");
        printPassengers(list, len);
        id = getInt("\nIngrese el ID del pasajero que desea dar de baja:");
        printf("\n");
        index = findPassengerById(list, len, id);
        if(index == -1){
            retorno = 1;
        }else{
            showOnePassenger(list[index]);
            confirmacion = getChar("\nIngrese s para eliminar al pasajero o n para conservarlo:");
            if(confirmacion == 's'){
                retorno = removePassenger(list, len, id);
            }else if(confirmacion == 'n'){
                retorno = 2;
            }
       }
    }
    return retorno;
}
int removePassenger(Passenger* list, int len, int id){
    int retorno = -1;
    int i;
    if(list != NULL && len>0){
        for(i=0;i<len;i++){
            if(list[i].isEmpty == true){
                if(list[i].id == id){
                    list[i].isEmpty = false;
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}

int informarPasajeros(Passenger* list, int len, int cantidadPasajeros){
    int retorno = -1;
    int opcion;
    int opcionContinuar = 's';
    if(list!=NULL && len>0){
        do{
            fflush(stdin);
            opcion = getInt("\nIngrese una opción:\n1.Listado de los pasajeros, ordenado por apellido y tipo de pasajero.\n2.Total y promedio de los"
            		" precios de los pasajes, y pasajeros que superan el precio promedio.\n"
            		"3.Listado de los pasajeros por Código de vuelo y estados de vuelos 'ACTIVO'\n4.Volver al menú principal.\n");
            switch(opcion){
				case 1:
					listarPasajerosApellidoYTipo(list, len);
					printf("\n");
					break;
				case 2:
					listarTotalYPromedios(list, len, cantidadPasajeros);
					printf("\n");
					break;
				case 3:
					listarPasajerosCodigoYEstado(list, len);
					break;
				case 4:
					opcionContinuar='n';
					retorno=0;
					break;
				default:
					printf("Opción inválida.\n");
					printf("\n");
					break;
				}
        }while(opcionContinuar == 's');
    }
    return retorno;
}

void listarPasajerosApellidoYTipo(Passenger* list, int len)
{
	int i;
	int j;
	Passenger auxTipo;
    Passenger auxApellido;


    if(list != NULL && len > 0)//Ordena por apellido alfabeticamente
   	{

    	for (i=0;i<len-1; i++)
    	{
    		for (j=i+1;j<len;j++)
    		{
    			if(strcmp(list[i].lastName,list[j].lastName)>0)
				{
					auxApellido=list[j];
					list[j]=list[i];
					list[i]=auxApellido;
				}
    		}
    	}
    }

    if(list != NULL && len > 0)//Ordena por tipo de pasajero ante igualdad de apellido
   	{

    	for (i=0;i<len-1; i++)
    	{
    		for (j=i+1;j<len;j++)
    		{
    			if(list[i].lastName==list[j].lastName)
				{
        			if(list[i].typePassenger < list[j].typePassenger)
        			{
        				auxTipo= list[i];
        				list[i] = list[j];
        				list[j] = auxTipo;
        			}
				}
    		}
    	}
    }

    if(list != NULL && len>0)
    {
        printf("Apellido del pasajero\t\tTipo");
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty != 0)
            {
            	mostrarUnPasajeroOrdenado(list[i]);
            }
        }
    }

}

void mostrarUnPasajeroOrdenado(Passenger list)
{
    printf("\n");
    printf("%s\t\t", list.lastName);
    printf("\t\t%d", list.typePassenger);

}

void listarTotalYPromedios(Passenger* list, int len, int cantidadPasajeros)
{
	int i;
	float precioTotal=0;
	float promedio;
	int pasajerosQueSuperanPromedio=0;

	for(i=0;i<cantidadPasajeros;i++)
	{
		precioTotal=precioTotal+list[i].price;
	}

	promedio=precioTotal/cantidadPasajeros;

	printf("\nEl precio total de los vuelos es de $%.2f, el promedio de precio de los pasajes es $%.2f.\n", precioTotal, promedio);

	for(i=0;i<cantidadPasajeros;i++)
	{
		if(list[i].price>promedio)
		{
			pasajerosQueSuperanPromedio++;
		}
	}
	printf("La cantidad de pasajeros que superan el promedio de precio es de %d.\n", pasajerosQueSuperanPromedio);

}

void listarPasajerosCodigoYEstado(Passenger* list, int len)
{
	int i;
	int j;
	Passenger auxCodigo;

    if(list != NULL && len > 0)//Ordena por codigo del vuelo
   	{

    	for (i=0;i<len-1; i++)
    	{
    		for (j=i+1;j<len;j++)
    		{
    			if(strcmp(list[i].flyCode,list[j].flyCode)>0)
				{
					auxCodigo=list[j];
					list[j]=list[i];
					list[i]=auxCodigo;
				}
    		}
    	}
    }


    if(list != NULL && len>0)
    {
        printf("Id pasajero\t\tCódigo del vuelo\t\tEstado del vuelo");
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty != 0)
            {
            	mostrarUnPasajeroOrdenadoPorCodigoYEstado(list[i]);
            }
        }
    }

}

void mostrarUnPasajeroOrdenadoPorCodigoYEstado(Passenger list)
{
    if(list.typePassenger==1)
    {
	printf("\n");
	printf("%d\t", list.id);
	printf("\t\t%s\t\t", list.flyCode);
    printf("\t\tActivo");
    }

}

void hardcodeoPasajeros(Passenger* list){

    int i;
    int id[]= {1,2,3,4,5,6};
    char name[][51]={"Pedro", "Agustina", "Jose", "Jorge", "Lucia", "Ana Maria"};
    char lastName[][51]={"Perez", "Lopez", "Gimenez", "Benitez", "Ruiz", "Lopez"};
    float price[]= {25.500, 30000, 70000, 50000, 65.500, 45000};
    char flyCode[][10]={"HBAZEL", "EEFGJK", "IIMESJ", "ZZLOTP", "BHSJEA", "FLOPEM"};
    int typePassenger[]={1,2,2,1,2,1};

    for(i=0; i<6;i++)
	{
		list[i].id= id[i];
		strcpy(list[i].name, name[i]);
		strcpy(list[i].lastName, lastName[i]);
		list[i].price= price[i];
		strcpy(list[i].flyCode, flyCode[i]);
		list[i].typePassenger= typePassenger[i];
		list[i].statusFlight= price[i];
		list[i].isEmpty=true;

	}
}

