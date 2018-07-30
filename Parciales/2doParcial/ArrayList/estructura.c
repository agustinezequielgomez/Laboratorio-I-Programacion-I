#include"estructura.h"
#include<stdio.h>

ejemplo* constructor()
{
    ejemplo* aux;
    aux=(ejemplo*)malloc(sizeof(ejemplo));
    return aux;
}

int set_int(ejemplo* this, int dato)
{
    this->id=dato;
}

int set_string(ejemplo* this, char dato[])
{
    strcpy(this->cadena,dato);
}

int set_float(ejemplo* this, float dato)
{
    this->salario=dato;
}

int get_int(ejemplo* this)
{
    return this->id;
}

char* get_string(ejemplo* this)
{
    return this->cadena;
}

float get_float(ejemplo* this)
{
    return this->salario;
}


//---------------------------------------------------------------\\


int getInt(char mensaje[],int* dato,char mensajeError[])
{
    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    return validarEntero(auxstring,dato,mensajeError);
}

int getFloat(char mensaje[],float* dato,char mensajeError[])
{
    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    return validarFloat(auxstring,dato,mensajeError);
}

int getString(char mensaje[],char* dato,char mensajeError[])
{
    char auxstring[500];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    return validarString(auxstring,dato,mensajeError);
}

char getChar(char mensaje[],char caracter)
{
    fflush(stdin);
    printf("%s",mensaje);
    scanf("%c",&caracter);
    return caracter;
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

int validarEntero(char auxiliar[],int* dato,char mensaje[])
{
    int intentos=0;
    int validar;
    validar=strlen(auxiliar);
    while(validar==0)
    {
        printf(mensaje);
        gets(auxiliar);
        validar=strlen(auxiliar);
        fflush(stdin);
        intentos=intentos+1;
        if(intentos==3)
        {
            printf("\nLimite de intentos alcanzado. Regresando al menu principal \n");
            return -1;
        }
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
                intentos=intentos+1;
                if(intentos==3)
                {
                    printf("\nLimite de intentos alcanzado. Regresando al menu principal \n");
                    return -1;
                }
            }
            while(isdigit(auxiliar[i])==0||isspace(auxiliar[i])!=0||validar==0);
        }
        else
        {
            i=i+1;
        }
    }
    *(dato)=atoi(auxiliar);
    return 0;
}

int validarFloat(char auxiliar[],float* dato,char mensaje[])
{
    int intentos=0;
    int validar;
    validar=strlen(auxiliar);
    while(validar==0)
    {
        printf(mensaje);
        gets(auxiliar);
        validar=strlen(auxiliar);
        fflush(stdin);
        intentos=intentos+1;
        if(intentos==3)
        {
            printf("\nLimite de intentos alcanzado. Regresando al menu principal \n");
            return -1;
        }
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
                intentos=intentos+1;
                if(intentos==3)
                {
                    printf("\nLimite de intentos alcanzado. Regresando al menu principal \n");
                    return -1;
                }
            }
            while(isdigit(auxiliar[i])==0||isspace(auxiliar[i])!=0||validar==0);
        }
        else
        {
            i=i+1;
        }
    }
    *(dato)=atoi(auxiliar);
    return 0;
}

int validarString(char auxiliar[],char* dato,char mensaje[])
{
    int intentos=0;
    int validar;
    validar=strlen(auxiliar);
    while(validar==0||isspace(auxiliar[0])!=0)
    {
        printf(mensaje);
        gets(auxiliar);
        fflush(stdin);
        validar=strlen(auxiliar);
        intentos=intentos+1;
        if(intentos==3)
        {
            printf("\nLimite de intentos alcanzado. Regresando al menu principal \n");
            return -1;
        }
    }
    strcpy(dato,auxiliar);
    return 0;
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

/*void idAutoIncremental(ArrayList* this, ArrayList* this2, ejemplo* aux)
{
    int contador=0;
    ePropietario* auxiliar;
    int i;
    if(this!=NULL&&aux!=NULL)
    {
        for(i=0;i<al_len(this);i++)
        {
            auxiliar=al_get(this,i);
            if(auxiliar->estado==1)
            {
                contador=contador+1;
            }
        }
        for(i=0;i<al_len(this2);i++)
        {
            auxiliar=al_get(this2,i);
            if(auxiliar->estado==2)
            {
                contador=contador+1;
            }
        }

    }
    aux->Id=contador;
}*/


void alta(ArrayList* this)
{
    char cadena[50];
    int entero;
    float flotante;
    ejemplo* aux;
    int flag=0;
    aux=constructor();
    if(aux!=NULL)
    {
        if(getInt("\nIngrese su ID ",&entero,"\nID no valido ")==0)
        {
            flag+=1;
            if(getString("\nIngrese su nombre ",cadena,"\nNombre invalido ")==0)
            {
                flag+=1;
                if(getFloat("\nIngrese su salario ",&flotante,"\nSalario invalido ")==0)
                {
                    flag+=1;
                    set_int(aux,entero);
                    set_string(aux, cadena);
                    set_float(aux,flotante);
                    this->add(this,aux);
                    parserWrite(this);
                }
            }
        }
        if(flag!=3)
        {
            free(aux);
        }
    }
}

void printAll(ArrayList* this)
{
    int i;
    int len=this->len(this);
    ejemplo* aux;
    printf("\nID\t\tNombre\t\tSalario");
    for(i=0;i<len;i++)
    {
        aux=this->get(this,i);
        if(aux!=NULL)
        {
            printOne(aux);
        }
    }
}
void printOne(ejemplo* this)
{
    printf("\n%d\t\t%s\t\t%f",get_int(this),get_string(this),get_float(this));
}

int compare_id(ArrayList* this,int id)
{
    int i;
    int len;
    len=this->len(this);
    ejemplo* aux;
    for(i=0;i<len;i++)
    {
        aux=this->get(this,i);
        if(aux!=NULL&&aux->id==id)
        {
            return i;
        }
    }
    return -1;
}

void baja(ArrayList* this, ArrayList* borrados)
{
    ejemplo* aux;
    int id;
    int indice;
    printAll(this);
    getInt("\nIngrese el ID a dar de baja ",&id,"\nID invalido ");
    indice=compare_id(this,id);
    if(indice!=-1)
    {
        if(deseaContinuar("\nID encontrado. Desea darlo de baja (S/N) ")=='s')
        {
            aux=this->pop(this,indice);
            this->add(borrados,aux);
            parserWrite(this);
        }
    }
    else
    {
        printf("\nID no encontrado");
    }
}

void modificar(ArrayList* this)
{
    int id;
    int indice;
    ejemplo* aux;
    printAll(this);
    getInt("\nIngresa el ID que quieras modificar ",&id,"\nID invalido ");
    indice=compare_id(this,id);
    if(indice!=-1)
    {
        aux=this->get(this,indice);
        modificarInt(aux);
    }
}

void modificarString(void* dato)
{
    printf("\nDato actual %s",dato);
    getString("\nIngresa el nuevo dato ",dato,"\nDato invalido ");
    stringToUpper(dato);
}

void modificarInt(ejemplo* dato)
{
    printf("\nDato actual %d",dato->id);
    getInt("\nIngresa el nuevo dato ",&dato->id,"\nDato invalido ");
}
