#include"ArrayList.h"
#ifndef TRAMITE_H_INCLUDED
#define TRAMITE_H_INCLUDED

typedef struct
{
    int idTramite;
    char dni[10];
}eTramite;

#endif // TRAMITE_H_INCLUDED

eTramite* new_Tramite(); //Constructor que crea espacio en memoria para la estcutura
int set_id(eTramite*,int id);
int getId(eTramite*);

int set_Dni(eTramite*,char*);
char* getDni(eTramite*);

int mostrarTramite(eTramite*);


int compararPorDni(void* elemento1, void* elemento2);

int mostrarListaTramites(ArrayList* lista);

int cargarTramite(ArrayList* lista,int id, char*);

int atenderTramite(ArrayList*, ArrayList*);
