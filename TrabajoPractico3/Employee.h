#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
//al employee_newParametros le agregue sueldo porque no estaba armada
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);


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
 * param
 * retorna int
 */
int showOneEmployee(Employee* employee);
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
/** \brief Pide datos para un nuevo empleado
 *
 * \param nombre char* para el nombre del empleado
 * \param horasTrabajadas char* para la cantidad de horas trabajadas del empleado
 * \param salario char* para el salario del empleado
 * \retorna void
 *
 */
void pedirDatosEmpleado(char* nombre, char* horasTrabajadas, char* salario);

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

int compareById(void* pElementOne, void* pElementTwo);
/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de empleados por salario
 *
 * \param pElementOne void* El primer empleado a comparar
 * \param pElementTwo void* El segundo empleado a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareBySalary(void* pElementOne, void* pElementTwo);
/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de empleados por nombre
 *
 * \param pElementOne void* El primer empleado a comparar
 * \param pElementTwo void* El segundo empleado a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareByName(void* pElementOne, void* pElementTwo);
/** \brief Esta funcion establece un criterio de comparacion para ordenar a una lista de empleados por cantidad de horas trabajadas
 *
 * \param pElementOne void* El primer empleado a comparar
 * \param pElementTwo void* El segundo empleado a comparar
 * \return int Devuelve 1 si el primero es mayor al segundo, si son iguales devuelve 0
 *
 */
int compareByHoursWorked(void* pElementOne, void* pElementTwo);

/** \brief Esta funcion elimina a un empleado
 *
 * \param employee Employee* el empleado a eliminar
 * \return void
 *
 */

#endif // employee_H_INCLUDED
