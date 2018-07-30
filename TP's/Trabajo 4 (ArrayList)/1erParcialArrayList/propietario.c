#include<stdio.h>
#include<stdlib.h>
#include"propietario.h"

void menu()
{
    ArrayList* listaPropietarios;
    ArrayList* propietariosBorrados;
    ArrayList* automoviles;
    ArrayList* automovilesBorrados;
    ArrayList* egresos;
    listaPropietarios=al_newArrayList();
    propietariosBorrados=al_newArrayList();
    automoviles=al_newArrayList();
    automovilesBorrados=al_newArrayList();
    egresos=al_newArrayList();
    parserRead(listaPropietarios,propietariosBorrados);
    parserReadAutomovil(automoviles,automovilesBorrados);
    parserReadEgresos(egresos);
    if(listaPropietarios!=NULL)
    {
        char continuar='s';
        int opcion=0;
        do
        {
            printf("\n1- Dar de alta propietario");
            printf("\n2- Mostrar propietarios");
            printf("\n3- Modificar propietarios");
            printf("\n4- Eliminar propietario");
            printf("\n5- Añadir automovil");
            printf("\n6- Mostrar automoviles");
            printf("\n7- Egresar automovil");
            printf("\n8- Mostrar recaudaciones del estacionamiento");
            printf("\n9- Mostrar recaudaciones por marca");
            printf("\n10- Salir");
            getInt("\nIngrese una opcion ",&opcion,"\nLa opcion ingresada es invalida. Ingrese una nuevamente ");
            switch(opcion)
            {
            case 1:
                addPropietario(listaPropietarios,propietariosBorrados);
                system("pause");
                break;
            case 2:
                printAllPropietarios(listaPropietarios);
                system("pause");
                break;
            case 3:
                modificarPropietario(listaPropietarios,propietariosBorrados);
                system("pause");
                break;
            case 4:
                deletePropietario(listaPropietarios,propietariosBorrados);
                break;
            case 5:
                addAutomovil(automoviles,automovilesBorrados,listaPropietarios);
                break;
            case 6:
                printAllAutomovil(automoviles);
                system("pause");
                break;
            case 7:
                egresarAutomovil(automoviles,automovilesBorrados,egresos);
                system("pause");
                break;
            case 8:
                printRecaudaciones(egresos);
                system("pause");
                break;
            case 9:
                printRecaudacionesPorMarca(egresos);
                system("pause");
                break;
            case 10:
                continuar='n';
                break;
            }
            system("cls");
        }
        while(continuar=='s');
    }
}

void getInt(char mensaje[],int* dato,char mensajeError[])
{
    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    validarEntero(auxstring,dato,mensajeError);
}

void getString(char mensaje[],char* dato,char mensajeError[])
{
    char auxstring[500];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    validarString(auxstring,dato,mensajeError);
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

void validarEntero(char auxiliar[],int* dato,char mensaje[])
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
            printf("\nLimite de intentos alcanzado. Finalizando programa \n");
            exit(EXIT_FAILURE);
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
                    printf("\nLimite de intentos alcanzado. Finalizando programa \n");
                    exit(EXIT_FAILURE);
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
}

void validarString(char auxiliar[],char* dato,char mensaje[])
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
            printf("\nLimite de intentos alcanzado. Finalizando programa \n");
            exit(EXIT_FAILURE);
        }
    }
    strcpy(dato,auxiliar);
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

void idAutoIncremental(ArrayList* this, ArrayList* this2, ePropietario* aux)
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
}

void propietario_set_name(ePropietario* aux)
{
    getString("\nIngresa el nombre del propietario ",aux->nombre,"\nEl nombre no es valido. Ingreselo nuevamente ");
    stringToUpper(aux->nombre);
}

void propietario_set_card(ePropietario* aux)
{
    getString("\nIngrese la tarjeta de credito del propietario ",aux->tarjeta,"\nLa tarjeta es invailda. Ingresela nuevamente ");
}

