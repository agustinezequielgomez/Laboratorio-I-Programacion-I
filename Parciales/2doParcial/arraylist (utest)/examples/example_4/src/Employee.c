#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>
#include "../inc/Employee.h"

int compareEmployee(void* pEmployeeA,void* pEmployeeB)
{

    if(((Employee*)pEmployeeA)->salary > ((Employee*)pEmployeeB)->salary)
    {
        return 1;
    }
    if(((Employee*)pEmployeeA)->salary < ((Employee*)pEmployeeB)->salary)
    {
        return -1;
    }
    return 0;


}

void* compareIdEmployee(int id)
{
    void* retorno=NULL;
    ArrayList* this;
    Employee* aux;
    int i;
    for(i=0;i<this->size;i++)
    {
        if(this!=NULL)
        {
            if((aux+i)->id==id)
            {
                retorno=al_get(this,i);
                break;
            }
        }
    }
    return retorno;
}

void printAllEmployees(void)
{
    ArrayList* this;
    Employee* aux;
    int i;
    for(i=0;i<=this->size;i++)
    {
        if((this+i)!=NULL)
        {
            aux=al_get(this->pElements,i);
            printEmployee(aux);
        }
    }
}

void printEmployee(Employee* p)
{
    printf("\n\nID %d\nNombre %s\nApellido %s\nSalario %f\nSector %d",p->id,p->name,p->lastName,p->salary,p->sector);
}

void deleteEmployee(void)
{
    void* pEmpleado=NULL;
    int id;
    printAllEmployees();
    getInt("\nIngresa el ID que desees borrar ",&id,"\nEl ID ingresado no es valido, ingreselo nuevamente ");
    pEmpleado=compareIdEmployee(id);
    if(pEmpleado!=NULL)
    {
        free(pEmpleado);
    }
}

/** \brief Set this employee the values recived as parameters
 *
 * \param pEmployee employee*
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [NULL pointer] - (0) if Ok
 *
 */
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector)
{
    Employee* returnAux = NULL;
    Employee* pEmployee = malloc(sizeof(Employee));

    if(pEmployee != NULL)
    {
        pEmployee->id = id;
        strcpy(pEmployee->name,name);
        strcpy(pEmployee->lastName,lastName);
        pEmployee->salary = salary;
        pEmployee->sector = sector;
        pEmployee->isEmpty = 0;
        returnAux = pEmployee;
    }

    return returnAux;

}

void getInt(char mensaje[],int* dato,char mensajeError[])
{
    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    validarEntero(auxstring,dato,mensajeError);
}

void getFloat(char mensaje[],float* dato,char mensajeError[])
{
    char auxstring[100];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    validarFloat(auxstring,dato,mensajeError);
}

void validarFloat(char auxiliar[],float* dato,char mensajeError[])
{
    int validar;
    validar=strlen(auxiliar);
    while(validar==0)
    {
        printf(mensajeError);
        gets(auxiliar);
        validar=strlen(auxiliar);
        fflush(stdin);
    }
    int i;
    for(i=0;i<validar;)
    {
        if(isdigit(auxiliar[i])==0||isspace(auxiliar[i])!=0||validar==0)
        {
            do
            {
                printf(mensajeError);
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
    *(dato)=atof(auxiliar);
}

void getString(char mensaje[],char* dato,char mensajeError[])
{
    char auxstring[500];
    printf("%s",mensaje);
    gets(auxstring);
    fflush(stdin);
    validarString(auxstring,dato,mensajeError);
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

void validarString(char auxiliar[],char* dato,char mensaje[])
{
    int validar;
    validar=strlen(auxiliar);
    int i;
    for(i=0; i<validar;)
    {
        if(validar==0||isspace(auxiliar[0])!=0||isdigit(auxiliar[i])!=0)
        {
            do
            {
                printf(mensaje);
                gets(auxiliar);
                fflush(stdin);
                validar=strlen(auxiliar);
            }
            while(validar==0||isspace(auxiliar[0])!=0||isdigit(auxiliar[i])!=0);
        }
        else
        {
            i+=i;
        }
    }
    strcpy(dato,auxiliar);
}

void employee_setId(Employee* this)
{
    getInt("\nIngrese el ID del empleado ",&this->id,"\nEl ID ingresado no es valido, ingrese uno nuevamente ");
}

void employee_setName(Employee* this)
{
    getString("\nIngrese el nombre del empleado ",&this->name,"\nEl nombre ingresado no es valido, ingreselo nuevamente ");
}

void employee_setLastName(Employee* this)
{
    getString("\nIngrese el apellido del empleado ",&this->lastName,"\nEl apellido ingresado no es valido, ingreselo nuevamente ");
}

void employee_setSalary(Employee* this)
{
    getFloat("\nIngrese el salario del empleado ",&this->salary,"\nEl salario ingresado no es valido, ingreselo nuevamente ");
}

void employee_setSector(Employee* this)
{
    getInt("\nIngrese el sector del empleado ",&this->sector,"\nEl sector ingresado no es valido, ingrese uno nuevamente ");
}

void employee_isEmptySet(Employee* this)
{
    this->isEmpty=1;
}

int employee_getId(Employee* this)
{
    int retorno=-1;
    if(this!=NULL)
    {
        retorno=this->id;
    }
    return retorno;
}

char employee_getName(Employee* this)
{
    char retorno;
    if(this!=NULL)
    {
        retorno=this->name;
        return retorno;
    }
}

char employee_getLastName(Employee* this)
{
    char retorno;
    if(this!=NULL)
    {
        retorno=this->lastName;
        return retorno;
    }
}

int employee_getSector(Employee* this)
{
    int retorno;
    if(this!=NULL)
    {
        retorno=this->sector;
        return retorno;
    }
}

float employee_getSalary(Employee* this)
{
    float retorno;
    if(this!=NULL)
    {
        retorno=this->salary;
        return retorno;
    }
}

Employee* addEmployee(void)
{
    Employee* returnAux=NULL;
    Employee* aux=malloc(sizeof(Employee));
    if(aux!=NULL)
    {
        employee_setId(aux);
        //employee_setName(aux);
        //employee_setLastName(aux);
        employee_setSalary(aux);
        employee_setSector(aux);
        employee_isEmptySet(aux);
        returnAux=aux;
    }
    return returnAux;
}
