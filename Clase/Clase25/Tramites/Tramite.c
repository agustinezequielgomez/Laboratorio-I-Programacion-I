#include<stdio.h>
#include<string.h>
#include"Tramite.h"

eTramite* new_Tramite()
{
    eTramite* aux;
    aux=(eTramite*)malloc(sizeof(eTramite));
    return aux;
}

int set_id(eTramite* this, int id)
{
    int seteo=-1;
    if(this!=NULL)
    {
        this->idTramite=id;
        seteo=0;
    }
    return seteo;
}

int getId(eTramite* this)
{
    int id=-1;
    if(this!=NULL)
    {
        id=this->idTramite;
    }
    return id;
}

int set_Dni(eTramite* this,char* dni)
{
   int seteo=-1;
   if(this!=NULL&&dni!=NULL)
   {
        strcpy(this->dni,dni);
        seteo=0;
   }
   return seteo;
}

char* getDni(eTramite* this)
{
    char* dni=NULL;
    if(this!=NULL)
    {
        dni=this->dni;
    }
    return dni;
}

int mostrarTramite(eTramite* this)
{
    int mostro=-1;
    if(this!=NULL)
    {
        printf("\n%d--%s",getId(this),getDni(this));
        mostro=0;
    }
    return mostro;
}

int compararPorDni(void* elemento1, void* elemento2)
{
    eTramite* tramite1;
    eTramite* tramite2;
    tramite1=(eTramite*)elemento1;
    tramite2=(eTramite*)elemento2;
    return(strcmp(tramite1->dni,tramite2->dni));
}

int mostrarListaTramites(ArrayList* listado)
{
    int listo=-1;
    int len;
    eTramite* tramiteActual;
    int i;
    len=listado->len(listado);
    if(listado!=NULL)
    {
        for(i=0;i<len;i++)
        {
            tramiteActual=(eTramite*)listado->get(listado,i);
            mostrarTramite(tramiteActual);
        }
    }
}

int cargarTramite(ArrayList* lista,int id, char* dni)
{
    int cargo=-1;
    if(lista!=NULL&&id>0&&dni!=NULL)
    {
        eTramite* tramiteActual;
        tramiteActual=new_Tramite();
        set_id(tramiteActual,id);
        set_Dni(tramiteActual,dni);
        lista->add(lista,tramiteActual);
        cargo=0;
    }
    return cargo;
}

int atenderTramite(ArrayList* listaPendientes, ArrayList* listaAtendidos)
{
    int atendio=-1;
    eTramite* tramiteActual;
    if(listaPendientes!=NULL&&listaAtendidos!=NULL)
    {
        tramiteActual=(eTramite*)listaPendientes->pop(listaPendientes,0);
        mostrarTramite(tramiteActual);
        listaAtendidos->add(listaAtendidos,tramiteActual);
    }
}
