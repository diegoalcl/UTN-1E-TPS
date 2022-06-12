#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "parser.h"
#include "ctype.h"

#define MAX_NOMBRE 128


Passenger* passenger_new()
{
	Passenger* this = (Passenger*) malloc(sizeof(Passenger));

    if(this != NULL)
    {
        this->id = 0;
        strcpy(this->nombre,"");
        strcpy(this->apellido,"");
        this->precio=0;
        strcpy(this->codigoVuelo,"");
        strcpy(this->tipoPasajero,"");
        strcpy(this->estadoVuelo,"");
    }

    return this;
}

Passenger* passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr,
char* tipoPasajeroStr, char* estadoVueloStr)
{
	Passenger* this = passenger_new();
    if(idStr != NULL && nombreStr != NULL && apellidoStr != NULL && codigoVueloStr != NULL && tipoPasajeroStr != NULL && estadoVueloStr != NULL)
    {
        if(this != NULL)
        {
        	passenger_setId(this, atoi(idStr));
        	passenger_setNombre(this, nombreStr);
        	passenger_setApellido(this, apellidoStr);
        	passenger_setCodigoVuelo(this, codigoVueloStr);;
        	passenger_setTipoPasajero(this, tipoPasajeroStr);
        	passenger_setPrecio(this, atoi(precioStr));
        	passenger_setEstadoVuelo(this, estadoVueloStr);
        }
    }

    return this;
}

void passenger_delete(Passenger* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int passenger_setId(Passenger* this,int id)
{
	int retorno=-1;
	if(this!=NULL && id>=0)
	{
		retorno=0;
		this->id=id;
	}
	return retorno;
}

int passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;
	if(this != NULL && id != NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

int passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(this->nombre,nombre);

	}
	return retorno;
}

int passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strncpy(nombre,this->nombre,MAX_NOMBRE);
	}
	return retorno;
}

int passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
			strcpy(this->apellido,apellido);
	}
	return retorno;
}

int passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		retorno = 0;
		strncpy(apellido,this->apellido,MAX_NOMBRE);
	}
	return retorno;
}

int passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno=-1;
	if(this!=NULL && tipoPasajero>=0)
	{
		retorno=0;
		strcpy(this->tipoPasajero,tipoPasajero);
	}
	return retorno;
}

int passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 0;
		strncpy(tipoPasajero,this->tipoPasajero,MAX_NOMBRE);
	}
	return retorno;
}

int passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		strcpy(this->codigoVuelo,codigoVuelo);
	}
	return retorno;
}

int passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 0;
		strncpy(codigoVuelo,this->codigoVuelo,MAX_NOMBRE);
	}
	return retorno;
}

int passenger_setPrecio(Passenger* this,float precio)
{
	int retorno=-1;
	if(this!=NULL && precio>=0)
	{
		retorno=0;
		this->precio=precio;
	}
	return retorno;
}

int passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}


int passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		strcpy(this->estadoVuelo,estadoVuelo);
	}
	return retorno;
}

int passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		retorno = 0;
		strncpy(estadoVuelo,this->estadoVuelo,MAX_NOMBRE);
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

int getBiggestId(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    if(pArrayListPassenger != NULL)
    {
        int len;
        int flag = 0;
        int i;
        Passenger* auxPassenger;

        len = ll_len(pArrayListPassenger);

        for(i=0; i<len; i++)
        {
            auxPassenger = (Passenger*) ll_get(pArrayListPassenger, i);
            if(flag == 0 || retorno < auxPassenger->id)
            {
                retorno = auxPassenger->id;
                flag = -1;
            }
        }
    }
    return retorno;
}

int getNextId(LinkedList* pArrayListPassenger)
{
    int retorno = -1;
    if(pArrayListPassenger != NULL)
    {
        retorno = getBiggestId(pArrayListPassenger);
        retorno++;
    }
    return retorno;
}


