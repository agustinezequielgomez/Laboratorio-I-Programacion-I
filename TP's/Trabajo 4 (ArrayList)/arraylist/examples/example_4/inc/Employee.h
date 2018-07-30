/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include"ArrayList.h"
#ifndef __EMPLOYEE
#define __EMPLOYEE
struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef Employee;
#endif // __EMPLOYEE

void* compareIdEmployee(int id);
int compareEmployee(void* pEmployeeA,void* pEmployeeB);
void printEmployee(Employee* p);
void printAllEmployees(void);
void deleteEmployee(void);
Employee* addEmployee(void);
Employee* newEmployee(int id, char name[],char lastName[],float salary,int sector);
void employee_setId(Employee* this);
void employee_setName(Employee* this);
void employee_setLastName(Employee* this);
void employee_setSalary(Employee* this);
void employee_setSector(Employee* this);
void employee_isEmptySet(Employee* this);
int employee_getId(Employee* this);
char employee_getName(Employee* this);
char employee_getLastName(Employee* this);
int employee_getSector(Employee* this);
float employee_getSalary(Employee* this);
/** \brief Funcion que recibe un numero y lo valida
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param dato int* Puntero a donde se va a guardar el dato
 * \param mensajeError[] char Mensaje de error que se va a mostrar en caso de que el dato sea invalido
 * \return void
 *
 */
void getInt(char mensaje[],int* dato,char mensajeError[]);

/** \brief Funcion que recibe un string y lo valida
 *
 * \param mensaje[] char MEnsaje que se le muestra al usuario
 * \param dato char* Puntero a donde se va a guardar el dato
 * \param mensajeError[] char Mensaje de error que se va a mostrar en caso de que el dato sea invalido
 * \return void
 *
 */
void getString(char mensaje[],char* dato,char mensajeError[]);

/** \brief Funcion que valida un entero ingresado
 *
 * \param auxiliar[] char Cadena de caracteres que se usa para validar
 * \param dato int* Puntero al dato a validar
 * \param mensaje[] char Mensaje que se muestra en caso de que el dato ingresado sea incorrecto
 * \return void
 *
 */
void validarEntero(char auxiliar[],int* dato,char mensaje[]);

/** \brief Funcion que valida el string ingresado por el usuario
 *
 * \param auxiliar[] char Cadena de caracteres que se usa para validar
 * \param dato char* Puntero al dato que se va a validar
 * \param mensaje[] char Mensaje que se muestra en caso de que el dato ingresado sea incorrecto
 * \return void
 *
 */
void validarString(char auxiliar[],char* dato,char mensaje[]);

void getFloat(char mensaje[],float* dato,char mensajeError[]);

void validarFloat(char auxiliar[],float* dato,char mensajeError[]);
