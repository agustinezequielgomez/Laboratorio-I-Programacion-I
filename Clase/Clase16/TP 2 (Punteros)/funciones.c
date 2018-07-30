#include<stdio.h>
#include"funciones.h"
#include <string.h>

int obtenerEspacioLibre(EPersona* lista)
{
    int indice=-1;
    int* punteroIndice=NULL;
    punteroIndice=&indice;
    int i;
    for(i=0; i<20; i++)
    {
        if((lista+i)->estado==0)
        {
            *punteroIndice=i;
            break;
        }
    }
    return *punteroIndice;
}

int buscarPorDni(EPersona* lista, int dni)
{
    int indice=-1;
    int* punteroIndice=NULL;
    punteroIndice=&indice;
    int i;
    for(i=0; i<20; i++)
    {
        if(dni==(lista+i)->dni)
        {
            *punteroIndice=i;
            break;
        }
    }
    return punteroIndice;
}

void inicializarEstados(EPersona* lista)
{
    int i;
    for(i=0; i<20; i++)
    {
        (lista+i)->estado=0;
    }
}

void inicializarHarcode(EPersona* lista)
{
    char nombre[20][50]= {"Alberto","Jose","Maria","Pepe","Julian","Camila","Victoria","Selene","Juan Cruz","Nicolas","Franco","Ciro","Ezequiel","Emanuel","Alejandro","Matias","Carlos","Natan","David","Francisco"};
    int dni[20]= {42589785,23456978,10457863,32014756,42147544,52333457,24965784,30145965,29771276,16279490,14575887,10476685,16686238,41371597,10385485,41754221,19373276,4385555,10173055,3073077};
    int edad[20]= {15,25,12,100,97,3,46,92,24,96,43,83,25,89,41,79,97,37,21,28};
    int i;
    for(i=0; i<20; i++)
    {
        strcpy((lista+i)->nombre,nombre[i]);
        (lista+i)->edad=edad[i];
        (lista+i)->dni=dni[i];
        (lista+i)->estado=1;
    }
}

char getString(char mensaje[], char* caracter)
{

    printf("%s",mensaje);
    scanf("%s",caracter);
    fflush(stdin);
 //   *caracter=validarStringCadena(&caracter);
    return *caracter;
}

int getInt(char mensaje[],int *numero)
{
    fflush(stdin);
    printf("%s",mensaje);
    scanf("%d",numero);
    //*numero=validarStringEntero(&punteroString);
    return numero;
}

void stringToUpper(char* caracter)
{
    int i;
    int largo;
    int* punteroLargo=NULL;
    punteroLargo=&largo;
    *caracter=toupper(&caracter[0]);
    *punteroLargo=strlen(*caracter);
    for(i=0; i<*punteroLargo; i++)
    {
        if((*(caracter+i))==' ')
        {
            i=i+1;
            *caracter=toupper((caracter+i));
        }
    }
}

int validarStringEntero(char* datoAValidar[])
{
    int A;
    int validar;
    int* punteroA=NULL;
    int* punteroValidar=NULL;
    punteroA=&A;
    punteroValidar=&validar;
    *punteroValidar=strlen(*datoAValidar);
    int i;
    for(i=0; i<*punteroValidar;)
    {
        if(isdigit(*(datoAValidar+i))!=0||*(datoAValidar+i)==' ')
        {
            do
            {
                printf("\nIngresa un numero valido ");
                gets(datoAValidar);
                *punteroValidar=strlen(*datoAValidar);
                fflush(stdin);
            }
            while(isdigit(*(datoAValidar+i))==0||*(datoAValidar+i)==' ');
        }
        else
        {
            i=i+1;
        }
    }
    punteroA=atoi(*datoAValidar);
    return punteroA;
}

char validarStringCadena(char* datoAValidar[])
{
    int validar;
    int* punteroValidar=NULL;
    punteroValidar=&validar;
    *punteroValidar=strlen(*datoAValidar);
    int i;
    for(i=0; i<*punteroValidar;)
    {
        if(isalpha(*(datoAValidar+i))==0&&*(datoAValidar+i)!=' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(&datoAValidar);
                *punteroValidar=strlen(*datoAValidar);
                fflush(stdin);
            }
            while(isalpha(*(datoAValidar+i))==0&&*(datoAValidar+i)!=' ');
        }
        else if(*(datoAValidar[0])== ' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(*datoAValidar);
                *punteroValidar=strlen(*datoAValidar);
                fflush(stdin);
            }
            while(*(datoAValidar[0])==' ');
        }
        else
        {
            i=i+1;
        }

    }
    return datoAValidar;
}

