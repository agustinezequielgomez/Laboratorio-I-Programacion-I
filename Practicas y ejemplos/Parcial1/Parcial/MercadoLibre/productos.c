#include<stdio.h>
#include<stdlib.h>
#include"productos.h"

void inicializarEstadosProducto(eProducto listadoProducto[],int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        listadoProducto[i].estado=0;
    }
}

void cargarHarcodeProducto(eProducto listadoProducto[],int tamanio)
{
    char nombre[20][50]= {"Alberto","Jose","Maria","Pepe","Julian","Camila","Victoria","Selene","Juan Cruz","Nicolas","Franco","Ciro","Ezequiel","Emanuel","Alejandro","Matias","Carlos","Natan","David","Francisco"};
    int dni[20]= {42589785,23456978,10457863,32014756,42147544,52333457,24965784,30145965,29771276,16279490,14575887,10476685,16686238,41371597,10385485,41754221,19373276,4385555,10173055,3073077};
    int edad[20]= {15,25,12,100,97,3,46,92,24,96,43,83,25,89,41,79,97,37,21,28};
    char direccion[20][50]= {"Beron de Astrada 4589","Montiel 154","Ana Diaz 892","Guamini 6600","Fructuoso Rivera 9785","Corrales 4788","Tabare 1024","Avenida Roca 6658","Timoteo Gordillo 9785","Cañada de Gomez 7845","Cosquin 1290","Itaqui 785","Avenida Cruz 2300","Chilavert 1900","Jose Leon Suarez 9800","Ferre 800","Soldado de la Frontera 3000","Madariaga 1200","Unanue 3300","Avenida Mitre 750"};
    int telefono[20]= {39665247,46057895,22367458,66654897,10456964,46222596,78453256,34521689,11169878,45567785,37894563,22224458,66697852,22364415,77829953,82930100,05126472,55962232,47859965,88956621};
    char apellido[20][50]= {"Gomez","Godinez","Fernandez","Vargas","Bardini","Galli","Rios Taurasi","Vitale","Pacheco","Jimenez","Quispe","Lezano","Velazco","Gonzalez","Sinay","Gasbarro","Estarque","Acuña","Vecchio","Brienza"};
    int i;
    for(i=0; i<20; i++)
    {
        strcpy(listadoProducto[i].nombre,nombre[i]);
        listadoProducto[i].Id=edad[i];
        listadoProducto[i].estado=1;
    }
}

void menu(eUsuario listadoUsuario[],eProducto listadoProducto[],int tamanio,int tamanioProducto)
{
    inicializarEstadosUsuario(listadoUsuario,tamanio);
    inicializarEstadosProducto(listadoProducto,tamanioProducto);
    //cargarHarcode(listadoUsuario,tamanio);
    char seguir='s';
    int opcion;
    int indice;
    int contador=0;
    do
    {
        printf("1- Agregar usuario");
        printf("\n2- Modificar usuario");
        printf("\n3- Borrar usuario");
        printf("\n4- Publicar producto");
        printf("\n5- Modificar producto");
        printf("\n6- Borrar producto");
        printf("\n7- Comprar producto");
        printf("\n8- Mostrar uno a muchos");
        printf("\n9- Salir\n");
        scanf("%d",&opcion);
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            indice=buscarLibreUsuario(listadoUsuario,tamanio);
            altaUsuario(listadoUsuario,tamanio,indice);
            break;
        case 2:
            modificarUsuario(listadoUsuario,tamanio);
            break;
        case 3:
            darDeBajaUsuario(listadoUsuario,listadoProducto,tamanio,tamanioProducto,"\nEstas seguro que queres dar de baja este usuario? (S/N) ");
            break;
        case 4:
            indice=buscarLibreProducto(listadoProducto,tamanioProducto);
            altaProducto(listadoProducto,listadoUsuario,tamanio,tamanioProducto,indice);
            break;
        case 5:
            modificarProducto(listadoProducto,listadoUsuario,tamanio,tamanioProducto);
            break;
        case 6:
            darDeBajaProducto(listadoProducto,listadoUsuario,tamanio,tamanioProducto,"Estas seguro de que queres borrar este producto? (S/N) ");
            break;
        case 7:
            comprarProducto(listadoUsuario,listadoProducto,tamanio,tamanioProducto);
            break;
        case 8:
            mostrarListaUsuario(listadoUsuario,tamanio);
            break;
        case 9:
            mostrarListaProducto(listadoProducto,tamanioProducto);
            break;
        }
        if(seguir!='n')
        {
            seguir=deseaContinuar("\nDesea continuar con el programa? (S/N) ");

        }

        system("cls");
    }
    while(seguir=='s');
}

