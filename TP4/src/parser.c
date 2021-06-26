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
    /*int id;
    int workHours;
    int salary;
    int counter = 0;
    char buffer[4][128];
    Employee* aux;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        while(!feof(pFile))
        {
            if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]) == 4
               && inputs_stringToInteger(buffer[0], &id) && buffer[1] != NULL
               && inputs_stringToInteger(buffer[2], &workHours)
               && inputs_stringToInteger(buffer[3], &salary))
            {
                aux = employee_newWithParameters(&id, buffer[1], &workHours, &salary);

                if(aux != NULL
                   && ll_len(pArrayListEmployee) < EMPLOYEE_MAX
                   && ll_add(pArrayListEmployee, (Employee*)aux) == 0)
                {
                    counter++;
                }
            }
        }
    }

    return counter; */
    /*int retorno = -1;
    int contador = 0;
    Employee* this = NULL;
    if(pArrayListEmployee != NULL && pFile != NULL)
    {
        while(!feof(pFile))
        {
            this = employee_new();
            if(this != NULL)
            {
                fread(this, sizeof(Employee), 1, pFile);
                if(feof(pFile))
                {
                    retorno = -1;
                    break;
                }
                ll_add(pArrayListEmployee, this);
                contador++;
            }
        }
        fclose(pFile);
        printf("Se cargaron : %d.\n", contador);
        pFile = NULL;
        retorno = 0;
    }*/
    return retorno;
}

