#include"ArrayList.h"
#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

typedef struct
{
    char cadena[50];
    int id;
    float salario;
}ejemplo;

#endif // ESTRUCTURA_H_INCLUDED

ejemplo* constructor();

int set_int(ejemplo* this, int dato);
int set_string(ejemplo* this, char dato[]);
int set_float(ejemplo* this, float dato);

int get_int(ejemplo* this);
char* get_string(ejemplo* this);
float get_float(ejemplo* this);

int getInt(char mensaje[],int* dato,char mensajeError[]);
int getFloat(char mensaje[],float* dato,char mensajeError[]);
int getString(char mensaje[],char* dato,char mensajeError[]);
int validarEntero(char auxiliar[],int* dato,char mensaje[]);
int validarFloat(char auxiliar[],float* dato,char mensaje[]);
int validarString(char auxiliar[],char* dato,char mensaje[]);
void stringToUpper(char caracter[]);
void idAutoIncremental(ArrayList* this, ArrayList* this2, ejemplo* aux);

void alta(ArrayList* this);
void printAll(ArrayList* this);
void printOne(ejemplo* this);
int compare_id(ArrayList* this,int id);
void baja(ArrayList* this, ArrayList* borrados);
void modificar(ArrayList* this);
void modificarString(void* dato);
void modificarInt(ejemplo* dato);
