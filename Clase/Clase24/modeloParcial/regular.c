#include"regular.h"
#include"cliente.h"
#include<stdio.h>
void addRegular(ArrayList* this, cliente* auxiliar)
{
    regular* aux;
    aux=(regular*)malloc(sizeof(regular));
    if(aux!=NULL)
    {
        aux->id=auxiliar->numeroTurno;
        aux->clienteDni=auxiliar->dni;
        aux->estadoAtencion=auxiliar->estado;
        al_add(this,aux);
        parserWriteRegular(this);
    }
}
