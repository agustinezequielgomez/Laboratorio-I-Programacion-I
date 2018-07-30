#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nombre[]="MiNombre";
    char *apellido="MiApellido";
    char *puntero;
    puntero= nombre;
    printf("\n%s",nombre);
    printf("\n%s",apellido);
    printf("\n%s",puntero);
    //printf("%s",*puntero);

    int i;
    for(i=0;*(apellido+i)!='\0';i++)
    {
        printf("\n%c",*(apellido+i));
    }
    printf("\n%s",apellido);

    return 0;
}
