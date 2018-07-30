#include "lib.h"


void inicializarClientes(eClient clientes[],int tamC)
{
    int i;

    for(i=0; i<tamC; i++)
    {
        clientes[i].estado=0;
    }

}

void inicializarRenta(eRent rentas[],int tamR)
{
    int i;
    for(i=0; i<tamR; i++)
    {
        rentas[i].idCliente=-1;
        rentas[i].equipo=-1;
        rentas[i].tiempoEstimado=-1;
        rentas[i].estado=-1;
    }
}

int menu(char mensaje[])
{
    int opcion;
    printf("%s",mensaje);
    printf("Ingrese una opcion: ");
    scanf("%d",&opcion);
    printf("\n");
    return opcion;
}

int posicionLibre(eClient clientes[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(clientes[i].estado==0)
            return i;
    }
    return -1;
}

int posicionLibreR(eRent rentas[],int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(rentas[i].estado==0)
            return i;
    }
    return -1;
}



int alta(eClient clientes[],int tam)
{
    char auxStringId[100],auxStringNombre[100], auxStringApellido[100],auxStringDni[100]; // 4 VARIABLES AUXILIARES STRINGS
    int auxId,auxDni,libre;// 3 VARIABLES AUXILIARES ENTERAS
    libre=posicionLibre(clientes,tam);//ASIGNA LA POSICION LIBRE A LA VARIABLE SINO HAY LIBRES ENTREGA -1
    if(libre==-1)//SI LIBRE ES -1 ES POR QUE ESTA LLENO
    {
        printf("Error 404 la base de datos esta llena.\n");
        return 0;
    }
    if(!getStringNumeros("Ingrese ID para crear cliente: ",auxStringId)) // VERIFICACION DEL ID
    {
        printf("El id debe contener solo numeros.\n");
        return 0;
    }
    auxId=atoi(auxStringId);// PASA EL STRING DE ID AL INT
    if(!verificarId(clientes,tam,auxId))// VERIFICACION DEL ID
    {
        printf("El ID ya se encuentra en uso.");
        return 0;
    }
    if(!getStringLetras("Ingrese nombre: ",auxStringNombre)) // VERIFICACION DEL NOMBRE
    {
        printf("El nombre debe contener solo letras.\n");
        return 0;
    }
    if(!getStringLetras("Ingrese apellido: ",auxStringApellido))// VERIFICACION APELLIDO
    {
        printf("El apellido debe contener solo letras.\n");
        return 0;
    }

    if(!getStringNumeros("Ingrese dni para crear cliente: ",auxStringDni)) // VERIFICACION DEL DNI
    {
        printf("El DNI debe contener solo numeros.\n");
        return 0;
    }
    auxDni=atoi(auxStringDni);// PASA EL STRING DE DNI AL INT
    if(!verificarDni(clientes,tam,auxDni))// VERIFICACION DEL DNI
    {
        printf("El ID ya se encuentra en uso.");
        return 0;
    }





    clientes[libre].id=auxId;
    strcpy(clientes[libre].nombre,auxStringNombre);
    strcpy(clientes[libre].apellido,auxStringApellido);
    clientes[libre].dni=auxDni;
    clientes[libre].estado=1;
    return 1;
}

int verificarId(eClient clientes[],int tam,int id)
{
    for(int i=0; i<tam; i++)
    {
        if(clientes[i].id==id) // SI MATCHEA RETORNA FALSO
        {
            return 0;
        }
    }
    return 1;
}

int verificarDni(eClient clientes[],int tam,int dni)
{
    for(int i=0; i<tam; i++)
    {
        if(clientes[i].dni==dni) // SI MATCHEA RETORNA FALSO
        {
            return 0;
        }
    }
    return 1;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);
}

int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}


void hardCodear(eClient clientes[],eRent rentas[])
{
    //AUX CLIENTES
    eClient AuxClientes[5]= {{1,"Lucas","Massa",39456789,1},{2,"Augusto","Alviggi",37852456,1},{3,"Martin","Alberio",40753951,1},{4,"Santiago","Bonasi",41741654,1},{5,"Leandro","Ripo",38274159,1}};
    // CARGA 5 CLIENTES CON EL AUXILIAR
    for(int i=0; i<5; i++)
    {
        clientes[i]=AuxClientes[i];
    }
    //AUX PROYECTOS
    eRent AuxRentas[5]= {{1,101,6.5,"Juan carlos",1},{2,102,10.0,"Roberto",1},{3,103,4.3,"Omar",1},{4,101,2.15,"Eduardo",1},{5,103,4.0,}};
    //CARGA 5 PROYECTOS CON EL AUXILIAR
    for(int i=0; i<5; i++)
    {
        rentas[i]=AuxRentas[i];
    }

}


