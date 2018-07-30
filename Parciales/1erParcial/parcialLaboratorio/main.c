#include <stdio.h>
#include <stdlib.h>
#include"egresos.h"
#define TAMPROPIETARIO 100
#define TAMESTACIONADOS 20
#define TAMEGRESO 100




int main()
{
    ePropietario listadoPropietario[TAMPROPIETARIO];
    eAutomovil listadoAutomovil[TAMESTACIONADOS];
    eEgreso listadoEgresos[TAMEGRESO];
    menu(listadoPropietario,listadoAutomovil,listadoEgresos,TAMPROPIETARIO,TAMESTACIONADOS,TAMEGRESO);
    return 0;
}
