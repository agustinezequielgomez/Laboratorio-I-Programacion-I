#include"parser.h"
#include<string.h>
int parserRead(ArrayList* this)
{
    char id[5];
    char nombre[50];
    char profesion[50];
    char salario[10];
    char edad[3];
    empleado* aux;
    int leidos;
    if(this!=NULL)
    {
        FILE* pFile;
        pFile=fopen("data.csv","r");
        if(pFile!=NULL)
        {
            do
            {
                leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,salario,edad,profesion);
                if(leidos==5)
                {
                    aux=constructor();
                    if(aux!=NULL)
                    {
                        set_id(aux,atoi(id));
                        set_name(aux,nombre);
                        set_sueldo(aux,atoi(salario));
                        set_edad(aux,atoi(edad));
                        set_profesion(aux,profesion);
                        this->add(this,aux);
                    }
                }
            }
            while(!feof(pFile));
            printf("\nArchivo leido con exito\n");
            system("cls");
        }
        else
        {
            printf("\nArchivo no encontrado\n");
            system("cls");
        }
        fclose(pFile);
    }
}

int parserWrite(ArrayList* this)
{
    int i;
    empleado* aux;
    FILE* pFile;
    pFile=fopen("out.csv","w");
    if(pFile!=NULL&&this!=NULL)
    {
        for(i=0; i<al_len(this); i++)
        {
            aux=this->get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%s,%f,%d,%s\n",get_id(aux),get_nombre(aux),get_salario(aux),get_edad(aux),get_profesion(aux));
            }
        }
        printf("\nArchivo guardado con exito\n ");
    }
    fclose(pFile);
}
