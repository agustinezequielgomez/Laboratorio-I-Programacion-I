#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Localidad.h"
#define TAMANIO 3

int main()
{
    eLocalidad listado;
    int respuesta;
    respuesta=loc_menu();
    loc_opcion(listado,TAMANIO,respuesta)


    /*eLocalidad nuevaLocalidad;
    nuevaLocalidad.estado=1;
    nuevaLocalidad.id=555,444;
    strcpy(nuevaLocalidad.nombreLocalidad,"Maria");
    //printf("%s ",nuevaLocalidad.nombreLocalidad);
    loc_MostrarUno(nuevaLocalidad);
    eLocalidad listadoDeLocalidades[TAMANIO];
    int i;
    for(i=0;i<TAMANIO;i++)
    {
        listadoDeLocalidades[i].id=i*3;
        listadoDeLocalidades[i].estado=1;
        strcpy(listadoDeLocalidades[i].nombreLocalidad,"Maria");
    }
    loc_MostrarListado(listadoDeLocalidades,TAMANIO);*/
    return 0;
}
