#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

int main()
{
    char nombre[10];
    char apellido[10];
    char nombreYApellido[20];
    printf("Ingresa tu nombre: ");
    gets(nombre);
    nombre[0]=toupper(nombre[0]);
    fflush(stdin);
    printf("Ingresa tu apellido: ");
    gets(apellido);
    apellido[0]=toupper(apellido[0]);
    fflush(stdin);
    nombreYApellido[0]=strcat(nombre,apellido);
    gets(nombreYApellido);
    printf("%s",nombreYApellido);
    fflush(stdin);
    return 0;
}
