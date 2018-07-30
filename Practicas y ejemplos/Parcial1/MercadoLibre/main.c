#include <stdio.h>
#include <stdlib.h>
#include"productos.h"
#define TAMUSUARIO 15
#define TAMPRODUCTO 1000

int main()
{
    eUsuario listadoUsuario[TAMUSUARIO];
    eProducto listadoProducto[TAMPRODUCTO];
    menu(listadoUsuario,listadoProducto,TAMUSUARIO,TAMPRODUCTO);
    return 0;
}
