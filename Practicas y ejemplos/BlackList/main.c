#include"parser.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int opcion;
    ArrayList* destinatarios;
    ArrayList* black;
    ArrayList* depurada;
    destinatarios=al_newArrayList();
    black=al_newArrayList();
    depurada=al_newArrayList();
    do
    {
        printf("\n1- Cargar destinatarios");
        printf("\n2- Cargar lista negra");
        printf("\n3- Depurar lista");
        printf("\n4- Listar");
        printf("\nIngrese una opcion ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            parserReadDestinatario("destinatarios.csv",destinatarios);
            break;
        case 2:
            parserReadDestinatario("black_list.csv",black);
            break;
        case 3:
            depurada=depurar(destinatarios,black);
            break;
        case 4:
            listar(depurada);
            system("pause");
            break;
        }
    }while(opcion!=5);
    return 0;
}
