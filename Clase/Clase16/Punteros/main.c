#include <stdio.h>
#include <stdlib.h>

int cargarArray(int*,int);

void mostrarArray(int*,int);

int main()
{
    int vector[3];


    if(cargarArray(NULL,3))
    {
        printf("\nCarga exitosa\n");
        mostrarArray(vector,3);
    }
    else
    {
        printf("\nError al cargar los datos");
    }


    /*int* puntero;
    puntero=vector;

    Cargar y mostrar un vector de manera secuencial(Por puntero)
    int i;
    for(i=0;i<3;i++)
    {
        printf("\nIngresa un numero: ");
        scanf("%d",puntero+i);
    }
    for(i=0;i<3;i++)
    {
        printf("%d\n",*(puntero+i));
        printf("%d\n",*puntero+i);
        Agarra el primer valor y le suma el valor de i (Ej, 5,6,7)
    }

    Equivalentes
    printf("%d\n",vector);
    printf("%d\n",&vector[0]);
    printf("%d\n",&vector);*/
    return 0;
}

int cargarArray(int* array,int tam)
{
    int retorno=0;
    int i;
    if(array!=NULL)
    {
        retorno=1;
        for(i=0; i<tam; i++)
        {
            printf("\nIngresa un numero: ");
            scanf("%d",array+i);
        }
    }
    return retorno;
}

void mostrarArray(int* array,int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d\n",*(array+i));
    }
}
