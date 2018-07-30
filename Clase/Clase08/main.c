#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 5

int buscarInt(int[],int,int);

int main()
{
    int vectorInt[T]={1,2,3,4,5};
    char vectorString[T][30]={"Juan","Ana","Maria","Pedro","Luis"};
    float vectorFloat[T]={2.3,2.2,6.9,4.1,2.21};
    int i;
    int j;
    char aux[30];
    int auxiliarInt;
    float auxiliarFloat;
    auxiliarInt=buscarInt(vectorInt,T,3);
    printf("INDICE: %d\n",auxiliarInt);
    for(i=0;i<T-1;i++)
    {
        for(j=i+1;j<T;j++)
        {

            if(strcmp(vectorString[i],vectorString[j])>0)
            {
                strcpy(aux,vectorString[i]);
                strcpy(vectorString[i],vectorString[j]);
                strcpy(vectorString[j],aux);

                auxiliarInt=vectorInt[i];
                vectorInt[i]=vectorInt[j];
                vectorInt[j]=auxiliarInt;

                auxiliarFloat=vectorFloat[i];
                vectorFloat[i]=vectorFloat[j];
                vectorFloat[j]=auxiliarFloat;

            }
        }
    }
    for (i=0;i<T;i++)
    {
        if(vectorInt[i]!=0)
            {
                printf("%d --  %s -- %f\n",vectorInt[i],vectorString[i],vectorFloat[i]);
            }
    }

    return 0;
}

int buscarInt(int enteros[],int tam,int cual)
{
    int indice=-1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(enteros[i]==cual)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
