#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED
#include"ArrayList.h"

typedef struct
{
    int Id;
    char nombre[20];
    char tarjeta[20];
    char direccion[20];
    int edad;
    int estado;
}ePropietario;

#endif // PROPIETARIO_H_INCLUDED

void menu();

void getInt(char mensaje[],int* dato,char mensajeError[]);

void getString(char mensaje[],char* dato,char mensajeError[]);

void validarEntero(char auxiliar[],int* dato,char mensaje[]);

void validarString(char auxiliar[],char* dato,char mensaje[]);

void stringToUpper(char caracter[]);

void idAutoIncremental(ArrayList* this, ArrayList* this2, ePropietario* aux);

void propietario_set_name(ePropietario* aux);

void propietario_set_card(ePropietario* aux);

void propietario_set_adress(ePropietario* aux);

void propietario_set_age(ePropietario* aux);

void propietario_set_state(ePropietario* aux);

void addPropietario(ArrayList* this, ArrayList* this2);

void printPropietario(ePropietario* this);

void printAllPropietarios(ArrayList* this);

void modificarPropietario(ArrayList* this,ArrayList* this2);

void* compare_propietarios(ArrayList* this, int* indice, ePropietario* aux);

void modificarString(void* dato);

void modificarInt(ePropietario* dato);

void deletePropietario(ArrayList* this,ArrayList* this2);

char getChar(char mensaje[],char caracter);

char deseaContinuar(char mensaje[]);
