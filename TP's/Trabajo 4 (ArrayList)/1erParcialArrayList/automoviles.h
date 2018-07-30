#include"propietario.h"
#ifndef AUTOMOVILES_H_INCLUDED
#define AUTOMOVILES_H_INCLUDED

typedef struct
{
    int idIngreso;
    char patente[8];
    int marca;
    char marcaNombre[10];
    int idPropietario;
    int estado;
}eAutomovil;

#endif // AUTOMOVILES_H_INCLUDED

void automovil_set_idIngreso(ArrayList* this,ArrayList* this2,eAutomovil* aux);
void automovil_set_patente(eAutomovil* aux);
void automovil_set_marca(eAutomovil* aux);
void automovil_set_idProp(ArrayList* prop, eAutomovil* aux);
void automovil_set_estado(eAutomovil* aux);
void addAutomovil(ArrayList* this, ArrayList* this2, ArrayList* prop);
int comparadorarIds(ArrayList* this,void* elemento);
void printAutomovil(eAutomovil* this);
void printAllAutomovil(ArrayList* this);
void mostrarPropietarioConSusCoches(ArrayList* this, ArrayList* this2);
