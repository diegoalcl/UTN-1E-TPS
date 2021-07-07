#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "inputs.h"
#define true 1
#define false 0

void menu(Employee list[], int len)
{
    int opcion;
    int retorno;
    char respuesta = 'n';
    int seCargoUnEmpleado = 0;
    initEmployees(list, len);
    initIds(list, len);
    do{
        printf("Ingrese la opción que desea\n1.Altas.\n2.Modificar.\n3.Bajas.\n4.Mostrar lista.\n5.Salir del programa.\n");
        fflush(stdin);
        scanf("%d", &opcion);
        switch(opcion){
        case 1://altas de empleados
            retorno = loadEmployee(list, len);
            switch(retorno){
            case -1:
                printf("No hay lugar disponible en la lista para guardar un empleado nuevo.\n");
                break;
            case 0:
                printf("Se ha cargado exitosamente al empleado.\n");
                seCargoUnEmpleado = 1;
                break;
            case 1:
                printf("Error. No se ha cargado al empleado.\n");
                break;
            case 2:
                printf("El usuario cancelo la carga.\n");
                break;
            }
            printf("\n");
            system("pause");
            break;
        case 2://modificar empleados
            if(seCargoUnEmpleado == 1){
                retorno = modificarEmpleado(list, len);
                switch(retorno){
                case -1:
                    printf("Error. No se encontro el dato.\n");
                    break;
                case 0:
                    printf("El usuario cancelo la accion.\n");
                    break;
                case 1:
                    printf("Se han cargado exitosamente los datos.\n");
                    break;
                }
            }else{
                printf("Debe ingresar al menos un empleado.\n");
            }
            printf("\n");
            system("pause");
            break;
        case 3://bajas de empleados
            if(seCargoUnEmpleado == 1){
                retorno = deleteEmployee(list, len);
                switch(retorno){
                case -1:
                    printf("Error. No se pudo completar la accion.\n");
                    break;
                case 0:
                    printf("Se ha eliminado al empleado de la lista exitosamente.\n");
                    break;
                case 1:
                    printf("El empleado no existe.\n");
                    break;
                case 2:
                    printf("El usuario cancelo la accion.\n");
                    break;
                }
            }else{
                printf("Debe ingresar al menos un empleado.\n");
            }
            printf("\n");
            system("pause");
            break;
        case 4://ordenamiento e informes de empleados
            if(seCargoUnEmpleado == 1){
                retorno = informarEmpleado(list, len);
                switch(retorno){
                case -1:
                    printf("Error. No se puede acceder a informes.\n");
                    break;
                case 1:
                    printf("Error. No se pudo realizar el ordenamiento.\n");
                    break;
                }
            }else{
                printf("Debe ingresar al menos un empleado.\n");
            }
            printf("\n");
            system("pause");
            break;
        case 5://salida del programa
            respuesta = getChar("¿Desea cerrar el programa? Ingrese s para SI o n para NO: ");
            printf("\n");
            break;
        default:
            printf("Opción inválida.\n");
            printf("\n");
            system("pause");
            break;
        }
    }while(respuesta=='n');
    printf("Programa cerrado con éxito.");

}

