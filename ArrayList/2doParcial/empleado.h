#include"ArrayList.h"
#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int id;
    char nombre[50];
    float sueldo;
    int edad;
    char profesion[20];
}empleado;


#endif // EMPLEADO_H_INCLUDED
empleado* constructor();

void set_id(empleado* this, int id);
void set_name(empleado* this, char name[]);
void set_sueldo(empleado* this, float sueldo);
void set_edad(empleado* this, int edad);
void set_profesion(empleado* this, char profesion[]);

int get_id(empleado* this);
char* get_nombre(empleado* this);
float get_salario(empleado* this);
int get_edad(empleado* this);
char* get_profesion(empleado* this);

void printAll(ArrayList* this);
void printOne(empleado* this);
int funcionQueFiltra(void* elemento);
