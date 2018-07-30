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
    ejemplo* auxiliar;
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
    set_int(this,contador);
}*/


void alta(ArrayList* this)
{
    char cadena[50];
    int entero;
    float flotante;
    ejemplo* aux;
    int flag=0;
    if(this!=NULL)
    {
        aux=constructor();
        if(aux!=NULL)
        {
            if(getInt("\nIngrese su ID ",&entero,"\nID no valido ")==0)
            {
                flag+=1;
                if(getString("\nIngrese su nombre ",cadena,"\nNombre invalido ")==0)
                {
                    stringToUpper(cadena);
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
}

void printAll(ArrayList* this)
{
    int i;
    int len;
    ejemplo* aux;
    if(this!=NULL)
    {
        len=this->len(this);
        printf("\nID\t\tNombre\t\tSalario");
        for(i=0; i<len; i++)
        {
            aux=this->get(this,i);
            if(aux!=NULL)
            {
                printOne(aux);
            }
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
    ejemplo* aux;
    if(this!=NULL)
    {
        len=this->len(this);
        for(i=0; i<len; i++)
        {
            aux=this->get(this,i);
            if(aux!=NULL&&aux->id==id)
            {
                return i;
            }
        }
    }
    return -1;
}

void baja(ArrayList* this, ArrayList* borrados)
{
    ejemplo* aux;
    int id;
    int indice;
    if(this!=NULL)
    {
        printAll(this);
        if(getInt("\nIngrese el ID a dar de baja ",&id,"\nID invalido ")!=-1)
        {
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
        }
        else
        {
            printf("\nID no encontrado");
        }
    }
}

void modificar(ArrayList* this)
{
    int id;
    int indice;
    int opcion;
    ejemplo* aux;
    if(this!=NULL)
    {
        printAll(this);
        if(getInt("\nIngresa el ID que quieras modificar ",&id,"\nID invalido ")!=-1)
        {
            indice=compare_id(this,id);
            if(indice!=-1)
            {
                aux=this->get(this,indice);
                if(aux!=NULL)
                {
                    printf("\n1- Modificar ID");
                    printf("\n2- Modificar nombre");
                    printf("\n3- Modificar salario");
                    getInt("\nQue desea modificar? ",&opcion,"\nOpcion invalida ");
                    switch(opcion)
                    {
                    case 1:
                        modificarInt(aux);
                        break;
                    case 2:
                        modificarString(aux);
                        break;
                    case 3:
                        modificarFloat(aux);
                        break;
                    }
                    parserWrite(this);
                }
            }
        }
        else
        {
            printf("\nID no encontrado\n");
        }
    }
}

void modificarString(ejemplo* dato)
{
    char aux[50];
    printf("\nDato actual %s",get_string(dato));
    if(getString("\nIngresa el nuevo dato ",aux,"\nDato invalido ")!=-1)
    {
        if(deseaContinuar("\nDesea realizar esta modificacion? (S/N) ")=='s')
        {
            stringToUpper(aux);
            set_string(dato,aux);
            printf("\nModificacion realizada con exito\n");
        }
    }
}

void modificarInt(ejemplo* dato)
{
    int aux;
    printf("\nDato actual %d",get_int(dato));
    if(getInt("\nIngresa el nuevo dato ",&aux,"\nDato invalido ")!=-1)
    {
        if(deseaContinuar("\nDesea realizar esta modificacion? (S/N) ")=='s')
        {
            set_int(dato,aux);
            printf("\nModificacion realizada con exito\n");
        }

    }
}

void modificarFloat(ejemplo* dato)
{
    float aux;
    printf("\nDato actual %f",get_float(dato));
    if(getFloat("\nIngrese su nuevo salario ",&aux,"\nSalario invalido")!=-1)
    {
        if(deseaContinuar("\nDesea realizar esta modificacion? (S/N) ")=='s')
        {
            set_float(dato,aux);
            printf("\nModificacion realizada con exito\n");
        }
    }
}

int sort_string(void* stringA, void* stringB)
{
    int retorno;
    ejemplo* aux1;
    ejemplo* aux2;
    aux1=(ejemplo*)stringA;
    aux2=(ejemplo*)stringB;
    retorno=strcmp(get_string(aux1),get_string(aux2));
    return retorno;
}

int sort_int(void* intA,void* intB)
{
    int retorno;
    if(get_int((ejemplo*)intA)>get_int((ejemplo*)intB))
    {
        retorno=1;
    }
    else if(get_int((ejemplo*)intA)<get_int((ejemplo*)intB))
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

int sort_float(void* floatA, void* floatB)
{
    int retorno;
    if(get_float((ejemplo*)floatA)>get_float((ejemplo*)floatB))
    {
        retorno=1;
    }
    else if(get_float((ejemplo*)floatA)<get_float((ejemplo*)floatB))
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

char get_char(void* element)
{
    char caracter[20];
    strcpy(caracter,get_string((ejemplo*)element));
    return caracter[0];
}

void double_sort(ArrayList* this)
{
    ArrayList* clone;
    clone=al_newArrayList();
    int i;
    int j;
    ejemplo* aux;
    ejemplo* aux2;
    void* auxiliar;
    if(this!=NULL&&clone!=NULL)
    {
        clone=al_clone(this);
        al_sort(clone,sort_string,1);
        printf("\nLista alfabeticamente\n");
        printAll(clone);
        printf("\n\n\n\n");
        for(i=0;i<clone->len(clone)-1;i++)
        {
            aux=clone->get(clone,i);
            for(j=i+1;j<clone->len(clone);j++)
            {
                aux2=clone->get(clone,j);
                if(aux!=NULL&aux2!=NULL)
                {
                    if(get_char(aux)==get_char(aux2))
                    {
                        if(get_float(aux)>get_float(aux2))
                        {
                            auxiliar=al_pop(clone,i);
                            al_push(clone,i,aux2);
                            al_set(clone,j,auxiliar);
                        }
                    }
                }
            }
        }
        printAll(clone);
    }
}
