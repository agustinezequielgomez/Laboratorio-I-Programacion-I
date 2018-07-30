#include <stdio.h>
#include <stdlib.h>
#define TAM 5

typedef struct
{
    char nombre[20];
    int edad;
    int estado;
}eEstructura;

int getIntPuntero(int* dato,char mensaje[]);

char getStringPuntero(char* dato[],char mensaje[]);

void alta(eEstructura* estructura,int indice);

int buscarLibrePuntero(eEstructura*,int tamanio);

void inicializarEstados(eEstructura* estructura,int tamanio);

void mostrarEstructura(eEstructura* estructura,int tamanio);

int main()
{
    int indice;
    char seguir='s';
    int opcion=0;
    eEstructura alumno[TAM];
    eEstructura* puntero;
    puntero=&alumno;
    inicializarEstados(&puntero,TAM);
    while(seguir=='s')
    {
        printf("\n1- ALTA");
        printf("\n2- MOSTRAR");
        getIntPuntero(&opcion,"\nIngresa una opcion ");
        printf("\n%d",opcion);
        switch(opcion)
        {
        case 1:
            indice=buscarLibrePuntero(&puntero,TAM);
            alta(&puntero,indice);
            break;
        case 2:
            mostrarEstructura(&puntero,TAM);
            break;
        }
        system("pause");
        system("cls");
    }

    return 0;
}

void inicializarEstados(eEstructura* estructura,int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        (estructura+i)->estado=0;
    }
}

int buscarLibrePuntero(eEstructura* estructura,int tamanio)
{
    int indice=-1;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if((estructura+i)->estado==0&&(estructura+i)!=NULL)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int getIntPuntero(int* dato,char mensaje[])
{
    printf("%s",mensaje);
    scanf("%d",dato);
    fflush(stdin);
    return dato;
}

char getStringPuntero(char* dato[],char mensaje[])
{
    printf("%s",mensaje);
    gets(dato);
    fflush(stdin);
    return dato;
}

void alta(eEstructura* estructura,int indice)
{
    if(indice!=-1)
    {
        getIntPuntero(&(estructura+indice)->edad,"Ingresa tu edad ");
        getStringPuntero(&(estructura+indice)->nombre,"Ingresa tu nombre ");
        (estructura+indice)->estado=1;
    }
    else
    {
        printf("NO HAY LUGAR");
    }
}

void mostrarEstructura(eEstructura* estructura,int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        if((estructura+i)->estado==1)
        {
            printf("\nNombre: %s",(estructura+i)->nombre);
            printf("\nEdad: %d",(estructura+i)->edad);
        }
    }
}
