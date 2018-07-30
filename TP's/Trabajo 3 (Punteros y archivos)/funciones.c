#include<stdlib.h>
#include<stdio.h>
#include"funciones.h"
#include<ctype.h>
#include<string.h>

void inicializarEstados(EMovie* lista,int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        if((lista+i)!=NULL)
        {
            (lista+i)->estado=0;
        }
    }
}

void getInt(char mensaje[],int* dato,char mensajeError[])
{
    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    validarEntero(auxstring,dato,mensajeError);
}

void getString(char mensaje[],char* dato,char mensajeError[])
{
    char auxstring[500];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    validarString(auxstring,dato,mensajeError);
}

void validarEntero(char auxiliar[],int* dato,char mensaje[])
{
    int validar;
    validar=strlen(auxiliar);
    while(validar==0)
    {
        printf(mensaje);
        gets(auxiliar);
        validar=strlen(auxiliar);
        fflush(stdin);
    }
    int i;
    for(i=0; i<validar;)
    {
        if(isdigit(auxiliar[i])==0||isspace(auxiliar[i])!=0||validar==0)
        {
            do
            {
                printf(mensaje);
                gets(auxiliar);
                validar=strlen(auxiliar);
                fflush(stdin);
            }
            while(isdigit(auxiliar[i])==0||isspace(auxiliar[i])!=0||validar==0);
        }
        else
        {
            i=i+1;
        }
    }
    *(dato)=atoi(auxiliar);
}

void validarString(char auxiliar[],char* dato,char mensaje[])
{
    int validar;
    validar=strlen(auxiliar);
    while(validar==0||isspace(auxiliar[0])!=0)
    {
        printf(mensaje);
        gets(auxiliar);
        fflush(stdin);
        validar=strlen(auxiliar);
    }
    strcpy(dato,auxiliar);
}

void validarRangoEntero(int* dato)
{
    while(*(dato)<0||*(dato)>100)
    {
        getInt("El puntaje ingresado debe ser entre 0 y 100 ",dato,"El puntaje ingresado no es un numero ");
    }
}

void stringToUpper(char caracter[])
{
    int i;
    int largo;
    caracter[0]=toupper(caracter[0]);
    largo=strlen(caracter);
    for(i=0; i<largo; i++)
    {
        if(caracter[i]==' ')
        {
            i=i+1;
            caracter[i]=toupper(caracter[i]);
        }
    }
}

void deseaContinuar(char mensaje[],char* respuesta)
{
    do
    {
        getString(mensaje,respuesta,"El caracter ingresado no es valido. Ingrese el caracter nuevamente ");
        respuesta=tolower(respuesta);
        fflush(stdin);
    }
    while(*(respuesta)!='s'&&*(respuesta)!='n');
}

void buscarLibre(EMovie* lista,int tamanio,int* indice)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        if((lista+i)->estado==0&&(lista+i)!=NULL)
        {
            *(indice)=i;
            break;
        }
    }
}

void IdIncremental(EMovie* lista,int tamanio,int* indice)
{
    *(indice)=0;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if((lista+i)->estado==1||(lista+i)->estado==2)
        {
            *(indice)=*(indice)+1;
        }
    }
    *(indice)=*(indice)+1;
}

void alta(EMovie* lista,int tamanio,int* contador)
{
    int indice=-1;
    buscarLibre(lista,tamanio,&indice);
    if(indice!=-1)
    {
        getString("\nIngresa el titulo de la pelicula ",(lista+indice)->titulo,"El titulo ingresado no es valido. Ingrese el titulo nuevamente ");
        stringToUpper((lista+indice)->titulo);
        getString("\nIngresa el genero de la pelicula ",(lista+indice)->genero,"El genero ingresado no es valido. Ingrese el genero nuevamente ");
        stringToUpper((lista+indice)->genero);
        getInt("\nIngresa la duracion de la pelicula ",&(lista+indice)->duracion,"La duracion ingresada no es un numero. Ingrese el dato nuevamente ");
        getString("\nIngresa la descripcion de la pelicula ",(lista+indice)->descripcion,"La descripcion ingresada no es valida. Ingrese la descripcion nuevamente ");
        getInt("\nIngresa el puntaje de la pelicula (entre 0 y 100) ",&(lista+indice)->puntaje,"El puntaje ingresado no es un numero. Ingrese el dato nuevamente ");
        validarRangoEntero(&(lista+indice)->puntaje);
        getString("\nIngresa el link de la imagen de la portada ",(lista+indice)->linkImagen,"El link ingresado no es un valido. Ingrese el link nuevamente ");
        IdIncremental(lista,tamanio,&(lista+indice)->id);
        (lista+indice)->estado=1;
        printf("\nPelicula guardada\n");
    }
    else
    {
        printf("\nNo hay mas espacio libre\n");
    }
    agregarPelicula(lista,tamanio,contador);
}

