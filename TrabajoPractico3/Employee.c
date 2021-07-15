#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "ctype.h"

#define MAX_NOMBRE 128

static int isValidNombre(char* cadena,int longitud);

static int isValidNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

Employee* employee_new()
{
    Employee* this = (Employee*) malloc(sizeof(Employee));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre,"");
        this->horasTrabajadas = 0;
        this->sueldo = 0;
    }

    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this = employee_new();

    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        if(this != NULL)
        {
            employee_setId(this, atoi(idStr));
            employee_setNombre(this, nombreStr);
            employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr));
            employee_setSueldo(this, atoi(sueldoStr));
        }
    }

    return this;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int id)
{
	int retorno=-1;
	if(this!=NULL && id>=0)
	{
		retorno=0;
		this->id=id;
	}
	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		if(isValidNombre(nombre,MAX_NOMBRE))
		{
			retorno = 0;
			strncpy(this->nombre,nombre,MAX_NOMBRE);
		}
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,MAX_NOMBRE);
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;
	if(this!=NULL && horasTrabajadas>=0)
	{
		retorno=0;
		this->horasTrabajadas=horasTrabajadas;
	}
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;
	if(this!=NULL && sueldo>=0)
	{
		retorno=0;
		this->sueldo=sueldo;
	}
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this != NULL && sueldo != NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;

}

//a partir de aca son funciones que agregue

int showOneEmployee(Employee* employee)
{
    int retorno = -1;

    if(employee != NULL)
    {
        printf("%4d %18s %20d %20d\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);
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

void pedirDatosEmpleado(char* nombre, char* horasTrabajadas, char* salario)
{
    checkString("Ingrese el nombre del empleado: ", nombre);
    checkStringNumbers("Ingrese las horas trabajadas del empleado: ", horasTrabajadas);
    checkStringNumbers("Ingrese el salario del empleado: ", salario);
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

    Employee* empleado_Uno = (Employee*) pElementOne;
    Employee* empleado_Dos = (Employee*) pElementTwo;

    employee_getId(empleado_Uno, &id_Uno);
    employee_getId(empleado_Dos, &id_Dos);

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

int compareBySalary(void* pElementOne, void* pElementTwo)
{
    int retorno = -1;
    int sueldo_Uno;
    int sueldo_Dos;

    Employee* empleado_Uno = (Employee*) pElementOne;
    Employee* empleado_Dos = (Employee*) pElementTwo;

    employee_getSueldo(empleado_Uno, &sueldo_Uno);
    employee_getSueldo(empleado_Dos, &sueldo_Dos);

    if(sueldo_Uno > sueldo_Dos)
    {
        retorno = 1;
    }
    else
    {
        if(sueldo_Uno == sueldo_Dos)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int compareByName(void* pElementOne, void* pElementTwo)
{
	int retorno=0;
	char auxiliarNombreA[130];
	char auxiliarNombreB[130];

		if(pElementOne!=NULL && pElementTwo!=NULL){
			if(     employee_getNombre(pElementOne, auxiliarNombreA)==0 &&
					employee_getNombre(pElementTwo, auxiliarNombreB)==0){
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

int compareByHoursWorked(void* pElementOne, void* pElementTwo)
{
    int retorno = -1;
    int horasTrabajadas_Uno;
    int horasTrabajadas_Dos;

    Employee* empleado_Uno = (Employee*) pElementOne;
    Employee* empleado_Dos = (Employee*) pElementTwo;

    employee_getHorasTrabajadas(empleado_Uno, &horasTrabajadas_Uno);
    employee_getHorasTrabajadas(empleado_Dos, &horasTrabajadas_Dos);

    if(horasTrabajadas_Uno > horasTrabajadas_Dos)
    {
        retorno = 1;
    }
    else
    {
        if(horasTrabajadas_Uno == horasTrabajadas_Dos)
        {
            retorno = 0;
        }
    }

    return retorno;
}
