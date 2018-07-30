#include"automoviles.h"
#ifndef EGRESOS_H_INCLUDED
#define EGRESOS_H_INCLUDED

typedef struct
{
    int idEgreso;
    int idIngreso;
    int horas;
    int marca;
    int estado;
    float recaudacion;
}eEgreso;

#endif // EGRESOS_H_INCLUDED

void egresarAutomovil(ArrayList* automovil, ArrayList* egresados, ArrayList* egresos);

int devolverHorasEstadia(eEgreso* aux);

void tasarEstadia(eAutomovil* aux, eEgreso* egreso);

int compararIdIngreso(ArrayList* automovil, int id);

void printRecaudaciones(ArrayList* egresos);

void printRecaudacionesPorMarca(ArrayList* egresos);
