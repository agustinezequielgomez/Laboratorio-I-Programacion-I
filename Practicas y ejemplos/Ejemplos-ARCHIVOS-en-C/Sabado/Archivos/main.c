#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int escribirTexto(char*);
int leerTexto(char* txt);

int main()
{
    char txt[50];
    int r;
    r=escribirTexto("Hola a todos!!\nChau a todos");
    if(r)
    {
        printf("Guardado con exito!");
    }
    else
    {
        printf("No se pudo abrir el archivo");
    }
    r=leerTexto(txt);
    if(r)
    {
        printf("\n%s",txt);
    }
    else
    {
        printf("Imposible leer el archivo");
    }
    return 0;
}

int escribirTexto(char* texto)
{
    FILE* pArchivo;
    int ret=0;
    pArchivo=fopen("archivoTXT.txt","w");//Si pudo crear el archivo devuelve el puntero, sino null

    if(pArchivo!=NULL)
    {
        fprintf(pArchivo,"%s",texto);
        fclose(pArchivo);
        ret=1;
    }
    return ret;
}

int leerTexto(char* txt)
{
     FILE* pArchivo;
     char t[100]="";
     int ret=0;

     pArchivo=fopen("archivoTXT.txt","r");
     if(pArchivo!=NULL)
     {
         while(!feof(pArchivo))//Para mostrar todas las lineas hace falta concatenar, sino se va a mostrar solo el ultimo
         {
             fgets(t,50,pArchivo);//Recibe la variable que tiene el texto, la cantidad de caracteres y el puntero a archivo
             strcat(txt,t);//concateno las lineas del archivo
         }

         fclose(pArchivo);
         ret=1;
     }
     return ret;
}
