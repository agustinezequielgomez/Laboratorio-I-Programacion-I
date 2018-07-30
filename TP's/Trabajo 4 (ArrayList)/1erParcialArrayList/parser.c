#include<stdio.h>
#include"parser.h"
void parserWrite(ArrayList* this, ArrayList* this2)
{
    int i;
    ePropietario* aux;
    FILE* pFile;
    pFile=fopen("propietarios.csv","w");
    if(pFile!=NULL)
    {
        for(i=0;i<al_len(this);i++)
        {
            aux=al_get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%s,%s,%s,%d,%d\n",aux->Id,aux->nombre,aux->tarjeta,aux->direccion,aux->edad,aux->estado);
            }
        }
        for(i=0;i<al_len(this2);i++)
        {
            aux=al_get(this2,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%s,%s,%s,%d,%d\n",aux->Id,aux->nombre,aux->tarjeta,aux->direccion,aux->edad,aux->estado);
            }
        }
    }
    fclose(pFile);
}


void parserRead(ArrayList* this, ArrayList* this2)
{
    char direccion[50];
    char tarjeta[50];
    char nombre[50];
    char id[4];
    char edad[2];
    char estado[2];
    int leidos;
    int i=0;
    ePropietario* aux;
    FILE* pFile;
    pFile=fopen("propietarios.csv","r");
    if(pFile!=NULL)
    {
        do
        {
            leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,tarjeta,direccion,edad,estado);
            if(leidos==6)
            {
                aux=(ePropietario*)malloc(sizeof(ePropietario));
                if(aux!=NULL&&atoi(estado)==1)
                {
                    strcpy(aux->nombre,nombre);
                    strcpy(aux->tarjeta,tarjeta);
                    strcpy(aux->direccion,direccion);
                    aux->Id=atoi(id);
                    aux->edad=atoi(edad);
                    aux->estado=atoi(estado);
                    al_add(this,aux);
                }
                else if(atoi(estado)==2)
                {
                    strcpy(aux->nombre,nombre);
                    strcpy(aux->tarjeta,tarjeta);
                    strcpy(aux->direccion,direccion);
                    aux->Id=atoi(id);
                    aux->edad=atoi(edad);
                    aux->estado=atoi(estado);
                    al_add(this2,aux);
                }
            }
        }while(!feof(pFile));
    }
    fclose(pFile);
}

void parserWriteAutomovil(ArrayList* this, ArrayList* this2)
{
    int i;
    eAutomovil* aux;
    FILE* pFile;
    pFile=fopen("automoviles.csv","w");
    if(pFile!=NULL)
    {
        for(i=0;i<al_len(this);i++)
        {
            aux=al_get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%d,%s,%s,%d,%d\n",aux->idIngreso,aux->idPropietario,aux->patente,aux->marcaNombre,aux->marca,aux->estado);
            }
        }
        for(i=0;i<al_len(this2);i++)
        {
            aux=al_get(this2,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%d,%s,%s,%d,%d\n",aux->idIngreso,aux->idPropietario,aux->patente,aux->marcaNombre,aux->marca,aux->estado);
            }
        }
    }
    fclose(pFile);
}


void parserReadAutomovil(ArrayList* this, ArrayList* this2)
{
    char marcaNombre[50];
    char patente[50];
    char idIngreso[4];
    char idPropietario[2];
    char estado[2];
    char marca[5];
    int leidos;
    eAutomovil* aux;
    FILE* pFile;
    pFile=fopen("automoviles.csv","r");
    if(pFile!=NULL)
    {
        do
        {
            leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",idIngreso,idPropietario,patente,marcaNombre,marca,estado);
            if(leidos==6)
            {
                aux=(ePropietario*)malloc(sizeof(ePropietario));
                if(aux!=NULL&&atoi(estado)==1)
                {
                    strcpy(aux->marcaNombre,marcaNombre);
                    strcpy(aux->patente,patente);
                    aux->idIngreso=atoi(idIngreso);
                    aux->idPropietario=atoi(idPropietario);
                    aux->estado=atoi(estado);
                    aux->marca=atoi(marca);
                    al_add(this,aux);
                }
                else if(atoi(estado)==2)
                {
                    strcpy(aux->marcaNombre,marcaNombre);
                    strcpy(aux->patente,patente);
                    aux->idIngreso=atoi(idIngreso);
                    aux->idPropietario=atoi(idPropietario);
                    aux->estado=atoi(estado);
                    aux->marca=atoi(marca);
                    al_add(this2,aux);
                }
            }
        }while(!feof(pFile));
    }
    fclose(pFile);
}

void parserWriteEgresos(ArrayList* this)
{
    eEgreso* aux;
    int i;
    FILE* pFile;
    pFile=fopen("egresos.csv","w");
    if(pFile!=NULL)
    {
        for(i=0;i<this->len(this);i++)
        {
            aux=this->get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%d,%d,%d,%d,%f\n",aux->idEgreso,aux->idIngreso,aux->horas,aux->marca,aux->estado,aux->recaudacion);
            }
        }
    }
    fclose(pFile);
}

void parserReadEgresos(ArrayList* this)
{
    char idEgreso[20];
    char idIngreso[20];
    char horas[20];
    char marca[20];
    char estado[20];
    char recaudacion[50];
    FILE* pFile;
    int leidos;
    eEgreso* aux;
    pFile=fopen("egresos.csv","r");
    if(pFile!=NULL)
    {
        do
        {
            leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",idEgreso,idIngreso,horas,marca,estado,recaudacion);
            if(leidos==6)
            {
                aux=(eEgreso*)malloc(sizeof(eEgreso));
                if(aux!=NULL)
                {
                    aux->idEgreso=atoi(idEgreso);
                    aux->idIngreso=atoi(idIngreso);
                    aux->horas=atoi(horas);
                    aux->marca=atoi(marca);
                    aux->estado=atoi(estado);
                    aux->recaudacion=atoi(recaudacion);
                    this->add(this,aux);
                }
            }
        }while(!feof(pFile));
    }
    fclose(pFile);
}
