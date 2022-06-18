#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Pacientes.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PacientesFromText(FILE* pFile , LinkedList* pArrayListPacientes)
{
    int retorno = -1;
    ePaciente* this = NULL;
    char idStr[128];
    char especieStr[128];
    char sexoStr[128];
    char nombreStr[128];
    char estadoVacunacionStr[128];
    char edadStr[128];

    //lee el primer renglon, realiza una falsa lectura del titulo
    if(pArrayListPacientes != NULL && pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, especieStr, sexoStr, nombreStr, estadoVacunacionStr, edadStr);
        //mientras que no sea el final de archivo voy leyendo los datos y los asigno en la lista dinamica
        while(!feof(pFile))
        {
        	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, especieStr, sexoStr, nombreStr, estadoVacunacionStr, edadStr);
            //leo el dato hasta el final de linea
            this = paciente_newParametros(idStr, especieStr, sexoStr, nombreStr, estadoVacunacionStr, edadStr);
            //creo el empleado con los datos que cargue asd
            ll_add(pArrayListPacientes, this);
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
int parser_PacientesFromBinary(FILE* pFile , LinkedList* pArrayListPacientes)
{
    int retorno = -1;
    ePaciente* this = NULL;
    char idStr[128];
    char especieStr[128];
    char sexoStr[128];
    char nombreStr[128];
    char estadoVacunacionStr[128];
    char edadStr[128];

    //lee el primer renglon, realiza una falsa lectura del titulo
    if(pArrayListPacientes != NULL && pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, especieStr, sexoStr, nombreStr, estadoVacunacionStr, edadStr);
        //mientras que no sea el final de archivo voy leyendo los datos y los asigno en la lista dinamica
        while(!feof(pFile))
        {
        	fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idStr, especieStr, sexoStr, nombreStr, estadoVacunacionStr, edadStr);
            //leo el dato hasta el final de linea
            this = paciente_newParametros(idStr, especieStr, sexoStr, nombreStr, estadoVacunacionStr, edadStr);
            //creo el empleado con los datos que cargue asd
            ll_add(pArrayListPacientes, this);
        }
        retorno = 0;
    }
    return retorno;
}