void agregarPersona(EPersona* lista[])
{
    int indice;
    int* punteroIndice=NULL;
    punteroIndice=&indice;
    *punteroIndice=obtenerEspacioLibre(&lista);
    if(*(punteroIndice)!=-1)
    {
        getString("Ingrese el nombre de la persona ",&(lista[*punteroIndice])->nombre);
        //stringToUpper(&(lista[*punteroIndice])->nombre);
        getInt("Ingresa la edad de la persona ",&(lista[*punteroIndice])->edad);
        getInt("Ingresa el DNI de la persona ",&(lista[*punteroIndice])->dni);
        lista[*punteroIndice]->estado=1;
    }
    else
    {
        printf("\nNo hay mas lugares libres");
    }
}

void borrarPersona(EPersona* lista[],int* flag)
{
    int dni;
    int indice;
    int* punteroIndice=NULL;
    punteroIndice=&indice;
    int i;
    if(*(flag)==1)
    {
        mostrarLista(&lista);
        getInt("Que persona queres borrar? (Ingresar DNI) ",&dni);
        fflush(stdin);
        *punteroIndice=buscarPorDni(&lista,&dni);
        if(*(punteroIndice)!=-1)
        {
            lista[*punteroIndice]->estado=0;
            lista[*punteroIndice]->dni=0;
            strcpy(&lista[*punteroIndice]->nombre,"");
            lista[*punteroIndice]->edad=0;
        }
        else
        {
            printf("\nDNI no encontrado");
        }
    }
    else
    {
        printf("\nPara borrar un usuario es necesario que se haya ingresado alguno en el sistema ");
    }


}

void mostrarLista(EPersona* lista[])
{
    int i;
    for(i=0;i<20;i++)
    {
        if(lista[i]->estado==1)
        {
            printf("\n\nNombre: %s\nEdad: %d\nDNI: %d",lista[i]->nombre,lista[i]->edad,lista[i]->dni);
        }
    }
}


void ordenarListaPorNombre(EPersona* lista[],int flag)
{
    EPersona* auxiliar;
    int i;
    int j;
    if(flag==1)
    {
        for(i=0; i<19; i++)
        {
            for(j=i+1; j<20; j++)
            {
                if(lista[i]->estado==1&&strcmp(lista[i]->nombre,lista[j]->nombre)>0)
                {
                    auxiliar=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxiliar;
                }
            }
        }
        mostrarLista(lista);
    }
    else
    {
        printf("\nPara realizar el ordenamiento es necesario que se haya ingresado algun usuario en el sistema ");
    }
}

void imprimirGrafico(EPersona lista[])
{
    int flag;
    int flagMenor18=0;
    int flagMas18=0;
    int flagMas35=0;
    int mayor;
    int i;
    for(i=0; i<20; i++)
    {
        if(lista[i].estado==1)
        {


            if(lista[i].edad<18)
            {
                flagMenor18=++flagMenor18;
            }
            else if(lista[i].edad>18&&lista[i].edad<=35)
            {
                flagMas18=++flagMas18;
            }
            else if(lista[i].edad>35)
            {
                flagMas35=++flagMas35;
            }
        }
    }
    if(flagMenor18>=flagMas18&&flagMenor18>=flagMas35)
    {
        mayor=flagMas18;
    }
    else if(flagMas18>=flagMenor18&&flagMas18>=flagMas35)
    {
        mayor=flagMas18;
    }
    else
    {
        mayor=flagMas35;
    }
    for(i=mayor; i>0; i--)
    {
        flag=0;
        printf("\n");
        if(i<=flagMenor18)
        {
            printf("\t*");
            flag=1;
        }
        if(i<=flagMas18)
        {
            if(flag==1)
            {
                printf("\t  *");
                flag=2;
            }
            else if(flag==0)
            {
                printf("\t\t  *");
                flag=2;
            }

        }
        if(i<=flagMas35)
        {
            if(flag==0)
            {
                printf("\t\t\t    *");
            }
            else if(flag==1)
            {
                printf("\t\t    *");
            }
            else if(flag==2)
            {
                printf("\t    *");
            }
        }
    }
    if(flagMas18==0&&flagMenor18==0&&flagMas35==0)
    {
        printf("\nPara realizar el grafico es necesario ingresar algun usuario al sistema");
    }
    else
    {
        printf("\n|------<18------19-35------>35------|");
        printf("\n|       %d         %d         %d       |",flagMenor18,flagMas18,flagMas35);
    }
}
