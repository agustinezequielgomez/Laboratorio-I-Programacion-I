int getEntero(char*mensaje,char*mensajeError,int maximo,int minimo)
{
    int numeroIngresado;
    do
    {
        printf("%s",mensaje);
        scanf("%d",&numeroIngresado);
        if(numeroIngresado<maximo&&numeroIngresado>minimo)
        {
            break;
        }
        printf("%s",mensajeError);
    }
    while(-1);


}


int pedirNumeroPar()
{
    int resultado=-1;
    int division;
    int numero;
    printf("\nIngresa un numero ");
    scanf("%d",&numero);
    division = numero%2;
    if(division==0)
    {
        resultado=0;
    }
    return resultado;
}

float dividirEnteros(int numeroUno,int numeroDos)
 {
     float resultado=0;
     resultado=(float)numeroUno/numeroDos;
     return resultado;
 }

int sumar(int numeroUno,int numeroDos)
{
    int resultado=0;
    resultado = numeroUno+numeroDos;
    return resultado;
}

saludar(void)
{
printf("Hola mundo\n");
}
