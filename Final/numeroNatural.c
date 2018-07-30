#include"numeroNatural.h"
#include<stdio.h>
numeroNatural* constructor()
{
    numeroNatural* aux;
    aux=(numeroNatural*)malloc(sizeof(numeroNatural));
    return aux;
}

int set_numero(numeroNatural* this, int dato)
{
    this->numero=dato;
}

int set_par(numeroNatural* this, int dato)
{
    this->par=dato;
}

int set_impar(numeroNatural* this, int dato)
{
    this->impar=dato;
}

int set_primo(numeroNatural* this, int dato)
{
    this->primo=dato;
}

int set_nombre(numeroNatural* this, char dato[])
{
    strcpy(this->nombre,dato);
}

int get_numero(numeroNatural* this)
{
    return this->numero;
}

int get_par(numeroNatural* this)
{
    return this->par;
}

int get_impar(numeroNatural* this)
{
    return this->impar;
}

int get_primo(numeroNatural* this)
{
    return this->primo;
}

char* get_nombre(numeroNatural* this)
{
    return this->nombre;
}

int getInt(char mensaje[],int* dato,char mensajeError[])
{
    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    return validarEntero(auxstring,dato,mensajeError);
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


void printAll(ArrayList* this)
{
    int i;
    int indice=1;
    int len;
    numeroNatural* aux;
    if(this!=NULL)
    {
        len=this->len(this);
        printf("\nID\tNumero\tNombre\t\t\tPar\tImpar\tPrimo\n");
        for(i=0; i<len; i++)
        {
            aux=this->get(this,i);
            if(aux!=NULL)
            {
                printOne(aux, indice);
                indice++;
            }
            if(i==216)
            {
                system("pause");
                system("cls");
            }
        }
    }
}

void printOne(numeroNatural* this, int id)
{
    printf("%d\t%d\t%s",id,get_numero(this),get_nombre(this));
    if(strlen(get_nombre(this))<8)
    {
        printf("\t\t\t");
    }
    else if(strlen(get_nombre(this))==16||strlen(get_nombre(this))>=18)
    {
        printf("\t");
    }
    else if(strlen(get_nombre(this))<17)
    {
        printf("\t\t");
    }

    printf("%d\t%d\t%d\n",get_par(this),get_impar(this),get_primo(this));
}

void completarNumero(ArrayList* this)
{
    int i;
    int j;
    int contador;
    numeroNatural* aux;
    for(i=0; i<this->len(this); i++)
    {
        aux=this->get(this,i);
        if(aux!=NULL)
        {
            contador=0;
            if(get_numero(aux)%2==0)
            {
                set_par(aux,1);
            }
            else
            {
                set_impar(aux,1);
            }
            for(j=1; j<=get_numero(aux); j++)
            {
                if(get_numero(aux)%j==0)
                {
                    contador++;
                }
            }
            if(contador==2)
            {
                set_primo(aux,1);
            }
            else
            {
                set_primo(aux,0);
            }
        }
    }
}

int compararNumeros(void* numero1, void* numero2)
{
    int retorno;
    if(get_numero((numeroNatural*)numero1)>get_numero((numeroNatural*)numero2))
    {
        retorno=1;
    }
    else if(get_numero((numeroNatural*)numero1)<get_numero((numeroNatural*)numero2))
    {
        retorno=-1;
    }
    else
    {
        retorno=0;
    }
    return retorno;
}

int buscarNumeroRepetido(ArrayList* this, ArrayList* repetidos, ArrayList* depurada)
{
    int retorno=-1;
    int i;
    int j;
    int flag=0;
    numeroNatural* numero;
    numeroNatural* aux;
    if(this!=NULL&&repetidos!=NULL&&depurada!=NULL)
    {
        for(i=0; i<this->len(this)-1; i++)
        {
            aux=this->get(this,i);
            if(comprobarSiElNumeroEsRepetido(repetidos,aux)==0)
            {
                flag=0;
                for(j=i+1; j<this->len(this); j++)
                {
                    numero=this->get(this,j);
                    if(get_numero(aux)==get_numero(numero))
                    {
                        repetidos->add(repetidos,numero);
                    }
                    if(flag==0)
                    {
                        depurada->remove(depurada,i);
                        flag==1;
                    }
                }
            }
        }
        repetidos->sort(repetidos,compararNumeros,0);
        printf("\nNumeros repetidos\n");
        printAll(repetidos);
        system("pause");
        system("cls");
        depurada->sort(depurada,compararNumeros,1);
        printf("\nNumeros que no se repitieron\n");
        printAll(depurada);
    }
}

int comprobarSiElNumeroEsRepetido(ArrayList* repetido, numeroNatural* aux)
{
    int retorno=0;
    numeroNatural* auxiliar;
    int i;
    for(i=0;i<repetido->len(repetido);i++)
    {
        auxiliar=repetido->get(repetido,i);
        if(get_numero(auxiliar)==get_numero(aux))
        {
            retorno=-1;
            break;
        }
    }
    return retorno;
}
