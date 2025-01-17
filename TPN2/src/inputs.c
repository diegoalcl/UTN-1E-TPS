#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "inputs.h"

int getInt(char *mensaje)
{
    int numero;
    while((getValidInt(&numero, mensaje)) == -1){
        printf("Error. Ingrese un n�mero v�lido.\n");
    }
    return numero;
}
int getValidInt(int* numero, char* mensaje){
    int sePudo = 1;
    int esEspacio = 1;
    char cadenaCargada [20];
    int i;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadenaCargada);
    for(i=0; i<strlen(cadenaCargada) ; i++){
        if(cadenaCargada[i]!='\0'){
            if(cadenaCargada[i] < '0' || cadenaCargada[i] > '9'){
                sePudo = -1;
            }
            if(cadenaCargada[i]!=' '){
                esEspacio = -1;
            }
        }
    }
    if(esEspacio == 1){
        sePudo = -1;
    }
    if(sePudo == 1){
        *numero = atoi (cadenaCargada);
    }
    return sePudo;
}
char getChar(char mensaje[]){
    char letter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letter);
    return letter;
}
int getValidChar(char* letra){
    int retorno = 0;
    if(*letra <'a' || *letra>'z'){
        printf("Error. Ingrese una sola letra.\n");
        retorno = 1;
    }
    return retorno;
}
char getConfirmacion(char mensaje[]){
    char letter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &letter);
    while(letter!='s' && letter!='n'){
        printf("Error. Ingrese s para si o n para no:\n");
        fflush(stdin);
        scanf("%c", &letter);
    }
    return letter;
}
void getString(char mensaje[], char cadena[]){
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    firstToUpper(cadena);
}
int getStringLetras(char cadena[]){
    int i;
    int flag = 0;
    int esEspacio = 0;
    int tam = strlen(cadena);
    for(i=0;i<tam;i++){
        if(cadena[i] != '\0'){
            if ((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A'||cadena[i]>'Z') && cadena[i]!=' '){
                flag = -1;
            }
            if(cadena[i]!=' '){
                esEspacio = -1;
            }
        }
    }
    if(esEspacio == 0){
        flag = -1;
    }
    return flag;
}
void pedirCadena (char mensaje[], char cadena[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    while(getStringLetras(cadena)== -1){
        printf("Error. Ingrese un nombre v�lido.\n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }
    firstToUpper(cadena);
}
void firstToUpper(char cadena[])
{
    int tam = strlen(cadena);
    int i;
    strlwr(cadena);
    cadena[0] = toupper(cadena[0]);
    for(i=0;i<tam;i++){
        if(cadena[i]!='\0'){
            if(isspace(cadena[i])){
                cadena[i+1] = toupper(cadena[i+1]);
            }
        }
    }
}
int getValidFloat(float* numero, char* mensaje)
{
    int sePudo = 1;
    int esEspacio = 1;
    char cadenaCargada [20];
    int i;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadenaCargada);
    for(i=0; i<strlen(cadenaCargada) ; i++){
        if(cadenaCargada[i]!='\0'){
            if((cadenaCargada[i] < '0' || cadenaCargada[i] > '9') && cadenaCargada[i]!='.'){
                sePudo = -1;
            }
            if(cadenaCargada[i]!=' '){
                esEspacio = -1;
            }
        }
    }
    if(esEspacio == 1){
        sePudo = -1;
    }
    if(sePudo == 1){
        *numero = atof (cadenaCargada);
    }
    return sePudo;
}
float getFloat(char mensaje[]){
    float numero;
    while((getValidFloat(&numero, mensaje)) == -1){
        printf("Error. Ingrese un n�mero v�lido.\n");
    }
    return numero;
}



