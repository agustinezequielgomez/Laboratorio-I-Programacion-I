#include "funcionesVectores.h"
void ejemploCargaSecuencial(void)
{
    int edad;
    float precio;
    int listadoEdades[5]={22,33,44,11,55};
    float listadoPrecios[5];
    int i;

    edad=66;
    printf("%d\n",edad);
    printf("%d\n",&edad);
    printf("&listadoEdades %d\n",&listadoEdades);
    printf("listadoEdades %d\n",listadoEdades);
    printf("listadoEdades[0] %d\n",listadoEdades[0]);
    printf("&listadoEdades[0] %d\n",&listadoEdades[0]);
    printf("listadoEdades[4] %d\n",listadoEdades[4]);
    printf("listadoEdades[5] %d\n",listadoEdades[5]);
    printf("&listadoEdades[5] %d\n",&listadoEdades[5]);

    for(i=0;i<5;i++)
    {
        printf("\nIngrese el numero para la siguiente direccion del array %d: ",i);
        scanf("%d",&listadoEdades[i]);
    }


    for(i=0;i<5;i++)
    {
        printf("\nLa posicion del array es %d y tiene almacenado el valor %d\n",i,listadoEdades[i]);
    }

    for(i=0;i<5;i++)
    {
        printf("Ingresa un precio para la siguiente direccion de array %d: ",i);
        scanf("%f",&listadoPrecios[i]);
    }

    for(i=0;i<5;i++)
    {
        printf("\nLa posicion del array es %d y tiene almacenado el precio %f ",i,listadoPrecios[i]);
    }

}




int ingresarIndice(int indice,int maximo,int minimo)
{
    do
    {
        printf("Ingresa la cantidad de productos que queres ingresar (Entre 0 y 4)");
        scanf("%d",indice);
    }
    while(indice>maximo||indice<minimo);
    return indice;
}

float ingresarPrecios(int indice,int minimo,int maximo,float precio)
{
    do
    {
        printf("Ingresa un precio (entre 1 y 1000) ");
        scanf("%f",&precio);
    }
    while(precio>maximo||precio<minimo);
    return precio;
}
