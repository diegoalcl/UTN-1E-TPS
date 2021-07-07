/*TP2 Alderete Diego Fernando 1E
 * Una empresa requiere un sistema para administrar su n�mina de empleados.
 * Se sabe quedicha n�mina bajo ninguna circunstancia superara los 1000 empleados.
 * El sistema deber� tener el siguiente men� de opciones:
 * 1.ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero de Id.
 * El resto de los campos se le pedir� al usuario.
 * 2.MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido Salario o Sector
 * 3.BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
 * 4.INFORMAR: 1.Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
 * 2.Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.
 * NOTA: Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
 * Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la carga de alg�n empleado.
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
