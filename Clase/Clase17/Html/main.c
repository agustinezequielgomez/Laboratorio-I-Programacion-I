#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    char msj[]="hola a todos";
    f=fopen("mihtml.html","w");

    if(f!=NULL)
    {
        fprintf(f,"<html><head>");
        fprintf(f,msj);
        fprintf(f,"</head></html>");
        fclose(f);
    }
    return 0;
}
