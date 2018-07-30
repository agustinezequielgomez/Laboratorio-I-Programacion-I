#include "Localidad.h"

void loc_MostrarUno(eLocalidad aux)
{
    printf("\nId: %d Nombre: %s ",aux.id,aux.nombreLocalidad);
}

void loc_MostrarListado(eLocalidad listado[],int arrayLenght)
{
    int i;
    for(i=0;i<arrayLenght;i++)
    {
        printf("%s",listado[i].nombreLocalidad);
    }
}

void loc_Alta(eLocalidad listado [],int largo)
{
    int i;
    for(i=0;i<largo;i++)
    {
        printf("Ingresa el Id: ");
        scanf("%d",&listado[i].id);
        printf("Ingresa el nombre de la localidad ");
        scanf("%s",listado[i].nombreLocalidad);
        listado[i].estado=1;
    }
}

void loc_Baja(eLocalidad listado [],int largo,int idParaBorrar)
{
    int i;
    for(i=0;i<largo;i++)
    {
        if(listado[i].id==idParaBorrar)
        {
            listado[i].estado=0;
            listado[i].id=0;
            strcpy(listado[i].nombreLocalidad,"");
            printf("Localidad dada de baja");
            break;
        }
    }
}

void loc_ordenarDescPorNombre(eLocalidad listado [],int largo)
{

    int i;
    int j;
    char auxiliarChar[20];
    int auxiliarInt;
    for(i=0;i<largo-1;i++)
    {
        for(j=i+1;j<largo;j++)
        {
            if(strcmp(listado[i].nombreLocalidad,listado[j].nombreLocalidad)>0)
            {
                strcpy(auxiliarChar,listado[i].nombreLocalidad);
                strcpy(listado[i].nombreLocalidad,listado[j].nombreLocalidad);
                strcpy(listado[j].nombreLocalidad,auxiliarChar);

                auxiliarInt=listado[i].id;
                listado[i].id=listado[j].id;
                listado[j].id=auxiliarInt;
            }
        }
    }
    printf("\nLocalidades ordenadas alfabeticamente (A-Z)\n");
}

void loc_ordenarDescPorID(eLocalidad listado [],int largo)
{
    int i;
    int j;
    char auxiliarChar[20];
    int auxiliarInt;
    for(i=0;i<largo-1;i++)
    {
        for(j=i+1;j<largo;j++)
        {
            if(listado[i].id>listado[j].id)
            {
                auxiliarInt=listado[i].id;
                listado[i].id=listado[j].id;
                listado[j].id=auxiliarInt;

                strcpy(auxiliarChar,listado[i].nombreLocalidad);
                strcpy(listado[i].nombreLocalidad,listado[j].nombreLocalidad);
                strcpy(listado[j].nombreLocalidad,auxiliarChar);
            }
        }
    }
}

int loc_pedirId(eLocalidad listado[],int largo)
{
    int Id;
    loc_MostrarListado(listado,largo);
    printf("Ingresa el Id para realizar la modificacion ");
    scanf("%d",&Id);
    return Id;
}

int loc_menu(void)
{
    int respuesta;
    printf("\n1- ALTA\n2- MOSTRAR\n3- BAJA\n4- MODIFICACION\n5- ORDENAR POR NOMBRE\6- ORDENAR POR ID\nElegir una opcion ");
    scanf("%d",&respuesta);
    return respuesta;
}

void loc_opcion(eLocalidad listado[],int largo,int respuesta)
{
    int Id;
       switch(respuesta)
    {
        case 1:
            loc_Alta(listado,largo);
            break;
        case 2:
            loc_MostrarListado(listado,largo);
            break;
        case 3:
            loc_Baja(listado,largo,Id);
            break;
        case 4:
            //loc_Modificacion();
            break;
        case 5:
            loc_ordenarDescPorNombre(listado,largo);
            break;
        case 6:
            loc_ordenarDescPorID(listado,largo);
    }
}
