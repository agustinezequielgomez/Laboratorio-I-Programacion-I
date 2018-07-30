#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANIO 5

/*OBJETIVO PRINCIPAL
-Ordenamiento de vectores paralelos, sin importar si los datos son hardcodeados.
1- Hacer el alta.
2- Hacer la baja (Poner todo en 0),
3- Modificar todo menos el legajo.
*/

void mostrarAlumno(char[][50],int[],int[],float[],int[],int);
void cargarAlumno(char[][50],int[],int[],float[],int[],int);
int buscarLugarVacio(int[],int);
float sacarPromedio(int, int);
void ordenarArray(int indice, int legajo[],char nombre[][50],int notasUno[],int notasDos[],float promedios[]);
int main()
{
    char nombre[TAMANIO][50]={"Juan","Maria","Alfredo","Jose","Lili"};
    int notasUno[TAMANIO]={4, 10, 2, 7, 2};
    int notasDos[TAMANIO]={4, 8, 7, 8, 3};
    float promedios[TAMANIO]={4, 9.5, 4.5, 8.5, 2.5};
    int legajo[TAMANIO]={111, 222, 333, 444, 555};
    cargarAlumno(nombre,notasUno,notasDos,promedios,legajo,TAMANIO);
    ordenarArray(TAMANIO,legajo,nombre,notasUno,notasDos,promedios);
    mostrarAlumno(nombre,notasUno,notasDos,promedios,legajo,TAMANIO);
    return 0;
}


void mostrarAlumno(char nombre[][50],int primeraNota[],int segundaNota[],float promedios[],int legajo[],int largo)
{
    int i;
    for(i=0;i<largo;i++)
    {
        printf("\nL: %d, N: %s, N1: %d, N2: %d, P: %.2f",legajo[i],nombre[i],primeraNota[i],segundaNota[i],promedios[i]);
    }
}

void cargarAlumno(char nombre[][50],int primeraNota[],int segundaNota[],float promedios[],int legajo[],int largo)
{
    int indice;
    if(indice>-1){
        indice=buscarLugarVacio(legajo,largo);
        legajo[indice]=666;
    }
    else{

    }

}

int buscarLugarVacio(int legajo[],int largo)
{
    int i;
    int indiceRetornado=-1;
    for(i=0;i<largo;i++)
    {
        if(legajo[i]==0)
        {
            indiceRetornado=i;
            break;
        }
    }
    return indiceRetornado; //Si retorna -1 no hay mas lugar para cargar.
}

void ordenarArray(int indice, int legajo[],char nombre[][50],int notasUno[],int notasDos[],float promedios[])
{
    int i;
    int j;
    int aux;
    char auxiliar[30];

    for(i=0;i<j;i++)
    {
        for(j=i+1;j<indice;j++)
        {
            if(legajo[i]<legajo[j])
            {
                aux=legajo[i];
                legajo[i]=legajo[j];
                legajo[j]=aux;

                aux=notasUno[i];
                notasUno[i]=notasUno[j];
                notasUno[j]=aux;

                aux=notasDos[i];
                notasDos[i]=notasDos[j];
                notasDos[j]=aux;

                strcpy(auxiliar,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],auxiliar);


            }
        }
    }
}

char ordenarString(int indice,int i,int j,char nombre[][50])
{
    char aux;


                aux=nombre[i][50];
                nombre[i][50]=nombre[j][50];
                nombre[j][50]=aux;


    return nombre;
}