void rentasxclientes(eClient clientes[],eRent rentas[],int tamC, int tamR)
{




    int k,j;

    for(j=0; j<tamC; j++)
    {
        if(clientes[j].estado==1)
        {
            printf("El cliente [%s %s] posee los siguientes alquileres:\n", clientes[j].nombre,clientes[j].apellido);



            for(k=0; k<tamR; k++)
            {
                if(rentas[k].idCliente == clientes[j].id)
                {




                    if(rentas[k].equipo==101)
                    {
                        printf("Equipo: Amoladora\n");
                        printf("Tiempo estimado de uso: %d\n",rentas[k].tiempoEstimado);
                    }

                    if(rentas[k].equipo==102)
                    {
                        printf("Equipo: Mezcladora\n");
                        printf("Tiempo estimado de uso: %d\n",rentas[k].tiempoEstimado);
                    }
                    if(rentas[k].equipo==103)
                    {
                        printf("Equipo: Taladro\n");
                        printf("Tiempo estimado de uso: %d\n",rentas[k].tiempoEstimado);
                    }
                    printf("\n");

                }
            }


        }

    }

    int modificar(eClient clientes[],eRent rentas[],int tamC,int tamR)
    {
        char auxStringId[100],auxStringNombre[100], auxStringApellido[100],auxStringDni[100]; // 4 VARIABLES AUXILIARES STRINGS
        int auxId,id,auxDni,flag=0;// 3 VARIABLES AUXILIARES ENTERAS
        if(!getStringNumeros("Ingrese ID a modificar: ",auxStringId)) // VERIFICACION DEL ID
        {
            printf("El id debe contener solo numeros.\n");
            return 0;
        }
        id=atoi(auxStringId);// PASA EL STRING DE ID AL INT
        for(int i=0; i<tamC; i++)
        {
            if(id==clientes[i].id && clientes[i].estado==1)
            {
                flag=1;
                switch(menu("¿Que opcion quiere modificar?\n1-ID\n2-Nombre\n3-Apellido\n4-dni\n5-Ninguna\n"))
                {
                case 1:
                    if(!getStringNumeros("ID modificado: ",auxStringId))// VERIFICA EL ID
                    {
                        printf("El id debe tener solo numeros\n");
                        return 0;
                    }
                    auxId=atoi(auxStringId);// PASA LA CADENA A UN ENTERO
                    if(!verificarId(clientes,tamC,auxId))//VERIFICA QUE NO SEA UN ID REPETIDO
                    {
                        printf("Ese ID ya existe.\n");
                        return 0;
                    }
                    clientes[i].id=auxId;
                    break;
                case 2:
                    if(!getStringLetras("Nombre modificado: ",auxStringNombre))//VERIFICA QUE TENGA SOLO LETRAS
                    {
                        printf("El nombre debe tener solo letras.\n");
                        return 0;
                    }
                    strcpy(clientes[i].nombre,auxStringNombre);//COPIA EL AUXILIAR A EL ORIGINAL
                    break;
                case 3:
                    if(!getStringLetras("Apellido modificado: ",auxStringApellido))//VERIFICA QUE TENGA SOLO LETRAS
                    {
                        printf("El nombre debe tener solo letras.\n");
                        return 0;
                    }
                    strcpy(clientes[i].apellido,auxStringApellido);//COPIA EL AUXILIAR A EL ORIGINAL
                    break;
                case 4:
                    if(!getStringNumeros("Dni modificado: ",auxStringDni))// VERIFICA EL ID
                    {
                        printf("El Dni debe tener solo numeros\n");
                        return 0;
                    }
                    auxDni=atoi(auxStringDni);// PASA LA CADENA A UN ENTERO
                    if(!verificarId(clientes,tamC,auxId))//VERIFICA QUE NO SEA UN ID REPETIDO
                    {
                        printf("Ese Dni ya existe.\n");
                        return 0;
                    }
                    clientes[i].dni=auxDni;
                    break;

                default:
                    printf("Modificacion cancelada");
                    return 0;
                    break;
                }
            }
        }
        if(!flag)// FLAG DE CONTROL PARA VER SI NO ENCONTRO EL IF
        {
            printf("No se encuentra el ID ingresado.\n");
            return 0;
        }
        return 1;
    }

    int nuevoAlquiler(eClient clientes[],eRent rentas[],int tamC,int tamR)
    {
        char auxOperador[100];
        int auxId,libre;// VARIABLES AUXILIARES ENTERAS
        int auxTime;// VARIABLE AUXILIAR DE TIEMPO
        libre=posicionLibreR(rentas,tamR);//ASIGNA LA POSICION LIBRE A LA VARIABLE SI NO HAY LIBRES ENTREGA -1
        if(libre==-1)//SI LIBRE ES -1 ES POR QUE ESTA LLENO
        {
            printf("Error 404 la base de datos esta llena.\n");
            return 0;
        }

        printf("Ingrese ID del cliente que desea alquilar: \n");
        scanf("%d",&auxId);

        if(clientes[auxId].estado==0)
        {
            printf("El cliente no existe");
            return 0;
        }

        if(clientes[auxId].estado==1)
        {
            printf("El cliente [%s %s] desea realizar un nuevo alquiler.\n",clientes[auxId].nombre,clientes[auxId].apellido);

            switch(menu("\nSeleccione el equipo que desea alquilar:\n1:Amoladora\n2:Mezcladora\n3:Taladro\n"))
            {
            case 1:
                rentas[libre].equipo=101;
                break;
            case 2:
                rentas[libre].equipo=102;
                break;
            case 3:
                rentas[libre].equipo=103;
                break;
            }

            printf("\nIngrese la cantidad de horas estimado del alquiler: \n");
            scanf("%d",&auxTime);
            rentas[auxId].tiempoEstimado=auxTime;

            getStringLetras("Ingrese el nombre del operador:\n",auxOperador);
            strcpy(rentas[auxId].operador,auxOperador);
            rentas[libre].estado=1;






        }


        printf("Cliente: %s %s\n",clientes[auxId].nombre,clientes[auxId].apellido);
        printf("Equipo alquilado:\n");

        if(rentas[libre].equipo==101)
        {
            printf("\nEquipo: Amoladora\n");
            printf("\nTiempo estimado de uso: %d\n",rentas[libre].tiempoEstimado);
        }

        if(rentas[libre].equipo==102)
        {
            printf("\nEquipo: Mezcladora\n");
            printf("\nTiempo estimado de uso: %d\n",rentas[libre].tiempoEstimado);
        }
        if(rentas[libre].equipo==103)
        {
            printf("\nEquipo: Taladro\n");
            printf("\nTiempo estimado de uso: %d\n",rentas[libre].tiempoEstimado);
        }

        system("pause");
        system("cls");
        return 1;
    }
