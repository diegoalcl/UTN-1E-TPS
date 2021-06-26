int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Busca el id actual mas alto
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int getBiggestId(LinkedList* pArrayListEmployee);
/** \brief Busca el espacio vacio siguiente al id mas alto
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int getNextId(LinkedList* pArrayListEmployee);
/** \brief Esta funcion busca a un empleado por id, dentro de una lista dinamica, y si lo encuentra, lo retorna
 *
 * \param pArrayListEmployee LinkedList* la lista dinamica
 * \param id int el id del empleado a encontrar
 * \return int Devuelve el empleado si lo encontro, caso contrario devuelve NULL
 *
 */
int getEmployeeById(LinkedList* pArrayListEmployee, int id);

