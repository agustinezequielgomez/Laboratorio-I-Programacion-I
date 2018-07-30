#include <stdio.h>
#include <stdlib.h>
#include"parser.h"
#include"estructura.h"

int main()
{
    int opcion;
    ArrayList* ejemplo;
    ArrayList* borrados;
    ejemplo=al_newArrayList();
    borrados=al_newArrayList();
    parserRead(ejemplo);
    do
    {
        printf("\n1- Alta");
        printf("\n2- Listar");
        printf("\n3- Baja");
        printf("\n4- Modificar");
        getInt("\nIngrese la opcion que desea realizar ",&opcion,"\nOpcion invalida ");
        switch(opcion)
        {
        case 1:
            alta(ejemplo);
            break;
        case 2:
            printAll(ejemplo);
            break;
        case 3:
            baja(ejemplo,borrados);
            break;
        case 4:
            modificar(ejemplo);
            break;
        }
        printf("\n");
        system("pause");
        system("cls");
    }while(opcion!=5);
    return 0;
}
