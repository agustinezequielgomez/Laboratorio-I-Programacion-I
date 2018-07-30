#include<string.h>
#include<stdio.h>
#include"parser.h"
void parserReadDestinatario(char archivo[],ArrayList* this)
{
    char nombre[50];
    char mail[100];
    int leidos;
    int i=0;
    destinatario* aux;
    FILE* pFile;
    pFile=fopen(archivo,"r");
    if(pFile!=NULL)
    {
        do
        {
            leidos=fscanf(pFile,"%[^,],%[^,\n]\n",nombre,mail);
            if(leidos==2)
            {
                aux=(destinatario*)malloc(sizeof(destinatario));
                if(aux!=NULL)
                {
                    strcpy(aux->nombre,nombre);
                    strcpy(aux->mail,mail);
                    al_add(this,aux);
                }
            }
        }while(!feof(pFile));
    }
    fclose(pFile);
}

ArrayList* depurar(ArrayList* destinatarios,ArrayList* listaNegra)
{
    ArrayList* listaDepurada;
    listaDepurada=al_newArrayList();
    destinatario* aux;
    destinatario* auxBlack;
    int flag;
    int i;
    int j;
    if(destinatarios!=NULL&&listaNegra!=NULL)
    {
        for(i=0;i<destinatarios->len(destinatarios);i++)
        {
            flag=0;
            aux=destinatarios->get(destinatarios,i);
            for(j=0; j<listaNegra->len(listaNegra); j++)
            {
                auxBlack=listaNegra->get(listaNegra,j);
                if((strcmp(aux->mail,auxBlack->mail))==0)
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                listaDepurada->add(listaDepurada,aux);
            }
        }
    }
    return listaDepurada;
}

void listar(ArrayList* listaDepurada)
{
    int contador=0;
    destinatario* aux;
    int i;
    for(i=0;i<listaDepurada->len(listaDepurada);i++)
    {
        aux=listaDepurada->get(listaDepurada,i);
        if(aux!=NULL)
        {
            printf("\n%s %s",aux->nombre,aux->mail);
            contador=contador+1;
        }
    }
    printf("\nTotal Printeados %d",contador);
}
