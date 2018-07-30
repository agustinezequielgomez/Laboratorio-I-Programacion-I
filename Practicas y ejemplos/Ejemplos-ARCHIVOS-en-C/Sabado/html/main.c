#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* f;
    char texto[50]="Los pelos verdes de Agustin";

    f=fopen("miHTML.html","w");
    //OPCION 1 para escribir html
    /*
    fprintf(f,"<html><body><h1>");
    fprintf(f,"%s",texto);
    fprintf(f,"</h1></body></html>");*/
    //OPCION 2 para escribir html
    fprintf(f,"<html><body><h1>%s</h1></body></html>",texto);
    fclose(f);
    return 0;
}
