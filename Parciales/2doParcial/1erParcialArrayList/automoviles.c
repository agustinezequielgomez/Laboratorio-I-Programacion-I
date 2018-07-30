#include<stdio.h>
#include"automoviles.h"

void automovil_set_idIngreso(ArrayList* this,ArrayList* this2,eAutomovil* aux)
{
    int contador=0;
    eAutomovil* auxiliar;
    int i;
    if(this!=NULL&&aux!=NULL)
    {
        for(i=0;i<al_len(this);i++)
        {
            auxiliar=al_get(this,i);
            if(auxiliar->estado==1)
            {
                contador=contador+1;
            }
        }
        for(i=0;i<al_len(this2);i++)
        {
            auxiliar=al_get(this2,i);
            if(auxiliar->estado==2)
            {
                contador=contador+1;
            }
        }

    }
    aux->idIngreso=contador;
}
void automovil_set_patente(eAutomovil* aux)
{
    getString("\nIngresa la patente del automovil ",aux->patente,"\nPatente invalida ");
    stringToUpper(aux->patente);
}
void automovil_set_marca(eAutomovil* aux)
{
    printf("\n1- ALFA ROMEO\n2- FERRARI\n3- AUDI\n4- OTRO");
    do
    {
        getInt("\nIngresa la marca de tu coche ",&aux->marca,"\nMarca invalida ");
    }while(aux->marca!=1&&aux->marca!=2&&aux->marca!=3&&aux->marca!=4);

    switch(aux->marca)
    {
    case 1:
        strcpy(aux->marcaNombre,"ALFA ROMEO");
        break;
    case 2:
        strcpy(aux->marcaNombre,"FERRARI");
        break;
    case 3:
        strcpy(aux->marcaNombre,"AUDI");
        break;
    case 4:
        strcpy(aux->marcaNombre,"OTRO");
        break;
    }
}
void automovil_set_idProp(ArrayList* prop, eAutomovil* aux)
{
    printAllPropietarios(prop);
    getInt("\nIngresa el ID del propietario al que deseas estacionarle un coche ",&aux->idPropietario,"\nID invalido ");
}
void automovil_set_estado(eAutomovil* aux)
{
    aux->estado=1;
}

int compararIdPropAuto(ArrayList* this,void* elemento)
{
    int retorno=-1;
    eAutomovil* aux;
    int i;
    for(i=0;i<al_len(this);i++)
    {
        aux=al_get(this,i);
        if(aux->idPropietario==elemento)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void addAutomovil(ArrayList* this, ArrayList* this2, ArrayList* propietario)
{
    eAutomovil* aux;
    aux=(eAutomovil*)malloc(sizeof(eAutomovil));
    if(aux!=NULL)
    {
        automovil_set_idProp(propietario,aux);
        if(compare_propietarios(propietario,aux->idPropietario)!=-1)
        {
            automovil_set_idIngreso(this,this2,aux);
            automovil_set_marca(aux);
            automovil_set_patente(aux);
            automovil_set_estado(aux);
            al_add(this,aux);
            parserWriteAutomovil(this,this2);
        }
        else
        {
            free(aux);
        }

    }
}


void printAutomovil(eAutomovil* this)
{
    printf("\n%d\t%d\t\t%s\t\t%s",this->idIngreso,this->idPropietario,this->patente,this->marcaNombre);
}

void printAllAutomovil(ArrayList* this)
{
    eAutomovil* aux;
    int i;
    if(this!=NULL)
    {
        printf("\nID\tID Propietario\t\tPatente\t\tMarca");
        for(i=0;i<al_len(this);i++)
        {
            aux=al_get(this,i);
            printAutomovil(aux);
        }
    }
}

void mostrarPropietarioConSusCoches(ArrayList* this, ArrayList* this2)
{
    int indice=-1;
    int id;
    int i;
    ePropietario* aux;
    eAutomovil* auxiliar;
    printAllPropietarios(this);
    getInt("\nIngresa el ID del propietario de quien quieras ver sus coches ",&id,"\nEl ID no es valido ");
    indice=compare_propietarios(this,id);
    if(indice!=-1)
    {
        aux=this->get(this,indice);
        printf("\nPropietario\n");
        printPropietario(aux);
        printf("\nCoches que tiene estacionados el propietario\n");
        for(i=0; i<al_len(this2); i++)
        {
            auxiliar=al_get(this2,i);
            if(auxiliar->idPropietario==aux->Id)
            {
                printAutomovil(auxiliar);
            }
    }

    }
}
