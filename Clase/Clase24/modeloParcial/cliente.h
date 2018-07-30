#include"ArrayList.h"
#include"urgente.h"
#include"regular.h"
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int dni;
    int turno;
    int numeroTurno;
    int estado;
}cliente;

#endif // CLIENTE_H_INCLUDED

void getInt(char mensaje[],int* dato,char mensajeError[]);
void validarEntero(char auxiliar[],int* dato,char mensaje[]);
void cliente_set_id(cliente* aux);
void cliente_set_turno(cliente* aux, int opcion);
void cliente_set_estado(cliente* aux);
void add_cliente(ArrayList* urgente, ArrayList* regular, ArrayList* cliente,int opcion);
void set_numero_turno(ArrayList* urgente,ArrayList* regular, cliente* auxiliar,int opcion);
void getProximoTurno(ArrayList* urgente, ArrayList* regular, ArrayList* listaCliente);
void addRegular(ArrayList* this, cliente* auxiliar);
void addUrgente(ArrayList* this, cliente* auxiliar);
void menu(void);
void listarPendientes(ArrayList* listaUrgentes, ArrayList* listaRegulares);
void listarAtendidos(ArrayList* listaClientes);
int compararDni(void* dni1,void* dni2);
void atenderCliente(ArrayList* listaCliente, void* elemento);
int buscarDni(void* elemento, ArrayList* listaClientes);
