#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Pacientes.h"
#include "parser.h"
#include "ctype.h"

#define MAX_NOMBRE 51


ePaciente* paciente_new()
{
	ePaciente* this = (ePaciente*) malloc(sizeof(ePaciente));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->especie,"");
        strcpy(this->sexo,"");
        strcpy(this->nombre,"");
        strcpy(this->esquemaVacunacion,"");
        this->edad=0;
    }

    return this;
}

ePaciente* paciente_newParametros(char* idStr, char* especieStr, char* sexoStr, char* nombreStr, char* esquemaVacunacionStr, char* edadStr)
{
	ePaciente* this = paciente_new();
    if(idStr != NULL && especieStr != NULL && sexoStr != NULL && nombreStr != NULL && esquemaVacunacionStr != NULL && edadStr != NULL)
    {
        if(this != NULL)
        {
        	paciente_setId(this, atoi(idStr));
        	paciente_setEspecie(this, especieStr);
        	paciente_setSexo(this, sexoStr);
        	paciente_setNombre(this, nombreStr);;
        	paciente_setEsquemaVacunacion(this, esquemaVacunacionStr);
        	paciente_setEdad(this, atoi(edadStr));
        }
    }

    return this;
}

void paciente_delete(ePaciente* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int paciente_setId(ePaciente* this,int id)
{
	int retorno=-1;
	if(this!=NULL && id>=0)
	{
		retorno=0;
		this->id=id;
	}
	return retorno;
}

int paciente_getId(ePaciente* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int paciente_setEspecie(ePaciente* this,char* especie)
{
	int retorno = -1;
	if(this != NULL && especie != NULL)
	{
			strcpy(this->especie,especie);
	}
	return retorno;
}

int paciente_getEspecie(ePaciente* this,char* especie)
{
	int retorno = -1;
	if(this != NULL && especie != NULL)
	{
		retorno = 0;
		strncpy(especie,this->especie,MAX_NOMBRE);
	}
	return retorno;
}

int paciente_setSexo(ePaciente* this,char* sexo)
{
	int retorno = -1;
	if(this != NULL && sexo != NULL)
	{
			strcpy(this->sexo,sexo);
	}
	return retorno;
}

int paciente_getSexo(ePaciente* this,char* sexo)
{
	int retorno = -1;
	if(this != NULL && sexo != NULL)
	{
		retorno = 0;
		strncpy(sexo,this->sexo,MAX_NOMBRE);
	}
	return retorno;
}

int paciente_setNombre(ePaciente* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(this->nombre,nombre);

	}
	return retorno;
}

int paciente_getNombre(ePaciente* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,MAX_NOMBRE);
	}
	return retorno;
}


int paciente_setEsquemaVacunacion(ePaciente* this,char* esquemaVacunacion)
{
	int retorno = -1;
	if(this != NULL && esquemaVacunacion != NULL)
	{
			strcpy(this->esquemaVacunacion,esquemaVacunacion);
	}
	return retorno;
}

int paciente_getEsquemaVacunacion(ePaciente* this,char* esquemaVacunacion)
{
	int retorno = -1;
	if(this != NULL && esquemaVacunacion != NULL)
	{
		retorno = 0;
		strncpy(esquemaVacunacion,this->esquemaVacunacion,MAX_NOMBRE);
	}
	return retorno;
}

int paciente_setEdad(ePaciente* this,int edad)
{
	int retorno=-1;
	if(this!=NULL && edad>=0)
	{
		retorno=0;
		this->edad=edad;
	}
	return retorno;
}

int paciente_getEdad(ePaciente* this,int* edad)
{
	int retorno = -1;
	if(this != NULL && edad != NULL)
	{
		retorno = 0;
		*edad = this->edad;
	}
	return retorno;
}


//A partir de aca son funciones creadas a medida que las fui necesitando

/*int getPassengerById(LinkedList* pArrayListPassenger, int id)
{
    int len;
    int i;
    int retorno;
    Passenger* auxPassenger = NULL;
    if(pArrayListPassenger != NULL)
    {
        len = ll_len(pArrayListPassenger);

        for(i=0; i<len; i++)
        {
            auxPassenger = (Passenger* ) ll_get(pArrayListPassenger, i);
            if(id == auxPassenger>id)
            {
                retorno=auxPassenger;
                break;
            }
        }
    }
    return retorno;

}*/

