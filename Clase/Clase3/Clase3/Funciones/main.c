#include <stdio.h>
#include <stdlib.h>

int main()
{
    int edad;
    edad=getEntero("Ingresa tu edad ","La edad ingresada no es valida\n",199,1);
    printf("%d",edad);

    int sePudo;
    sePudo=pedirNumeroPar();

    float numeroDividir;
    numeroDividir=dividirEnteros(10,3);
    printf("%f\n",numeroDividir);

    int numero;
    numero=sumar(3,3);
    printf("%d\n",numero);


    saludar();
    return 0;
}
