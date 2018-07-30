#include"ArrayList.h"
#ifndef ESTRUCTURA_H_INCLUDED
#define ESTRUCTURA_H_INCLUDED

typedef struct
{
    char cadena[50];
    int id;
    float salario;
}ejemplo;

#endif // ESTRUCTURA_H_INCLUDED

/** \brief Funcion que reserva espacio en memoria para una nueva estructura
 *
 * \return ejemplo* Puntero a la nueva estructura
 *
 */
ejemplo* constructor();


//-----------------------------------------------------------------------------------------------------------------------------\\


/** \brief Funcion que guarda un entero en una variable estruturada
 *
 * \param this ejemplo* Variable donde se va a guardar el entero
 * \param dato int Entero a guardar
 * \return int
 *
 */
int set_int(ejemplo* this, int dato);

/** \brief Funcion que guarda un string en una variable estruturada
 *
 * \param this ejemplo* Variable en la que se guardara el string
 * \param dato[] char String a guardar
 * \return int
 *
 */
int set_string(ejemplo* this, char dato[]);


/** \brief Funcion que guarda un flotante en una variable estructurada
 *
 * \param this ejemplo* Variable en la que se guardara el flotante
 * \param dato float Flotante a guardar
 * \return int
 *
 */
int set_float(ejemplo* this, float dato);


//-----------------------------------------------------------------------------------------------------------------------------\\


/** \brief Funcion que obtiene un dato de tipo entero de una variable estructurada
 *
 * \param this ejemplo* Variable estructurada de la que se obtendra el dato de tipo entero
 * \return int Entero obtenido
 *
 */
int get_int(ejemplo* this);

/** \brief Funcion que obtiene un dato de tipo cadena de una variable estructurada
 *
 * \param this ejemplo* Variable estructurada de la que se obtendra el dato de tipo cadena
 * \return char* String obtenido
 *
 */
char* get_string(ejemplo* this);

/** \brief Funcion que obtiene un dato de tipo flotante de una variable estructurada
 *
 * \param this ejemplo* Variable estructurada de la que se obtendra el dato de tipo flotante
 * \return float Flotante obtenido
 *
 */
float get_float(ejemplo* this);

//-----------------------------------------------------------------------------------------------------------------------------\\

/** \brief Funcion que toma un dato entero y lo valida
 *
 * \param mensaje[] char Mensaje que se le mostrara al usuario al pedir el dato
 * \param dato int* Puntero a la variable en la que se almacenara el dato
 * \param mensajeError[] char Mensaje de error que se le muestra al usuario si su dato ingresado no es entero
 * \return int Retorna -1 si el dato ingresado no es entero y 0 si el dato ingresado es entero
 *
 */
int getInt(char mensaje[],int* dato,char mensajeError[]);

/** \brief Funcion que toma un dato floatante y lo valida
 *
 * \param mensaje[] char Mensaje que se le mostrara al usuario al pedir el dato
 * \param dato float* Puntero a la variable en la que se almacenara el dato
 * \param mensajeError[] char Mensaje de error que se le muestra al usuario si su dato ingresado no es flotante
 * \return int Retorna -1 si el dato ingresado no es flotante y 0 si el dato ingresado es flotante
 *
 */
int getFloat(char mensaje[],float* dato,char mensajeError[]);

/** \brief Funcion que toma un dato de tipo string y lo valida
 *
 * \param mensaje[] char Mensaje que se le mostrara al usuario al pedir el dato
 * \param dato char* Puntero a la variable en la que se almacenara el dato
 * \param mensajeError[] char Mensaje de error que se le muestra al usuario si su dato ingresado no es una cadena
 * \return int Retorna -1 si el dato ingresado no es cadena y 0 si el dato ingresado es cadena
 *
 */
int getString(char mensaje[],char* dato,char mensajeError[]);

/** \brief Funcion que valida si el dato ingresado es entero
 *
 * \param auxiliar[] char Variable que contiene el dato a validar
 * \param dato int* Puntero a la variable que almacena el dato
 * \param mensaje[] char Mensaje de error que se le muestra al usuario si su dato ingresado no es entero
 * \return int Retorna -1 si el dato ingresado no es entero y 0 si el dato ingresado es entero
 *
 */
int validarEntero(char auxiliar[],int* dato,char mensaje[]);

/** \brief Funcion que valida si el dato ingresado es flotante
 *
 * \param auxiliar[] char Variable que contiene el dato a validar
 * \param dato float* Puntero a la variable que almacena el dato
 * \param mensaje[] char Mensaje de error que se le muestra al usuario si su dato ingresado no es flotante
 * \return int Retorna -1 si el dato ingresado no es flotante y 0 si el dato ingresado es flotante
 *
 */
int validarFloat(char auxiliar[],float* dato,char mensaje[]);

