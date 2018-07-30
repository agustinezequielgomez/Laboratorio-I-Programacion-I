#include"empleado.h"
#include<stdio.h>
empleado* constructor()
{
    empleado* aux;
    aux=(empleado*)malloc(sizeof(empleado));
    return aux;
}

void set_id(empleado* this, int id)
{
    this->id=id;
}

void set_name(empleado* this, char name[])
{
    strcpy(this->nombre,name);
}

void set_sueldo(empleado* this, float sueldo)
{
    this->sueldo=sueldo;
}

void set_edad(empleado* this, int edad)
{
    this->edad=edad;
}

void set_profesion(empleado* this, char profesion[])
{
    tolower(profesion);
    if(profesion!="analista"&&profesion!="programador"&&profesion!="tester")
    {
        strcpy(this->profesion,profesion);
    }
}

int get_id(empleado* this)
{
    return this->id;
}

char* get_nombre(empleado* this)
{
    return this->nombre;
}

float get_salario(empleado* this)
{
    return this->sueldo;
}

int get_edad(empleado* this)
{
    return this->edad;
}

char* get_profesion(empleado* this)
{
    return this->profesion;
}

void printAll(ArrayList* this)
{
    int i;
    int len=this->len(this);
    empleado* aux;
    printf("\nID\tNombre\t\tSalario\t\tEdad\tProfesion");
    for(i=0;i<len;i++)
    {
        aux=this->get(this,i);
        if(aux!=NULL)
        {
            printOne(aux);
        }
    }
}
void printOne(empleado* this)
{
    printf("\n%d\t%s\t\t%f\t%d\t%s",get_id(this),get_nombre(this),get_salario(this),get_edad(this),get_profesion(this));
}

int funcionQueFiltra(void* elemento)
{
    if(get_edad((empleado*)elemento)>30&&strcmp(get_profesion((empleado*)elemento),"programador")==0)
    {
        return 1;
    }
}
