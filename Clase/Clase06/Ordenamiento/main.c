#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int vector[5]={5,2,9,6,5};
    char vector[5]={'w','a','v','e','b'}; //ordena segu el nomero de codigo ascii perteneciente a la letra
    char aux;
    int i;
    int j;
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(vector[i]>vector[j]) //criterio de ordenamiento
            {
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
        }
    }

    for(i=0;i<5;i++)
    {
        printf("%c\n",vector[i]);
    }
    return 0;
}





    /*int a=9;
    int b=5;
    int c;
    //swap
    c=a;
    a=b;
    b=c;
    printf("a=%d--b=%d--c=%d",a,b,c);*/
