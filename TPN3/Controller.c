#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE* pFile;

    pFile = fopen(path,"r");

    if(pFile != NULL && pArrayListPassenger != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListPassenger);
        if(isEmpty == 1)
        {
            retorno = parser_PassengerFromText(pFile, pArrayListPassenger);
            fclose(pFile);
        }
        else
        {
            retorno = 2;
        }
    }
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE* pFile = NULL;

    pFile = fopen(path,"rb");

    if(pFile != NULL && pArrayListPassenger != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListPassenger);
        if(isEmpty == 1)
        {
            retorno=parser_PassengerFromBinary(pFile, pArrayListPassenger);
        }
        else
        {
            retorno = 2;
        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* id)
{
	 int retorno = 1;
	 char nombre[4096];
	 char apellido[4096];
	 char tipoPasajero[4096];
	 char codigoVuelo[4096];
	 char precio[4096];
	 char idPasajero[4096];
	 char estadoVuelo[4096];
	 int proximoID;
	 char confirmacion;
	 char opcion_continuar;

	 if(pArrayListPassenger != NULL)
	 	 {
		 do
		 {
			 Passenger* nuevo_Pasajero;

			 sprintf(idPasajero, "%d", *id);
			 pedirDatosPasajero(nombre, apellido, tipoPasajero, codigoVuelo, precio);
			 nuevo_Pasajero = passenger_newParametros(idPasajero, nombre, apellido, tipoPasajero, codigoVuelo, precio, estadoVuelo);
			 printf("\n");

			 printf("Estos son los datos ingresados:\n");//muestro el pasajero a cargar
			 printf("%4s %18s %18s %18s %20s %20s %20s\n", "ID:", "Nombre:", "Apellido:", "Tipo pasajero:", "Código de vuelo:", "Precio:", "Estado vuelo:");
			 showOnePassenger(nuevo_Pasajero);
			 printf("\n");

			 confirmacion = getYesOrNo("Desea cargar al pasajero? Ingrese s para SI o n para NO: ");//pido confirmacion para cargar o cancelar la accion
			 if(confirmacion == 's')
			 {
				 retorno = ll_add(pArrayListPassenger, nuevo_Pasajero);
			 }
	         else if(confirmacion == 'n'){
	                retorno = 2;
	            }
	            printf("\n");

	      proximoID = *id;
	      proximoID++;
	      *id = proximoID;

	     opcion_continuar = getYesOrNo("Desea ingresar otro empleado? Ingrese s para SI o n para NO: ");
	     printf("\n");
	     }
	     while(opcion_continuar == 's');
	    }
	 return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int retorno = -1;
    int isEmpty = 0;
    int id;
    int opcion;
    char confirmacion = 's';
    char cargar = 'n';
    Passenger* pasajeroAModificar;
    Passenger* auxPassenger;

    if(pArrayListPassenger != NULL)
    {
       isEmpty = ll_isEmpty(pArrayListPassenger);
       if(isEmpty!= 1)
       {
           printf("Estos son los pasajeros: \n");
           controller_ListPassenger(pArrayListPassenger);
           id = getInt("Ingrese el id del pasajero a modificar: \n");
           printf("\n");
           id--;
           auxPassenger = (Passenger*)ll_get(pArrayListPassenger, id);
           passenger_getId(auxPassenger, &id);


           if(auxPassenger != NULL)
           {
               printf("\n");
               printf("Este es el pasajero a modificar: \n");
               printf("%4s %18s %18s %18s %20s %20s %20s\n", "ID:", "Nombre:", "Apellido:", "Tipo pasajero:", "Código de vuelo:", "Precio:", "Estado de vuelo:");
               showOnePassenger(auxPassenger);
               do
               {
                  system("cls");
                  opcion = getInt("Ingrese una opcion:\n1. Cambiar nombre.\n2. Cambiar apellido.\n3. Cambiar tipo de pasajero."
                		  "\n4. Cambiar código de vuelo.\n5. Cambiar precio.\n6. Cambiar estado de vuelo.\n7. Salir al menu principal.\n");
                  switch(opcion)
                  {
                  case 1:
                      checkString("Ingrese un nuevo nombre: ", auxPassenger->nombre);
                      confirmacion = getYesOrNo("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                      printf("\n");
                      break;
                  case 2:
                      checkString("Ingrese un nuevo apellido: ", auxPassenger->apellido);
                      confirmacion = getYesOrNo("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                      printf("\n");
                      break;
                   case 3:
                	   checkString("Ingrese un nuevo tipo de pasajero: ", auxPassenger->tipoPasajero);
                	   confirmacion = getYesOrNo("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO:");
                	   printf("\n");
                	   break;
                   case 4:
                	   checkString("Ingrese un nuevo código de vuelo: ", auxPassenger->codigoVuelo);
                	   confirmacion = getYesOrNo("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                	   printf("\n");
                	   break;
                   case 5:
                	   auxPassenger->precio = getInt("Ingrese el nuevo precio: ");
                	   confirmacion = getYesOrNo("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                	   printf("\n");
                	   break;
                   case 6:
                	   checkString("Ingrese un nuevo estado de vuelo: ", auxPassenger->estadoVuelo);
                	   confirmacion = getYesOrNo("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                	   printf("\n");
                	   break;
                   case 7:
                	   confirmacion='n';
                	   printf("\n");
                	   break;
                   default:
                	   printf("Ingreso una opcion incorrecta.\n");
                	   printf("\n");
                	   break;
                   }
                }
                while(confirmacion == 's');
            }
            else{
            	retorno = 1;
            }
            printf("\n");
            printf("Este es el pasajero con los cambios realizados:\n");
            printf("\n");
            printf("%4s %18s %18s %18s %20s %20s\n", "ID:", "Nombre:", "Apellido:", "Tipo pasajero:", "Código de vuelo:", "Precio:");
            showOnePassenger(auxPassenger);
            printf("\n");
            cargar = getYesOrNo("\nDesea cargar los datos? Ingrese s para SI o n para NO:");
            if(cargar == 's')
            {
            	pasajeroAModificar = auxPassenger;
            	retorno = 2;
            }
            else
            {
            	retorno = 3;
            }
       }else{
    	   retorno = 0;
	        }
	    }
	    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int retorno = 1;
    int id;
    int isEmpty = 0;
    char confirmacion;
    Passenger* auxPassenger;
    int indicePasajero;

    if(pArrayListPassenger != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListPassenger);
        if(isEmpty != 1)
        {
            printf("Estos son los pasajeros:\n");
            controller_ListPassenger(pArrayListPassenger);
            id = getInt("\nIngrese el id del pasajero que desea dar de baja: ");
            printf("\n");
            id--;
			auxPassenger = (Passenger*)ll_get(pArrayListPassenger, id);
			passenger_getId(auxPassenger, &id);

            if(auxPassenger != NULL)
            {
            	printf("%4s %18s %18s %18s %20s %20s\n", "ID:", "Nombre:", "Apellido:", "Tipo pasajero:", "Código de vuelo:", "Precio:");
                showOnePassenger(auxPassenger);
                confirmacion = getYesOrNo("\nEsta seguro que quiere eliminar al pasajero? Ingrese s para SI o n para NO:");
                if(confirmacion == 's')
                {
                    indicePasajero = ll_indexOf(pArrayListPassenger, auxPassenger);
                    retorno = ll_remove(pArrayListPassenger, indicePasajero);
                }
                else if(confirmacion == 'n')
                {
                    retorno = 2;
                }
            }
            else
            {
                retorno = 3;
            }
        }
        else
        {
            retorno = 4;
        }
    }
    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int i;
    int len;
    int isEmpty = 0;

    if(pArrayListPassenger != NULL)
    {
        retorno = 0;
        isEmpty = ll_isEmpty(pArrayListPassenger);
        if(isEmpty != 1)
        {
            len = ll_len(pArrayListPassenger);
            Passenger* auxPassenger;
            printf("--Id-------------Nombre----------Apellido-----------Tipo de pasajero----------Código de vuelo-----------Precio-------Estado del vuelo----\n");
            for(i=0; i<len; i++)
            {
                auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
                showOnePassenger(auxPassenger);
            }
        }
        else
        {
            retorno = 1;
        }
    }
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = 1;
    int opcion;
    char option_continue = 'n';
    int orden;
    int isEmpty = 0;

    if(pArrayListPassenger != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListPassenger);
        retorno = 2;
        if(isEmpty != 1)
        {
            do
            {
                opcion = getInt("Estos son los campos por los cuales puede ordenar a los pasajeros:"
                		"\n1.Por ID.\n2.Por nombre.\n3.Por apellido.\n4.Por tipo de pasajero.\n5.Por código de vuelo.\n6.Por precio."
                		"\n7.Por estado de vuelo.\nIngrese el campo por el cual ordenar a los pasajeros u 8 para salir del subMenu de ordenamiento: ");
                switch(opcion)
                {
                case 1:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPassenger, compareById, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 2:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPassenger, compareByName, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 3:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPassenger, compareByLastName, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 4:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPassenger, compareByType, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 5:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPassenger, compareByCode, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 6:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPassenger, compareByPrice, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 7:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPassenger, compareByFlightStatus, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 8:
                    option_continue = getYesOrNo("Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
                    retorno = 3;
                    break;
                default:
                    printf("Ha ingresado una opcion incorrecta.\n");
                    printf("\n");
                    break;
                }
            }
            while(option_continue == 'n');
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    Passenger* auxPassenger = NULL;

    int idStr;
    char nombreStr[51];
    char apellidoStr[51];
    char tipoPasajeroStr[51];
    char codigoVueloStr[4];
    float precioStr;

    if(pArrayListPassenger != NULL && path != NULL)
    {
        pFile = fopen(path, "w");//abro el archivo en modo escritura
        len = ll_len(pArrayListPassenger);

        if(pFile != NULL)
        {
            fprintf(pFile, "Id,Nombre,Apellido,Tipo de pasajero,Código de vuelo,Precio\n");
            for(i=0; i<len; i++)
            {
                auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
                passenger_getId(auxPassenger, &idStr);
                passenger_getNombre(auxPassenger, nombreStr);
                passenger_getApellido(auxPassenger, apellidoStr);
                passenger_getTipoPasajero(auxPassenger, tipoPasajeroStr);
                passenger_getCodigoVuelo(auxPassenger, codigoVueloStr);
                passenger_getPrecio(auxPassenger, &precioStr);

                fprintf(pFile, "%d,%s,%s,%s,%s,%f\n", idStr, nombreStr, apellidoStr, tipoPasajeroStr, codigoVueloStr, precioStr);
            }
        }
        fclose(pFile);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    Passenger* auxPassenger = NULL;

    if(pArrayListPassenger != NULL && path != NULL)
    {
        pFile = fopen(path, "wb");//abro el archivo en modo escritura
        len = ll_len(pArrayListPassenger);

        if(pFile!=NULL)
        {
            for(i=0; i<len; i++)
            {
                auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
                fwrite(auxPassenger, sizeof(Passenger), 1, pFile);
            }
        }
        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}

