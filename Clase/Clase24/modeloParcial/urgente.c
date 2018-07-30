
#include<stdio.h>
#include"cliente.h"

void addUrgente(ArrayList* this, cliente* auxiliar)
{
    urgente* aux;
    aux=(urgente*)malloc(sizeof(urgente));
    if(aux!=NULL)
    {
        aux->id=auxiliar->numeroTurno;
        aux->clienteDni=auxiliar->dni;
        aux->estadoAtencion=auxiliar->estado;
        al_add(this,aux);
        parserWriteUrgente(this);
    }
}