int getBiggestId(LinkedList* pArrayListPacientes)
{
    int retorno = -1;
    if(pArrayListPacientes != NULL)
    {
        int len;
        int flag = 0;
        int i;
        ePaciente* auxPaciente;

        len = ll_len(pArrayListPacientes);

        for(i=0; i<len; i++)
        {
            auxPaciente = (ePaciente*) ll_get(pArrayListPacientes, i);
            if(flag == 0 || retorno < auxPaciente->id)
            {
                retorno = auxPaciente->id;
                flag = -1;
            }
        }
    }
    return retorno;
}

int getNextId(LinkedList* pArrayListPacientes)
{
    int retorno = -1;
    if(pArrayListPacientes != NULL)
    {
        retorno = getBiggestId(pArrayListPacientes);
        retorno++;
    }
    return retorno;
}


int showOnePaciente(ePaciente* paciente)
{
    int retorno = -1;
    if(paciente != NULL)
    {
        printf("%4d %18s %18s %20s %20s %20d\n", paciente->id, paciente->especie, paciente->sexo, paciente->nombre, paciente->esquemaVacunacion,
        		paciente->edad);
        retorno = 0;
    }

    return retorno;
}

int getStringCharacters(char cadena[])
{
    int i;
    int flag = 0;
    int esEspacio = 0;
    int tam = strlen(cadena);
    for(i=0; i<tam; i++)
    {
        if(cadena[i] != '\0')
        {
            if ((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A'||cadena[i]>'Z') && cadena[i]!=' ')
            {
                flag = -1;
            }
            if(cadena[i]!=' ')
            {
                esEspacio = -1;
            }
        }
    }
    if(esEspacio == 0)
    {
        flag = -1;
    }

    return flag;
}

int getStringNumbers(char cadena[])
{
    int i;
    int flag = 0;
    int esEspacio = 0;
    int tam = strlen(cadena);
    for(i=0; i<tam; i++)
    {
        if(cadena[i] != '\0')
        {
            if ((cadena[i]<'0' || cadena[i]>'9') && cadena[i]!=' ')
            {
                flag = -1;
            }
        }
    }
    if(esEspacio == -1)
    {
        flag = -1;
    }
    return flag;
}

void firstToUpper(char cadena[])
{
    int tam = strlen(cadena);
    int i;
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
    for(i=0; i<tam; i++)
    {
        if(cadena[i]!='\0')
        {
            if(isspace(cadena[i]))
            {
                cadena[i+1] = toupper(cadena[i+1]);
            }
        }
    }
}
void checkString (char mensaje[], char cadena[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    while(getStringCharacters(cadena)== -1)
    {
        printf("Error. Ingrese solo letras!\n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
    firstToUpper(cadena);
}

void checkStringNumbers (char mensaje[], char cadena[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    while(getStringNumbers(cadena)== -1)
    {
        printf("Error. Ingrese solo numeros!\n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
}

void pedirDatosPaciente(char* especie, char* sexo, char* nombre, char* estadoVacunacion, char* edad)
{
    checkString("Ingrese la especie del paciente: ", especie);
    checkString("Ingrese el sexo del paciente: ", sexo);
    checkString("Ingrese el nombre del paciente: ", nombre);
    checkString("Ingrese el estado del esquema de vacunación del paciente: ", estadoVacunacion);
    checkStringNumbers("Ingrese la edad del paciente: ", edad);
}

char getYesOrNo(char mensaje[])
{
    char letter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letter);
    letter = tolower(letter);
    while(letter!='s' && letter!='n')
    {
        printf("Error. Ingrese s para SI o n para NO:\n");
        fflush(stdin);
        scanf("%c", &letter);
    }
    return letter;
}

int getInt(char *mensaje)
{
    int numero;
    while((getValidInt(&numero, mensaje)) == -1)
    {
        printf("Error. Ingrese solo numeros!\n");
    }
    return numero;
}

int getValidInt(int* numero, char* mensaje)
{
    int sePudo = 1;
    int esEspacio = 0;
    char cadenaCargada [20];
    int i;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadenaCargada);
    for(i=0; i<strlen(cadenaCargada) ; i++)
    {
        if(cadenaCargada[i]==' ')
        {
            esEspacio = 1;
            break;
        }

        if(cadenaCargada[i]!='\0')
        {
            if(cadenaCargada[i] < '0' || cadenaCargada[i] > '9')
            {
                sePudo = -1;
            }
        }
    }
    if(esEspacio == 1)
    {
        sePudo = -1;
    }
    if(sePudo == 1)
    {
        *numero = atoi (cadenaCargada);
    }
    return sePudo;
}

int getDosEstados(char* mensaje, int primerEstado, int segundoEstado)
{
    int estadoIngresado;
    estadoIngresado = getInt(mensaje);
    while(primerEstado != estadoIngresado && segundoEstado != estadoIngresado)
    {
        printf("\nError: las opciones son %d o %d.\n",primerEstado,segundoEstado);
        printf(mensaje);
    }
    return estadoIngresado;
}

int compareById(void* pElementOne, void* pElementTwo)
{
    int retorno = -1;
    int id_Uno;
    int id_Dos;

    ePaciente* paciente_Uno = (ePaciente*) pElementOne;
    ePaciente* paciente_Dos = (ePaciente*) pElementTwo;

    paciente_getId(paciente_Uno, &id_Uno);
    paciente_getId(paciente_Dos, &id_Dos);

    if(id_Uno > id_Dos)
    {
        retorno = 1;
    }
    else
    {
        if(id_Uno == id_Dos)
        {
            retorno = 0;
        }
    }

    return retorno;
}


int compareByEspecie(void* pElementOne, void* pElementTwo)
{
	int retorno=0;
	char auxiliarEspecieA[130];
	char auxiliarEspecieB[130];

		if(pElementOne!=NULL && pElementTwo!=NULL){
			if(     paciente_getEspecie(pElementOne, auxiliarEspecieA)==0 &&
					paciente_getEspecie(pElementTwo, auxiliarEspecieB)==0){
				if(strcmp (auxiliarEspecieA , auxiliarEspecieB) > 0 ){
					retorno=1;
				}
				if(strcmp (auxiliarEspecieA , auxiliarEspecieB) < 0 ){
					retorno=-1;
				}
			}
		}
		return retorno;
}

int compareBySexo(void* pElementOne, void* pElementTwo)
{
	int retorno=0;
	char auxiliarSexoA[130];
	char auxiliarSexoB[130];

		if(pElementOne!=NULL && pElementTwo!=NULL){
			if(     paciente_getSexo(pElementOne, auxiliarSexoA)==0 &&
					paciente_getSexo(pElementTwo, auxiliarSexoB)==0){
				if(strcmp (auxiliarSexoA , auxiliarSexoB) > 0 ){
					retorno=1;
				}
				if(strcmp (auxiliarSexoA , auxiliarSexoB) < 0 ){
					retorno=-1;
				}
			}
		}
		return retorno;
}

int compareByNombre(void* pElementOne, void* pElementTwo)
{
	int retorno=0;
	char auxiliarNombreA[130];
	char auxiliarNombreB[130];

		if(pElementOne!=NULL && pElementTwo!=NULL){
			if(     paciente_getNombre(pElementOne, auxiliarNombreA)==0 &&
					paciente_getNombre(pElementTwo, auxiliarNombreB)==0){
				if(strcmp (auxiliarNombreA , auxiliarNombreB) > 0 ){
					retorno=1;
				}
				if(strcmp (auxiliarNombreA , auxiliarNombreB) < 0 ){
					retorno=-1;
				}
			}
		}

    return retorno;
}

int compareByEstadoEsquemaDeVacunacion(void* pElementOne, void* pElementTwo)
{
	int retorno=0;
	char auxiliarEstadoDeVacunacionA[130];
	char auxiliarEstadoDeVacunacionB[130];

		if(pElementOne!=NULL && pElementTwo!=NULL){
			if(     paciente_getEsquemaVacunacion(pElementOne, auxiliarEstadoDeVacunacionA)==0 &&
					paciente_getEsquemaVacunacion(pElementTwo, auxiliarEstadoDeVacunacionB)==0){
				if(strcmp (auxiliarEstadoDeVacunacionA , auxiliarEstadoDeVacunacionB) > 0 ){
					retorno=1;
				}
				if(strcmp (auxiliarEstadoDeVacunacionA , auxiliarEstadoDeVacunacionB) < 0 ){
					retorno=-1;
				}
			}
		}
		return retorno;
}

int compareByEdad(void* pElementOne, void* pElementTwo)
{
    int retorno = -1;
    int edad_Uno;
    int edad_Dos;

    ePaciente* paciente_Uno = (ePaciente*) pElementOne;
    ePaciente* paciente_Dos = (ePaciente*) pElementTwo;

    paciente_getEdad(paciente_Uno, &edad_Uno);
    paciente_getEdad(paciente_Dos, &edad_Dos);

    if(edad_Uno > edad_Dos)
    {
        retorno = 1;
    }
    else
    {
        if(edad_Uno == edad_Dos)
        {
            retorno = 0;
        }
    }

    return retorno;
}