/** \brief Funcion que valida si el dato ingresado es string
 *
 * \param auxiliar[] char Variable que contiene el dato a validar
 * \param dato char* Puntero a la variable que almacena el dato
 * \param mensaje[] char Mensaje de error que se le muestra al usuario si su dato ingresado no es string
 * \return int Retorna -1 si el dato ingresado no es string y 0 si el dato ingresado es string
 *
 */
int validarString(char auxiliar[],char* dato,char mensaje[]);

/** \brief Funcion que convierte a mayusculas la primer letra de cada palabra
 *
 * \param caracter[] char Palabra que va a convertir a mayusculas
 * \return void
 *
 */
void stringToUpper(char caracter[]);

/** \brief Funcion que le asigna un ID a una nueva variable estructurada
 *
 * \param this ArrayList* Lista que contiene los elementos ingresados
 * \param this2 ArrayList* Funcion que contiene los elementos borrados
 * \param aux ejemplo* Variable a la que se le asignara el ID
 * \return void
 *
 */
void idAutoIncremental(ArrayList* this, ArrayList* this2, ejemplo* aux);


//-----------------------------------------------------------------------------------------------------------------------------\\


/** \brief Funcion que da de alta una nueva estructura y la guarda en una lista
 *
 * \param this ArrayList* Lista en la que se guardara la nueva estructura dada de alta
 * \return void
 *
 */
void alta(ArrayList* this);

/** \brief Funcion que muestra por pantalla todos los elementos de una lista
 *
 * \param this ArrayList* Lista que se mostrara por pantalla
 * \return void
 *
 */
void printAll(ArrayList* this);

/** \brief Funcion que imprime una variable estructurada de una lista por pantalla
 *
 * \param this ejemplo* variable estructurada a mostrar
 * \return void
 *
 */
void printOne(ejemplo* this);

/** \brief Funcion que compara un id ingresado con todos los ingresados en una lista
 *
 * \param this ArrayList* Lista que se va a recorrer
 * \param id int ID ingresado
 * \return int Retorna el indice en el que se encontro el ID ingresado o -1 si no se lo encontro
 *
 */
int compare_id(ArrayList* this,int id);

/** \brief Funcion que da de baja una variable estructurada de una lista
 *
 * \param this ArrayList* Lista en donde se encuentra el elemento a dar de baja
 * \param borrados ArrayList* Lista a la que se agregara el elemento borrado
 * \return void
 *
 */
void baja(ArrayList* this, ArrayList* borrados);

/** \brief Funcion que permite modificar los datos de una variable estructurada
 *
 * \param this ArrayList* Lista en la que se encuentra la variable estructurada
 * \return void
 *
 */
void modificar(ArrayList* this);

/** \brief Funcion que modifica una cadena dentro de una variable estructurada
 *
 * \param dato ejemplo* Variable estructurada que contiene la cadena a modificar
 * \return void
 *
 */
void modificarString(ejemplo* dato);

/** \brief Funcion que modifica un entero dentro de una variable estructurada
 *
 * \param dato ejemplo* Variable estructurada que contiene el entero a modificar
 * \return void
 *
 */
void modificarInt(ejemplo* dato);

/** \brief Funcion que modifica un flotante dentro de una variable estructurada
 *
 * \param dato ejemplo* Variable estructurada que contiene el flotante a modificar
 * \return void
 *
 */
void modificarFloat(ejemplo* dato);

/** \brief Funcion que obtiene la primera letra de un nombre para realizar una comparacion
 *
 * \param element void* Estructura que recibe conteniendo la primer letra
 * \return char Primera letra
 *
 */
char get_char(void* element);

/** \brief Funcion que compara dos strings
 *
 * \param stingA void* Elemento 1 conteniendo el primer string
 * \param stringB void* Elemento 2 conteniendo el segundo string
 * \return int Retorna 0 si los strings son iguales, 1 si el primero es mayor que el segundo y -1 si el segundo es mayor que el primero
 *
 */
int sort_string(void* stingA, void* stringB);

/** \brief Funcion que compara dos enteros
 *
 * \param floatA void* Elemento 1 que contiene el primer entero
 * \param floatB void* Elemento 2 que contiene el segundo enteros
 * \return int Retorna 1 si el primer enteros es mas grande que el segundo, -1 si el segundo es mas grande que el primero y 0 si son iguales
 *
 */
int sort_int(void* intA,void* intB);

/** \brief Funcion que compara dos floats
 *
 * \param floatA void* Elemento 1 que contiene el primer float
 * \param floatB void* Elemento 2 que contiene el segundo float
 * \return int Retorna 1 si el primer float es mas grande que el segundo, -1 si el segundo es mas grande que el primero y 0 si son iguales
 *
 */
int sort_float(void* floatA,void* floatB);

/** \brief Funcion que ordena una lista segun dos criterios distintos
 *
 * \param this ArrayList* Lista a ordenar
 * \return void
 *
 */
void double_sort(ArrayList* this);
