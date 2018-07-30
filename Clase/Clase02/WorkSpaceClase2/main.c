#include <stdio.h>
#include <stdlib.h>

/*Se ingresan numeros (ser distintos de cero), no se saben cuantos.
se pide mostrar:
    * Cantidad de pares e impares.
    * Porcentaje de numeros positivos y negativos.
    * Maximo y minimo.
    * Maximo numero par.
    * Cantidad de numeros comprendidos entre 125 y 236.*/

int main()
{
    int numero;
    char respuesta='s';
    int cantidadPares=0;
    int cantidadImpares=0;
    int contadorNumeros=0;
    int contadorPositivos=0;
    int contadorNegativos=0;
    float porcentajePositivos;
    float porcentajeNegativos;
    int max;
    int min;
    int bandera=0;
    int maxNumeroPar;
    int numeroComprendido=0;
    while(respuesta !='n'){
        printf("\nIngresa un numero distinto de cero\t");
        scanf("%d",&numero);
            while(numero == 0){
                printf("Ingresa un numero valido\t");
                scanf("%d",&numero);
            }
        contadorNumeros=++contadorNumeros;
        if(numero%2==0){
                if(cantidadPares==0||numero>maxNumeroPar){
                    maxNumeroPar=numero;
                }
            cantidadPares=++cantidadPares;
        }else{
            cantidadImpares=++cantidadImpares;
        }

        if(numero>0){
            contadorPositivos=++contadorPositivos;
        }else{
            contadorNegativos=++contadorNegativos;
        }

        if(bandera==0||numero>max){
            max=numero;
        }if(bandera==0||numero<min){
            min=numero;
            bandera=1;
        }

        /*if(bandera==0){
            bandera=1;
            max=numero;
            min=numero;
        }else if(numero>max){
            max=numero;
        }else if(numero<min){
            min=numero;
        }
        */
        /*
        * Quedo adentro de numero par.
        if(numero==max&&numero%2==0){
            maxNumeroPar=numero;
        }*/

        if(numero>124&&numero<237){
            numeroComprendido=++numeroComprendido;
        }

        printf("¿Queres seguir ingresando numeros? (Responder con s/n)");
        respuesta=getche();
        while(respuesta!='s'&&respuesta!='n'){
            printf("\nIngresa una respuesta valida");
            respuesta=getche();
        }
    }
    porcentajePositivos=(float)(contadorPositivos*100)/contadorNumeros;
    porcentajeNegativos=100-porcentajePositivos;
    printf("\nLa cantidad de numeros pares es: %d\n",cantidadPares);
    printf("La cantidad de numeros impares es: %d\n",cantidadImpares);
    printf("El porcentaje de numeros positivos es: %.2f%%\n",porcentajePositivos);
    printf("El porcentaje de numeros negativos es: %.2f%%\n",porcentajeNegativos);
    printf("El numero maximo es: %d\n",max);
    printf("El numero minimo es: %d\n",min);
    printf("El numero maximo par es: %d\n",maxNumeroPar);
    printf("La cantidad de numeros comprendidos entre 125 y 236 es de: %d\n",numeroComprendido);

    return 0;
}
