#include<stdio.h>
#include"egresos.h"


void menu(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioPropietario,int tamanioAutomovil,int tamanioEgresos)
{
    char seguir='s';
    int valor=0;
    int opcion;
    int indice;
    int flagPropietario=0;
    int flagAutomovil=0;
    int flagEgreso=0;
    inicializarEstadosPropietario(listadoPropietario,tamanioPropietario);
    flagPropietario=cargarHarcodePropietario(listadoPropietario,tamanioPropietario);
    inicializarEstadosAutomovil(listadoAutomovil,tamanioAutomovil);
    flagAutomovil=cargarHarcodeAutomovil(listadoAutomovil,tamanioAutomovil);
    inicializarEgresos(listadoEgresos,tamanioEgresos);
    flagEgreso=egresosHarcode(listadoEgresos);
    do
    {
        printf("MENU PRINCIPAL\n");
        printf("1- Gestionar propietarios");
        printf("\n2- Gestionar automoviles");
        printf("\n3- Recaudaciones");
        printf("\n4- Mostrar datos filtrados");
        printf("\n5- Salir\n");
        opcion=getInt("\nEliga una opcion ",opcion);
        fflush(stdin);
        switch(opcion)
        {
        case 1:
            system("cls");
            printf("MENU DE PROPIETARIOS\n");
            printf("1- Alta propietario");
            printf("\n2- Mostrar propietario");
            printf("\n3- Modificar propietario");
            printf("\n4- Borrar propietario");
            printf("\n5- Salir del menu de propietarios");
            opcion=getInt("\nEliga una opcion ",opcion);
            fflush(stdin);
            switch(opcion)
            {
            case 1:
                indice=buscarLibrePropietario(listadoPropietario,tamanioPropietario);
                flagPropietario=altaPropietario(listadoPropietario,tamanioPropietario,indice);
                break;
            case 2:
                mostrarListaPropietario(listadoPropietario,tamanioPropietario,flagPropietario);
                break;
            case 3:
                modificarPropietario(listadoPropietario,tamanioPropietario,flagPropietario);
                break;
            case 4:
                flagEgreso=darDeBajaPropietario(listadoPropietario,listadoAutomovil,listadoEgresos,tamanioAutomovil,tamanioPropietario,tamanioEgresos,"Esta seguro que quiere dar de baja al propietario? (S/N) ",flagPropietario);
                break;
            case 5:
                break;
            default:
                printf("\nOpcion no encontrada ");
                break;
            }
            break;
        case 2:
            system("cls");
            printf("MENU DE AUTOMOVILES");
            printf("\n1- Alta automovil");
            printf("\n2- Mostrar Automoviles");
            printf("\n3- Egreso automovil");
            printf("\n4- Salir del menu de automoviles");
            opcion=getInt("\nEliga una opcion ",opcion);
            fflush(stdin);
            switch(opcion)
            {
            case 1:
                indice=buscarLibreAutomovil(listadoAutomovil,tamanioAutomovil);
                flagAutomovil=altaAutomovil(listadoAutomovil,listadoPropietario,tamanioAutomovil,tamanioPropietario,indice,flagPropietario);
                break;
            case 2:
                mostrarListaAutomovil(listadoAutomovil,tamanioAutomovil,flagAutomovil);
                break;
            case 3:
                flagEgreso=darDeBajaAutomovil(listadoAutomovil,listadoPropietario,listadoEgresos,tamanioAutomovil,tamanioPropietario,"Estas seguro que queres realizar el egreso de este automovil? (S/N) ",tamanioEgresos,flagAutomovil);
                break;
            case 4:
                break;
            default:
                printf("\nOpcion no encontrada ");
                break;
            }
            break;
        case 3:
            system("cls");
            printf("MENU DE RECAUDACIONES");
            printf("\n1- Mostrar recaudacion total");
            printf("\n2- Mostrar recaudacion por marca");
            printf("\n3- Salir del menu de recaudaciones");
            opcion=getInt("\nEliga una opcion ",opcion);
            fflush(stdin);
            switch(opcion)
            {
            case 1:
                mostrarRecaudaciones(listadoEgresos,tamanioEgresos,1);
                break;
            case 2:
                mostrarRecaudacionesPorMarca(listadoEgresos,tamanioEgresos,1);
                break;
            case 3:
                break;
            default:
                printf("\nOpcion no encontrada ");
                break;
            }
            break;
        case 4:
            system("cls");
            printf("MENU DE DATOS FILTRADOS");
            printf("\n1- Mostrar propietario con sus coches");
            printf("\n2- Mostrar propietarios que posean un coche marca Audi");
            printf("\n3- Autos ordenados por patente");
            printf("\n4- Propietarios ordenados por nombre");
            printf("\n5- Mostrar los propietarios que superan cierta edad");
            printf("\n6- Salir del menu de filtros");
            opcion=getInt("\nEliga una opcion ",opcion);
            fflush(stdin);
            switch(opcion)
            {
            case 1:
                mostrarUsuarioConSusAutomoviles(listadoPropietario,listadoAutomovil,tamanioPropietario,tamanioAutomovil,flagAutomovil);
                break;
            case 2:
                mostrarPropietarioAudi(listadoPropietario,listadoAutomovil,tamanioPropietario,tamanioAutomovil,flagAutomovil);
                break;
            case 3:
                mostrarOrdenadosPorPatente(listadoPropietario,listadoAutomovil,tamanioPropietario,tamanioAutomovil,flagAutomovil);
                break;
            case 4:
                mostrarPropietarioPorNombre(listadoPropietario,tamanioPropietario);
                break;
            case 5:
                mostrarPropietariosSuperanEdad(listadoPropietario,tamanioPropietario);
                break;
            case 6:
                break;
            default:
                printf("\nOpcion no encontrada ");
                break;
            }
            break;
            case 5:
                seguir='n';
                break;
            default:
                printf("\nOpcion no encontrada ");
                break;
        }
        printf("\n");
        system("pause");
        system("cls");
    }
    while(seguir=='s');
}

