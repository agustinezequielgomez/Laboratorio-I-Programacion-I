#include <stdio.h>
#include <stdlib.h>
#include"parser.h"

int main()
{
    ArrayList* numero;
    ArrayList* depurado;
    ArrayList* repetidos;
    repetidos=al_newArrayList();
    depurado=al_newArrayList();
    numero=al_newArrayList();
    int opcion;
    do
    {
        printf("\n1- Altas");
        printf("\n2- Mostrar");
        printf("\n3- Completar");
        printf("\n4- Listar");
        printf("\n5- Generar");
        printf("\n6- Salir");
        getInt("\nIngrese una opcion ",&opcion,"\nOpcion invalida ");
        switch(opcion)
        {
        case 1:
            parserRead(numero);
            break;
        case 2:
            printAll(numero);
            break;
        case 3:
            completarNumero(numero);
            break;
        case 4:
            depurado=al_clone(numero);
            buscarNumeroRepetido(numero,repetidos,depurado);
            break;
        case 5:
            parserWrite(repetidos,"repetidos.csv");
            parserWrite(depurado,"depurado.csv");
            parserWrite(numero,"datos.csv");
            break;

        }
        system("pause");
        system("cls");
    }while(opcion!=6);
    return 0;
}