void altaProducto(eProducto listadoProducto[],eUsuario listadoUsuario[],int tamanio,int tamanioProducto,int indice)
{
    int id;
    int subindice;
    if(indice!=-1)
    {
        mostrarListaUsuario(listadoUsuario,tamanio);
        id=getInt("Ingresa el ID de usuario para publicar un producto ",id);
        fflush(stdin);
        subindice=buscarPorIdUsuario(listadoUsuario,tamanio,id);
        if(subindice!=-1)
        {
            listadoProducto[indice].estado=1;
            getString("Ingresa tu nombre de Producto ",listadoProducto[indice].nombre);
            stringToUpper(listadoProducto[indice].nombre);
            listadoProducto[indice].precio=getFloat("Ingresa el precio de tu producto ",listadoProducto[indice].precio);
            listadoProducto[indice].stock=getInt("Ingresa el stock del producto ",listadoProducto[indice].stock);
            listadoProducto[indice].Id=idAutoIncrementalProducto(listadoProducto,tamanioProducto);
            listadoProducto[indice].IdUsuario=listadoUsuario[subindice].Id;
        }

    }
    else
    {
        printf("\nNo hay lugares libres");
    }
}

int buscarLibreProducto(eProducto listadoProducto[],int tamanio)
{
    int indice;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listadoProducto[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

int idAutoIncrementalProducto(eProducto listadoProducto[],int tamanio)
{
    int contador=0;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(listadoProducto[i].estado==1||listadoProducto[i].estado==2)
        {
            contador=contador+1;
        }
    }
    return contador;
}

void mostrarUnoProducto(eProducto listadoProducto[],int tamanio,int i)
{
    printf("\n\nNombre: %s\nPrecio: %f\nStock: %d\nId: %d",listadoProducto[i].nombre,listadoProducto[i].precio,listadoProducto[i].stock,listadoProducto[i].Id);
}

void mostrarListaProducto(eProducto listadoProducto[],int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listadoProducto[i].estado==1)
        {
            mostrarUnoProducto(listadoProducto,tamanio,i);
        }

    }
}

void modificarProducto(eProducto listadoProducto[],eUsuario listadoUsuario[],int tamanio,int tamanioProducto)
{
    fflush(stdin);
    int Id;
    int indice;
    int opcion;
    mostrarUnoConMuchos(listadoUsuario,tamanio,listadoProducto,tamanioProducto);
    Id=getInt("\nIngresa el ID de producto que quieras modificar \n",opcion);
    Id=buscarPorIdProducto(listadoProducto,tamanioProducto,Id);
    fflush(stdin);
    if(Id!=-1)
    {
        opcion=getInt("Que queres modificar?\n1- Precio\n2- Stock\n ",opcion);
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            listadoProducto[Id].precio=getFloat("Ingresa el nuevo precio ",listadoProducto[Id].precio);
            break;
        case 2:
            listadoProducto[Id].stock=getInt("Ingresa el nuevo stock ",listadoProducto[Id].stock);
            break;
        }
    }

}

