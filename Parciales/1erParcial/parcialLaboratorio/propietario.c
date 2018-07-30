#include<stdio.h>
#include<string.h>
#include"propietario.h"


void inicializarEstadosPropietario(ePropietario listadoPropietario[],int tamanioPropietario)
{
    int i;
    for(i=0; i<tamanioPropietario; i++)
    {
        listadoPropietario[i].estado=0;
    }
}

int cargarHarcodePropietario(ePropietario listadoPropietario[],int tamanioPropietario)
{
    int id[]= {1,2,3,4};
    char nombre[][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[][20]= {"mitre","urquiza","belgrano","alsina"};
    int edad[]={18,35,15,29};
    int i;
    for(i=0; i<4; i++)
    {
        strcpy(listadoPropietario[i].nombre,nombre[i]);
        listadoPropietario[i].Id=id[i];
        strcpy(listadoPropietario[i].tarjeta,tarjeta[i]);
        strcpy(listadoPropietario[i].direccion,direccion[i]);
        listadoPropietario[i].edad=edad[i];
        listadoPropietario[i].estado=1;
    }
    return 1;
}

char getString(char mensaje[], char caracter[])
{

    printf("%s",mensaje);
    gets(caracter);
    fflush(stdin);
    return caracter;
}

int getInt(char mensaje[],int A)
{

    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    A=validarStringEntero(auxstring);
    return A;
}

float getFloat(char mensaje[],float numeroIngresado)
{
    char auxstring[100];
    printf("%s",mensaje);
    scanf("%f",&numeroIngresado);
    fflush(stdin);
    return numeroIngresado;
}

char getChar(char mensaje[],char caracter)
{
    fflush(stdin);
    printf("%s",mensaje);
    scanf("%c",&caracter);
    return caracter;
}

void stringToUpper(char caracter[])
{
    int i;
    int largo;
    caracter[0]=toupper(caracter[0]);
    largo=strlen(caracter);
    for(i=0;i<largo;i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }
    return caracter;
}

int validarStringEntero(char datoAValidar[])
{
    int A;
    int validar;
    validar=strlen(datoAValidar);
    int i;
    for(i=0;i<validar;)
    {
        if(isdigit(datoAValidar[i])==0||datoAValidar[i]==' ')
        {
            do
            {
                printf("\nIngresa un numero valido ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isdigit(datoAValidar[i])==0||datoAValidar[i]==' ');
        }
        else
        {
            i=i+1;
        }
    }
    A=atoi(datoAValidar);
    return A;
}

char validarStringCadena(char datoAValidar[])
{
    int validar;
    validar=strlen(datoAValidar);
    while(validar==0)
    {
        printf("\nLa palabra ingresada no es valida. Ingresela nuevamente ");
        gets(datoAValidar);
        fflush(stdin);
        validar=strlen(datoAValidar);
    }
    int i;
    for(i=0;i<validar;)
    {
        if(isalpha(datoAValidar[i])==0&&datoAValidar[i]!=' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isalpha(datoAValidar[i])==0);
        }
        else if(datoAValidar[0]== ' ')
        {
            do
            {
                printf("\nIngresa una palabra valida ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(datoAValidar[0]==' ');
        }
        else
        {
            i=i+1;
        }

    }
    return datoAValidar;
}

char validarStringCaracter(char datoAValidar)
{
        if(isalpha(datoAValidar)==0||datoAValidar==' ')
        {
            do
            {
                printf("\nIngresa un caracter valido ");
                scanf("%c",&datoAValidar);
                fflush(stdin);
            }
            while(isalpha(datoAValidar)==0||datoAValidar==' ');
        }
        return datoAValidar;
}

float validarStringFloat(char datoAValidar[])
{
    float numero;
    int validar;
    validar=strlen(datoAValidar);
    int i;
    for(i=0;i<validar;)
    {
        if(isdigit(datoAValidar[i])==0)
        {
            do
            {
                printf("\nIngresa un numero valido ");
                gets(datoAValidar);
                validar=strlen(datoAValidar);
                fflush(stdin);
            }
            while(isdigit(datoAValidar[i])==0);
        }
        else
        {
            i=i+1;
        }
    }
    numero=atof(datoAValidar);
    return numero;
}

char deseaContinuar(char mensaje[])
{
    char seguir;
    do
    {
        seguir=getChar(mensaje,seguir);
        seguir=tolower(seguir);
        fflush(stdin);
    }
    while(seguir!='s'&&seguir!='n');
    return seguir;
}

int altaPropietario(ePropietario listadoPropietario[],int tamanioPropietario,int indice)
{
    if(indice!=-1)
    {
        getString("Ingresa tu nombre: ",listadoPropietario[indice].nombre);
        validarStringCadena(listadoPropietario[indice].nombre);
        stringToUpper(listadoPropietario[indice].nombre);
        listadoPropietario[indice].Id=idAutoIncrementalPropietario(listadoPropietario,tamanioPropietario);
        getString("Ingresa tu direccion: ",listadoPropietario[indice].direccion);
        stringToUpper(listadoPropietario[indice].direccion);
        getString("Ingresa tu tarjeta de credito (Debe seguir el formato 123-456 incluyendo el guion): ",listadoPropietario[indice].tarjeta);
        validarTarjetaDeCredito(listadoPropietario[indice].tarjeta);
        listadoPropietario[indice].edad=getInt("Ingresa tu edad: ",listadoPropietario[indice].edad);
        listadoPropietario[indice].estado=1;
        return 1;
    }
    else
    {
        printf("\nNo hay lugares libres");
    }
}

int buscarLibrePropietario(ePropietario listadoPropietario[],int tamanioPropietario)
{
    int indice;
    int i;
    for(i=0; i<tamanioPropietario; i++)
    {
        if(listadoPropietario[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int idAutoIncrementalPropietario(ePropietario listadoPropietario[],int tamanioPropietario)
{
    int contador=0;
    int i;
    for(i=0;i<tamanioPropietario;i++)
    {
        if(listadoPropietario[i].estado==1||listadoPropietario[i].estado==2)
        {
            contador=contador+1;
        }
    }
    return contador+1;
}

void mostrarUnoPropietario(ePropietario listadoPropietario[],int tamanio,int i)
{
    printf("%d\t%s\t  %s\t\t%s\t%d\n",listadoPropietario[i].Id,listadoPropietario[i].nombre,listadoPropietario[i].tarjeta,listadoPropietario[i].direccion,listadoPropietario[i].edad);
}

void mostrarListaPropietario(ePropietario listadoPropietario[],int tamanio,int flag)
{
    if(flag==1)
    {
        printf("ID\tNombre\t\t\tTarjeta de credito\tDireccion\tEdad\n");
        int i;
        int largo;
        for(i=0; i<tamanio; i++)
        {
            if(listadoPropietario[i].estado==1)
            {
                printf("%d\t%s",listadoPropietario[i].Id,listadoPropietario[i].nombre);
                largo=strlen(listadoPropietario[i].nombre);
                if(largo<16)
                {
                    printf("\t");
                }
                printf("\t\t%s\t\t\t%s\t%d\n",listadoPropietario[i].tarjeta,listadoPropietario[i].direccion,listadoPropietario[i].edad);
            }

        }
    }
    else
    {
        printf("\nNo es posible mostrar propietarios porque no hay ninguno ingresado\n");
    }

}

void modificarPropietario(ePropietario listadoPropietario[],int tamanio,int flag)
{
    if(flag==1)
    {
        fflush(stdin);
        int Id;
        int indice;
        char caracter;
        char auxiliar[20];
        mostrarListaPropietario(listadoPropietario,tamanio,flag);
        Id=getInt("\nIngresa el Id del usuario que queres modificar ",Id);
        indice=buscarPorIdPropietario(listadoPropietario,tamanio,Id);
        modificarStringPropietario(listadoPropietario,indice,auxiliar);
        caracter=deseaContinuar("Desea realizar esta modificacion? (S/N) ");
        if(caracter=='s')
        {
            strcpy(listadoPropietario[indice].tarjeta,auxiliar);
            printf("\nTarjeta modificada ");
        }
        else
        {
            printf("Modificacion no realizada ");
        }
    }
    else
    {
        printf("\nNo es posible modificar propietarios porque no hay ninguno ingresado\n");
    }

}


int buscarPorIdPropietario(ePropietario listadoPropietario[],int tamanio,int id)
{
    int indice=-1;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listadoPropietario[i].estado==1)
        {
            if(listadoPropietario[i].Id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

char modificarStringPropietario(ePropietario listadoPropietario[],int indice,char caracter[])
{
    if(indice!=-1)
    {
        getString("\nIngresa la nueva tarjeta de credito (Debe seguir el formato 123-456 incluyendo guion): ",caracter);
        validarTarjetaDeCredito(caracter);
    }
    else
    {
        printf("\nId no encontrado");
    }
}

void validarTarjetaDeCredito(char tarjeta[])
{
    int largo;
    largo=strlen(tarjeta);
    int i;
    for(i=0;i<7;i++)
    {
        while(largo!=7)
        {
            getString("\nTarjeta ingrsada invalida. Debe seguir el formato 123-456 (Incluyendo guion). Ingresela nuevamente ",tarjeta);
            largo=strlen(tarjeta);
        }
        if(i<3)
        {
            if(tarjeta[i]<'0'||tarjeta[i]>'9'||tarjeta[i]==' '||tarjeta[i]=='\0')
            {
                getString("\nTarjeta ingrsada invalida. Debe seguir el formato 123-456 (Incluyendo guion). Ingresela nuevamente ",tarjeta);
                largo=strlen(tarjeta);
                i=0;
            }
        }
        else if(i==3)
        {
            if(tarjeta[3]!='-')
            {
                getString("\nTarjeta ingrsada invalida. Debe seguir el formato 123-456 (Incluyendo guion). Ingresela nuevamente ",tarjeta);
                largo=strlen(tarjeta);
                i=0;
            }
        }
        else if(i>3)
        {
            if(tarjeta[i]<'0'||tarjeta[i]>'9'||tarjeta[i]==' '||tarjeta[i]=='\0')
            {
                getString("\nTarjeta ingrsada invalida. Debe seguir el formato 123-456 (Incluyendo guion). Ingresela nuevamente ",tarjeta);
                largo=strlen(tarjeta);
                i=0;
            }
        }
    }
}


char stringMayusculas(char cadena[])
{
    int largo;
    largo=strlen(cadena);
    int i;
    for(i=0;i<largo;i++)
    {
        cadena[i]=toupper(cadena[i]);
    }
    return cadena;
}

void mostrarPropietarioPorNombre(ePropietario listadoPropietario[],int tamPropietario)
{
    int opcion;
    opcion=getInt("\n1-Ascendente\n2-Descendente\nComo desea ordenar los propietarios? ",opcion);
    ordenarPropietarios(listadoPropietario,tamPropietario,opcion);
}

void ordenarPropietarios(ePropietario listadoPropietario[],int tamPropietario,int opcion)
{
    ePropietario aux;
    int i;
    int j;
    if(opcion==1)
    {
        for(i=0; i<tamPropietario-1; i++)
        {
            for(j=i+1; j<tamPropietario; j++)
            {
                if(strcmp(listadoPropietario[i].nombre,listadoPropietario[j].nombre)>0)
                {
                    aux=listadoPropietario[i];
                    listadoPropietario[i]=listadoPropietario[j];
                    listadoPropietario[j]=aux;
                }
            }
        }
        mostrarListaPropietario(listadoPropietario,tamPropietario,1);
    }
    else if(opcion==2)
    {
        for(i=0; i<tamPropietario-1; i++)
        {
            for(j=i+1; j<tamPropietario; j++)
            {
                if(strcmp(listadoPropietario[i].nombre,listadoPropietario[j].nombre)<0)
                {
                    aux=listadoPropietario[i];
                    listadoPropietario[i]=listadoPropietario[j];
                    listadoPropietario[j]=aux;
                }
            }
        }
        mostrarListaPropietario(listadoPropietario,tamPropietario,1);
    }
    else
    {
        printf("\nOpcion no encontrada\n");
    }
}

void mostrarPropietariosSuperanEdad(ePropietario listadoPropietario[],int tamanioPropietario)
{
    int contador=0;
    int edad;
    edad=getInt("Ingresa la edad para listar los propietarios que la superen ",edad);
    printf("\nID\tNombre\t  Tarjeta\t\tDireccion\tEdad\n");
    int i;
    for(i=0;i<tamanioPropietario;i++)
    {
        if(listadoPropietario[i].edad>edad&&listadoPropietario[i].estado==1)
        {
            mostrarUnoPropietario(listadoPropietario,tamanioPropietario,i);
            contador=contador+1;
        }
    }
    if(contador==0)
    {
        system("cls");
        printf("\nNo hay usuarios que superen la edad ingresada ");
    }
}
