#include"cliente.h"
#include"ArrayList.h"
#include"stdio.h"

void parserWriteCliente(ArrayList* this)
{
    int i;
    cliente* aux;
    FILE* pFile;
    pFile=fopen("clientes.csv","w");
    if(pFile!=NULL)
    {
        for(i=0;i<al_len(this);i++)
        {
            aux=al_get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%d,%d,%d\n",aux->dni,aux->estado,aux->turno,aux->numeroTurno);
            }
        }
    }
    fclose(pFile);
}

void parserReadCliente(ArrayList* this)
{
    char dni[5];
    char estado[5];
    char turno[5];
    char numeroTurno[5];
    int leidos;
    cliente* aux;
    FILE* pFile;
    pFile=fopen("clientes.csv","r");
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            aux=(cliente*)malloc(sizeof(cliente));
            if(aux!=NULL)
            {
                leidos=fscanf(pFile,"%[^,],%[^,],%[^,],[^,\n]\n",dni,estado,turno,numeroTurno);
                if(leidos==4)
                {
                    aux->dni=atoi(dni);
                    aux->estado=atoi(estado);
                    aux->numeroTurno=atoi(numeroTurno);
                    aux->turno=atoi(turno);
                    al_add(this,aux);
                }
            }
        }
    }
    fclose(pFile);
}

void parserWriteRegular(ArrayList* this)
{
    int i;
    regular* aux;
    FILE* pFile;
    pFile=fopen("regular.csv","w");
    if(pFile!=NULL)
    {
        for(i=0;i<al_len(this);i++)
        {
            aux=al_get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%d,%d\n",aux->id,aux->clienteDni,aux->estadoAtencion);
            }
        }
    }
    fclose(pFile);
}
void parserReadRegular(ArrayList* this)
{
    char id[5];
    char clienteDni[5];
    char estadoAtencion[5];
    int leidos;
    regular* aux;
    FILE* pFile;
    pFile=fopen("regular.csv","r");
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            aux=(regular*)malloc(sizeof(regular));
            if(aux!=NULL)
            {
                leidos=fscanf(pFile,"%[^,],%[^,],%[^,\n]\n",id,clienteDni,estadoAtencion);
                if(leidos==3)
                {
                    aux->id=atoi(id);
                    aux->clienteDni=atoi(clienteDni);
                    aux->estadoAtencion=atoi(estadoAtencion);
                    al_add(this,aux);
                }
            }
        }
    }
    fclose(pFile);
}
void parserWriteUrgente(ArrayList* this)
{
    int i;
    urgente* aux;
    FILE* pFile;
    pFile=fopen("urgente.csv","w");
    if(pFile!=NULL)
    {
        for(i=0;i<al_len(this);i++)
        {
            aux=al_get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%d,%d\n",aux->id,aux->clienteDni,aux->estadoAtencion);
            }
        }
    }
    fclose(pFile);
}

void parserReadUrgente(ArrayList* this)
{
    char id[5];
    char clienteDni[5];
    char estadoAtencion[5];
    int leidos;
    urgente* aux;
    FILE* pFile;
    pFile=fopen("urgente.csv","r");
    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            aux=(urgente*)malloc(sizeof(urgente));
            if(aux!=NULL)
            {
                leidos=fscanf(pFile,"%[^,],%[^,],%[^,\n]\n",id,clienteDni,estadoAtencion);
                if(leidos==3)
                {
                    aux->id=atoi(id);
                    aux->clienteDni=atoi(clienteDni);
                    aux->estadoAtencion=atoi(estadoAtencion);
                    al_add(this,aux);
                }
            }
        }
    }
    fclose(pFile);
}

