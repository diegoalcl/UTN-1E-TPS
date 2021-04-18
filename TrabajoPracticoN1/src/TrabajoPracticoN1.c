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
	int metioUnCero;
	int factoreoCero1;
	int factoreoCero2;
	int factoreoNegativo1;
	int factoreoNegativo2;

	ingresoPrimero=0;
	ingresoSegundo=0;
	metioUnCero=0;
	factoreoCero1=0;
	factoreoCero2=0;
	factoreoNegativo1=0;
	factoreoNegativo2=0;

	printf("Bienvenid@ a la calculadora no oficial de la UTN. Ingrese el número correspondiente al item que desea.");
	printf("\n1.Ingresar o cambiar el primer operando.\n2.Ingresar o cambiar el segundo operando.");
	printf("\n3.Realizar las funciones de suma, resta, división, multiplicación y factoreo.");
	printf("\n4.Ver los resultados de esas funciones.\n5.Cerrar la calculadora.");
	//puse las opciones en varios printf para que no haya una linea enorme
	scanf("%d", & opcion);

	while(opcion!=999)
	{
		if(opcion>=1 && opcion<=6)//if para que no se metan opciones invalidas, el 6 es un "reset secreto"
		{
			switch (opcion)//desarrollo de las opciones 1 a 6 del menu
			{
				case 1:
					printf("Ingrese el primer operando:");
					scanf("%d", & operando1);
					ingresoPrimero=1;
					if(ingresoPrimero==1)
					{
						printf("1.Cambiar el valor del primer operando.(Valor actual=%d).", operando1);
					}else{
						printf("1.Ingrese el valor del primer operando(Actualmente no hay valor asignado).");
					}
					if(ingresoSegundo==1)
					{
						printf("\n2.Ingresar o cambiar el segundo operando.(Valor actual=%d).", operando2);
					}else{
						printf("\n2.Ingresar o cambiar el segundo operando.(Actualmente no hay valor asignado).");
					}
					printf("\n3.Realizar las funciones de suma, resta, división, multiplicación y factoreo.");
					printf("\n4.Ver los resultados de esas funciones.\n5.Cerrar la calculadora.");
					scanf("%d", & opcion);
					break;
				case 2:
					printf("Ingrese el segundo operando:");
					scanf("%d", & operando2);
					ingresoSegundo=1;
					if(ingresoPrimero==1)
					{
						printf("1.Ingresar o cambiar el segundo operando.(Valor actual=%d).", operando1);
					}
					else{
						printf("1.Ingresar o cambiar el segundo operando.(Actualmente no hay valor asignado).");
					}
					if(ingresoSegundo==1)
					{
						printf("\n2.Cambiar el segundo operando.(Valor actual=%d).", operando2);
					}else{
						printf("\n2.Ingrese el valor del segundo perando(Actualmente no hay valor asignado).");
					}
					printf("\n3.Realizar las funciones de suma, resta, división, multiplicación y factoreo.");
					printf("\n4.Ver los resultados de esas funciones.\n5.Cerrar la calculadora.");
					scanf("%d", & opcion);
					break;
				case 3:
					if(!ingresoPrimero || !ingresoSegundo)
					{
						if(!ingresoPrimero)
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
						if(operando2!=0)
						{
							metioUnCero=1;
							resultadoDivision=division(operando1,operando2);
						}
						resultadoMultiplicacion=multiplicacion(operando1,operando2);
						if(operando1>0)
						{
							resultadoFactoreo1=factorial(operando1);
						}else{
							if(operando1==0)
							{
								factoreoCero1=1;
							}else{
								factoreoNegativo1=1;
							}
						}
						if(operando2>0)
						{
						resultadoFactoreo2=factorial(operando2);
						}else{
							if(operando2==0)
							{
								factoreoCero2=1;
							}else{
								factoreoNegativo2=1;
							}
						}
						printf("¡Operaciones hechas!.Ingrese 4 para ver los resultados:");
						scanf("%d", & opcion);
						}
					break;
				case 4:
					if(operacionesResueltas==1)
					{
						printf("Sus valores elegidos fueron %d y %d.\n", operando1, operando2);
						printf("El resultado de %d sumado a %d es: %d.", operando1, operando2, resultadoSuma);
						printf("\nEl resultado de %d menos %d es: %d.", operando1, operando2, resultadoResta);

						if(metioUnCero==1)
						{
							printf("\nEl resultado de %d dividido %d es: %.2f.", operando1, operando2, resultadoDivision);
						}else{
							printf("\nNo se puede dividir con un 0.");
						}
							printf("\nEl resultado de %d multiplicado %d es: %d.", operando1, operando2, resultadoMultiplicacion);
						if(factoreoNegativo1==1)
						{
							printf("\n%d es negativo y no se puede factorear y ", operando1);
						}else{
							if(factoreoCero1==0)
							{
								printf("\nEl factorial de %d es %d y ", operando1, resultadoFactoreo1);
							}else
							{
								printf("\nEl factorial de 0 es 1 y ");
							}
						}
						if(factoreoNegativo2==1)
						{
							printf("%d es negativo y no se puede factorear.", operando2);
						}else{
							if(factoreoCero2==0)
							{
								printf("el factorial de %d es %d.", operando2, resultadoFactoreo2);
							}else{
								printf("el factorial de 0 es 1.");
							}
						}
						opcion=6;
					}else{
						printf("Error. Primero ingrese 3 para resolver las operaciones:");
						scanf("%d", &opcion);
					}
					break;
				case 5:
					printf("Ha cerrado la calculadora exitosamente.");
					opcion=999;
					break;
				case 6:
					ingresoPrimero=0;
					ingresoSegundo=0;
					operacionesResueltas=0;
					metioUnCero=0;
					factoreoCero1=0;
					factoreoCero2=0;
					factoreoNegativo1=0;
					factoreoNegativo2=0;
					printf("\nPara seguir realizando operaciones ingrese 1, para cerrar la calculadora ingrese 5:");
					scanf("%d", & opcion);
					break;
			}//termina el switch
		//se cierra el if y se abre un else para asegurarse que no se metan opciones invalidas
		}else{
			printf("Error. Ingrese una opción entre 1 y 5:");
			scanf("%d", & opcion);
		}
	}//termina el while
	return EXIT_SUCCESS;
}
