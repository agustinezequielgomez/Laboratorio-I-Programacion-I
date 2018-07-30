#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[50];
}ePersona;

ePersona* newPersona();

int main()
{
    ePersona* pPersona;
    pPersona=newPersona();
    return 0;
}

ePersona* newPersona()
{
    ePersona* persona;
    persona=(ePersona*),alloc(sizeof(ePersona));
    return persona;
}
