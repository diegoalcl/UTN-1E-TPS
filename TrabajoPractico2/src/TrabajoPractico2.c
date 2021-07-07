/*TP2 Alderete Diego Fernando 1E
 * Una empresa requiere un sistema para administrar su nómina de empleados.
 * Se sabe quedicha nómina bajo ninguna circunstancia superara los 1000 empleados.
 * El sistema deberá tener el siguiente menú de opciones:
 * 1.ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número de Id.
 * El resto de los campos se le pedirá al usuario.
 * 2.MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido Salario o Sector
 * 3.BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
 * 4.INFORMAR: 1.Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
 * 2.Total y promedio de los salarios, y cuántos empleados superan el salario promedio.
 * NOTA: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
 * Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la carga de algún empleado.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"

int main(void)
{
	setbuf(stdout,NULL);

    Employee lista[1000];

    menu(lista, 1000);

	void menu();

	return EXIT_SUCCESS;
}
