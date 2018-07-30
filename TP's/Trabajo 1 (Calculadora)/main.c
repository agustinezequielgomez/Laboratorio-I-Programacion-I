#include <stdio.h>
#include <stdlib.h>
#include "operacionesMatematicas.h"
#include "comprobaciones.h"
#include "inputs.h"
#include <conio.h>

int main()
{
    char seguir='s';
    int opcion=0;
    float numeroUno;
    float numeroDos;
    int flagA=0;
    int flagB=0;
    float suma;
    float resta;
    float division;
    float multiplicacion;
    int entero;
    unsigned long long factor;

    while(seguir=='s')
    {
        comprobarValores(flagA,flagB,numeroUno,numeroDos);
        scanf("%d",&opcion);
        opcion=comprobarOperando(opcion,flagA,flagB);

        switch(opcion)
        {
            case 1:
                numeroUno=getFloat("Ingresa el primer operando ", numeroUno);
                printf("%f\n",numeroUno);
                flagA=1;
                break;
            case 2:
                numeroDos=getFloat("Ingresa el segundo operando ", numeroDos);
                printf("%f",numeroDos);
                flagB=1;
                break;
            case 3:
                suma=sumarDosNumeros(numeroUno, numeroDos);
                break;
            case 4:
                resta=restarDosNumeros(numeroUno, numeroDos);
                break;
            case 5:
                division=dividirDosNumeros(numeroUno, numeroDos);
                break;
            case 6:
                multiplicacion=multiplicarDosNumeros(numeroUno, numeroDos);
                break;
            case 7:
                entero=getInt("Para realizar el factorial es necesario ingresar un numero entero y positivo (Entre 0 y 20): ",entero,20,0);
                factor=factorial(entero);
                break;
            case 8:
                suma=sumarDosNumeros(numeroUno, numeroDos);
                resta=restarDosNumeros(numeroUno, numeroDos);
                division=dividirDosNumeros(numeroUno, numeroDos);
                multiplicacion=multiplicarDosNumeros(numeroUno, numeroDos);
                entero=getInt("\nPara realizar el factorial es necesario ingresar un numero entero y positivo (Entre 0 y 20): ",entero,20,0);
                factor=factorial(entero);
                break;
            case 9:
                seguir = 'n';
                break;
        }

    seguir=seguirConElPrograma(seguir);
    system("cls");
}
printf("Programa finalizado");
return 0;
}