void mostrarPelicula(EMovie* lista,int tamanio)
{
    int largo;
    int i;
    printf("\nID\tNombre\t\t\t\t\tGenero\t\t\tDuracion\tPuntaje");
    for(i=0;i<tamanio;i++)
    {
        if((lista+i)->estado==1)
        {
            printf("\n%d\t%s",(lista+i)->id,(lista+i)->titulo);
            largo=strlen((lista+i)->titulo);
            if(largo<7)
            {
                printf("\t\t");
            }
            else if(largo<16)
            {
                printf("\t");
            }
                printf("\t\t\t%s",(lista+i)->genero);
                largo=strlen((lista+i)->genero);
                if(largo<=6)
                {
                    printf("\t\t");
                }
                else if(largo<16)
                {
                    printf("\t");
                }
                printf("\t%d\t\t%d",(lista+i)->duracion,(lista+i)->puntaje);
        }
    }
}

int buscarPelicula(EMovie* lista,int tamanio,int id)
{
    int indice=-1;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if((lista+i)->estado==1)
        {
            if((lista+i)->id==id)
            {
                indice=i;
                break;
                return indice;
            }
        }
    }
    return indice;
}

void borrarPelicula(EMovie* lista,int tamanio,int* contador)
{
    int i;
    int verificar=0;
    for(i=0;i<tamanio;i++)
    {
        if((lista+i)->estado==1)
        {
            verificar=verificar+1;
            break;
        }
    }
    if(verificar!=0)
    {
        int id;
        int indice;
        char respuesta;
        mostrarPelicula(lista,tamanio);
        getInt("\nIngrese el Id de la pelicula a dar de baja ",&id,"El ID ingrsado no es un numero. Ingrese nuevamente el dato ");
        indice=buscarPelicula(lista,tamanio,id);
        if(indice!=-1)
        {
            deseaContinuar("Esta seguro que desea dar de baja esta pelicula? (S/N)",&respuesta);
            if(respuesta=='s')
            {
                (lista+indice)->estado=2;
                printf("\nPelicula dada de baja\n");
                agregarPelicula(lista,tamanio,contador);
            }
            else
            {
                printf("\nPelicula no dada de baja\n");
            }
        }
        else
        {
            printf("\nNo se encontro el ID ingresado\n");
        }
    }
    else
    {
        printf("\nNo es posible borrar peliculas porque no hay ninguna ingresada\n");
    }

}

void modificarPelicula(EMovie* lista,int tamanio,int* contador)
{
    int i;
    int verificar=0;
    for(i=0; i<tamanio; i++)
    {
        if((lista+i)->estado==1)
        {
            verificar=verificar+1;
            break;
        }
    }
    if(verificar!=0)
    {
        int id;
        int indice;
        mostrarPelicula(lista,tamanio);
        getInt("\nIngresa el ID de la pelicula que desees modificar ",&id,"El ID ingresado no es un numero. Ingreselo nuevamente ");
        indice=buscarPelicula(lista,tamanio,id);
        if(indice!=-1)
        {
            menuModificar(lista,indice);
            agregarPelicula(lista,tamanio,contador);
        }
        else
        {
            printf("\nEl ID ingresado no existe \n");
        }
    }
    else
    {
        printf("\nNo es posible modificar peliculas porque no hay ninguna ingresada\n");
    }
}

