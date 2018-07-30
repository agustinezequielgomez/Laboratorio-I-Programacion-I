#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"

//Funcion que se le pasa al sort
int employee_compare(void* pEmployeeA,void* pEmployeeB)
{
    Employee* empleado1;
    Employee* empleado2;
    empleado1=(Employee*)pEmployeeA;
    empleado2=(Employee*)pEmployeeB;
    int retorno;
    retorno=strcmp(empleado1->name,empleado2->name);
    return retorno;
}


void employee_print(Employee* this)
{
    printf("\nNombre %s\nApellido %s\nID %d\n",this->name,this->lastName,this->id);
}


Employee* employee_new(void)
{

    Employee* returnAux = NULL;

    return returnAux;

}

void employee_delete(Employee* this)
{


}

int employee_getId(Employee* this)
{

    return 0;

}

void menu(void)
{
    ArrayList* lista;
    lista=al_newArrayList();
    Employee* aux;
    FILE* pFile;
    char seguir='s';
    int opcion=0;
    int cantidad;
    int i;
    do
    {
        printf("\n1- Cargar archivo");
        printf("\n2- Listar empleados");
        printf("\n3- Ordenar por nombre");
        printf("\n4- Agregar elemento");
        printf("\n5- Eliminar elemento");
        printf("\n6- Listar empleados");
        getInt("\nIngresa una opcion ",&opcion,"\nLa opcion ingresada no es valida. Ingrese una nuevamente ");
        switch(opcion)
        {
        case 1:
            parserEmployee(pFile,lista);
            system("pause");
            break;
        case 2:
            cantidad=al_len(lista);
            for(i=0;i<cantidad;i++)
            {
                aux=al_get(lista,i);
                employee_print(aux);
            }
            system("pause");
            break;
        case 3:
            al_sort(lista,employee_compare,1);
            cantidad=al_len(lista);
            for(i=0;i<cantidad;i++)
            {
                aux=al_get(lista,i);
                employee_print(aux);
            }
            system("pause");
            break;
        case 4:
            new_empleado(lista);
            system("pause");
            break;
        case 5:
            break;
        case 6:
            break;
        }
        system("cls");
    }
    while(seguir=='s');
}

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
    int validar;
    validar=strlen(auxiliar);
    while(validar==0)
    {
        printf(mensaje);
        gets(auxiliar);
        validar=strlen(auxiliar);
        fflush(stdin);
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

void getString(char mensaje[],char* dato,char mensajeError[])
{
    char auxstring[500];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    validarString(auxstring,dato,mensajeError);
}

void validarString(char auxiliar[],char* dato,char mensaje[])
{
    int validar;
    validar=strlen(auxiliar);
    while(validar==0||isspace(auxiliar[0])!=0)
    {
        printf(mensaje);
        gets(auxiliar);
        fflush(stdin);
        validar=strlen(auxiliar);
    }
    strcpy(dato,auxiliar);
}

int employee_setId(Employee* this)
{
    getInt("\nIngresa el ID ",&this->id,"El ID ingresado no es valido. Ingrese uno nuevamente ");
}

void employee_setName(Employee* this)
{
    getString("\nIngresa el nombre del empleado ",this->name,"\nEl nombre ingresado no es valido. Ingrese uno nuevamente ");
}

void employee_setLastName(Employee* this)
{
    getString("\nIngresa el apellido del empleado ",this->lastName,"\nEl apellido ingresado no es valido. Ingrese uno nuevamente ");
}

void employee_setState(Employee* this)
{
    this->isEmpty=1;
}

void new_empleado(ArrayList* pList)
{
    Employee* aux;
    aux=(Employee*)malloc(sizeof(Employee));
    if(aux!=NULL)
    {
        employee_setId(aux);
        employee_setName(aux);
        employee_setLastName(aux);
        employee_setState(aux);
        al_add(pList,aux);
        printf("\nEmpleado guardado con exito");
    }
    else
    {
        printf("\nNo pudo darse de alta al empleado");
    }
}

void delete_employee(ArrayList* pList)
{
    int id;
    int cantidad;
    cantidad=al_len(pList);
    Employee* aux;
    int i;
    for(i=0;i<cantidad;i++)
    {
        aux=al_get(pList,i);
        employee_print(aux);
    }
    getInt("Ingresa el ID del empleado a eliminar ",&id,"El ID ingresado no es valido, ingrese uno nuevamente ");

}

int employee_compare_ID(int id)
{
    Employee* aux;

}