void inicializarEgresos(eEgreso listadoEgreso[],int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        listadoEgreso[i].estado=0;
    }
}

int idEgresoAutoIncremental(eEgreso listadoEgresos[],int tamanio)
{
    int contador=0;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(listadoEgresos[i].estado==1)
        {
            contador=contador+1;
        }
    }
    return contador+1;
}

int darDeBajaAutomovil(eAutomovil listadoAutomovil[],ePropietario listadoPropietario[],eEgreso listadoEgresos[],int tamanio,int tamanioPropietario,char mensaje[],int tamanioEgreso,int flag)
{
    if(flag==1)
    {
        int Id=0;
        int indice;
        int indicePropietario;
        int retorno;
        fflush(stdin);
        mostrarListaAutomovil(listadoAutomovil,tamanio,flag);
        Id=getInt("\nIngresa el Id de ingreso a dar de baja ",Id);
        indice=buscarPorIdAutomovil(listadoAutomovil,tamanio,Id);
        indicePropietario=buscarPorIdPropietarioAutomovil(listadoAutomovil,listadoPropietario,indice,tamanioPropietario);
        retorno=borrarEntidadAutomovil(listadoAutomovil,listadoPropietario,listadoEgresos,indice,indicePropietario,mensaje,tamanioEgreso);
        return retorno;
    }
    else
    {
        printf("\nPara dar de baja un automovil debe haber alguno ingresado\n");
    }

}

int borrarEntidadAutomovil(eAutomovil listadoAutomovil[],ePropietario listadoPropietario[],eEgreso listadoEgresos[],int indice,int indicePropietario,char mensaje[],int tamanioEgreso)
{
    char pregunta;
    int horas;
    int valor;
    int indiceEgreso;
    if(indice!=-1)
    {
        horas=devolverHorasEstadia();
        valor=tasarEstadia(listadoAutomovil[indice].marca,horas);
        cambiarMarcas(listadoAutomovil,listadoAutomovil[indice].marca,listadoAutomovil[indice].marcaNombre);
        printf("\nNombre del propietario: %s\nPatente del Auto: %s\nMarca del auto: %s\nHoras de estadia: %d\nValor de la estadia: $%d\n",listadoPropietario[indicePropietario].nombre,listadoAutomovil[indice].patente,listadoAutomovil[indice].marcaNombre,horas,valor);
        pregunta=deseaContinuar(mensaje);
        if(pregunta=='s')
        {
            listadoAutomovil[indice].estado=0;
            indiceEgreso=buscarLibreEgresos(listadoEgresos,tamanioEgreso);
            listadoEgresos[indiceEgreso].estado=1;
            listadoEgresos[indiceEgreso].idEgreso=idEgresoAutoIncremental(listadoEgresos,tamanioEgreso);
            listadoEgresos[indiceEgreso].idIngreso=listadoAutomovil[indice].idIngreso;
            listadoEgresos[indiceEgreso].marca=listadoAutomovil[indice].marca;
            listadoEgresos[indiceEgreso].recaudacion=valor;
            listadoEgresos[indiceEgreso].horas=horas;
            return 1;
        }
        return 0;
    }
    else
    {
        printf("\nId no encontrado");
    }
}

