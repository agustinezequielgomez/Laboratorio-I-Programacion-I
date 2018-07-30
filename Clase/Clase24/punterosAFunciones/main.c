#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void funcionBienvenida(char* nombre);
void funcionDespedida(char* nombre);
void fdelegada(void(*punteroFuncion)(char* eldato),char* nombre);
void funcionDelegada(void(*pFuncion)(char* dato1, char* dato2),char* nombre);
void funcionDel(void(*pFuncion));

//void fdelegada(void(*)(char*),char*);
//void fdelegada(void(*punteroFuncion)(char* eldato),char* nombre);
//void Lo que retorna
//(*punteroFuncion) Nombre de la funcion. El asterisco va por dentro del parentesis para indicar que es puntero a funcion. Si estuviera por fuera seria un puntero a void
//(char* eldato) Parametro que recibe


int main()
{
    fdelegada(funcionBienvenida,"Natalia natalia");
    getche();
    fdelegada(funcionDespedida,"Natalia natalia");
    getche();
    return 0;
}


void funcionBienvenida(char* nombre)
{
    printf("\nBienvenida %s, a la empresa.",nombre);
}
void funcionDespedida(char* nombre)
{
    printf("\nVos %s estas despedida ----->.",nombre);
}

void fdelegada(void(*punteroFuncion)(char* eldato),char* nombre)
{
    punteroFuncion(nombre);
}

void funcionDelegada(void(*pFuncion)(char* dato1, char* dato2),char* nombre)
{
    pFuncion(nombre);
}