void menuModificar(EMovie* lista,int indice)
{
    int opcion;
    printf("\n1- Titulo");
    printf("\n2- Genero");
    printf("\n3- Duracion");
    printf("\n4- Descripcion");
    printf("\n5- Puntaje");
    printf("\n6- Link imagen");
    getInt("\nQue deseas modificar? ",&opcion,"La opcion ingresada no es valida. Ingrese una nuevamente ");
    switch(opcion)
    {
    case 1:
        printf("\nTitulo actual %s",(lista+indice)->titulo);
        getString("\nIngresa el nuevo titulo ",(lista+indice)->titulo,"El titulo ingresado no es valido. Ingresalo nuevamente ");
        stringToUpper((lista+indice)->titulo);
        printf("\nModificacion guardada\n");
        break;
    case 2:
        printf("\nGenero actual %s",(lista+indice)->genero);
        getString("\nIngresa el nuevo genero ",(lista+indice)->genero,"El genero ingresado no es valido. Ingresalo nuevamente ");
        stringToUpper((lista+indice)->genero);
        printf("\nModificacion guardada\n");
        break;
    case 3:
        printf("\nDuracion actual %d",(lista+indice)->duracion);
        getInt("\nIngresa la nueva duracion ",&(lista+indice)->duracion,"La duracion ingresada no es valida. Ingresala nuevamente ");
        printf("\nModificacion guardada\n");
        break;
    case 4:
        printf("\nDescripcion actual %s",(lista+indice)->descripcion);
        getString("\nIngresa la nueva descripcion ",(lista+indice)->descripcion,"La descripcion ingresada no es valida. Ingresala nuevamente ");
        printf("\nModificacion guardada\n");
        break;
    case 5:
        printf("\nPuntaje actual %d",(lista+indice)->puntaje);
        getInt("\nIngresa el nuevo puntaje (Entre 0 y 100) ",&(lista+indice)->puntaje,"El puntaje ingresado no es valido. Ingresalo nuevamente ");
        validarRangoEntero(&(lista+indice)->puntaje);
        printf("\nModificacion guardada\n");
        break;
    case 6:
        printf("\nLink actual %s",(lista+indice)->linkImagen);
        getString("\nIngresa el nuevo link de la imagen ",(lista+indice)->linkImagen,"El link ingresado no es valido. Ingresalo nuevamente ");
        printf("\nModificacion guardada\n");
        break;
    default:
        printf("\nLa opcion ingresada no existe\n");
        break;
    }
}

void agregarPelicula(EMovie* listado,int tamanio,int* contador)
{
    *(contador)=0;
    int i;
    FILE* pelicula;
    pelicula=fopen("movies.dat","wb");
    if(pelicula!=NULL)
    {
        for(i=0;i<tamanio;i++)
        {
            if((listado+i)->estado==1||(listado+i)->estado==2)
            {
                *(contador)=*(contador)+1;
            }
        }
        fwrite(contador,sizeof(int),1,pelicula);

        for(i=0;i<tamanio;i++)
        {
            if((listado+i)->estado==1||(listado+i)->estado==2)
            {
                fwrite((listado+i),sizeof(EMovie),1,pelicula);
            }
        }
    }
    fclose(pelicula);
}

void cargarPelicula(EMovie* lista,int tamanio,int* contador)
{
    int i;
    FILE* pelicula;
    pelicula=fopen("movies.dat","rb");
    if(pelicula!=NULL)
    {
        fread(contador,sizeof(int),1,pelicula);
        for(i=0;i<*(contador);i++)
        {
           fread((lista+i),sizeof(EMovie),1,pelicula);
        }
        printf("Archivos cargados con exito!!\n");
        system("pause");
        system("cls");
    }
    else
    {
        printf("\nNo pudo cargarse el archivo\n");
        system("pause");
        system("cls");
    }
    fclose(pelicula);
}

void generarPagina(EMovie* lista,int tamanio,char nombre[])
{
    int i;
    int verificar=0;
    for(i=0; i<tamanio; i++)
    {
        if((lista+i)->estado==1)
        {
            verificar=verificar+1;
            break;
        }
    }
    if(verificar!=0)
    {
        FILE* miArchivo;
        miArchivo=fopen(nombre,"w");
        if(miArchivo!=NULL)
        {
            fprintf(miArchivo,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");
            int i;
            for(i=0; i<tamanio; i++)
            {
                if((lista+i)->estado==1)
                {
                    fprintf(miArchivo,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s'alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero: %s</li><li>Puntaje: %d</li><li>Duracion: %d</li></ul><p>%s</p></article>",(lista+i)->linkImagen,(lista+i)->titulo,(lista+i)->genero,(lista+i)->puntaje,(lista+i)->duracion,(lista+i)->descripcion);
                }
            }
            fprintf(miArchivo,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
            printf("\nPagina web creada\n");
        }
        fclose(miArchivo);
    }
    else
    {
        printf("\nNo es posible generar la pagina web porque no hay peliculas ingresadas\n");
    }

}
