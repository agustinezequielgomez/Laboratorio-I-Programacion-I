#include"parser.h"
void parserRead(ArrayList* this)
{
    char cadena[50];
    char entero[50];
    char flotante[150];
    ejemplo* aux;
    int leidos;
    FILE* pFile;
    pFile=fopen("ejemplo.csv","r");
    if(pFile!=NULL)
    {
        do
        {
            leidos=fscanf(pFile,"%[^,],%[^,],%[^,\n]\n",entero,flotante,cadena);
            if(leidos==3)
            {
                aux=constructor();
                if(aux!=NULL)
                {
                    set_string(aux,cadena);
                    set_int(aux,atoi(entero));
                    set_float(aux,atoi(flotante));
                    this->add(this,aux);
                }
            }
        }while(!feof(pFile));
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

void parserWrite(ArrayList* this)
{
    int i;
    ejemplo* aux;
    FILE* pFile;
    pFile=fopen("ejemplo.csv","w");
    if(pFile!=NULL)
    {
        for(i=0; i<al_len(this); i++)
        {
            aux=this->get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%f,%s\n",get_int(aux),get_float(aux),get_string(aux));
            }
        }
        printf("\nArchivo guardado con exito\n ");
    }
    fclose(pFile);
}

void parserDuoRead(ArrayList* this, ArrayList* this2)
{
    char string[50];
    char entero[50];
    char flotante[50];
    char estado[50];
    int leidos;
    ejemplo* aux;
    FILE* pFile;
    pFile=fopen("propietarios.csv","r");
    if(pFile!=NULL)
    {
        do
        {
            leidos=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",string,entero,flotante,estado);
            if(leidos==3)
            {
                aux=constructor();
                if(aux!=NULL&&atoi(estado)==1)
                {
                    set_string(aux,string);
                    set_int(aux,atoi(entero));
                    set_float(aux,atoi(flotante));
                    al_add(this,aux);
                }
                else if(atoi(estado)==2)
                {
                    set_string(aux,string);
                    set_int(aux,atoi(entero));
                    set_float(aux,atoi(flotante));
                    al_add(this2,aux);
                }
            }
        }while(!feof(pFile));
    }
fclose(pFile);
}

void parserDuoWrite(ArrayList* this, ArrayList* this2)
{
    int len;
    int i;
    ejemplo* aux;
    FILE* pFile;
    pFile=fopen("propietarios.csv","w");
    if(pFile!=NULL)
    {
        len=this->len(this);
        for(i=0;i<len;i++)
        {
            aux=al_get(this,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%s,%f\n",get_int(aux),get_string(aux),get_float(aux));
            }
        }
        len=this2->len(this2);
        for(i=0;i<len;i++)
        {
            aux=al_get(this2,i);
            if(aux!=NULL)
            {
                fprintf(pFile,"%d,%s,%f\n",get_int(aux),get_string(aux),get_float(aux));
            }
        }
    }
    fclose(pFile);
}

void saveBinary(ArrayList* this)
{
    int i;
    int len;
    ejemplo* aux;
    FILE* pFile;
    if(this!=NULL)
    {
        len=this->len(this);
        pFile=fopen("archivo.dat","wb");
        if(pFile!=NULL)
        {
            fwrite(&len,sizeof(int),1,pFile);
            for(i=0; i<len; i++)
            {
                aux=this->get(this,i);
                fwrite(aux,sizeof(ejemplo),1,pFile);
            }
        }
        fclose(pFile);
    }
}

void loadBinary(ArrayList* this)
{
    int i;
    ejemplo* aux;
    FILE* pFile;
    int len;
    pFile=fopen("archivo.dat","rb");
    if(pFile!=NULL)
    {
        fread(&len,sizeof(int),1,pFile);
        for(i=0;i<len;i++)
        {
            aux=constructor();
            fread(aux,sizeof(ejemplo),1,pFile);
            this->add(this,aux);
        }
    }
    fclose(pFile);
}
