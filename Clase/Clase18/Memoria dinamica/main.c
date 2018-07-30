#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct
{
    int id;
    char nombre[50];
}ePersona;

int ePersona_setId(ePersona*,int);
int ePersona_setNombre(ePersona*,char*);
int ePersona_getId(ePersona*);
char* ePersona_getNombre(ePersona*);

int main()
{
    ePersona* pPersona;
    //printf("%p\n",pPersona);//devuelve una 'direccion' basura
    pPersona=(ePersona*) malloc(sizeof(ePersona));
    //printf("%p\n",pPersona);//devuelve una direccion de memoria dinamica. va cambiando cada vez que se ejecuta
    if(pPersona!=NULL)
    {
        if(ePersona_setId(pPersona,45)==-1)//pPersona->id=45;
        {
            printf("Id incorrecto");
        }
        else
        {
            if(ePersona_setNombre(pPersona,"Juan")==-1)
            {
                printf("\nNombre incorrecto");
            }
            else
            {
                printf("%d--%s",ePersona_getId(pPersona),ePersona_getNombre(pPersona));
            }
        }

    }
    return 0;
}


int ePersona_setId(ePersona* this,int id)//this: palabra reservada de C++. es lo mismo que poner ePersona* miPersona
{
    int retorno=-1;
    if(this!=NULL&&id>0)
    {
        retorno=1;
      this->id=id;
    }
    return retorno;
}

int ePersona_setNombre(ePersona* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL&&nombre!=NULL&&strlen(nombre)>3)
    {
        retorno=1;
      strcpy(this->nombre,nombre);
    }
    return retorno;
}

int ePersona_getId(ePersona* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
       retorno=this->id;
    }
    return retorno;
}


char* ePersona_getNombre(ePersona* this)
{
    char* retorno=NULL;
    if(this!=NULL)
    {
        retorno=this->nombre;
    }
    return retorno;
}
