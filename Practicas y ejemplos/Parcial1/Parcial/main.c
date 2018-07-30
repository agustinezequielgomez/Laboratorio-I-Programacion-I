#include "lib.h"

int main()
{

    eClient clientes[TAMC];
    eRent rentas[TAMR];

    char seguir = 's';

    inicializarClientes(clientes,TAMC);//INICIALIZA ESTADOS DE CLIENTES EN 0
    inicializarRenta(rentas,TAMR);//INICIALIZA LAS RENTAS EN -1
    hardCodear(clientes,rentas);//HARDCODEA LOS PRIMERO CINCO CLIENTES Y ALQUILERES

     while(seguir=='s')
    {
        switch(menu("1-Alta cliente \n2-Modificar cliente \n3-Baja cliente \n4-Nuevo alquiler \n5-Listado de alquileres por cliente \n6-Salir\n"))// FUNCION MENU SOLO MUESTRA Y LEE LA OPCION
        {
        case 1:
            if(alta(clientes,TAMC)) // ALTA
            {
                printf("Alta exitosa\n");
            }
            break;
        case 2:
            if(modificar(clientes,rentas,TAMC,TAMR))//MODIFICACION
            {
                printf("Modificacion exitosa\n");
            }
            break;
        /*case 3:
            if(baja(programadores,programadoresproyectos,TAMP,TAMPP))//BAJA
            {
                printf("Eliminacion exitosa.\n");
            }
            break;*/
        case 4:

            {
                nuevoAlquiler(clientes,rentas,TAMC,TAMR);
                printf("Alquiler exitoso.\n");
            }
            break;
        case 5://LISTADO DE RENTAS POR CLIENTES
            rentasxclientes(clientes,rentas,TAMC,TAMR);
            {
                printf("Listado exitoso.");
            }
            break;
        case 6:
           seguir='n';
            break;
        default:
            printf("Opcion incorrecta.\n");
            break;
        }
        getch();
        system("cls");

    }
    return 0;
}


