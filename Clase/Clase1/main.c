#include <stdio.h>
#include <stdlib.h>

/**
*
*@param
*@return
*/
int main()
{
    char nombre;
    float sueldo;
    int porcentaje;
    float sueldoFinal;
    float operacion;

    printf("Ingrese su nombre: \n");
    scanf("%c",&nombre);
    printf("Ingrese su sueldo: \n");
    scanf("%f",&sueldo);
    printf("Ingrese el porcentaje de aumento que recibio \n");
    scanf("%d",&porcentaje);

    operacion=(sueldo*porcentaje)/100;
    sueldoFinal=operacion+sueldo;

    printf("Su nombre es %c. Su sueldo es de %.f. Su aumento es del: %d %%. Su sueldo final es de %.f", nombre, sueldo, porcentaje, sueldoFinal);
    return 0;
}
