#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include"lib.h"

void inicializarEstadosUsuario(eUsuario listadoUsuario[],int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        listadoUsuario[i].estado=0;
    }
}

void cargarHarcodeUsuario(eUsuario listadoUsuario[],int tamanio)
{
    char nombre[20][50]= {"Alberto","Jose","Maria","Pepe","Julian","Camila","Victoria","Selene","Juan Cruz","Nicolas","Franco","Ciro","Ezequiel","Emanuel","Alejandro","Matias","Carlos","Natan","David","Francisco"};
    int dni[20]= {42589785,23456978,10457863,32014756,42147544,52333457,24965784,30145965,29771276,16279490,14575887,10476685,16686238,41371597,10385485,41754221,19373276,4385555,10173055,3073077};
    int edad[20]= {15,25,12,100,97,3,46,92,24,96,43,83,25,89,41,79,97,37,21,28};
    char direccion[20][50]= {"Beron de Astrada 4589","Montiel 154","Ana Diaz 892","Guamini 6600","Fructuoso Rivera 9785","Corrales 4788","Tabare 1024","Avenida Roca 6658","Timoteo Gordillo 9785","Cañada de Gomez 7845","Cosquin 1290","Itaqui 785","Avenida Cruz 2300","Chilavert 1900","Jose Leon Suarez 9800","Ferre 800","Soldado de la Frontera 3000","Madariaga 1200","Unanue 3300","Avenida Mitre 750"};
    int telefono[20]= {39665247,46057895,22367458,66654897,10456964,46222596,78453256,34521689,11169878,45567785,37894563,22224458,66697852,22364415,77829953,82930100,05126472,55962232,47859965,88956621};
    char apellido[20][50]= {"Gomez","Godinez","Fernandez","Vargas","Bardini","Galli","Rios Taurasi","Vitale","Pacheco","Jimenez","Quispe","Lezano","Velazco","Gonzalez","Sinay","Gasbarro","Estarque","Acuña","Vecchio","Brienza"};
    int i;
    for(i=0; i<20; i++)
    {
        strcpy(listadoUsuario[i].nombre,nombre[i]);
        listadoUsuario[i].Id=edad[i];
        listadoUsuario[i].estado=1;
    }
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
    printf("%s",mensaje);
    scanf("%d",&A);
    fflush(stdin);
    return A;
}

float getFloat(char mensaje[],float numeroIngresado)
{
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

void altaUsuario(eUsuario listadoUsuario[],int tamanio,int indice)
{
    if(indice!=-1)
    {
        getString("Ingresa tu nombre de usuario ",listadoUsuario[indice].nombre);
        stringToUpper(listadoUsuario[indice].nombre);
        getString("Ingresa tu contraseña ",listadoUsuario[indice].password);
        listadoUsuario[indice].Id=idAutoIncrementalUsuario(listadoUsuario,tamanio);
        listadoUsuario[indice].estado=1;
    }
    else
    {
        printf("\nNo hay lugares libres");
    }
}

int buscarLibreUsuario(eUsuario listadoUsuario[],int tamanio)
{
    int indice;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listadoUsuario[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int idAutoIncrementalUsuario(eUsuario listadoUsuario[],int tamanio)
{
    int contador=0;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(listadoUsuario[i].estado==1||listadoUsuario[i].estado==2)
        {
            contador=contador+1;
        }
    }
    return contador;
}

void mostrarUnoUsuario(eUsuario listadoUsuario[],int tamanio,int i)
{
    printf("\n\nNombre: %s\nPassword %s\nId: %d\nCalificacion: %f",listadoUsuario[i].nombre,listadoUsuario[i].password,listadoUsuario[i].Id,listadoUsuario[i].calificacion);
}

void mostrarListaUsuario(eUsuario listadoUsuario[],int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listadoUsuario[i].estado==1)
        {
            mostrarUnoUsuario(listadoUsuario,tamanio,i);
        }

    }
}

void modificarUsuario(eUsuario listadoUsuario[],int tamanio)
{
    fflush(stdin);
    int Id;
    int indice;
    int opcion;
    opcion=getInt("\nQue queres modificar?\n1- Nombre\n2- Contraseña\n",opcion);
    fflush(stdin);
    switch(opcion)
    {
    case 1:
        mostrarListaUsuario(listadoUsuario,tamanio);
        Id=getInt("\nIngresa el Id del nombre que queres modificar ",Id);
        indice=buscarPorIdUsuario(listadoUsuario,tamanio,Id);
        modificarStringUsuario(listadoUsuario,indice,listadoUsuario[indice].nombre);
        break;
    case 2:
        mostrarListaUsuario(listadoUsuario,tamanio);
        Id=getInt("\nIngresa el Id de la contraseña que queres modificar ",Id);
        indice=buscarPorIdUsuario(listadoUsuario,tamanio,Id);
        modificarStringUsuario(listadoUsuario,indice,listadoUsuario[indice].password);
        break;
    }
}

int buscarPorIdUsuario(eUsuario listadoUsuario[],int tamanio,int id)
{
    int indice=-1;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listadoUsuario[i].estado==1)
        {
            if(listadoUsuario[i].Id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

char modificarStringUsuario(eUsuario listadoUsuario[],int indice,char caracter[])
{
    if(indice!=-1)
    {
        getString("\nIngresa el nuevo dato: ",caracter);
        stringToUpper(caracter);
    }
    else
    {
        printf("\nId no encontrado");
    }
}

int modificarEnteroUsuario(eUsuario listadoUsuario[],int indice,int dato)
{
    if(indice!=-1)
    {
        getInt("\nIngresa el nuevo dato: ",dato);
    }
    else
    {
        printf("\nId no encontrado");
    }
}

float modificarFlotanteUsuario(eUsuario listadoUsuario[],int indice,float dato)
{
    if(indice!=-1)
    {
        getFloat("\nIngresa el nuevo dato: ",dato);
    }
    else
    {
        printf("\nId no encontrado");
    }
}



void ordenarSegunCriterio(eUsuario listadoUsuario[],int tamanio)
{
    eUsuario aux;
    int i;
    int j;
    for(i=0; i<tamanio-1; i++)
    {
        for(j=i+1; j<tamanio; j++)
        {
            if(listadoUsuario[i].estado==1&&listadoUsuario[j].estado==1)
            {
                if(strcmp(listadoUsuario[i].nombre,listadoUsuario[j].nombre)>0)
                {
                    aux=listadoUsuario[i];
                    listadoUsuario[i]=listadoUsuario[j];
                    listadoUsuario[j]=aux;
                }
            }
        }
    }
    mostrarListaUsuario(listadoUsuario,tamanio);
}

void mostrarBorrados(eUsuario listadoUsuario[],int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(listadoUsuario[i].estado==2)
        {
            mostrarUnoUsuario(listadoUsuario,tamanio,i);
        }
    }
}


