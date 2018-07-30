#include <stdio.h>
#include <stdlib.h>
void intercambiar(int num1,int num2);
void intercambiarConPunteros(int *num1,int *num2);
void ponerEnCero(int *num1);//Pone en 0 a la variable que esta en el puntero

int main()
{
    int edadUno;
    int edadDos;
    edadUno=22;
    edadDos=99;
    ponerEnCero(&edadDos);
    //intercambiar(edadUno,edadDos); No funciona porque es un pasaje por valor, en el main los valores siguen siendo iguales
    //intercambiarConPunteros(edadUno,edadDos); No funca porque hay que pasarle un puntero
    intercambiarConPunteros(&edadUno,&edadDos);
    printf("\nEdad 1:%d",edadUno);
    printf("\nEdad 2:%d",edadDos);

    return 0;
}

void intercambiar(int num1,int num2)
{
    int aux;
    aux=num1;
    num1=num2;
    num2=aux;
}

void intercambiarConPunteros(int *num1,int *num2)
{
    int aux;
    aux=*num1;
    *num1=*num2;
    *num2=aux;
}

void ponerEnCero(int *num1)
{
    *num1=0;
}
