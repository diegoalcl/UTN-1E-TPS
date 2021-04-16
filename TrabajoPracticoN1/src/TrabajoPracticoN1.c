/*Alderete Diego Fernando 1E
1 Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesUTN.h"

int main(void)
{
	setbuf(stdout,NULL);

	int operando1;
	int operando2;
	int resultadoSuma;
	int resultadoResta;
	int resultadoMultiplicacion;
	float resultadoDivision;
	int resultadoFactoreo1;
	int resultadoFactoreo2;
	int opcion;
	int ingresoPrimero;
	int ingresoSegundo;
	int operacionesResueltas;

	printf("Bienvenid@ a la calculadora no oficial de la UTN. Ingrese el número correspondiente al item que desea.\n1.Ingresar o cambiar el primer valor.\n2.Ingresar o cambiar el segundo valor.\n3.Realizar las funciones de suma, resta, división, multiplicación y factoreo.\n4.Ver los resultados de esas funciones.\n5.Cerrar la calculadora.");
	scanf("%d", & opcion);

	while(opcion!=7)
	{
		switch (opcion)
		{
			case 1:
				printf("Ingrese el primer operando:");
				scanf("%d", & operando1);
				printf("1.Cambiar el valor del primer operando.\n2.Ingresar o cambiar el segundo operando.\n3.Realizar las funciones de suma, resta, división, multiplicación y factoreo.\n4.Ver los resultados de esas funciones.\n5.Cerrar la calculadora.");
				scanf("%d", & opcion);
				ingresoPrimero=1;
				break;
			case 2:
				printf("Ingrese el segundo operando:");
				scanf("%d", & operando2);
				printf("1.Ingresar o cambiar el valor del primer operando.\n2.Cambiar el segundo operando.\n3.Realizar las funciones de suma, resta, división, multiplicación y factoreo.\n4.Ver los resultados de esas funciones.\n5.Cerrar la calculadora.");
				scanf("%d", & opcion);
				ingresoSegundo=1;
				break;
			case 3:
				if(ingresoPrimero!=1 || ingresoSegundo!=1)
				{
					if(ingresoPrimero!=1)
					{
						printf("Error. No asigno un valor al operando 1.\n");
						opcion=1;
					}
					else
					{
						printf("Error. No asigno un valor al operando 2.\n");
						opcion=2;
					}
				}else{
					operacionesResueltas=1;
					printf("Sus valores elegidos fueron %d y %d, realizando operaciones...\n", operando1, operando2);
					resultadoSuma=suma(operando1,operando2);
					resultadoResta=resta(operando1,operando2);
					resultadoDivision=division(operando1,operando2);
					resultadoMultiplicacion=multiplicacion(operando1,operando2);
					resultadoFactoreo1=factorial(operando1);
					resultadoFactoreo2=factorial(operando2);
					printf("¡Operaciones hechas!.Ingrese 4 para ver los resultados:");
					scanf("%d", & opcion);
					}
				break;
			case 4:
				if(ingresoPrimero!=1 || ingresoSegundo!=1)
				{
					if(ingresoPrimero!=1)
					{
						printf("Error. No asigno un valor al operando 1.");
						opcion=1;
					}
					else
					{
						printf("Error. No asigno un valor al operando 2.");
						opcion=2;
					}
				}else{
					if(operacionesResueltas==1)
					{
						printf("Sus valores elegidos fueron %d y %d.\n", operando1, operando2);
						printf("El resultado de %d sumado a %d es: %d.", operando1, operando2, resultadoSuma);
						printf("\nEl resultado de %d menos %d es: %d.", operando1, operando2, resultadoResta);
						printf("\nEl resultado de %d dividido %d es: %.2f.", operando1, operando2, resultadoDivision);
						printf("\nEl resultado de %d multiplicado %d es: %d.", operando1, operando2, resultadoMultiplicacion);
						printf("\nEl factorial de %d es %d y ", operando1, resultadoFactoreo1);
						printf("el factorial de %d es %d.", operando2, resultadoFactoreo2);
						opcion=6;
					}else{
						printf("Error. Primero ingrese 3 para resolver las operaciones:");
						scanf("%d", &opcion);
					}
				}
				break;
			case 5:
				printf("Ha cerrado la calculadora exitosamente.");
				opcion=7;
				break;
			case 6:
				ingresoPrimero=0;
				ingresoSegundo=0;
				operacionesResueltas=0;
				printf("\nPara seguir realizando operaciones ingrese 1, para cerrar la calculadora ingrese 5:");
				scanf("%d", & opcion);
				break;

		}//termina el switch
	}//termina el while
	return EXIT_SUCCESS;
}
