/*
 ============================================================================
	Alderete Diego Fernando 1F TP4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../testing/inc/main_test.h"
//#include "../inc/LinkedList.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Pacientes.h"
#include "Parser.h"

int main(void) {

	setbuf(stdout, NULL);

	int ingresarMenu;
    int option = 0;
    int id =0;
    int casosPosiblesDeRetorno=0;
    int banderaAlgoParaGuardar=0;

	startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort

    LinkedList* listaPacientes = ll_newLinkedList();
	printf("Se hicieron las pruebas de las funciones LinkedList.\nIngrese 1 para ingresar al menú del programa principal o 0 para cerrar:");
	fflush(stdin);
	scanf("%d", &ingresarMenu);

	while(ingresarMenu!=0 && ingresarMenu!=1)
	{
		printf("Error. Ingrese 1 para ingresar al menú del programa principal o 0 para cerrar:");
		scanf("%d", &ingresarMenu);
	}

	if(ingresarMenu==1){
	    do{
	    	printf("\n-------Menu-------\n1-Cargar datos en modo texto.\n2-Cargar datos en modo binario.\n3-Alta de paciente.\n4-Modificar datos de paciente."
	    			"\n5-Baja de paciente.\n6-Listar pacientes.\n7-Ordenar pacientes.\n8-Guardar datos de pacientes en modo texto."
	    			"\n9-Guardar datos de pacientes en modo binario.\n10-Salir.\n");
	    	scanf("%d", &option);
	        switch(option)
	        {
	        	case 1:
	                casosPosiblesDeRetorno=controller_loadFromText("data.csv",listaPacientes);
					switch(casosPosiblesDeRetorno)
					{
		            case -1:
		                printf("Error: el archivo no puede ser abierto.\n");
		                break;
		            case 0:
		                printf("Se ha abierto el archivo exitosamente.\n");
		                banderaAlgoParaGuardar=1;
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
	                casosPosiblesDeRetorno=controller_loadFromBinary("data.csv", listaPacientes);
	                switch(casosPosiblesDeRetorno)
	                {
	                case -1:
	                    printf("Error: el archivo no puede ser abierto.\n");
	                    break;
	                case 0:
	                    printf("Se ha abierto el archivo exitosamente.\n");
	                    banderaAlgoParaGuardar=1;
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
	            	casosPosiblesDeRetorno=controller_addPacientes(listaPacientes, &id);
	                switch(casosPosiblesDeRetorno)
	                {
	                case -1:
	                    printf("Error: no se puede agregar el paciente a la lista.\n");
	                    break;
	                case 0:
	                    printf("El paciente fue agregado exitosamente.\n");
	                    banderaAlgoParaGuardar=1;
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
	                    casosPosiblesDeRetorno=controller_editPaciente(listaPacientes);
	                    switch(casosPosiblesDeRetorno)
	                    {
	                    case -1:
	                        printf("Error: no se ha podido acceder al menu de modificaciones.\n");
	                        break;
	                    case 0:
	                        printf("Error: no se han agregado pacientes a la lista.\n");
	                        break;
	                    case 1:
	                        printf("Error: el paciente no existe.\n");
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
	                casosPosiblesDeRetorno=controller_removePaciente(listaPacientes);
	                switch(casosPosiblesDeRetorno)
	                {
	                case -1:
	                    printf("Error: no se ha podido eliminar al paciente.\n");
	                    break;
	                case 0:
	                    printf("Se ha eliminado al paciente.\n");
	                    break;
	                case 1:
	                    printf("Error: no se pudo acceder a la baja de pacientes.\n");
	                    break;
	                case 2:
	                    printf("El usuario cancelo la accion.\n");
	                    break;
	                case 3:
	                    printf("Error: el pasajero no existe.\n");
	                    break;
	                case 4:
	                    printf("Error: no se han agregado pacientes a la lista.\n");
	                    break;
	                }
	                printf("\n");
	                break;
	            case 6:
	            	casosPosiblesDeRetorno=controller_ListPacientes(listaPacientes);
	                switch(casosPosiblesDeRetorno)
	                {
	                case -1:
	                    printf("Error: no se puede acceder al listado de pacientes.\n");
	                    break;
	                case 0:
	                    printf("Se han listado todos los pacientes.\n");
	                    break;
	                case 1:
	                    printf("Error: No se han agregado pacientes a la lista.\n");
	                    break;
	                }
	                printf("\n");
	                break;
	            case 7:
	                casosPosiblesDeRetorno=controller_sortPacientes(listaPacientes);
	                switch(casosPosiblesDeRetorno)
	                {
	                case -1:
	                    printf("Error: no se pudo realizar el ordenamiento.\n");
	                    break;
	                case 0:
	                    printf("Se ha ordenado a los pacientes.\n");
	                    break;
	                case 1:
	                    printf("Error: no se pudo acceder al ordenamiento de pacientes.\n");
	                    break;
	                case 2:
	                    printf("No se han agregado pacientes a la lista.\n");
	                    break;
	                case 3:
	                    printf("Se ha salido del submenu de ordenamiento.\n");
	                    break;
	                }
	                printf("\n");
	                break;
	            case 8:
	            	if(banderaAlgoParaGuardar==0)
	            	{
	            		printf("No hay nada para guardar.");
	            	}else if(banderaAlgoParaGuardar==1)
	            	{
						casosPosiblesDeRetorno=controller_saveAsText("data.csv", listaPacientes);
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
	            	}
	                break;
	            case 9:
	            	if(banderaAlgoParaGuardar==0)
	            	{
	            		printf("No hay nada para guardar.");
	            	}else if(banderaAlgoParaGuardar==1)
	            	{
						casosPosiblesDeRetorno = controller_saveAsBinary("data.bin", listaPacientes);
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
	            	}
	                    break;
	            case 10:
	            		getYesOrNo("Esta seguro que desea salir? Ingrese s para SI o n para NO: ");
	            		printf("\n");
	                    break;
	            default:
	                    printf("Ha ingresado una opcion incorrecta.\n");
	                    printf("\n");
	                    break;
	    		}
	    }while(option != 10);
	}else{
		printf("Programa cerrado exitosamente.");
	}

}
