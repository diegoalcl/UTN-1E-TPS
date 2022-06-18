#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Pacientes.h"
#include "Parser.h"
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPacientes)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE* pFile;

    pFile = fopen(path,"r");
    if(pFile != NULL && pArrayListPacientes != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListPacientes);
        if(isEmpty == 1)
        {
            retorno = parser_PacientesFromText(pFile, pArrayListPacientes);
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
int controller_loadFromBinary(char* path , LinkedList* pArrayListPacientes)
{
    int retorno = 1;
    int isEmpty = 0;
    FILE* pFile = NULL;

    pFile = fopen(path,"rb");

    if(pFile != NULL && pArrayListPacientes != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListPacientes);
        if(isEmpty == 1)
        {
            retorno=parser_PacientesFromBinary(pFile, pArrayListPacientes);
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
int controller_addPacientes(LinkedList* pArrayListPacientes, int* id)
{
	 int retorno = 1;
	 char nombre[4096];
	 char sexo[4096];
	 char especie[4096];
	 char esquemaVacunacion[4096];
	 char edad[4096];
	 char idPaciente[4096];
	 int proximoID;
	 char confirmacion;
	 char opcion_continuar;

	 if(pArrayListPacientes != NULL)
	 	 {
		 do
		 {
			 ePaciente* nuevo_Paciente;

			 sprintf(idPaciente, "%d", *id);
			 pedirDatosPaciente(especie, sexo, nombre, esquemaVacunacion, edad);
			 nuevo_Paciente = paciente_newParametros(idPaciente, especie, sexo, nombre, esquemaVacunacion, edad);
			 printf("\n");

			 printf("Estos son los datos ingresados:\n");//muestro el paciente a cargar
			 printf("%4s %18s %18s %18s %20s %20s\n", "ID:", "Nombre:", "Sexo:", "Especie:", "Esquema de vacunación:", "Edad:");
			 showOnePaciente(nuevo_Paciente);
			 printf("\n");

			 confirmacion = getYesOrNo("Desea cargar al paciente? Ingrese s para SI o n para NO: ");//pido confirmacion para cargar o cancelar la accion
			 if(confirmacion == 's')
			 {
				 retorno = ll_add(pArrayListPacientes, nuevo_Paciente);
			 }
	         else if(confirmacion == 'n'){
	                retorno = 2;
	            }
	            printf("\n");

	      proximoID = *id;
	      proximoID++;
	      *id = proximoID;

	     opcion_continuar = getYesOrNo("Desea ingresar otro paciente? Ingrese s para SI o n para NO: ");
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
int controller_editPaciente(LinkedList* pArrayListPacientes)
{
	int retorno = -1;
    int isEmpty = 0;
    int id;
    int opcion;
    char confirmacion = 's';
    char cargar = 'n';
    ePaciente* pacienteAModificar;
    ePaciente* auxPaciente;

    if(pArrayListPacientes != NULL)
    {
       isEmpty = ll_isEmpty(pArrayListPacientes);
       if(isEmpty!= 1)
       {
           printf("Estos son los pacientes: \n");
           controller_ListPacientes(pArrayListPacientes);
           id = getInt("Ingrese el id del paciente a modificar: \n");
           printf("\n");
           id--;
           auxPaciente = (ePaciente*)ll_get(pArrayListPacientes, id);
           paciente_getId(auxPaciente, &id);


           if(auxPaciente != NULL)
           {
               printf("\n");
               printf("Este es el paciente a modificar: \n");
               printf("%4s %18s %18s %18s %20s %20s\n", "ID:", "Especie:", "Sexo:", "Nombre:", "Estado esquema de vacunación:", "Edad:");
               showOnePaciente(auxPaciente);
               do
               {
                  system("cls");
                  opcion = getInt("Ingrese una opcion:\n1. Cambiar especie.\n2. Cambiar sexo.\n3. Cambiar nombre."
                		  "\n4. Cambiar estado del esquema de vacunación.\n5. Cambiar edad.\n6. Salir al menu principal.\n");
                  switch(opcion)
                  {
                  case 1:
                      checkString("Ingrese la especie: ", auxPaciente->especie);
                      confirmacion = getYesOrNo("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                      printf("\n");
                      break;
                  case 2:
                      checkString("Ingrese el sexo: ", auxPaciente->sexo);
                      confirmacion = getYesOrNo("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                      printf("\n");
                      break;
                   case 3:
                	   checkString("Ingrese el nuevo nombre: ", auxPaciente->nombre);
                	   confirmacion = getYesOrNo("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO:");
                	   printf("\n");
                	   break;
                   case 4:
                	   checkString("Ingrese el estado del esquema de vacunación: ", auxPaciente->esquemaVacunacion);
                	   confirmacion = getYesOrNo("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                	   printf("\n");
                	   break;
                   case 5:
                	   auxPaciente->edad = getInt("Ingrese la edad: ");
                	   confirmacion = getYesOrNo("\nDesea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                	   printf("\n");
                	   break;
                   case 6:
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
            printf("Este es el paciente con los cambios realizados:\n");
            printf("\n");
            printf("%4s %18s %18s %18s %20s %20s\n", "ID:", "Especie:", "Sexo:", "Nombre:", "Estado esquema de vacunación:", "Edad:");
            showOnePaciente(auxPaciente);
            printf("\n");
            cargar = getYesOrNo("\nDesea cargar los datos? Ingrese s para SI o n para NO:");
            if(cargar == 's')
            {
            	pacienteAModificar = auxPaciente;
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
int controller_removePaciente(LinkedList* pArrayListPacientes)
{
    int retorno = 1;
    int id;
    int isEmpty = 0;
    char confirmacion;
    ePaciente* auxPaciente;
    int indicePaciente;

    if(pArrayListPacientes != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListPacientes);
        if(isEmpty != 1)
        {
            printf("Estos son los pacientes:\n");
            controller_ListPacientes(pArrayListPacientes);
            id = getInt("\nIngrese el id del Paciente que desea dar de baja: ");
            printf("\n");
            id--;
			auxPaciente = (ePaciente*)ll_get(pArrayListPacientes, id);
			paciente_getId(auxPaciente, &id);

            if(auxPaciente != NULL)
            {
                printf("%4s %18s %18s %18s %20s %20s\n", "ID:", "Especie:", "Sexo:", "Nombre:", "Estado esquema de vacunación:", "Edad:");
                showOnePaciente(auxPaciente);
                confirmacion = getYesOrNo("\nEsta seguro que quiere eliminar al paciente? Ingrese s para SI o n para NO:");
                if(confirmacion == 's')
                {
                    indicePaciente = ll_indexOf(pArrayListPacientes, auxPaciente);
                    retorno = ll_remove(pArrayListPacientes, indicePaciente);
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
int controller_ListPacientes(LinkedList* pArrayListPacientes)
{
    int retorno = -1;
    int i;
    int len;
    int isEmpty = 0;

    if(pArrayListPacientes != NULL)
    {
        retorno = 0;
        isEmpty = ll_isEmpty(pArrayListPacientes);
        if(isEmpty != 1)
        {
            len = ll_len(pArrayListPacientes);
            ePaciente* auxPaciente;
            printf("--Id-------------Especie----------Sexo-----------Nombre----------Estado esquema de vacunación-----------Edad-------\n");
            for(i=0; i<len; i++)
            {
                auxPaciente = (ePaciente*) ll_get(pArrayListPacientes, i);
                showOnePaciente(auxPaciente);
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
int controller_sortPacientes(LinkedList* pArrayListPacientes)
{
    int retorno = 1;
    int opcion;
    char option_continue = 'n';
    int orden;
    int isEmpty = 0;

    if(pArrayListPacientes != NULL)
    {
        isEmpty = ll_isEmpty(pArrayListPacientes);
        retorno = 2;
        if(isEmpty != 1)
        {
            do
            {
                opcion = getInt("Estos son los campos por los cuales puede ordenar a los pacientes:"
                		"\n1.Por ID.\n2.Por especie.\n3.Por sexo.\n4.Por nombre.\n5.Por estado del esquema de vacunación.\n6.Por edad."
                		"\nIngrese el campo por el cual ordenar a los pasajeros o 7 para salir del subMenu de ordenamiento: ");
                switch(opcion)
                {
                case 1:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPacientes, compareById, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 2:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPacientes, compareByEspecie, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 3:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPacientes, compareBySexo, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 4:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPacientes, compareByNombre, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 5:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPacientes, compareByEstadoEsquemaDeVacunacion, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 6:
                    orden = getDosEstados("Ingrese 1 si desea ordenar de forma ascendente o 0 si desea ordenar de forma descendente: ", 1, 0);
                    printf("Ordenando, por favor espere...\n");
                    retorno = ll_sort(pArrayListPacientes, compareByEdad, orden);
                    option_continue = 's';
                    printf("\n");
                    system("pause");
                    break;
                case 7:
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
int controller_saveAsText(char* path , LinkedList* pArrayListPacientes)
{
    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    ePaciente* auxPaciente = NULL;

    int idStr;
    char especieStr[51];
    char sexoStr[51];
    char nombreStr[51];
    char esquemaVacunacionStr[51];
    int edadStr;

    if(pArrayListPacientes != NULL && path != NULL)
    {
        pFile = fopen(path, "w");//abro el archivo en modo escritura
        len = ll_len(pArrayListPacientes);

        if(pFile != NULL)
        {
            fprintf(pFile, "Id,Especie,Sexo,Nombre,Estado esquema de vacunación,Edad\n");
            for(i=0; i<len; i++)
            {
                auxPaciente = (ePaciente*) ll_get(pArrayListPacientes, i);
                paciente_getId(auxPaciente, &idStr);
                paciente_getEspecie(auxPaciente, especieStr);
                paciente_getSexo(auxPaciente, sexoStr);
                paciente_getNombre(auxPaciente, nombreStr);
                paciente_getEsquemaVacunacion(auxPaciente, esquemaVacunacionStr);
                paciente_getEdad(auxPaciente, &edadStr);

                fprintf(pFile, "%d,%s,%s,%s,%s,%d\n", idStr, especieStr, sexoStr, nombreStr, esquemaVacunacionStr, edadStr);
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
int controller_saveAsBinary(char* path , LinkedList* pArrayListPacientes)
{
    int retorno = -1;
    int len;
    int i;
    FILE* pFile;
    ePaciente* auxPaciente = NULL;

    if(pArrayListPacientes != NULL && path != NULL)
    {
        pFile = fopen(path, "wb");//abro el archivo en modo escritura
        len = ll_len(pArrayListPacientes);

        if(pFile!=NULL)
        {
            for(i=0; i<len; i++)
            {
                auxPaciente = (ePaciente*) ll_get(pArrayListPacientes, i);
                fwrite(auxPaciente, sizeof(ePaciente), 1, pFile);
            }
        }
        fclose(pFile);
        retorno = 0;
    }

    return retorno;
}

