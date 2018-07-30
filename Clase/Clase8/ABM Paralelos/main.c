#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Funciones.h"
#define TAM 5

int main()
{
    int legajo[TAM]= {};
    char nombre[TAM][20];
    int nota1[TAM];
    int nota2[TAM];
    float promedio[TAM];
    int opcion;
    int index;
    int i;
    do
    {
        printf("\n1. ALTAS\n2. MOSTRAR\n3. MODIFICAR\n4.BAJA\n5.ORDENAR (por nombre)\n9. SALIR\nElija una opcion: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch(opcion)
        {
        case 1:

            index=cargarAlumno(legajo,nombre,nota1,nota2,promedio,TAM);
            if(index == -1)
            {
                printf("No hay lugar\n");
            }
            else
            {
                printf("\nAlumno ingresado\n");
            }
            break;
        case 2:
            mostrarAlumnos(legajo,nombre,nota1,nota2,promedio,TAM);
            break;
        case 3:
            modificarAlumno(legajo,nombre,nota1,nota2,promedio,TAM);
            break;
        case 4:
            darDeBaja(legajo,nombre,nota1,nota2,promedio,TAM);
            break;
        case 5:
            ordenarPorNombre(legajo,nombre,nota1,nota2,promedio,TAM);
            break;
        }
        system("pause");
        system("cls");
    }
    while(opcion!=9);




    return 0;
}