void propietario_set_adress(ePropietario* aux)
{
    getString("\nIngresa la direccion del  propietario ",aux->direccion,"\nDireccion incorrecta. Ingresela nuevamente ");
}

void propietario_set_age(ePropietario* aux)
{
    getInt("\nIngrese la edad del usuario ",&aux->edad,"\nLa edad no es valida. Ingresela nuevamente ");
}

void propietario_set_state(ePropietario* aux)
{
    aux->estado=1;
}

void addPropietario(ArrayList* this, ArrayList* this2)
{
    ePropietario* aux;
    aux=malloc(sizeof(ePropietario));
    if(aux!=NULL)
    {
        idAutoIncremental(this,this2,aux);
        propietario_set_name(aux);
        propietario_set_card(aux);
        propietario_set_adress(aux);
        propietario_set_age(aux);
        propietario_set_state(aux);
        al_add(this,aux);
        parserWrite(this,this2);
    }
}

void printPropietario(ePropietario* this)
{
    printf("\n%d\t%s",this->Id,this->nombre);
    if(strlen(this->nombre)<=16)
    {
        printf("\t");
    }
    printf("\t%s",this->tarjeta);
    if(strlen(this->tarjeta)<=16)
    {
        printf("\t");
    }
    printf("\t%s",this->direccion);
    if(strlen(this->direccion)<=16)
    {
        printf("\t");
    }
    printf("\t%d",this->edad);
}

void printAllPropietarios(ArrayList* this)
{
    ePropietario* aux;
    int i;
    if(this!=NULL)
    {
        printf("\nID\tNombre\t\tTarjeta\t\tDireccion\tEdad");
        for(i=0;i<al_len(this);i++)
        {
            aux=al_get(this,i);
            printPropietario(aux);
        }
    }
}

void* compare_propietarios(ArrayList* this, int* indice, ePropietario* aux)
{
    int id;
    int i;
    printAllPropietarios(this);
    getInt("\nIngresa el ID del propietario que quieras modificar ",&id,"\nEl ID ingresado no es valido ");
    for(i=0;i<al_len(this);i++)
    {
        aux=al_get(this,i);
        if(aux->Id==id)
        {
           *(indice)=al_indexOf(this,aux);
           break;
        }
    }
    return aux;
}

void modificarPropietario(ArrayList* this, ArrayList* this2)
{
    int indice=-1;
    ePropietario* aux=NULL;
    aux=compare_propietarios(this,&indice,aux);
    if(indice!=-1)
    {
        int opcion;
        printf("\n1- Modificar nombre");
        printf("\n2- Modificar tarjeta");
        printf("\n3- Modificar direccion");
        printf("\n4- Modificar edad");
        getInt("\nIngresa la opcion de la cual quieras hacer la modificacion ",&opcion,"\nOpcion invalida ");
        switch(opcion)
        {
        case 1:
            modificarString(aux->nombre);
            break;
        case 2:
            modificarString(aux->tarjeta);
            break;
        case 3:
            modificarString(aux->direccion);
            break;
        case 4:
            modificarInt(aux);
            break;
        }
        parserWrite(this,this2);
    }
    else
    {
        printf("\nId no encontrado\n");
    }
}

void modificarString(void* dato)
{
    printf("\nDato actual %s",dato);
    getString("\nIngresa el nuevo dato ",dato,"\nDato invalido ");
    stringToUpper(dato);
}

void modificarInt(ePropietario* dato)
{
    printf("\nDato actual %d",dato->edad);
    getInt("\nIngresa el nuevo dato ",&dato->edad,"\nDato invalido ");
}

void deletePropietario(ArrayList* this,ArrayList* this2)
{
    int indice=-1;
    ePropietario* aux;
    compare_propietarios(this,&indice,aux);
    if(indice!=-1)
    {
        aux=al_pop(this,indice);
        aux->estado=2;
        al_add(this2,aux);
        parserWrite(this,this2);
    }
}
