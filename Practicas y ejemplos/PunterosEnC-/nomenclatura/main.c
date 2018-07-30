#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *punteroNumero;
    int numero;
    int numeroDos;
    numero=66;
    //&numeroDos=&numero;NO SE PYEDE HACER PORQUE NO HAY NADA PARA ASIGNAR, SON DIRECCIONES DE MEMORIA

    punteroNumero=&numero;
    //*punteroNumero=&numero; NO SE HACE
    //*punteroNumero=55; NO SE HACE
    numeroDos=&numero;//ASIGNACION DE MEMORIA
    printf("\nA-%d",numeroDos);
    numeroDos=*punteroNumero;//ASIGNACION DE VALOR
    printf("\nB-%d",numeroDos);
    printf("\nC-%p",&numero);//MUESTRA DIRECCION DE LA VARIABLE
    printf("\nD-%p",punteroNumero);//MUESTRA DIRECCION DE LA VARIABLE (LLAMANDO AL PUNTERO, YA QUE ESTE CONTIENE LA VARIABLE)
    printf("\nE-%p",&punteroNumero); //MUESTRA DIRECCION DE DONDE ESTA GUARDADO EL PUNTERO
    printf("\nF-%d",*punteroNumero);//VALOR QUE CONTIENE LA DIRECCION DE MEMORIA

    //printf("%d",*punteroNumero); NO SE HACE

    return 0;
}
