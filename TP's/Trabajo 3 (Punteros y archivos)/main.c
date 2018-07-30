#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 100

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie lista[TAM];
    inicializarEstados(&lista,TAM);
    int contadorPeliculas=0;
    cargarPelicula(&lista,TAM,&contadorPeliculas);
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        getInt("Ingresa una opcion ",&opcion,"La opcion ingresada no es un numero. Ingresala nuevamente ");
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                alta(&lista,TAM,&contadorPeliculas);
                system("pause");
                break;
            case 2:
                borrarPelicula(&lista,TAM,&contadorPeliculas);
                system("pause");
                break;
            case 3:
                modificarPelicula(&lista,TAM,&contadorPeliculas);
                system("pause");
               break;
            case 4:
                generarPagina(&lista,TAM,"miArchivo.html");
                system("pause");
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                printf("\nLa opcion ingresada no existe\n");
                system("pause");
                break;
        }
        system("cls");
    }

    return 0;
}