int buscarPorIdProducto(eProducto listadoProducto[],int tamanio,int id)
{
    int indice=-1;
    int i;
    for(i=0; i<tamanio; i++)
    {
        if(listadoProducto[i].estado==1)
        {
            if(listadoProducto[i].Id==id)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;
}

char modificarStringProducto(eProducto listadoProducto[],int indice,char caracter[])
{
    if(indice!=-1)
    {
        getString("\nIngresa el nuevo dato: ",caracter);
        stringToUpper(caracter);
    }
    else
    {
        printf("\nId no encontrado");
    }
}

int modificarEnteroProducto(eProducto listadoProducto[],int indice,int dato)
{
    if(indice!=-1)
    {
        getInt("\nIngresa el nuevo dato: ",dato);
    }
    else
    {
        printf("\nId no encontrado");
    }
}

float modificarFlotanteProducto(eProducto listadoProducto[],int indice,float dato)
{
    if(indice!=-1)
    {
        getFloat("\nIngresa el nuevo dato: ",dato);
    }
    else
    {
        printf("\nId no encontrado");
    }
}

void darDeBajaProducto(eProducto listadoProducto[],eUsuario listadoUsuario[],int tamanio,int tamanioProducto,char mensaje[])
{
    int Id;
    int indice;
    fflush(stdin);
    mostrarUnoConMuchos(listadoUsuario,tamanio,listadoProducto,tamanioProducto);
    Id=getInt("\nIngresa el Id a dar de baja ",Id);
    indice=buscarPorIdProducto(listadoProducto,tamanio,Id);
    borrarEntidadProducto(listadoProducto,indice,mensaje);
}

void borrarEntidadProducto(eProducto listadoProducto[],int indice,char mensaje[])
{
    char pregunta;
    if(indice!=-1)
    {
        pregunta=deseaContinuar(mensaje);
        if(pregunta=='s')
        {
            listadoProducto[indice].estado=2;
        }

    }
    else
    {
        printf("\nId no encontrado");
    }
}

void darDeBajaUsuario(eUsuario listadoUsuario[],eProducto listadoProducto[],int tamanio,int tamanioProducto,char mensaje[])
{
    int Id;
    int indice;
    fflush(stdin);
    mostrarListaUsuario(listadoUsuario,tamanio);
    Id=getInt("\nIngresa el Id a dar de baja ",Id);
    indice=buscarPorIdUsuario(listadoUsuario,tamanio,Id);
    borrarEntidadUsuario(listadoUsuario,listadoProducto,tamanioProducto,indice,mensaje);
}

borrarEntidadUsuario(eUsuario listadoUsuario[],eProducto listadoProducto[],int tamanioProducto,int indice,char mensaje[])
{
    int i;
    char pregunta;
    if(indice!=-1)
    {
        pregunta=deseaContinuar(mensaje);
        if(pregunta=='s')
        {
            listadoUsuario[indice].estado=2;
            for(i=0;i<tamanioProducto;i++)
            {
                if(listadoUsuario[indice].Id==listadoProducto[i].IdUsuario)
                {
                    listadoProducto[i].estado=2;
                }
            }
        }

    }
    else
    {
        printf("\nId no encontrado");
    }
}

void mostrarUnoConMuchos(eUsuario listadoUsuario[],int tamanio,eProducto listadoProducto[],int tamanioProducto)
{
    int i;
    int j;
    for(i=0; i<tamanio; i++)
    {
        if(listadoUsuario[i].estado==1)
        {
            printf("\n\nUsuario: %s",listadoUsuario[i].nombre);
            for(j=0; j<tamanioProducto; j++)
            {
                if(listadoProducto[j].IdUsuario==listadoUsuario[i].Id&&listadoProducto[j].estado==1)
                {
                    printf("\n      Nombre  %s\n       Precio %f\n       Stock %d\n      Id %d\n",listadoProducto[j].nombre,listadoProducto[j].precio,listadoProducto[j].stock,listadoProducto[j].Id);
                }
            }
        }
    }
}


void comprarProducto(eUsuario listadoUsuario[],eProducto listadoProducto[],int tamanio,int tamanioProducto)
{
    int Id;
    int indice;
    int stock;
    mostrarListaProducto(listadoProducto,tamanioProducto);
    Id=getInt("Ingresa el producto que deseas comprar ",Id);
    indice=buscarPorIdProducto(listadoProducto,tamanioProducto,Id);
    if(indice!=-1)
    {
        stock=getInt("Cuantas unidaddes deseas comprar? ",stock);
        if(stock<=listadoProducto[indice].stock)
        {
            listadoUsuario[indice].calificacion=getFloat("Compra realizada. Por favor, ingresa una calificacion para el vendedor: ",listadoUsuario[indice].calificacion);
        }
        else
        {
            printf("\nStock insuficiente");
        }
    }
    else
    {
        printf("\nProducto no encontrado");
    }
}
