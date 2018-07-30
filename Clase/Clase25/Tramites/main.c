#include"Tramite.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len;
    int i;
    int opcion;
    int ultimoIdTramiteUrgente=0;
    int ultimoIdTramiteRegular=0;

    ArrayList* listaTramiteUrgentes;
    ArrayList* listaTramitesRegulares;

    ArrayList* atendidosUrgentes;
    ArrayList* atendidosRegulares;

    listaTramiteUrgentes=al_newArrayList();
    listaTramitesRegulares=al_newArrayList();

    eTramite* tramiteActual;
    char dni[10];

    atendidosUrgentes=al_newArrayList();
    atendidosRegulares=al_newArrayList();

    do
    {
        printf("\n1- Tramite urgente\n2- Tramite regular\n3- Proximo\n4- Listar pendientes\n5- Informar atendidos\n6- Salir\nElija opcion");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            ultimoIdTramiteUrgente++;
            printf("\nIngrese su DNI ");
            fflush(stdin);
            gets(dni);
            cargarTramite(listaTramiteUrgentes,ultimoIdTramiteUrgente,dni);
            break;
        case 2:
            ultimoIdTramiteRegular++;
            printf("\nIngrese su DNI ");
            fflush(stdin);
            gets(dni);
            cargarTramite(listaTramitesRegulares,ultimoIdTramiteRegular,dni);
            break;
        case 3:
            if(!listaTramiteUrgentes->isEmpty(listaTramiteUrgentes))
            {
                printf("\nCliente a ser atendido (Urgente): ");
                atenderTramite(listaTramiteUrgentes,atendidosUrgentes);
            }
            else if(!listaTramitesRegulares->isEmpty(listaTramitesRegulares))
            {
                printf("\nCliente a ser atendido (Regular): ");
                atenderTramite(listaTramitesRegulares,atendidosRegulares);
            }
            else
            {
                printf("\nNo hay clientes por atender");
            }
            break;
        case 4:
            if(!listaTramiteUrgentes->isEmpty(listaTramiteUrgentes))
            {
                printf("\nTramites urgentes");
                mostrarListaTramites(listaTramiteUrgentes);
            }
            if(!listaTramitesRegulares->isEmpty(listaTramitesRegulares))
            {
                printf("\nTramites Regulares");
                mostrarListaTramites(listaTramitesRegulares);
            }
            break;
        case 5:
            if(!atendidosUrgentes->isEmpty(atendidosUrgentes))
            {
                len=atendidosUrgentes->len(atendidosUrgentes);//Se hace esto porque sino cada vez que se ejecuta el for se llama a una funcion que devuelve un valor estatico
                atendidosUrgentes->sort(atendidosUrgentes,compararPorDni,0);
                printf("\nTramites urgentes");
                for(i=0; i<len; i++)
                {
                    tramiteActual=(eTramite*)atendidosUrgentes->get(atendidosUrgentes,i);
                    mostrarTramite(tramiteActual);
                }
            }
            if(!atendidosRegulares->isEmpty(atendidosRegulares))
            {
                atendidosRegulares->sort(atendidosRegulares,compararPorDni,0);
                printf("\nTramites Regulares");
                len=atendidosRegulares->len(atendidosRegulares);
                for(i=0; i<len; i++)
                {
                    tramiteActual=(eTramite*)atendidosRegulares->get(atendidosRegulares,i);
                    mostrarTramite(tramiteActual);
                }
            }
        }
        system("pause");
        system("cls");
    }
    while(opcion!=6);
    return 0;
}
