#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int a;
    char b;
}dato;

int main()
{
    int i;
    dato l[2]={{1,'a'},{1,'b'}};
    dato* pLista;
    pLista=l;
    for(i=0;i<2;i++)
    {
        printf("%d--%c\n",(*(pLista+i)).a,(*(pLista+i)).b); //Acceder a campo de estructura por puntero (manera enquilombada)
        printf("%d--%c\n",(pLista+i)->a,(pLista+i)->b); //Acceder a campo de estructura por puntero (manera enquilombada)
    }

    /*dato d;
    d.a=5;
    d.b='<';

    dato* pDato;
    pDato=&d;
    printf("%d--%c\n",pDato->a,pDato->b);


    printf("TAM: %d\n",sizeof(dato));
    printf("\n%d--%c",d.a,d.b);*/
    return 0;
}
