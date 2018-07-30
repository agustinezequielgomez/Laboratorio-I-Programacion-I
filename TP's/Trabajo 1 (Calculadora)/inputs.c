#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include <conio.h>


float getFloat(char mensaje[],float numeroIngresado)
{
    printf("%s",mensaje);
    scanf("%f",&numeroIngresado);
    getchar();
    return numeroIngresado;
}

int getInt(char mensaje[], int enteroIngresado, int maximo, int minimo)
{
    do
    {
        printf("%s",mensaje);
        scanf("%d",&enteroIngresado);
    }
    while(enteroIngresado>maximo||enteroIngresado<minimo);
    return enteroIngresado;
}
