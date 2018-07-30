#include <stdio.h>
#include <stdlib.h>
#define TAM 5

int main()
{
    int* pVector;
    int* aux;
    pVector=(int*)malloc(sizeof(int)*TAM);
    int i;
    if(pVector!=NULL)
    {
        for(i=0; i<TAM; i++)
        {
            *(pVector+i)=i+1;
        }
        for(i=0; i<TAM; i++)
        {
            printf("\n%d",*(pVector+i));
        }
        //Agrego espacio
        aux=(int*)realloc(pVector,sizeof(int)*(TAM*2));
        if(aux!=NULL)
        {
            pVector=aux;
            for(i=TAM; i<TAM*2; i++)
            {
                *(pVector+i)=i+1;
            }
            printf("\nLUEGO DEL REALLOC");
            for(i=0; i<TAM*2; i++)
            {
                printf("\n%d",*(pVector+i));
            }
            aux=(int*)realloc(pVector,sizeof(int)*4);
        }
        if(aux!=NULL)
        {
            pVector=aux;
            printf("\nLUEGO DEL REALLOC POR MENOS");
            for(i=0; i<4; i++)
            {
                printf("\n%d",*(pVector+i));
            }
        }
    }
return 0;
}

