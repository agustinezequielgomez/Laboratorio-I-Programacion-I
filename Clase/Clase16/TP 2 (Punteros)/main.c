#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


int main()
{
    char seguir='s';
    int opcion=0;
    int* punteroOpcion=NULL;
    punteroOpcion=opcion;
    int flag=0;
    int* punteroFlag=NULL;
    punteroFlag=&flag;
    EPersona lista[20];
    EPersona* punteroEstructura;
    punteroEstructura=lista;
    inicializarEstados(punteroEstructura);
    //inicializarHarcode(punteroEstructura);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        getInt("Elegi una opcion ",&opcion);
        printf("%d",opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                agregarPersona(lista);
                *punteroFlag=1;
                break;
            case 2:
                borrarPersona(lista,punteroFlag);
                break;
            case 3:
                ordenarListaPorNombre(&lista,&punteroFlag);
                break;
            case 4:
                imprimirGrafico(lista);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\nOpcion no encontrada");
                break;
        }
        printf("\n");
        system("pause");
        system("cls");
    }

    return 0;
}
