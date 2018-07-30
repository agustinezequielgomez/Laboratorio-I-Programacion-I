#include <stdio.h>
#include <stdlib.h>
#include "comprobaciones.h"

char seguirConElPrograma(char respuesta)
{
    do
    {
    printf("\n¿Queres seguir con el programa? (s/n) \n");
    scanf("%c",&respuesta);
    }
    while(respuesta!='s'&&respuesta!='n');
    return respuesta;

}

float comprobarValores(int flagA,int flagB,float auxiliar1,float auxiliar2)
{
    if(flagA==1&&flagB==1)
    {
        printf("\n1- Ingresar 1er operando (A=%.2f)\n",auxiliar1);
        printf("2- Ingresar 2do operando (B=%.2f)\n",auxiliar2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
    }
    else if(flagA==1)
    {
        printf("\n1- Ingresar 1er operando (A=%.2f)\n",auxiliar1);
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
    }
    else if(flagB==1)
    {
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=%.2f)\n",auxiliar2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
    }
    else
    {
        printf("\n1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
    }

}


int comprobarOperando(int opcion,int flagA,int flagB)
{
    if(opcion!=1&&opcion!=2&&opcion!=7&&opcion!=9&&flagA==0)
    {
        printf("Para realizar cualquier operacion es necesario que este ingresado el primer operando\n");
        opcion=1;
    }
    else if(opcion!=1&&opcion!=2&&opcion!=7&&opcion!=9&&flagB==0)
    {
        printf("Para realizar cualquier operacion es necesario que este ingresado el segundo operando\n");
        opcion=2;
    }
    return opcion;

}

