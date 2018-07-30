#ifndef EUSUARIO_H_INCLUDED
#define EUSUARIO_H_INCLUDED
#define TAMUSUARIO 100
#define LIBRE 1
#define OCUPADO 0

typedef struct
{
    char nombre[TAMUSUARIO][50];
    int Id[TAMUSUARIO];
    int estado[TAMUSUARIO];
}eUsuario;


#endif // EUSUARIO_H_INCLUDED

int eGen_init(eUsuario listado[],int tamanio);

void inicializarHarcode(eUsuario listado[],int tamanio);

int usuario_BuscarLibre(eUsuario listado[],int tamanio);

int eGen_alta(eUsuario listado[] ,int limite);

void altaUsuario(eUsuario listado[],int tamanio,int indice);

void user_modificar(eUsuario listado[],int tamanio);

void mostrarUno(eUsuario listado[],int tamanio);
