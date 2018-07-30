
#include "Serie.h"
#include <string.h>

/*
    int idSerie;
    char nombre[50];
    char genero[20];
    int cantidadTemporadas;
    int estado;

*/

void inicializarSeriesEstado(eSerie series[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        series[i].estado = 0;
    }
}


void inicializarSeriesHardCode(eSerie series[])
{
    int id[5] = {100,101,102,103,104};
    char nombre[][50]={"TBBT","TWD","GOT","BB","LCDP"};
    char genero[][50]={"Comedia","Terror","Suspenso","Policial","Policial"};
    int cantidad[5] = {10,9,7,5,2};

    int i;

    for(i=0; i<5; i++)
    {
        series[i].idSerie=id[i];
        series[i].cantidadTemporadas=cantidad[i];
        series[i].estado = 1;
        strcpy(series[i].nombre, nombre[i]);
        strcpy(series[i].genero, genero[i]);
    }
}

void mostrarListaSeries(eSerie listado[], int largo)
{
    int i;
    for(i=0;i<largo;i++)
    {
        if(listado[i].estado!=0)
        {
            printf("\n\nNombre de la serie: %s",listado[i].nombre);
            printf("\nId de la serie: %d",listado[i].idSerie);
            printf("\nCantidad de temporadas de la serie: %d",listado[i].cantidadTemporadas);
            printf("\nGenero de la serie: %s",listado[i].genero);
        }
    }
}

