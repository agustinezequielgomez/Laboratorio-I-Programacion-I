#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int id;
    char nombre[50];
    int estado;
}ePersona;

int main()
{
    ePersona listaPersonas[4]={{1,"Juan",1},{2,"Maria",0},{3,"Jose",1},{0,"",0}};
    ePersona lectura[4];
    int i;
    for(i=0;i<4;i++)
    {
        lectura[i].estado=0;
    }
    int contador=0;
    FILE* pArchivo;
    /*pArchivo=fopen("miArchivo.dat","wb");
    for(i=0;i<4;i++)
    {
        if(listaPersonas[i].estado==1)
        {
            //fwrite(&listaPersonas[i],sizeof(ePersona),1,pArchivo);
            contador++;
        }
    }

    fwrite(&contador,sizeof(int),1,pArchivo);
    for(i=0;i<4;i++)
    {
        if(listaPersonas[i].estado==1)
        {
            fwrite(&listaPersonas[i],sizeof(ePersona),1,pArchivo);

        }
    }
    fclose(pArchivo);
*/
    pArchivo=fopen("miArchivo.dat","rb");
    fread(&contador,sizeof(int),1,pArchivo);
    fread(lectura,sizeof(ePersona),contador,pArchivo);//lee el archivo en el array lectura
    fclose(pArchivo);


    for(i=0;i<4;i++)
    {
        if(lectura[i].estado==1)
        {
            printf("%d--%s\n",lectura[i].id,lectura[i].nombre);//muestro el array lectura, que contiene los datos que contenia listaPersonas
        }
    }



    /*ePersona miPersona;//={1,"Juan"};
    FILE* pArchivo;
    //Escribir estructura en archivo de texto
    /*pArchivo=fopen("miArchivo.txt","w");
    fprintf(pArchivo,"%d--%s",miPersona.id,miPersona.nombre);*/

    //Escribir estructura en archivo binario
    /*
    pArchivo=fopen("miArchivo.dat","wb");
    fwrite(&miPersona,sizeof(ePersona),1,pArchivo);
    fclose(pArchivo);

    pArchivo=fopen("miArchivo.dat","rb");
    fread(&miPersona,sizeof(ePersona),1,pArchivo);
    fclose(pArchivo);

    printf("%d--%s",miPersona.id,miPersona.nombre);*/
    return 0;
}