int showOnePassenger(Passenger* passenger)
{
    int retorno = -1;
    //printf("%4s %18s %18s %18s %20s %20s\n", "ID:", "Nombre:", "Apellido:", "Tipo pasajero:", "Código de vuelo:", "Precio:", "Estado de vuelo");
    if(passenger != NULL)
    {
        printf("%4d %18s %18s %20s %20s %20.2f %20s\n", passenger->id, passenger->nombre, passenger->apellido, passenger->tipoPasajero, passenger->codigoVuelo,
        		passenger->precio, passenger->estadoVuelo);
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

void pedirDatosPasajero(char* nombre, char* apellido, char* tipoPasajero, char* codigoVuelo, char* precio, char* estadoVuelo)
{
    checkString("Ingrese el nombre del pasajero: ", nombre);
    checkString("Ingrese el apellido del pasajero: ", apellido);
    checkStringNumbers("Ingrese el tipo de pasajero: ", tipoPasajero);
    checkString("Ingrese el código de vuelo: ", codigoVuelo);
    checkStringNumbers("Ingrese el precio del vuelo: ", precio);
    checkString("Ingrese el estado del vuelo:", estadoVuelo);
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

    Passenger* pasajero_Uno = (Passenger*) pElementOne;
    Passenger* pasajero_Dos = (Passenger*) pElementTwo;

    passenger_getId(pasajero_Uno, &id_Uno);
    passenger_getId(pasajero_Dos, &id_Dos);

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


int compareByName(void* pElementOne, void* pElementTwo)
{
	int retorno=0;
	char auxiliarNombreA[130];
	char auxiliarNombreB[130];

		if(pElementOne!=NULL && pElementTwo!=NULL){
			if(     passenger_getNombre(pElementOne, auxiliarNombreA)==0 &&
					passenger_getNombre(pElementTwo, auxiliarNombreB)==0){
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

int compareByLastName(void* pElementOne, void* pElementTwo)
{
	int retorno=0;
	char auxiliarApellidoA[130];
	char auxiliarApellidoB[130];

		if(pElementOne!=NULL && pElementTwo!=NULL){
			if(     passenger_getApellido(pElementOne, auxiliarApellidoA)==0 &&
					passenger_getApellido(pElementTwo, auxiliarApellidoB)==0){
				if(strcmp (auxiliarApellidoA , auxiliarApellidoB) > 0 ){
					retorno=1;
				}
				if(strcmp (auxiliarApellidoA , auxiliarApellidoB) < 0 ){
					retorno=-1;
				}
			}
		}
		return retorno;
}

int compareByType(void* pElementOne, void* pElementTwo)
{
	int retorno=0;
	char auxiliarTipoPasajeroA[130];
	char auxiliarTipoPasajeroB[130];

		if(pElementOne!=NULL && pElementTwo!=NULL){
			if(     passenger_getTipoPasajero(pElementOne, auxiliarTipoPasajeroA)==0 &&
					passenger_getTipoPasajero(pElementTwo, auxiliarTipoPasajeroB)==0){
				if(strcmp (auxiliarTipoPasajeroA , auxiliarTipoPasajeroB) > 0 ){
					retorno=1;
				}
				if(strcmp (auxiliarTipoPasajeroA , auxiliarTipoPasajeroB) < 0 ){
					retorno=-1;
				}
			}
		}

    return retorno;
}

int compareByCode(void* pElementOne, void* pElementTwo)
{
	int retorno=0;
	char auxiliarCodigoA[130];
	char auxiliarCodigoB[130];

		if(pElementOne!=NULL && pElementTwo!=NULL){
			if(     passenger_getCodigoVuelo(pElementOne, auxiliarCodigoA)==0 &&
					passenger_getCodigoVuelo(pElementTwo, auxiliarCodigoB)==0){
				if(strcmp (auxiliarCodigoA , auxiliarCodigoB) > 0 ){
					retorno=1;
				}
				if(strcmp (auxiliarCodigoA , auxiliarCodigoB) < 0 ){
					retorno=-1;
				}
			}
		}
		return retorno;
}

int compareByPrice(void* pElementOne, void* pElementTwo)
{
    int retorno = -1;
    float precio_Uno;
    float precio_Dos;

    Passenger* pasajero_Uno = (Passenger*) pElementOne;
    Passenger* pasajero_Dos = (Passenger*) pElementTwo;

    passenger_getPrecio(pasajero_Uno, &precio_Uno);
    passenger_getPrecio(pasajero_Dos, &precio_Dos);

    if(precio_Uno > precio_Dos)
    {
        retorno = 1;
    }
    else
    {
        if(precio_Uno == precio_Dos)
        {
            retorno = 0;
        }
    }

    return retorno;
}

int compareByFlightStatus(void* pElementOne, void* pElementTwo)
{
	int retorno=0;
	char auxiliarEstadoVueloA[130];
	char auxiliarEstadoVueloB[130];

		if(pElementOne!=NULL && pElementTwo!=NULL){
			if(     passenger_getEstadoVuelo(pElementOne, auxiliarEstadoVueloA)==0 &&
					passenger_getEstadoVuelo(pElementTwo, auxiliarEstadoVueloB)==0){
				if(strcmp (auxiliarEstadoVueloA , auxiliarEstadoVueloB) > 0 ){
					retorno=1;
				}
				if(strcmp (auxiliarEstadoVueloA , auxiliarEstadoVueloB) < 0 ){
					retorno=-1;
				}
			}
		}
		return retorno;
}

