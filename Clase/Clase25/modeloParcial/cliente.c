#include"cliente.h"
#include"stdio.h"

void getInt(char mensaje[],int* dato,char mensajeError[])
{
    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    validarEntero(auxstring,dato,mensajeError);
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
            return;
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
                    return;
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

void cliente_set_id(cliente* aux)
{
    getInt("\nIngresa tu dni ",&aux->dni,"\nDNI invalido ");
}

void cliente_set_turno(cliente* aux, int opcion)
{
    aux->turno=opcion;
}

void cliente_set_estado(cliente* aux)
{
    aux->estado=1;
}

void add_cliente(ArrayList* urgente, ArrayList* regular, ArrayList* listaCliente,int opcion)
{
    cliente* aux;
    aux=(cliente*)malloc(sizeof(cliente));
    if(aux!=NULL)
    {
        cliente_set_id(aux);
        cliente_set_turno(aux,opcion);
        cliente_set_estado(aux);
        set_numero_turno(urgente,regular,aux,opcion);
        al_add(listaCliente,aux);
        parserWriteCliente(listaCliente);
        if(opcion==1)
        {
            addUrgente(urgente,aux);
        }
        else if(opcion==2)
        {
            addRegular(regular,aux);
        }
        printf("\nTu numero de turno es %d",aux->numeroTurno);
    }

}

void set_numero_turno(ArrayList* urgente,ArrayList* regular, cliente* aux,int opcion)
{
    int contador=0;
    int i;
    if(urgente!=NULL&&regular!=NULL&&aux!=NULL)
    {
        if(opcion==1)
        {
            for(i=0; i<al_len(urgente); i++)
            {
                contador=contador+1;
            }
        }
        else if(opcion==2)
        {
            for(i=0; i<al_len(regular); i++)
            {
                contador=contador+1;
            }
        }
        aux->numeroTurno=contador+1;
    }
}

void menu()
{
    ArrayList* cliente;
    ArrayList* urgente;
    ArrayList* regulares;
    cliente=al_newArrayList();
    urgente=al_newArrayList();
    regulares=al_newArrayList();
    parserReadCliente(cliente);
    parserReadRegular(regulares);
    parserReadUrgente(urgente);
    int opcion;
    char continuar='s';
    do
    {
        printf("\n1- Tramite urgente");
        printf("\n2- Tramite regular");
        printf("\n3- Proximo cliente");
        printf("\n4- Listar pendientes");
        printf("\n5- Listar atendidos");
        printf("\n9- Salir");
        getInt("\nElegi una opcion ",&opcion,"\nOpcion invalida ");
        switch(opcion)
        {
        case 1:
            add_cliente(urgente,regulares,cliente,opcion);
            printf("\n");
            system("pause");
            break;
        case 2:
            add_cliente(urgente,regulares,cliente,opcion);
            printf("\n");
            system("pause");
            break;
        case 3:
            getProximoTurno(urgente,regulares,cliente);
            printf("\n");
            system("pause");
            break;
        case 4:
            listarPendientes(urgente,regulares);
            printf("\n");
            system("pause");
            break;
        case 5:
            listarAtendidos(cliente);
            printf("\n");
            system("pause");
            break;
        case 9:
            continuar='n';
            break;
        }
        system("cls");
    }
    while(continuar=='s');
}

void getProximoTurno(ArrayList* listaUrgente, ArrayList* listaRegular, ArrayList* listaCliente)
{
    int indice;
    int i;
    int proximoTurno=-1;
    int flag=-1;
    int dni=-1;
    urgente* aux;
    regular* auxRegu;
    for(i=0;i<al_len(listaUrgente);i++)
    {
        aux=al_get(listaUrgente,i);
        if(aux!=NULL&&aux->estadoAtencion==1)
        {
            proximoTurno=aux->id;
            aux->estadoAtencion=2;
            dni=aux->clienteDni;
            parserWriteUrgente(listaUrgente);
            atenderCliente(listaCliente,aux->clienteDni);
            break;
        }
    }
    if(proximoTurno==-1)
    {
        for(i=0;i<al_len(listaRegular);i++)
        {
            auxRegu=al_get(listaRegular,i);
            if(auxRegu!=NULL&&auxRegu->estadoAtencion==1)
            {
                flag=0;
                proximoTurno=auxRegu->id;
                dni=auxRegu->clienteDni;
                auxRegu->estadoAtencion=2;
                parserWriteRegular(listaRegular);
                atenderCliente(listaCliente,auxRegu->clienteDni);
                break;
            }
        }
    }
    if(flag==-1)
    {
        printf("\nEl proximo es el Nº %d de tipo URGENTE (Cliente DNI %d)\n",proximoTurno,dni);
    }
    else if(flag==0)
    {
        printf("\nEl proximo es el Nº %d de tipo REGULAr (Cliente DNI %d)\n",proximoTurno,dni);
    }
}

void listarPendientes(ArrayList* listaUrgentes, ArrayList* listaRegulares)
{
    regular* aux;
    urgente* auxurgente;
    int i;
    if(listaRegulares!=NULL&&listaUrgentes!=NULL)
    {
        printf("\nUsuarios urgentes pendientes");
        printf("\nDNI\tN Turno");
        for(i=0;i<al_len(listaUrgentes);i++)
        {
            auxurgente=al_get(listaUrgentes,i);
            if(auxurgente->estadoAtencion==1)
            {
                printf("\n%d\t%d",auxurgente->clienteDni,auxurgente->id);
            }
        }
        printf("\nUsuarios regulares pendientes");
        printf("\nDNI\tN Turno");
        for(i=0;i<al_len(listaRegulares);i++)
        {
            aux=al_get(listaRegulares,i);
            if(aux->estadoAtencion==1)
            {
                printf("\n%d\t%d",aux->clienteDni,aux->id);
            }
        }
    }
}

void listarAtendidos(ArrayList* listaClientes)
{
    void* lista;
    lista=al_clone(listaClientes);
    cliente* aux;
    int i;
    if(listaClientes!=NULL&&listaClientes!=NULL)
    {
        al_sort(listaClientes,compararDni,0);
        printf("\nUsuarios urgentes atendidos");
        printf("\nDNI\tN Turno");
        for(i=0;i<al_len(listaClientes);i++)
        {
            aux=al_get(listaClientes,i);
            if(aux->estado==2&&aux->turno==1&&aux!=NULL)
            {
                printf("\n%d\t%d",aux->dni,aux->numeroTurno);
            }
        }
        printf("\nUsuarios regulares atendidos");
        printf("\nDNI\tN Turno");
        for(i=0;i<al_len(listaClientes);i++)
        {
            aux=al_get(listaClientes,i);
            if(aux->estado==2&&aux->turno==2&&aux!=NULL)
            {
                printf("\n%d\t%d",aux->dni,aux->numeroTurno);
            }
        }
    }
}

int compararDni(void* dni1,void* dni2)
{
    cliente* pEl1;
    cliente* pEl2;
    pEl1=(cliente*)dni1;
    pEl2=(cliente*)dni2;
    if(pEl1->dni>pEl2->dni)
    {
        return 1;
    }
    else if(pEl1->dni<pEl2->dni)
    {
        return -1;
    }
}

int buscarDni(void* elemento, ArrayList* listaClientes)
{
    cliente* aux;
    int i;
    for(i=0;i<al_len(listaClientes);i++)
    {
        aux=al_get(listaClientes,i);
        if(aux!=NULL&&aux->dni==elemento)
        {
            return i;
        }
    }
}

void atenderCliente(ArrayList* listaCliente, void* elemento)
{
    int indice;
    cliente* auxCliente;
    indice=buscarDni(elemento,listaCliente);
    auxCliente=al_get(listaCliente,indice);
    auxCliente->estado=2;
    parserWriteCliente(listaCliente);
}
