#ifndef LOCALIDAD_H_INCLUDED
#define LOCALIDAD_H_INCLUDED

typedef struct
{
    int id;
    int estado;
    char nombreLocalidad[50];
}eLocalidad;


#endif // LOCALIDAD_H_INCLUDED

void loc_MostrarUno(eLocalidad aux);

void loc_MostrarListado(eLocalidad listado[],int arrayLenght);
void loc_MostrarUno(eLocalidad aux);
void loc_MostrarListado(eLocalidad listado [],int largo);
void loc_Alta(eLocalidad listado [],int largo);
void loc_Baja(eLocalidad listado [],int largo,int idParaBorrar);
void loc_Modificacion(eLocalidad listado [],int largo,int idParamodificar);
void loc_ordenarDescPorNombre(eLocalidad listado [],int largo);
void loc_ordenarDescPorID(eLocalidad listado [],int largo);
int loc_pedirId(eLocalidad listado[],int largo);
int loc_menu(void);
void loc_opcion(eLocalidad listado[],int largo,int respuesta);

