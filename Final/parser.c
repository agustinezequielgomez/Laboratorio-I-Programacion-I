#include"parser.h"
#include<stdio.h>
void parserRead(ArrayList* this)
{
    char nombre[50];
    char numero[10];
    char par[10];
    char impar[10];
    char primo[10];
    numeroNatural* aux;
    int leidos;
    FILE* pFile;
    pFile=fopen("datos.csv","r");
    if(pFile!=NULL&&this!=NULL)
    {
        do
        {
            leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",numero,nombre,par,impar,primo);
            if(leidos==5)
            {
                aux=constructor();
                if(aux!=NULL)
                {
                    if(atoi(numero)>=0&&strlen(nombre)<=50&&atoi(par)==0||atoi(par)==1&&atoi(impar)==0||atoi(impar)==1&&atoi(primo)==0||atoi(primo)==1)
                    {
                        set_numero(aux,atoi(numero));
                        set_nombre(aux,nombre);
                        set_par(aux,atoi(par));
                        set_impar(aux,atoi(impar));
                        set_primo(aux,atoi(primo));
                        this->add(this,aux);
                    }
                }
            }
        }while(!feof(pFile));
        printf("\nArchivo leido con exito\n");
    }
    else
    {
        printf("\nArchivo no encontrado\n");
        system("cls");
    }
    fclose(pFile);
}

void parserWrite(ArrayList* this, char nombre[20])
{
    int i;
    numeroNatural* aux;
    FILE* pFile;
    pFile=fopen(nombre,"w");
    if(pFile!=NULL&&this!=NULL)
    {
        for(i=0; i<al_len(this); i++)
        {
            aux=this->get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%s,%d,%d,%d\n",get_numero(aux),get_nombre(aux),get_par(aux),get_impar(aux),get_primo(aux));
            }
        }
        printf("\nArchivo guardado con exito\n ");
    }
    fclose(pFile);
}
