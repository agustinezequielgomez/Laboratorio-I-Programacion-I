#include<stdio.h>
#include"egresos.h"
void egresarAutomovil(ArrayList* automovil, ArrayList* egresados, ArrayList* egresos)
{
    int id;
    int indice=-1;
    eEgreso* aux;
    eAutomovil* auxiliar;
    aux=(eEgreso*)malloc(sizeof(eEgreso));
    if(aux!=NULL)
    {
        printAllAutomovil(automovil);
        getInt("\nIngresa el ID de ingreso a dar de baja ",&id,"\nEl ID no es valido ");
        indice=compararIdIngreso(automovil,id);
        if(indice!=-1)
        {
            auxiliar=automovil->get(automovil,indice);
            devolverHorasEstadia(aux);
            tasarEstadia(auxiliar,aux);
            printf("\nDebe abonar %f",aux->recaudacion);
            if((deseaContinuar("Desea continuar?(S/N) "))=='s')
            {
                aux->idIngreso=auxiliar->idIngreso;
                aux->idEgreso=egresados->size;
                aux->marca=auxiliar->marca;
                aux->estado=1;
                egresos->add(egresos,aux);
                parserWriteEgresos(egresos);
                auxiliar=al_pop(automovil,indice);
                auxiliar->estado=2;
                al_add(egresados,auxiliar);
                parserWriteAutomovil(automovil,egresados);
            }
            else
            {
                free(aux);
            }
        }
    }
}

int devolverHorasEstadia(eEgreso* aux)
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    aux->horas=horas;
    return horas ;
}

void tasarEstadia(eAutomovil* aux, eEgreso* egreso)
{
    int valor;
    if(aux!=NULL&&egreso!=NULL)
    {
        switch(aux->marca)
        {
        case 1:
            valor=egreso->horas*150;
            egreso->recaudacion=valor;
            break;
        case 2:
            valor=egreso->horas*175;
            egreso->recaudacion=valor;
            break;
        case 3:
            valor=egreso->horas*200;
            egreso->recaudacion=valor;
            break;
        case 4:
            valor=egreso->horas*250;
            egreso->recaudacion=valor;
            break;
        }
    }
}

int compararIdIngreso(ArrayList* automovil, int id)
{
    eAutomovil* aux;
    int i;
    for(i=0;i<automovil->len(automovil);i++)
    {
        aux=automovil->get(automovil,i);
        if(aux!=NULL&&aux->idIngreso==id)
        {
            return i;
        }
    }
}

void printRecaudaciones(ArrayList* egresos)
{
    int i;
    float acumulador=0;
    eEgreso* aux;
    for(i=0;i<egresos->len(egresos);i++)
    {
        aux=egresos->get(egresos,i);
        if(aux!=NULL)
        {
            acumulador+=aux->recaudacion;
        }
    }
    printf("\nLa recaudacion total del estacionamiento es de %f",acumulador);
}

void printRecaudacionesPorMarca(ArrayList* egresos)
{
    float acumulador1=0;
    float acumulador2=0;
    float acumulador3=0;
    float acumulador4=0;
    eEgreso* aux;
    int i;
    for(i=0;i<egresos->len(egresos);i++)
    {
        aux=egresos->get(egresos,i);
        if(aux!=NULL)
        {
            switch(aux->marca)
            {
            case 1:
                acumulador1+=aux->recaudacion;
                break;
            case 2:
                acumulador2+=aux->recaudacion;
                break;
            case 3:
                acumulador3+=aux->recaudacion;
                break;
            case 4:
                acumulador4+=aux->recaudacion;
                break;
            }
        }
    }
    printf("\nRecaudacion de ALFA ROMEO %f",acumulador1);
    printf("\nRecaudacion de FERRARI %f",acumulador2);
    printf("\nRecaudacion de AUDI %f",acumulador3);
    printf("\nRecaudacion de OTRO %f",acumulador4);
}
