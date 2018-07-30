#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palabra1[15];
    char palabra2[15];
    char buffer[1024];
    int cant;
    int comp;
    char alsd[10];
    printf("Ingrese una palabra: ");
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer)>14)
    {
        printf("Ingrese una palabra: ");
        fflush(stdin);
        gets(buffer);
    }

    strcpy(palabra1,"alfa");
    comp=strcmp(palabra1,buffer);
    printf("%d",comp);
    alsd[0]=strcat(buffer,palabra2);
    printf("alsd %s",alsd);
    /*strcpy("destino","origen");
    cant=strlen(palabra1);
    printf("%d",cant);
    printf("%s",palabra2);*/
    return 0;
}
