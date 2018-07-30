#include"ArrayList.h"
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

typedef struct
{
    char nombre[50];
    char mail[50];
}destinatario;

#endif // PARSER_H_INCLUDED
void parserReadDestinatario(char archivo[],ArrayList* this);
ArrayList* depurar(ArrayList* destinatarios,ArrayList* listaNegra);
void listar(ArrayList* listaDepurada);
