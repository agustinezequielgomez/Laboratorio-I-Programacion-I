#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int entero;
    char caracter;
}eDato;

void funcion2a(void);

void funcion2b(void);

void funcion3(void);


int main()
{
    /*FILE* miArchivo;
    int numero=64;

    miArchivo=fopen("prueba1.txt","w");

    fwrite(&numero,sizeof(int),1,miArchivo);

    fclose(miArchivo);

    miArchivo=fopen("prueba1.txt","r");

    fread(&numero,sizeof(int),1,miArchivo);

    fclose(miArchivo);

    printf("NUMERO %d",numero);*/

    funcion3();
    return 0;
}

void funcion2a()
{
    FILE* miArchivo;
    int i=0;
    int numero;
    int lista[5];

    miArchivo=fopen("prueba.txt","w");

    for(i=0; i<5; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numero);
        fwrite(&numero,sizeof(int),1,miArchivo);
    }

    fclose(miArchivo);

    miArchivo = fopen("prueba.txt","r");
    i=0;
    while(!feof(miArchivo))
    {
         fread(&lista[i],sizeof(int),1,miArchivo);

         if(feof(miArchivo))
         {
             break;
         }
         i++;
    }
    fclose(miArchivo);

    for(i=0; i<5; i++)
    {

        printf("%d\n",lista[i]);

    }

}

void funcion2b(void)
{
    FILE* miArchivo;
    int i=0;
    int numero;
    int lista[5]={1,5,9,6,4};

    miArchivo=fopen("prueba3.txt","w");

    fwrite(lista,sizeof(int),5,miArchivo);

    fclose(miArchivo);

    fread(lista,sizeof(int),5,miArchivo);

    miArchivo=fopen("prueba3.txt","r");

    /*for(i=0;i<5;i++)
    {
        printf()
    }*/
}

void funcion3(void)
{
    FILE* miArcivo;
    eDato d ={1,'B'};

    miArcivo=fopen("miBinario.bin","wb");

    if(miArcivo!=NULL)
    {
        fwrite(&d,sizeof(eDato),1,miArcivo);
        fclose(miArcivo);
    }

    miArcivo=fopen("miBinario.bin","rb");
    if(miArcivo!=NULL)
    {
        fread(&d,sizeof(eDato),1,miArcivo);
        fclose(miArcivo);

        printf("%d--%c",d.entero,d.caracter);
    }
}
