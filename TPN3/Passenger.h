/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];
	char codigoVuelo[4];
	int isEmpty;
	char estadoVuelo[51];

}Passenger;

Passenger* Passenger_new();
Passenger* passenger_newParametros(char* idStr, char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr,
char* tipoPasajeroStr, char* estadoVueloStr);

void passenger_delete();
int passenger_setId(Passenger* this,int id);
int passenger_getId(Passenger* this,int* id);

int passenger_setNombre(Passenger* this,char* nombre);
int passenger_getNombre(Passenger* this,char* nombre);

int passenger_setApellido(Passenger* this,char* apellido);
int passenger_getApellido(Passenger* this,char* apellido);

int passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int passenger_setPrecio(Passenger* this,float precio);
int passenger_getPrecio(Passenger* this,float* precio);


/** \brief Esta funcion pide el ingreso de 's' o de 'n'
 *
 * \param mensaje[] char El mensaje de ingreso
 * \return char El caracter ingresado
 *
 */
char getYesOrNo(char mensaje[]);

/** \brief Esta funcion convierte la primera letra de un string a mayuscula y las demas a minuscula
 *
 * \param cadena[] char La cadena ingresada
 * \return void
 *
 */

void firstToUpper(char cadena[]);
/** \Brief
 *
 *\ param passenger Passenger* recibe el pasajero a mostrar
 * \muestra la información de un pasajero
 *
 */
int showOnePassenger(Passenger* passenger);

/** \Brief Chequeo que me pasan cadenas de caracteres
 *
 * \param recibe por parametros las cadenas a chequear
 * \param retorna void
 */
/** \Brief Consigue una cadena de solo letras
 *
 * \param recibe por parametros el string
 * \param retorna un int para confirmar si es de solo letras
 */
int getStringCharacters(char cadena[]);

/** \Brief Consigue una cadena de solo numeros
 *
 * \param recibe por parametros el string
 * \param retorna un int para confirmar si es de solo numeros
 */

int getStringNumbers(char cadena[]);

/** \Brief chequeo que me pasen solo cadenas de numeros
 * \
 * \param recibe por parametro las cadenas a chequear
 * retorna void
 */
void checkString (char mensaje[], char cadena[]);

/** \Brief chequeo que me pasen solo cadenas de letras
 * \
 * \param recibe por parametro las cadenas a chequear
 * retorna void
 */
void checkStringNumbers (char mensaje[], char cadena[]);
/** \brief Pide datos para un nuevo pasajero
 *
 * \param nombre char* para el nombre del pasajero
 * \param apellido char* para el nombre del pasajero
 * \param tipoPasajero char* para el tipo de pasajero
 * \param codigoVuelo char* para el codigo de vuelo
 * \param precio char* para el precio del vuelo
 * \param estadoVuelo char* para el estado del vuelo
 * \retorna void
 *
 */
void pedirDatosPasajero(char* nombre, char* apellido, char* tipoPasajero, char* codigoVuelo, char* precio, char* estadoVuelo);

/** \brief Esta funcion pide un entero y lo devuelve
 *
 * \param mensaje char* El mensaje de ingreso
 * \return int El entero ingresado
 *
 */
int getInt(char *mensaje);
/** \brief Esta funcion valida si el valor ingresado es un entero o no
 *
 * \param numero int* El valor ingresado
 * \param mensaje char* El mensaje de ingreso
 * \return int Devuelve -1 si no es un entero o es un entero mas otro valor no entero, o 0 si es entero
 *
 */
int getValidInt(int* numero, char *mensaje);
/** \brief Esta funcion valida que el valor entero ingresado sea uno de dos valores enteros posibles
 *
 * \param mensaje char* el mensaje de ingreso
 * \param primerEstado int el primer valor entero posible
 * \param segundoEstado int el segundo valor entero posible
 * \return int devuelve el valor entero ingresado, luego de haber sido validado
 *
 */
int getDosEstados(char* mensaje, int primerEstado, int segundoEstado);
/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de pasajeros por id
 *
 * \param pElementOne void* El primer pasajero a comparar
 * \param pElementTwo void* El segundo pasajero a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareById(void* pElementOne, void* pElementTwo);

/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de pasajeros por nombre
 *
 * \param pElementOne void* El primer pasajero a comparar
 * \param pElementTwo void* El segundo pasajero a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareByName(void* pElementOne, void* pElementTwo);

/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de pasajeros por apellido
 *
 * \param pElementOne void* El primer pasajero a comparar
 * \param pElementTwo void* El segundo pasajero a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareByLastName(void* pElementOne, void* pElementTwo);

/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de pasajeros por su tipo
 *
 * \param pElementOne void* El primer pasajero a comparar
 * \param pElementTwo void* El segundo pasajero a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareByType(void* pElementOne, void* pElementTwo);

/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de pasajeros por código de vuelo
 *
 * \param pElementOne void* El primer pasajero a comparar
 * \param pElementTwo void* El segundo pasajero a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareByCode(void* pElementOne, void* pElementTwo);

/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de pasajeros por el precio del vuelo
 *
 * \param pElementOne void* El primer pasajero a comparar
 * \param pElementTwo void* El segundo pasajero a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareByPrice(void* pElementOne, void* pElementTwo);


/** \brief Esta funcion elimina a un pasajero
 *
 * \param pasajero Passenger* el pasajero a eliminar
 * \return void
 *
 */
void passenger_delete(Passenger* this);

/** \brief Esta funcion setea el estado del vuelo
 *
 * \param this Passenger* el libro
 * \param estadoVuelo char* el estado del vuelo
 * \return int Devuelve -1 si el puntero al libro es nulo, caso contrario devuelve 0
 *
 */
int passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);

/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de pasajeros por el estado del vuelo
 *
 * \param pElementOne void* El primer pasajero a comparar
 * \param pElementTwo void* El segundo pasajero a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareByFlightStatus(void* pElementOne, void* pElementTwo);

/** \brief Esta funcion busca y trae a un pasajero por su id
 *
 * \param pArrayListPassenger LinkedList* la lista de pasajeros
 * \param id int* el id del pasajero
 * \return int Devuelve -1 si el puntero al libro o al id son nulos, caso contrario devuelve 0
 *
 */

//int getPassengerById(LinkedList* pArrayListPassenger, int id); la reformule
#endif /* PASSENGER_H_ */
