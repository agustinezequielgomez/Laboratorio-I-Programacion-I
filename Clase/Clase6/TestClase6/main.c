#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char stringUno[10];
    char stringDos[10];
    char stringAux[10];
    int largoUno;
    int largoDos;
    int comparacion;
    char strCat;
    printf("Ingresar stringUno: ");
    gets(stringUno);
    printf("Ingresar stringDos: ");
    gets(stringDos);
    printf("stringUno %s\n",stringUno);
    printf("stringDos %s\n",stringDos);
    largoUno=strlen(stringUno);
    largoDos=strlen(stringDos);
    printf("Largo stringUno %d\n",largoUno);
    printf("Largo stringDos %d\n",largoDos);
    strcpy(stringAux,stringUno);
    strcpy(stringUno,stringDos);
    strcpy(stringDos,stringAux);
    printf("stringDos %s\n",stringDos);
    printf("stringUno %s\n",stringUno);
    comparacion=strcmp(stringUno,stringDos);
    printf("comparacion %d\n",comparacion);
    strCat=strcat(stringUno,stringDos);
    printf("strcat %c",strCat);
    return 0;
}