int buscarLibreEgresos(eEgreso listadoEgresos[],int tamanio)
{
    int indice;
    int i;
    for(i=0;i<tamanio;i++)
    {
        if(listadoEgresos[i].estado==0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}

void mostrarRecaudaciones(eEgreso listadoEgresos[],int tamanio,int flag)
{
    if(flag==1)
    {
        float egresos=0;
        int i;
        for(i=0; i<tamanio; i++)
        {
            if(listadoEgresos[i].estado==1)
            {
                egresos+=listadoEgresos[i].recaudacion;
            }
        }
        printf("La recaudacion total del estacionamiento es de: $%.2f",egresos);
    }
    else
    {
        printf("\nNo es posible mostrar recaudaciones porque no se realizo ningun egreso");
    }

}

void mostrarRecaudacionesPorMarca(eEgreso listadoEgresos[],int tamanio,int flag)
{
    if(flag==1)
    {
        float alpha=0;
        float ferrari=0;
        float audi=0;
        float otro=0;
        int i;
        for(i=0; i<tamanio; i++)
        {
            if(listadoEgresos[i].estado==1)
            {
                if(listadoEgresos[i].marca==1)
                {
                    alpha+=listadoEgresos[i].recaudacion;
                }
                else if(listadoEgresos[i].marca==2)
                {
                    ferrari+=listadoEgresos[i].recaudacion;
                }
                else if(listadoEgresos[i].marca==3)
                {
                    audi+=listadoEgresos[i].recaudacion;
                }
                else
                {
                    otro+=listadoEgresos[i].recaudacion;
                }

            }
        }
        printf("\nRecaudacion de los coches pertenecientes a la marca Alfa Romeo: $%.2f",alpha);
        printf("\nRecaudacion de los coches pertenecientes a la marca Ferrari: $%.2f",ferrari);
        printf("\nRecaudacion de los coches pertenecientes a la marca Audi: $%.2f",audi);
        printf("\nRecaudacion de los coches pertenecientes a otras marcas: $%.2f",otro);
    }
    else
    {
        printf("\nNo es posible mostrar recaudaciones porque no se realizo ningun egreso");
    }

}

int egresosHarcode(eEgreso listadoEgreso[])
{
    int marca[]= {1,1,2,3,2,2,3,4,1,1};
    float importe[]= {100,200,100,300,100,100,200,200,100,100};
    int idPropietario[]={1,4,3,2,1,2,2,4,3,1};
    int i;
    for(i=0;i<10;i++)
    {
        listadoEgreso[i].marca=marca[i];
        listadoEgreso[i].recaudacion=importe[i];
        listadoEgreso[i].estado=1;
    }
    return 1;
}

int darDeBajaPropietario(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioAutomovil,int tamanioPropietario,int tamanioEgreso,char mensaje[],int flag)
{
    if(flag==1)
    {
        int Id;
        int indice;
        int retorno;
        fflush(stdin);
        mostrarListaPropietario(listadoPropietario,tamanioPropietario,flag);
        Id=getInt("\nIngresa el Id a dar de baja ",Id);
        indice=buscarPorIdPropietario(listadoPropietario,tamanioPropietario,Id);
        retorno=borrarEntidadPropietario(listadoPropietario,listadoAutomovil,listadoEgresos,tamanioAutomovil,indice,tamanioEgreso,mensaje);
        return retorno;
    }
    else
    {
        printf("\nNo es posible dar de baja propietarios porque no hay ninguno ingresado");
    }

}

int borrarEntidadPropietario(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioAutomovil,int indice,int tamanioEgreso,char mensaje[])
{
    int contadorEncontrados=0;
    int valor=0;
    int contadorEgresados=0;
    char pregunta;
    int valorTotal=0;
    int retorno=0;
    int i;
    int horas;
    if(indice!=-1)
    {
        for(i=0; i<tamanioAutomovil; i++)
            if(listadoPropietario[indice].Id==listadoAutomovil[i].idPropietario&&listadoAutomovil[i].estado==1)
            {
                contadorEncontrados=contadorEncontrados+1;
                valor=tasarCochePropietario(listadoPropietario,listadoAutomovil,listadoEgresos,tamanioAutomovil,indice,tamanioEgreso);
                valorTotal=valorTotal+valor;
            }
    }
    printf("\nDebe abonar $%d correspondientes a los %d coches que tiene estacionados",valorTotal,contadorEncontrados);
    pregunta=deseaContinuar("\nDesea dar de baja al propietario? (S/N)");
    if(pregunta=='s')
    {
        listadoPropietario[indice].estado=2;
        printf("\nPropietario dado de baja");
        for(i=0; i<tamanioAutomovil; i++)
        {
            if(listadoPropietario[indice].Id==listadoAutomovil[i].idPropietario&&listadoAutomovil[i].estado==1)
            {
                egresarCochePropietario(listadoPropietario,listadoAutomovil,listadoEgresos,tamanioAutomovil,i,tamanioEgreso,valor,horas);
            }
        }
    }
    else
    {
        printf("\nPropietario no borrado\n");
    }
}




int tasarCochePropietario(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioAutomovil,int indice,int tamanioEgreso)
{
    int horas;
    int valor;
    horas=devolverHorasEstadia();
    valor=tasarEstadia(listadoAutomovil[indice].marca,horas);
    return valor;
}

void egresarCochePropietario(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioAutomovil,int indice,int tamanioEgreso,int valor,int horas)
{
    int indiceEgreso;
    listadoAutomovil[indice].estado=0;
    indiceEgreso=buscarLibreEgresos(listadoEgresos,tamanioEgreso);
    listadoEgresos[indiceEgreso].estado=1;
    listadoEgresos[indiceEgreso].idEgreso=idEgresoAutoIncremental(listadoEgresos,tamanioEgreso);
    listadoEgresos[indiceEgreso].idIngreso=listadoAutomovil[indice].idIngreso;
    listadoEgresos[indiceEgreso].marca=listadoAutomovil[indice].marca;
    listadoEgresos[indiceEgreso].recaudacion=valor;
    listadoEgresos[indiceEgreso].horas=horas;
}

float mostrarMayorTicket(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgreso[],int tamEgreso,int tamAutomovil,int tamPropietario)
{
    int indice;
    int i;
    int indicePropietario;
    int idAutomovil;
    float mayor;
    int flag=1;
    for(i=0;i<tamEgreso;i++)
    {
        if(listadoEgreso[i].estado==1)
        {
            if(flag==1)
            {
                mayor=listadoEgreso[i].recaudacion;
                flag=0;
            }
            else if(flag==0)
            {
                if(listadoEgreso[i].recaudacion>mayor)
                {
                    mayor=listadoEgreso[i].recaudacion;
                    indice=i;
                }
            }
        }
    }
        for(i=0;i<tamAutomovil;i++)
        {
            if(listadoEgreso[indice].idIngreso==listadoAutomovil[i].idIngreso&&listadoAutomovil[i].estado==1)
            {
                idAutomovil=listadoAutomovil[i].idPropietario;
            }
        }
        for(i=0;i<tamPropietario;i++)
        {
            if(listadoPropietario[i].estado==1&&listadoPropietario[i].Id==idAutomovil)
            {
                indicePropietario=i;
            }
        }
    }
    printf("El mayor ticket es de %f",mayor);
    printf("\nEl propietario es");
    mostrarUnoPropietario(listadoPropietario,1,indicePropietario);
    printf("\nSus horas de estadia fueron %d",listadoEgres)
}
