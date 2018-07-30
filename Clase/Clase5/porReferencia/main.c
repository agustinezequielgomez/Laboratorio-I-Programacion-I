#include <stdio.h>
#include <stdlib.h>
#define cantidad 5

void cambiarEntero(int numero);
void cambiarVector(int listadoDeNumeros[]);
void cargarVectorConMenosUno(int listado[cantidad]);

int main()
{
    /*int edad=22;
    cambiarEntero(edad);
    printf("%d",edad);
    int edades[3];
    cambiarVector(edades);
    printf("\n%d",edades[0]);
    cargarVectorConMenosUno(cantidad);*/
    int i;

    int tamanioVector;
    int tamanioElemento;
    int cantidadElementos;
    int listadoEdades[cantidad]={2,3,4};
    for(i=0;i<cantidad;i++)
    {
        printf("\n%d", listadoEdades[i]);
    }

    tamanioVector= sizeof(listadoEdades);
    printf("\n tamanioVector %d",tamanioVector);
    tamanioElemento= sizeof(listadoEdades[0]);
    cantidadElementos=tamanioVector/tamanioElemento;
    printf("\ntamanioElemenetoasd %d",tamanioElemento);
    printf("\ncantidadasd %d",cantidadElementos);

    printf(" \n\n funcion");
    cargarVectorConMenosUno(listadoEdades);

    return 0;
}

/*void cambiarEntero(int numero)
{
    numero=666;
}

void cambiarVector(int listadoDeNumeros[])
{
    listadoDeNumeros[0]=666;
}*/

void cargarVectorConMenosUno(int listado[])
{
    int tamanioVector;
    int tamanioElemento;
    int cantidadElementos;
    tamanioVector= sizeof(listado);
    printf("\n tamanioVector %d",tamanioVector);
    tamanioElemento= sizeof(listado[0]);
    cantidadElementos=tamanioVector/tamanioElemento;
    printf("\ntamanioElemento %d",tamanioElemento);
    printf("\ncantidad %d",cantidadElementos);

}
