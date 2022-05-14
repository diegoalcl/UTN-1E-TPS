#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}
typedef Passenger;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/

int initPassengers(Passenger* list, int len);


/** \brief Esta funcion inicializa los ids de todos los lugares del array de pasajeros en 0
 *
 * \param list Passenger* Recibe un puntero a array de pasajeros
 * \param len int Recibe el largo del array
 * \return int Devuelve 0 si realizo la inicializacion o -1 (si el largo del array es invalido o el puntero al array es NULL).
 *
 */
int initIds(Passenger* list, int len);

/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/


int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger,char flyCode[]);

/** \brief Esta funcion carga datos del pasajero en un lugar disponible dentro del array
 *
 * \param list Passenger* Recibe un puntero a array de pasajeros
 * \param len int Recibe el largo del array
 * \return int Devuelve 1 (si el largo del array es invalido o el puntero al array es NULL), -1 (no hay lugar disponible), 0 (logro cargar al pasajero dentro del array)
 *  o 2 (el usuario decidio cancelar la carga)
 *
 */

int loadPassenger(Passenger* list, int len);

/** \brief Esta funcion pide los datos de un pasajero y los guarda en las variables recibidas como parametro
 *
 * \param name[] char El nombre del pasajero
 * \param lastName[] char El apellido del pasajero
 * \param price float* Un puntero a float que es el precio del vuelo
 * \param typePassenger int* Un puntero a int que es el tipo de pasajero
 * \param flyCode[] char El codigo de vuelo
 * \return void
 *
 */

void getDataPassenger(char name[],char lastName[],float* price,int* typePassenger,char flyCode[]);

/** \brief Esta funcion muestra un conjunto de datos de un pasajero.
 *
 * \param name[] char Recibe el nombre del pasajero
 * \param lastName[] char Recibe el apellido del pasajero
 * \param price float Recibe el precio del vuelo del pasajero
 * \param typePassenger int Recibe el tipo de pasajero
 * \param flyCode[] char Recibe el codigo de vuelo
 * \return void
 *
 */

void showData(char name[],char lastName[],float price,int typePassenger,char flyCode[]);

/** \brief Esta función consigue un id nuevo para el pasajero
 *
 * \param list Passenger* Recibe un puntero al array de pasajeros
 * \param len int Recibe el largo del array de pasajeros
 * \return int Retorna el id conseguido
 */

int getNewId(Passenger* list, int len);

/** \brief Esta funcion busca el primer lugar libre en un array de pasajeros
 *
 * \param list Passenger* Recibe un puntero a array de pasajeros
 * \param len int Recibe el largo del array de pasajeros
 * \return int Devuelve el indice del primer lugar libre dentro del array de pasajeros o -1
 * (si no hay lugar disponible, si el largo del array es invalido o si el puntero al array es NULL)
 *
 */

int getIsEmpty(Passenger* list, int len);

/** \brief Esta funcion crea un submenu de modificaciones a un pasajero del array
 *
 * \param list Passenger* Recibe un puntero a un array de pasajeros
 * \param len int Recibe el largo del array de pasajeros
 * \return int Devuelve 0 si logro ordenar o -1 (si el largo del array es invalido o si el puntero al array es NULL o si no encontro al pasajero)
 *
 */

int modificarPasajero(Passenger* list, int len);

/** \brief Esta funcion muestra el contenido de un array de pasajeros
 *
 * \param list Pasenger* Recibe el puntero al array de pasajeros
 * \param len int Recibe el largo del array de pasajeros
 * \return int Devuelve 0 si realizo el mostrar o -1 (si el largo del array es invalido o el puntero al array es NULL).
 *
 */
int printPassengers(Passenger* list, int len);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);

/** \brief Esta funcion muestra a un pasajero existente dentro de la lista
 *
 * \param sPassenger Passenger Recibe el pasajero a mostrar
 * \return void
 *
 */
void showOnePassenger(Passenger sPassenger);

/** \brief Esta funcion muestra la lista de pasajeros existentes y realiza la eliminacion de un empleado o no, dependiendo de lo que elija el usuario.
 *
 * \param list Pasenger* Recibe un puntero a un array de pasajeros
 * \param len int Recibe el largo del array de pasajeros
 * \return int Devuelve -1 si (si el largo del array es invalido, si el puntero al array es NULL),
 * 1 si no encontro al pasajero por ID, 0 si pudo eilminar al pasajero, 2 si el usuario cancelo la accion para eliminar.
 */
int deletePassenger(Passenger* list, int len);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);

/** \brief Esta funcion muestra un submenú para diferentes opciones de listado
 *
 * \param list Passenger* Recibe el puntero al array de pasajeros
 * \param len int Recibe el largo del array de pasajeros
 * \param cantidadPasajeros int recibe la cantidad de pasajeros en forma de entero
 * \return int Devuelve 0 si realizo el mostrar o -1 (si el largo del array es invalido o el puntero al array es NULL).
 *
 */

int informarPasajeros(Passenger* list, int len, int cantidadPasajeros);

/** \brief Esta funcion hardcodea seis pasajeros
 *
 * \param list Passenger* Recibe el puntero al array de pasajeros
 *
 */

void hardcodeoPasajeros(Passenger* list);

/** \brief Esta funcion ordena el listado según los criterios pedidos
 *
 * \param list Passenger* Recibe el puntero al array de tipo Passenger*
 * \param len int Recibe el largo del array de Passenger
 *
 */

void listarPasajerosApellidoYTipo(Passenger* list, int len);

/** \brief Esta funcion muestra un pasajero que aparecerá ordenado según criterio pedido
 *
 * \param list Passenger Recibe el index del pasajero
 *
 */

void mostrarUnPasajeroOrdenado(Passenger list);

/** \brief Esta funcion ordena el listado según los criterios pedidos
 *
 * \param list Passenger* Recibe el puntero al array de tipo Passenger*
 * \param len int Recibe el largo del array de Passenger
 * \param cantidadPasajeros int Recibe la cantidad de pasajeros cargados
 *
 */
void listarTotalYPromedios(Passenger* list, int len, int cantidadPasajeros);

/** \brief Esta funcion ordena el listado según los criterios pedidos
 *
 * \param list Passenger* Recibe el puntero al array de tipo Passenger*
 * \param len int Recibe el largo del array de Passenger
 *
 */

void listarPasajerosCodigoYEstado(Passenger* list, int len);

/** \brief Esta funcion muestra un pasajero que aparecerá ordenado según criterio pedido
 *
 * \param list Passenger Recibe el index del pasajero
 *
 */
void mostrarUnPasajeroOrdenadoPorCodigoYEstado(Passenger list);
#endif /* ARRAYPASSENGER_H_ */
