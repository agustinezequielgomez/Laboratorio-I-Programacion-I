#include <stdio.h>
#include <stdlib.h>
#include"parser.h"

int main()
{
    ArrayList* empleado;
    ArrayList* filtro;
    empleado=al_newArrayList();
    parserRead(empleado);
    printAll(empleado);
    printf("\n---Despues de filtrar---\n");
    filtro=al_filter(empleado,funcionQueFiltra);
    if(filtro!=NULL&&filtro->len(filtro)>0)
    {
        printAll(filtro);
        parserWrite(filtro);
    }
    else
    {
        printf("\nNo hay empleados que cumplan los requisitos\n");
    }
    return 0;
}
