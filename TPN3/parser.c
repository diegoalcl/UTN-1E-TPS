#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    Passenger* this = NULL;
    char idStr[128];
    char nombreStr[128];
    char apellidoStr[128];
    char tipoPasajeroStr[128];
    char codigoVueloStr[128];
    char precioStr[128];
    char estadoVueloStr[128];

    //lee el primer renglon, realiza una falsa lectura del titulo
    if(pArrayListPassenger != NULL && pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
        //mientras que no sea el final de archivo voy leyendo los datos y los asigno en la lista dinamica
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
            //leo el dato hasta el final de linea
            this = passenger_newParametros(idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
            //creo el empleado con los datos que cargue asd
            ll_add(pArrayListPassenger, this);
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    Passenger* this = NULL;

    //creo los campos para que vaya guardando lo que lee del archivo
    char idStr[128];
    char nombreStr[128];
    char apellidoStr[128];
    char tipoPasajeroStr[128];
    char codigoVueloStr[128];
    char precioStr[128];
    char estadoVueloStr[128];

    //lee el primer renglon, realiza una falsa lectura del titulo
    if(pArrayListPassenger != NULL && pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
        //mientras que no sea el final de archivo voy leyendo los datos y los asigno en la lista dinamica
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
            //leo el dato hasta el final de linea
            this = passenger_newParametros(idStr, nombreStr, apellidoStr, precioStr, codigoVueloStr, tipoPasajeroStr, estadoVueloStr);
            //creo el empleado con los datos que cargue asd
            ll_add(pArrayListPassenger, this);
        }
        retorno = 0;
    }
    return retorno;
}