int initEmployees(Employee* list, int len){
    int i;
    int retorno = -1;
    if(list != NULL && len>0){
        for(i=0; i<len; i++){
            list[i].isEmpty = false;
            retorno = 0;
        }
    }
    return retorno;
}
int initIds(Employee* list, int len){
    int i;
    int retorno = -1;
    if(list != NULL && len>0){
        for(i=0; i<len; i++){
            list[i].id = 0;
            retorno = 0;
        }
    }
    return retorno;
}
int printEmployees(Employee* list, int len){
    int retorno = -1;
    int i;
    if(list != NULL && len>0){
        printf("Id:\tNombre:\t\tApellido:\t\tSalario:\t\tSector:\n");
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty != false)
            {
                retorno = 1;
                showOneEmployee(list[i]);
            }
        }
    }
    return retorno;
}
void showOneEmployee(Employee sEmployee){
    printf("\n");
    printf("%03d", sEmployee.id);
    printf("%12s", sEmployee.name);
    printf("%18s", sEmployee.lastName);
    printf("%22.2f", sEmployee.salary);
    printf("%23d\n", sEmployee.sector);
}
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector){
    int retorno = -1;
    int lugar_Disponible = getIsEmpty(list, len);
    if(lugar_Disponible!= -1){
        list[lugar_Disponible].id = id;
        strcpy(list[lugar_Disponible].name, name);
        strcpy(list[lugar_Disponible].lastName, lastName);
        list[lugar_Disponible].salary = salary;
        list[lugar_Disponible].sector = sector;
        list[lugar_Disponible].isEmpty = true;
        retorno = 0;
    }
    return retorno;
}
int getNewId(Employee* list, int len){
    int retorno = -1;
    int flag = 0;
    int newId;
    if(list != NULL && len>0){
        int i;
        for(i=0;i<len;i++){
            if(flag == 0 || list[i].id>newId){
                newId = list[i].id;
                flag = 1;
            }
        }
        retorno = newId;
    }
    return retorno;
}
int loadEmployee(Employee* list, int len){
    int retorno = 1;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int id;
    char confirmacion;
    char opcion_continuar;
    if(list != NULL && len>0){
        do{
            getDataEmployee(name, lastName, &salary, &sector);
            printf("\n");
            printf("Estos son los datos ingresados:\n");
            showData(name, lastName, salary, sector);
            printf("\n");
            confirmacion = getConfirmacion("Ingrese s para cargar los datos o n para no:\n");
            if(confirmacion == 's'){
                id = getNewId(list, len);
                id++;
                retorno = addEmployee(list, len, id, name, lastName, salary, sector);
            }
            else if(confirmacion == 'n'){
                retorno = 2;
            }
            printf("\n");
            opcion_continuar = getConfirmacion("Ingrese s para agregar otro empleado o n para cargar solo los datos ya ingresados:");
            printf("\n");
        }while(opcion_continuar == 's');
    }
    return retorno;
}
void showData(char name[],char lastName[],float salary,int sector){
    printf("\n");
    printf("Nombre: %s\n", name);
    printf("Apellido %s\n", lastName);
    printf("Salario: $%.2f\n", salary);
    printf("Sector: %d\n", sector);
}
void getDataEmployee(char name[],char lastName[],float* salary,int* sector){
    pedirCadena("Nombre del empleado:\n", name);
    pedirCadena("Apellido del empleado:\n", lastName);
    *salary = getFloat("Salario del empleado:\n");
    *sector = getInt("Sector del empleado:\n");
}
int findEmployeeById(Employee* list, int len,int id){
    int retorno = -1;
    int i;
    if(list != NULL && len>0){
        for(i=0;i<len;i++){
            if(list[i].isEmpty == true){
                if(list[i].id == id){
                    retorno = i;
                    break;
                }
            }
        }
    }
    return retorno;
}
int deleteEmployee(Employee* list, int len){
    int retorno = -1;
    int id = 0;
    int index = 0;
    char confirmacion;
    if(list != NULL && len>0){
        printf("Estos son los empleados:\n");
        printEmployees(list, len);
        id = getInt("\nIngrese el id del empleado que desea dar de baja:");
        printf("\n");
        index = findEmployeeById(list, len, id);
        if(index == -1){
            retorno = 1;
        }else{
            showOneEmployee(list[index]);
            confirmacion = getChar("\nIngrese s para eliminar al empleado o n para conservarlo:");
            if(confirmacion == 's'){
                retorno = removeEmployee(list, len, id);
            }else if(confirmacion == 'n'){
                retorno = 2;
            }
       }
    }
    return retorno;
}
int removeEmployee(Employee* list, int len, int id){
    int retorno = -1;
    int i;
    if(list != NULL && len>0){
        for(i=0;i<len;i++){
            if(list[i].isEmpty == true){
                if(list[i].id == id){
                    list[i].isEmpty = false;
                    retorno = 0;
                    break;
                }
            }
        }
    }
    return retorno;
}
int getIsEmpty(Employee* list, int len){
    int i;
    int retorno = -1;
    if(list != NULL && len>0){
        for(i=0; i<len; i++){
            if(list[i].isEmpty == false){
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
int getIsOccupied(Employee* list, int len){
    int i;
    int retorno = -1;
    if(list != NULL && len>0){
        for(i=0; i<len; i++){
            if(list[i].isEmpty == true){
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
int modificarEmpleado(Employee* list, int len){
    int retorno = -1;
    int id;
    int indice;
    Employee aux;
    int opcion;
    char confirmacion = 's';
    char cargar = 'n';

    printEmployees(list, len);

    id = getInt("\nIngrese el id del empleado a modificar:");
    indice = findEmployeeById(list, len, id);

    if(indice != -1){
        aux = list[indice];
        do{
            fflush(stdin);
            opcion = getInt("Ingrese una opcion:\n1. Cambiar nombre.\n2. Cambiar apellido.\n3. Cambiar salario.\n4. Cambiar sector.\n5. Salir al menú principal.\n");
            switch(opcion){
            case 1:
                pedirCadena("Ingrese un nombre:", aux.name);
                confirmacion = getConfirmacion("\n¿Desea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                printf("\n");
                system("pause");
                break;
            case 2:
                pedirCadena("Ingrese un apellido:", aux.lastName);
                confirmacion = getConfirmacion("\n¿Desea seguir ingresando datos? Ingrese s para SI o n para NO:");
                printf("\n");
                system("pause");
                break;
            case 3:
                aux.salary = getFloat("Ingrese el salario nuevo:");
                confirmacion = getConfirmacion("\n¿Desea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                printf("\n");
                system("pause");
                break;
            case 4:
                aux.sector = getInt("Ingrese el sector nuevo:");
                confirmacion = getConfirmacion("\n¿Desea seguir ingresando datos? Ingrese s para SI o n para NO: ");
                printf("\n");
                system("pause");
                break;
            case 5:
                confirmacion='n';
                printf("\n");
                system("pause");
                break;
            default:
                printf("Opción inválida.\n");
                printf("\n");
                system("pause");
                break;
            }
        }while(confirmacion == 's');

        printf("Este es el empleado:\n");
        printf("\n");
        showOneEmployee(aux);
        printf("\n");
        cargar = getConfirmacion("\n¿Desea cargar los datos? Ingrese s para SI o n para NO:");
        if(cargar == 's'){
            list[indice]=aux;
            retorno = 1;
        }else{
            retorno = 0;
        }
    }
    return retorno;
}
int informarEmpleado(Employee* list, int len){
    int retorno = -1;
    int opcion;
    int orden;
    int opcionContinuar = 's';
    if(list!=NULL && len>0){
        do{
            fflush(stdin);
            opcion = getInt("Ingrese una opción:\n1. Listado de los empleados, ordenado por sector y alfabeticamente.\n2. Informe de los salarios.\n3. Salir al menú principal.\n");
            switch(opcion){
            case 1:
                orden = getInt("\nIngrese 1 si desea ordenar de manera ascendente o 0 si desea ordenar de manera descendente:");
                if(sortEmployees(list, len, orden)!= -1){
                    printEmployees(list, len);
                }else{
                    retorno = 1;
                }
                printf("\n");
                system("pause");
                break;
            case 2:
                menuInformesSalarios(list, len);
                printf("\n");
                system("pause");
                break;
            case 3:
                opcionContinuar='n';
                retorno = 0;
                break;
            default:
                printf("Opción inválida.\n");
                printf("\n");
                system("pause");
                break;
            }
        }while(opcionContinuar == 's');
    }
    return retorno;
}
void menuInformesSalarios(Employee* list, int len){
    float salarios;
    int opcion;
    char opcionContinuar = 's';
    do{
    	fflush(stdin);
        opcion = getInt("Ingrese una opción:\n1.Informe del salario total.\n2.Informe del promedio de salarios.\n3.Informe de los salarios mayores al promedio.\n4.Salir al menu principal.\n");
        switch(opcion){
        case 1:
            salarios = getTotalSalarios(list, len);
            if(salarios == -1){
                printf("No hay total de salarios a mostrar.\n");
            }else{
                printf("Este es el total de los salarios: $%.2f\n", salarios);
            }
            printf("\n");
            system("pause");
            break;
        case 2:
            salarios = getPromedioSalarios(list, len);
            if(salarios == -1){
                printf("No hay salario promedio a mostrar.\n");
            }else{
                printf("Este es el promedio de los salarios: $%.2f\n", salarios);
            }
            printf("\n");
            system("pause");
            break;
        case 3:
            salarios = getMaximoSalario(list, len);
            if(salarios == -1){
                printf("No hay empleados con salarios mayores al promedio.");
            }
            printf("\n");
            system("pause");
            break;
        case 4:
            opcionContinuar='n';
            break;
        default:
            printf("Opción inválida.\n");
            printf("\n");
            system("pause");
            break;
        }
    }while(opcionContinuar == 's');
}
int sortEmployees(Employee* list, int len, int order){
    int retorno = -1;
    Employee auxEmployee;
    int i;
    int j;
    if(list != NULL && len>0){
        if(order == 1){
            for(i=0; i<len-1; i++){
                for(j=i+1; j<len; j++){
                    if(list[i].sector > list[j].sector && list[i].isEmpty == true && list[j].isEmpty == true){
                        auxEmployee = list[i];
                        list[i] = list[j];  //organizado por sector
                        list[j] = auxEmployee;
                    }
                    else{
                        if(list[i].sector == list[j].sector && list[i].isEmpty == true && list[j].isEmpty == true){
                            if(strcmp(list[i].lastName,list[j].lastName)>0){
                                auxEmployee = list[i];
                                list[i] = list[j]; //en el mismo sector, organizado por apellido
                                list[j] = auxEmployee;
                            }
                            else if(strcmp(list[i].lastName,list[j].lastName)==0){
                                if(strcmp(list[i].name,list[j].name)>0){
                                    auxEmployee = list[i];
                                    list[i] = list[j]; //con el mismo apellido, organizaddo por nombre
                                    list[j] = auxEmployee;
                                }
                            }
                        }
                    }
                }
            }
            retorno = 0;
        }
        else if(order == 0){
            for(i=0; i<len-1; i++){
                for(j=i+1; j<len; j++){
                    if(list[i].sector < list[j].sector && list[i].isEmpty == true && list[j].isEmpty == true){
                        auxEmployee = list[i];
                        list[i] = list[j];  //organizo por sector
                        list[j] = auxEmployee;
                    }
                    else{
                        if(list[i].sector == list[j].sector && list[j].sector && list[i].isEmpty == true && list[j].isEmpty == true){
                            if(strcmp(list[i].lastName,list[j].lastName)<0){
                                auxEmployee = list[i];
                                list[i] = list[j]; //dentro del mismo sector, organizo por apellido.
                                list[j] = auxEmployee;
                            }
                            else if(strcmp(list[i].lastName,list[j].lastName)==0){
                                if(strcmp(list[i].name,list[j].name)<0){
                                    auxEmployee = list[i];
                                    list[i] = list[j]; //dentro del mismo apellido, organizo por nombre.
                                    list[j] = auxEmployee;
                                }
                            }
                        }
                    }
                }
            }
            retorno = 0;
        }
    }
    return retorno;
}
float getTotalSalarios(Employee* list, int len){
    float retorno = -1;
    int i;
    float acumuladorSalarios = 0;
    if(list != NULL && len>0){
        for(i=0;i<len;i++){
                if(list[i].isEmpty == true){
                    acumuladorSalarios = list[i].salary + acumuladorSalarios;
                }
        }
        retorno = acumuladorSalarios;
    }
    return retorno;
}
float getPromedioSalarios(Employee* list, int len){
    float retorno = -1;
    float acumuladorSalarios = 0;
    float contadorEmpleados = 0;
    float promedioSalarios = 0;
    int i;
    acumuladorSalarios = getTotalSalarios(list, len);
    if(list != NULL && len>0 && acumuladorSalarios != -1){
        for(i=0;i<len;i++){
            if(list[i].isEmpty == true){
                contadorEmpleados ++;
            }
        }
        promedioSalarios = acumuladorSalarios/contadorEmpleados;
        retorno = promedioSalarios;
    }
    return retorno;
}
int getMaximoSalario(Employee* list, int len){
    int retorno = -1;
    float salarioPromedio = getPromedioSalarios(list, len);
    int i;
    if(list != NULL && len>0){
        if(salarioPromedio != -1){
            for(i=0; i<len; i++){
                if(list[i].isEmpty == true){
                    if(salarioPromedio < list[i].salary){
                        showOneEmployee(list[i]);
                        retorno = 1;
                    }
                }
            }
        }
    }
    return retorno;
}
