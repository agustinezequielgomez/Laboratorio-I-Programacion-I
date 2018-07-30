
#include "Usuario.h"

void inicializarUsuariosEstado(eUsuario usuarios[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        usuarios[i].estado = 0;
    }
}
void inicializarUsuariosHardCode(eUsuario usuarios[])
{


    int id[15] = {1000,1001,1002,1003,1004, 1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};

    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,101,100,100,101};



    int i;

    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);

    }
}

void mostrarListaUsuarios(eUsuario listado[], int largo)
{
    int i;
    for(i=0;i<largo;i++)
    {
        if(listado[i].estado!=0)
        {
            printf("\n\nNombre de usuario: %s\nId usuario: %d\nId serie: %d",listado[i].nombre,listado[i].idUsuario,listado[i].idSerie);
        }
    }
}

void mostrarUsuarioConSuSerie(eUsuario usuario[], int largoUsuario, eSerie serie[], int largoSerie)
{
    int i;
    int j;
    for(i=0;i<largoUsuario;i++)
    {
        if(usuario[i].estado!=0)
        {
            usuario[i].idSerie=serie[i].idSerie;
        }

    }
}


