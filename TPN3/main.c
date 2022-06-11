#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
 Alderete Diego Fernando 1F
 Modifique tipo de pasajero int[] a char[].
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main(void)
{
	setbuf(stdout, NULL);

    int option = 0;
    int id =0;
    int casosPosiblesDeRetorno=0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	printf("\n-------Menu-------\n1-Cargar datos en modo texto.\n2-Cargar datos en modo binario.\n3-Alta de pasajero.\n4-Modificar datos de pasajero."
    			"\n5-Baja de pasajero.\n6-Listar pasajeros.\n7-Ordenar pasajeros.\n8-Guardar datos de pasajeros en modo texto."
    			"\n9-Guardar datos de pasajeros en modo binario.\n10-Salir.\n");
    	scanf("%d", &option);
        switch(option)
        {
        	case 1:
                casosPosiblesDeRetorno=controller_loadFromText("data.csv",listaPasajeros);
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
                break;
            case 2:
                casosPosiblesDeRetorno=controller_loadFromBinary("data.csv", listaPasajeros);
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
                break;
            case 3:
            	casosPosiblesDeRetorno=controller_addPassenger(listaPasajeros, &id);
                switch(casosPosiblesDeRetorno)
                {
                case -1:
                    printf("Error: no se puede agregar el pasajero a la lista.\n");
                    break;
                case 0:
                    printf("El pasajero fue agregado exitosamente.\n");
                    break;
                case 1:
                    printf("Error: no se puede dar el alta.\n");
                    break;
                case 2:
                    printf("Acción cancelada.\n");
                    break;
                }
                printf("\n");
                break;
            case 4:
                    casosPosiblesDeRetorno=controller_editPassenger(listaPasajeros);
                    switch(casosPosiblesDeRetorno)
                    {
                    case -1:
                        printf("Error: no se ha podido acceder al menu de modificaciones.\n");
                        break;
                    case 0:
                        printf("Error: no se han agregado pasajeros a la lista.\n");
                        break;
                    case 1:
                        printf("Error: el pasajero no existe.\n");
                        break;
                    case 2:
                        printf("Se han guardado las modificaciones.\n");
                        break;
                    case 3:
                        printf("El usuario cancelo la accion.\n");
                        break;
                    }
                    printf("\n");
                    break;
            case 5:
                casosPosiblesDeRetorno=controller_removePassenger(listaPasajeros);
                switch(casosPosiblesDeRetorno)
                {
                case -1:
                    printf("Error: no se ha podido eliminar al pasajero.\n");
                    break;
                case 0:
                    printf("Se ha eliminado al pasajero.\n");
                    break;
                case 1:
                    printf("Error: no se pudo acceder a la baja de pasajeros.\n");
                    break;
                case 2:
                    printf("El usuario cancelo la accion.\n");
                    break;
                case 3:
                    printf("Error: el pasajero no existe.\n");
                    break;
                case 4:
                    printf("Error: no se han agregado pasajeros a la lista.\n");
                    break;
                }
                printf("\n");
                break;
            case 6:
            	casosPosiblesDeRetorno=controller_ListPassenger(listaPasajeros);
                switch(casosPosiblesDeRetorno)
                {
                case -1:
                    printf("Error: no se puede acceder al listado de pasajeros.\n");
                    break;
                case 0:
                    printf("Se han listado todos los pasajeros.\n");
                    break;
                case 1:
                    printf("Error: No se han agregado pasajeros a la lista.\n");
                    break;
                }
                printf("\n");
                break;
            case 7:
                casosPosiblesDeRetorno=controller_sortPassenger(listaPasajeros);
                switch(casosPosiblesDeRetorno)
                {
                case -1:
                    printf("Error: no se pudo realizar el ordenamiento.\n");
                    break;
                case 0:
                    printf("Se ha ordenado a los pasajeros.\n");
                    break;
                case 1:
                    printf("Error: no se pudo acceder al ordenamiento de pasajeros.\n");
                    break;
                case 2:
                    printf("No se han agregado pasajeros a la lista.\n");
                    break;
                case 3:
                    printf("Se ha salido del submenu de ordenamiento.\n");
                    break;
                }
                printf("\n");
                break;
            case 8:
                casosPosiblesDeRetorno=controller_saveAsText("data.csv", listaPasajeros);
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
            	casosPosiblesDeRetorno = controller_saveAsBinary("data.bin", listaPasajeros);
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
                    break;
            case 10:
            		//getYesOrNo("Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
            		printf("\n");
                    break;
            default:
                    printf("Ha ingresado una opcion incorrecta.\n");
                    printf("\n");
                    break;
    		}
    }while(option != 10);


    printf("Se ha cerrado exitosamente el programa.");
    return 0;
}
