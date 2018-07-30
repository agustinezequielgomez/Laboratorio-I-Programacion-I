#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Employee.h"


int parserEmployee(FILE* pFile , ArrayList* pArrayListEmployee)
{
    char nombre[100];
    char apellido[100];
    char id[4];
    char isEmptyString[10];
    int isEmpty;
    int largo;
    Employee* pAuxiliar;
    pFile=fopen("data.csv","r");
    if(pFile!=NULL)
    {
        do
        {
          largo=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,\n]\n",id,nombre,apellido,isEmptyString);
          if(largo==4)
          {
            if(strcmp(isEmptyString,"true")==0)
            {
                pAuxiliar=(Employee*)malloc(sizeof(Employee));
                pAuxiliar->id=atoi(id);
                strcpy(pAuxiliar->name,nombre);
                strcpy(pAuxiliar->lastName,apellido);
                pAuxiliar->isEmpty=1;
                al_add(pArrayListEmployee,pAuxiliar);
            }
          }
          else
          {
              exit(EXIT_FAILURE);
          }
        }
        while(!feof(pFile));
        printf("\nArchivo cargado con exito\n");
    }
    else
    {
        printf("\nNo pudo cargarse el archivo\n");
    }
    fclose(pFile);

    return 0;
}
