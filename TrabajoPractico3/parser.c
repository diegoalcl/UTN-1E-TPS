#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* this = NULL;

    char idStr[4096];
    char nombreStr[4096];
    char horasTrabajadasStr[4096];
    char sueldoStr[4096];

    //lee el primer renglon, realiza una falsa lectura del titulo
    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
        //mientras que no sea el final de archivo voy leyendo los datos y los asigno en la lista dinamica
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);//leo el dato hasta el final de linea
            this = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);//creo el empleado con los datos que cargue
            ll_add(pArrayListEmployee, this);
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* this = NULL;

    //creo los campos para que vaya guardando lo que lee del archivo
    char idStr[20];
    char nombreStr[51];
    char horasTrabajadasStr[51];
    char sueldoStr[20];

    //lee el primer renglon, realiza una falsa lectura del titulo
    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);
        //mientras que no sea el final de archivo voy leyendo los datos y los asigno en la lista dinamica
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombreStr, horasTrabajadasStr, sueldoStr);//leo el dato hasta el final de linea
            this = employee_newParametros(idStr, nombreStr, horasTrabajadasStr, sueldoStr);//creo el empleado con los datos que cargue
            ll_add(pArrayListEmployee, this);
        }
        retorno = 0;
    }

    return retorno;
}

