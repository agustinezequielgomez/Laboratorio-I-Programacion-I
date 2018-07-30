#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct
{
    int a;
    char b[50];
}eDato;

int eDato_set_a(eDato*,int);
int eDato_set_b(eDato*,char*);
int eDato_get_a(eDato*);
char* eDato_get_b(eDato*);

int main()
{
    eDato dato;
    eDato* d;

    d=&dato;

    eDato_set_a(d,1800);
    eDato_set_b(d,"Alfonso");
    printf("%d--%s",eDato_get_a(d),eDato_get_b(d));
    return 0;
}


int eDato_set_a(eDato* dato,int valor)
{
    int ret=0;
    if(dato!=NULL&&valor>1500)
    {
        dato->a=valor;
        ret=1;
    }
    return ret;
}


int eDato_set_b(eDato* dato,char* valor)
{
    int ret=0;
    if(dato!=NULL&&valor!=NULL)
    {
        strcpy(dato->b,valor);
        ret=1;
    }

}

int eDato_get_a(eDato* dato)
{
    int valor=-1;
    if(dato!=NULL)
    {
        valor=dato->a;
    }
    return valor;
}

char* eDato_get_b(eDato* dato)
{
    char* valor=NULL;
    if(dato!=NULL)
    {
        valor=dato->b;
    }
    return valor;
}
