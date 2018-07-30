#include<stdio.h>
#include<stdlib.h>
#include"eUsuario.h"

int eGen_init(eUsuario listado[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado = 0;
        }
    }
    return retorno;
}

void inicializarHarcode(eUsuario listado[],int tamanio)
{
    char nombre[20][50]= {"Alberto","Jose","Maria","Pepe","Julian","Camila","Victoria","Selene","Juan Cruz","Nicolas","Franco","Ciro","Ezequiel","Emanuel","Alejandro","Matias","Carlos","Natan","David","Francisco"};
    int dni[20]= {42589785,23456978,10457863,32014756,42147544,52333457,24965784,30145965,29771276,16279490,14575887,10476685,16686238,41371597,10385485,41754221,19373276,4385555,10173055,3073077};
    int edad[20]= {15,25,12,100,97,3,46,92,24,96,43,83,25,89,41,79,97,37,21,28};
    char direccion[20][50]= {"Beron de Astrada 4589","Montiel 154","Ana Diaz 892","Guamini 6600","Fructuoso Rivera 9785","Corrales 4788","Tabare 1024","Avenida Roca 6658","Timoteo Gordillo 9785","Cañada de Gomez 7845","Cosquin 1290","Itaqui 785","Avenida Cruz 2300","Chilavert 1900","Jose Leon Suarez 9800","Ferre 800","Soldado de la Frontera 3000","Madariaga 1200","Unanue 3300","Avenida Mitre 750"};
    int telefono[20]={39665247,46057895,22367458,66654897,10456964,46222596,78453256,34521689,11169878,45567785,37894563,22224458,66697852,22364415,77829953,82930100,05126472,55962232,47859965,88956621};
    char apellido[20][50]= {"Gomez","Godinez","Fernandez","Vargas","Bardini","Galli","Rios Taurasi","Vitale","Pacheco","Jimenez","Quispe","Lezano","Velazco","Gonzalez","Sinay","Gasbarro","Estarque","Acuña","Vecchio","Brienza"};
    int i;
    for(i=0; i<tamanio; i++)
    {
        strcpy(listado[i].nombre,nombre[i]);
        listado[i].Id=edad[i];
        listado[i].estado=1;
    }
}

int listado_BuscarLibre(elistado listado[],int tamanio)
{
    int i;
    int indice=-1;
    for(i=0;i<tamanio;i++)
    {
        if(listado[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void altaUsuario(eUsuario listado[],int tamanio,int indice)
{
    if(indice!=-1)
    {
            printf("Ingresa el Id de usuario: ");
            scanf("%d",&listado[indice].Id);
            fflush(stdin);
            printf("Ingresa el nombre del Usuario: ");
            gets(listado[indice].nombre);
            fflush(stdin);
            listado[indice].estado=1;
    }
    else
    {
        printf("\nNo hay mas lugares disponibles");
    }

}

void user_modificar(eUsuario listado[],int tamanio)
{
    int opcion;
    printf("\n\n1- CAMBIAR NOMBRE");
    scanf("%d",&opcion);
    switch(opcion)
    {
    case 1:
        user_modificarCadena(usuario,usuarioLenght);
        break;
    }
}

void user_modificarCadena(eUsuario listado[],int tamanio)
{
    int respuesta;
    mostrarUno(listado,tamanio);
    printf("\nQue nombre queres modificar? (Ingresar ID Usuario) ");
    scanf("%d",&respuesta);
    fflush(stdin);
    for(i=0; i<tamanio; i++)
    {
        if(respuesta==listado[i].idUsuario)
        {
            printf("Ingresa el nuevo dato ");
            gets(listado[i].nombre);
            break;
        }
    }
    fflush(stdin);
}

void mostrarUno(eUsuario listado[],int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        printf("\n\nNombre: %s\nId: %d",listado[i].nombre,listado[i].Id);
    }
}
