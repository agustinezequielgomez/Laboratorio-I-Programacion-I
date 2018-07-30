#include"automovil.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define ALPHA_ROMEO "ALFA ROMERO"
#define FERRARI "FERRARI"
#define AUDI "AUDI\t"
#define OTRO "OTRO\t"

int idAutoIncrementalAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil)
{
    int contador=0;
    int i;
    for(i=0;i<tamanioAutomovil;i++)
    {
        if(listadoAutomovil[i].estado==1)
        {
            contador=contador+1;
        }
    }
    return contador+1;
}


int altaAutomovil(eAutomovil listadoAutomovil[],ePropietario listadoPropietario[],int tamanioAutomovil,int tamanioPropietario,int indice,int flagPropietario)
{
    if(flagPropietario==1)
    {
        int ID;
        if(indice!=-1)
        {
            mostrarListaPropietario(listadoPropietario,tamanioPropietario,flagPropietario);
            listadoAutomovil[indice].idPropietario=getInt("\nIngresa el ID del propietario al que se le va a asignar el coche ",listadoAutomovil[indice].idPropietario);
            ID=buscarPorIdPropietario(listadoPropietario,tamanioPropietario,listadoAutomovil[indice].idPropietario);
            if(ID!=-1)
            {
                getString("Ingresa la patente de tu coche (ABC-123) ",listadoAutomovil[indice].patente);
                validarPatenteIngresada(listadoAutomovil[indice].patente);
                mostrarMarcasAutomovil(listadoAutomovil);
                listadoAutomovil[indice].marca=getInt("\nIngresa la marca de tu automovil ",listadoAutomovil[indice].marca);
                verificarMarca(listadoAutomovil[indice].marca);
                cambiarMarcas(listadoAutomovil,listadoAutomovil[indice].marca,listadoAutomovil[indice].marcaNombre);
                listadoAutomovil[indice].idIngreso=idAutoIncrementalAutomovil(listadoAutomovil,tamanioAutomovil);
                listadoAutomovil[indice].estado=1;
                return 1;
            }
            else
            {
                printf("\nID de propietario no encontrado");
            }

        }
        else
        {
            printf("\nNo hay lugares libres");
        }
    }
    else
    {
        printf("\nNo se puede dar de alta un automovil porque no hay ningun propietario ingresado\n");
    }
}

int buscarLibreAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil)
{
    int indice;
    int i;
    for(i=0; i<tamanioAutomovil; i++)
    {
        if(listadoAutomovil[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void mostrarUnoAutomovil(eAutomovil listadoAutomovil[],int tamanio,int i)
{
    printf("%d\t\t%d\t\t  %s\t     %s\n",listadoAutomovil[i].idIngreso,listadoAutomovil[i].idPropietario,listadoAutomovil[i].patente,listadoAutomovil[i].marcaNombre);
}

void mostrarListaAutomovil(eAutomovil listadoAutomovil[],int tamanio,int flag)
{
    if(flag==1)
    {
        int i;
        printf("Id ingreso\tId propietario\tPatente\t\tMarca \n");
        for(i=0; i<tamanio; i++)
        {
            if(listadoAutomovil[i].estado==1)
            {
                cambiarMarcas(listadoAutomovil,listadoAutomovil[i].marca,listadoAutomovil[i].marcaNombre);
                printf("%d\t\t%d\t\t%s\t\t%s\n",listadoAutomovil[i].idIngreso,listadoAutomovil[i].idPropietario,listadoAutomovil[i].patente,listadoAutomovil[i].marcaNombre);
            }

        }
    }
    else
    {
        printf("\nPara mostrar los automoviles es necesario que haya ingresado alguno\n");
    }

}

void mostrarMarcasAutomovil()
{
    printf("\n1- ALFA ROMEO");
    printf("\n2- FERRARI");
    printf("\n3- AUDI");
    printf("\n4- OTRO");
}

void inicializarEstadosAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil)
{
    int i;
    for(i=0; i<tamanioAutomovil; i++)
    {
        listadoAutomovil[i].estado=0;
    }
}

int cargarHarcodeAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil)
{
    int id[]= {1,2,3,4,5,6,7,8,9,10};
    char patente[][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[]= {2,1,2,1,3,3,4,1,4,3};
    int i;
    for(i=0; i<10; i++)
    {
        strcpy(listadoAutomovil[i].patente,patente[i]);
        listadoAutomovil[i].idIngreso=id[i];
        listadoAutomovil[i].marca=marca[i];
        listadoAutomovil[i].idPropietario=propietario[i];
        listadoAutomovil[i].estado=1;
    }
    return 1;
}

int verificarMarca(int marcaAVerificar)
{
    while(marcaAVerificar!=1&&marcaAVerificar!=2&&marcaAVerificar!=3&&marcaAVerificar!=4)
    {
        marcaAVerificar=getInt("Marca no existente. Ingrese una valida ",marcaAVerificar);
    }
    return marcaAVerificar;
}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}

int buscarPorIdAutomovil(eAutomovil listadoAutomovil[],int tamanioAutomovil,int id)
{
    int indice=-1;
    int i;
    for(i=0; i<tamanioAutomovil; i++)
    {
        if(listadoAutomovil[i].estado==1)
        {
            if(listadoAutomovil[i].idIngreso==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

int tasarEstadia(int marca,int horas)
{
    int valorTotal;
    if(marca==1)
    {
        valorTotal=horas*150;
    }
    else if(marca==2)
    {
        valorTotal=horas*175;
    }
    else if(marca==3)
    {
        valorTotal=horas*200;
    }
    else
    {
        valorTotal=horas*250;
    }
    return valorTotal;
}

char cambiarMarcas(eAutomovil listadoAutomovil[],int marca,char marcaString[])
{
    switch(marca)
    {
    case 1:
        strcpy(marcaString,ALPHA_ROMEO);
        break;
    case 2:
        strcpy(marcaString,FERRARI);
        break;
    case 3:
        strcpy(marcaString,AUDI);
        break;
    case 4:
       strcpy(marcaString,OTRO);
       break;
    }
    return marcaString;
}


int buscarPorIdPropietarioAutomovil(eAutomovil listadoAutomovil[],ePropietario listadoPropietario[],int indiceAutomovil,int tamanioPropietario)
{
    int indicePropietario;
    int i;
    for(i=0;i<tamanioPropietario;i++)
    {
        if(listadoPropietario[i].estado==1)
        {
            if(listadoAutomovil[indiceAutomovil].idPropietario==listadoPropietario[i].Id)
            {
                indicePropietario=i;
                break;
            }
        }
    }
    return indicePropietario;
}

void mostrarUsuarioConSusAutomoviles(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],int tamanioPropietario,int tamanioAutomovil,int flag)
{
    if(flag==1)
    {
        int IdPropietario;
        int indice;
        int i;
        mostrarListaPropietario(listadoPropietario,tamanioPropietario,flag);
        IdPropietario=getInt("Ingresa el propietario del que quieras ver sus coches: ",IdPropietario);
        indice=buscarPorIdPropietario(listadoPropietario,tamanioPropietario,IdPropietario);
        if(indice!=-1)
        {
            printf("\nPropietario: %s\n",listadoPropietario[indice].nombre);
            for(i=0; i<tamanioAutomovil; i++)
            {
                if(listadoPropietario[indice].Id==listadoAutomovil[i].idPropietario)
                {
                    cambiarMarcas(listadoAutomovil,listadoAutomovil[i].marca,listadoAutomovil[i].marcaNombre);
                    printf("\nMarca: %s",listadoAutomovil[i].marcaNombre);
                    printf("\nPatente: %s\n",listadoAutomovil[i].patente);
                }
            }
        }
        else
        {
            printf("\nPropietario no encontrado\n");
        }
    }
    else
    {
        printf("\nNo es posible mostrar los automoviles porque no se ha ingresado ninguno");
    }

}

void mostrarPropietarioAudi(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],int tamanioPropietario,int tamanioAutomovil,int flag)
{
    if(flag==1)
    {
        int i;
        int j;
        int flag=0;
        printf("\n\nPropietarios que poseen un coche marca Audi\n");
        printf("ID\tNombre\tTarjeta de credito\tDireccion\n");
        for(i=0; i<tamanioAutomovil; i++)
        {
            if(listadoAutomovil[i].estado==1&&listadoAutomovil[i].marca==3)
            {
                for(j=0; j<tamanioPropietario; j++)
                {
                    if(listadoAutomovil[i].idPropietario==listadoPropietario[j].Id&&listadoPropietario[j].estado==1)
                    {
                        flag=flag+1;
                        printf("%d\t%s\t  %s\t\t%s\n",listadoPropietario[j].Id,listadoPropietario[j].nombre,listadoPropietario[j].tarjeta,listadoPropietario[j].direccion);
                    }
                }
            }
        }
        if(flag==0)
        {
            printf("\nNo hay propietarios que tengan estacionado un coche marca AUDI");
        }
    }
    else
    {
        printf("\nNo es posible mostrar los automoviles porque no se ha ingresado ninguno");
    }
}


void mostrarOrdenadosPorPatente(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],int tamanioPropietario,int tamanioAutomovil,int flag)
{
    if(flag==1)
    {
        eAutomovil auxiliarEstructura;
        eAutomovil estructuraOrdenada[tamanioAutomovil];
        transefrirDatos(listadoAutomovil,estructuraOrdenada,tamanioAutomovil);
        int largo;
        int i;
        int j;
        for(i=0; i<tamanioAutomovil-1; i++)
        {
            for(j=i+1; j<tamanioAutomovil; j++)
            {
                if(strcmp(estructuraOrdenada[i].patente,estructuraOrdenada[j].patente)>0)
                {
                    auxiliarEstructura=estructuraOrdenada[i];
                    estructuraOrdenada[i]=estructuraOrdenada[j];
                    estructuraOrdenada[j]=auxiliarEstructura;
                }
            }
        }
        printf("Id ingreso\tPatente\t  Marca\t\t   Propietario  Id Propietario \n");
        for(i=0; i<tamanioAutomovil; i++)
        {
            if(estructuraOrdenada[i].estado==1)
            {
                for(j=0; j<tamanioPropietario; j++)
                {
                    if(estructuraOrdenada[i].idPropietario==listadoPropietario[j].Id&&listadoPropietario[j].estado==1)
                    {
                        largo=strlen(listadoPropietario[j].nombre);
                        cambiarMarcas(estructuraOrdenada,estructuraOrdenada[i].marca,estructuraOrdenada[i].marcaNombre);
                        printf("\n%d\t\t%s\t  %s\t   %s\t\t",estructuraOrdenada[i].idIngreso,estructuraOrdenada[i].patente,estructuraOrdenada[i].marcaNombre,listadoPropietario[j].nombre);
                        if(largo<5)
                        {
                            printf("\t");
                        }
                        printf("%d",listadoPropietario[j].Id);
                    }
                }
            }
        }
    }
    else
    {
        printf("\nNo es posible mostrar los automoviles porque no se ha ingresado ninguno");
    }

}

void transefrirDatos(eAutomovil listadoAutomovil[],eAutomovil auxiliarAutomovil[],int tamanioAutomovil)
{
    int i;
    for(i=0;i<tamanioAutomovil;i++)
    {
        if(listadoAutomovil[i].estado==1)
        {
            auxiliarAutomovil[i].estado=listadoAutomovil[i].estado;
            auxiliarAutomovil[i].idIngreso=listadoAutomovil[i].idIngreso;
            auxiliarAutomovil[i].idPropietario=listadoAutomovil[i].idPropietario;
            auxiliarAutomovil[i].marca=listadoAutomovil[i].marca;
            strcpy(auxiliarAutomovil[i].marcaNombre,listadoAutomovil[i].marcaNombre);
            strcpy(auxiliarAutomovil[i].patente,listadoAutomovil[i].patente);
        }
    }
}

char validarPatenteIngresada(char patente[])
{
    stringMayusculas(patente);
    int largo;
    largo=strlen(patente);
    int i;
    for(i=0; i<7; i++)
    {
        while(largo!=7)
        {
            getString("\nEl formato de patente debe ser ABC-123 (Incluyendo guion). Ingrese una patente valida ",patente);
            largo=strlen(patente);
            stringMayusculas(patente);
        }
        if(i<3)
        {
            if(patente[i]<'A'||patente[i]>'Z'||patente[i]==' '||patente[i]=='\0'&&patente[i]<'a'&&patente[i]>'z')
            {
                getString("\nEl formato de patente debe ser ABC-123 (Incluyendo guion). Ingrese una patente valida ",patente);
                stringMayusculas(patente);
                largo=strlen(patente);
                i=0;
            }
        }
        else if(i==3)
        {
            if(patente[i]!='-')
            {
                getString("\nEl formato de patente debe ser ABC-123 (Incluyendo guion). Ingrese una patente valida ",patente);
                stringMayusculas(patente);
                largo=strlen(patente);
                i=0;
            }
        }
        else if(i>=4&&i<7)
        {
            if(patente[i]<'0'||patente[i]>'9')
            {
                getString("\nEl formato de patente debe ser ABC-123 (Incluyendo guion). Ingrese una patente valida ",patente);
                stringMayusculas(patente);
                largo=strlen(patente);
                i=0;
            }
        }
    }
    return patente;
}
