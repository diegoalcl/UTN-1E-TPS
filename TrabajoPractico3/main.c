#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
 Alderete Diego Fernando 1E
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
	setbuf(stdout,NULL);

    int option = 0;
    int id =0;
    int casosPosiblesDeRetorno=0;//en base a lo que devuelva cada funcion se muestra un mensaje distinto

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	printf("\n-------Menu-------\n1-Cargar datos en modo texto.\n2-Cargar datos en modo binario.\n3-Alta de empleado.\n4-Modificar datos de empleados.\n5-Baja de empleado.");
    	printf("\n6-Listar empleados.\n7-Ordenar empleados.\n8-Guardar datos de empleados en modo texto.\n9-Guardar datos de empleados en modo binario.\n10-Salir.\n");
    	scanf("%d", &option);
        switch(option)
        {
        	case 1:
                casosPosiblesDeRetorno=controller_loadFromText("data.csv",listaEmpleados);
				switch(casosPosiblesDeRetorno)
				{
	            case -1:
	                printf("Error: el archivo no puede ser abierto.\n");
	                break;
	            case 0:
	                printf("Se ha abierto el archivo exitosamente.\n");
	                break;
	            case 1:
	                printf("Error: el archivo no pudo ser cargado en modo texto.\n");
	                break;
	            case 2:
	                printf("Error: La lista ya esta cargada.\n");
	                break;
	           }
	            printf("\n");
	            system("pause");
                break;
            case 2:
                casosPosiblesDeRetorno=controller_loadFromBinary("data.csv", listaEmpleados);
                switch(casosPosiblesDeRetorno)
                {
                case -1:
                    printf("Error: el archivo no puede ser abierto.\n");
                    break;
                case 0:
                    printf("Se ha abierto el archivo exitosamente.\n");
                    break;
                case 1:
                    printf("Error: no pudo ser cargado en modo binario.\n");
                    break;
                case 2:
                    printf("Error: la lista ya esta cargada.\n");
                    break;
                }
                printf("\n");
                system("pause");
                break;
            case 3:
            	casosPosiblesDeRetorno=controller_addEmployee(listaEmpleados, &id);
                switch(casosPosiblesDeRetorno)
                {
                case -1:
                    printf("Error: no se puede agregar el empleado a la lista.\n");
                    break;
                case 0:
                    printf("El empleado fue agregado exitosamente.\n");
                    break;
                case 1:
                    printf("Error: no se puede dar el alta.\n");
                    break;
                case 2:
                    printf("Acción cancelada.\n");
                    break;
                }
                printf("\n");
                system("pause");
                break;
            case 4:
                    casosPosiblesDeRetorno=controller_editEmployee(listaEmpleados);
                    switch(casosPosiblesDeRetorno)
                    {
                    case -1:
                        printf("Error: no se ha podido acceder al menu de modificaciones.\n");
                        break;
                    case 0:
                        printf("Error: no se han agregado empleados a la lista.\n");
                        break;
                    case 1:
                        printf("Error: el empleado no existe.\n");
                        break;
                    case 2:
                        printf("Se han guardado las modificaciones.\n");
                        break;
                    case 3:
                        printf("El usuario cancelo la accion.\n");
                        break;
                    }
                    printf("\n");
                    system("pause");
                    break;
            case 5:
                casosPosiblesDeRetorno=controller_removeEmployee(listaEmpleados);
                switch(casosPosiblesDeRetorno)
                {
                case -1:
                    printf("Error: no se ha podido eliminar al empleado.\n");
                    break;
                case 0:
                    printf("Se ha eliminado al empleado.\n");
                    break;
                case 1:
                    printf("Error: no se pudo acceder a la baja de empleados.\n");
                    break;
                case 2:
                    printf("El usuario cancelo la accion.\n");
                    break;
                case 3:
                    printf("Error: el empleado no existe.\n");
                    break;
                case 4:
                    printf("Error: no se han agregado empleados a la lista.\n");
                    break;
                }
                printf("\n");
                system("pause");
                break;
            case 6:
            	casosPosiblesDeRetorno=controller_ListEmployee(listaEmpleados);
                switch(casosPosiblesDeRetorno)
                {
                case -1:
                    printf("Error: no se puede acceder al listado de empleados.\n");
                    break;
                case 0:
                    printf("Se han listado todos los empleados.\n");
                    break;
                case 1:
                    printf("Error: No se han agregado empleados a la lista.\n");
                    break;
                }
                printf("\n");
                system("pause");
                break;
            case 7:
                casosPosiblesDeRetorno=controller_sortEmployee(listaEmpleados);
                switch(casosPosiblesDeRetorno)
                {
                case -1:
                    printf("Error: no se pudo realizar el ordenamiento.\n");
                    break;
                case 0:
                    printf("Se ha ordenado a los empleados.\n");
                    break;
                case 1:
                    printf("Error: no se pudo acceder al ordenamiento de empleados.\n");
                    break;
                case 2:
                    printf("No se han agregado empleados a la lista.\n");
                    break;
                case 3:
                    printf("Se ha salido del submenu de ordenamiento.\n");
                    break;
                }
                printf("\n");
                system("pause");
                break;
            case 8:
                casosPosiblesDeRetorno=controller_saveAsText("data.csv", listaEmpleados);
                switch(casosPosiblesDeRetorno)
                {
                case -1:
                    printf("Error: no se ha podido acceder al guardado en texto.\n");
                    break;
                case 0:
                    printf("El archivo se ha guardado exitosamente en modo texto.\n");
                    break;
                }
                printf("\n");
                system("pause");
                break;
            case 9:
            	casosPosiblesDeRetorno = controller_saveAsBinary("data.bin", listaEmpleados);
            	switch(casosPosiblesDeRetorno)
            	{
        		case -1:
        			printf("Error: no se ha podido acceder al guardado en binario.\n");
        			break;
        		case 0:
        			printf("El archivo se ha guardado exitosamente en modo binario.\n");
        			break;
            	}
                    printf("\n");
                    system("pause");
                    break;
            case 10:
            		getYesOrNo("Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
            		printf("\n");
                    system("pause");
                    break;
            default:
                    printf("Ha ingresado una opcion incorrecta.\n");
                    printf("\n");
                    system("pause");
                    break;
    		}
    }while(option != 10);


    printf("Se ha cerrado exitosamente el programa.");



    return 0;
}

