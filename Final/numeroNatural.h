#include"ArrayList.h"
#ifndef NUMERONATURAL_H_INCLUDED
#define NUMERONATURAL_H_INCLUDED

typedef struct
{
    int numero;
    char nombre[50];
    int par;
    int impar;
    int primo;
}numeroNatural;

#endif // NUMERONATURAL_H_INCLUDED

/** \brief Funcion que reserva espacio en memoria para una nueva estructura
 *
 * \return numeroNatural* Puntero a la nueva estructura
 *
 */
numeroNatural* constructor();


//-----------------------------------------------------------------------------------------------------------------------------\\


/** \brief Funcion que guarda un entero en una variable estruturada
 *
 * \param this numeroNatural* Variable donde se va a guardar el entero
 * \param dato int Entero a guardar
 * \return int
 *
 */
int set_numero(numeroNatural* this, int dato);


/** \brief Funcion que guarda un entero en una variable estruturada
 *
 * \param this numeroNatural* Variable donde se va a guardar el entero
 * \param dato int Entero a guardar
 * \return int
 *
 */
int set_par(numeroNatural* this, int dato);



/** \brief Funcion que guarda un entero en una variable estruturada
 *
 * \param this numeroNatural* Variable donde se va a guardar el entero
 * \param dato int Entero a guardar
 * \return int
 *
 */
int set_impar(numeroNatural* this, int dato);

/** \brief Funcion que guarda un entero en una variable estruturada
 *
 * \param this numeroNatural* Variable donde se va a guardar el entero
 * \param dato int Entero a guardar
 * \return int
 *
 */
int set_primo(numeroNatural* this, int dato);

/** \brief Funcion que guarda un string en una variable estruturada
 *
 * \param this numeroNatural* Variable en la que se guardara el string
 * \param dato[] char String a guardar
 * \return int
 *
 */
int set_nombre(numeroNatural* this, char nombre[]);



/** \brief Funcion que obtiene un dato de tipo entero de una variable estructurada
 *
 * \param this numeroNatural* Variable estructurada de la que se obtendra el dato de tipo entero
 * \return int Entero obtenido
 *
 */
int get_numero(numeroNatural* this);

/** \brief Funcion que obtiene un dato de tipo entero de una variable estructurada
 *
 * \param this numeroNatural* Variable estructurada de la que se obtendra el dato de tipo entero
 * \return int Entero obtenido
 *
 */
int get_par(numeroNatural* this);

/** \brief Funcion que obtiene un dato de tipo entero de una variable estructurada
 *
 * \param this numeroNatural* Variable estructurada de la que se obtendra el dato de tipo entero
 * \return int Entero obtenido
 *
 */
int get_impar(numeroNatural* this);

/** \brief Funcion que obtiene un dato de tipo entero de una variable estructurada
 *
 * \param this numeroNatural* Variable estructurada de la que se obtendra el dato de tipo entero
 * \return int Entero obtenido
 *
 */
int get_primo(numeroNatural* this);

/** \brief Funcion que obtiene un dato de tipo cadena de una variable estructurada
 *
 * \param this numeroNatural* Variable estructurada de la que se obtendra el dato de tipo cadena
 * \return char* String obtenido
 *
 */
char* get_nombre(numeroNatural* this);


/** \brief Funcion que toma un dato entero y lo valida
 *
 * \param mensaje[] char Mensaje que se le mostrara al usuario al pedir el dato
 * \param dato int* Puntero a la variable en la que se almacenara el dato
 * \param mensajeError[] char Mensaje de error que se le muestra al usuario si su dato ingresado no es entero
 * \return int Retorna -1 si el dato ingresado no es entero y 0 si el dato ingresado es entero
 *
 */
int getInt(char mensaje[],int* dato,char mensajeError[]);

/** \brief Funcion que valida si el dato ingresado es entero
 *
 * \param auxiliar[] char Variable que contiene el dato a validar
 * \param dato int* Puntero a la variable que almacena el dato
 * \param mensaje[] char Mensaje de error que se le muestra al usuario si su dato ingresado no es entero
 * \return int Retorna -1 si el dato ingresado no es entero y 0 si el dato ingresado es entero
 *
 */
int validarEntero(char auxiliar[],int* dato,char mensaje[]);

/** \brief Funcion que muestra por pantalla todos los elementos de una lista
 *
 * \param this ArrayList* Lista que se mostrara por pantalla
 * \return void
 *
 */
void printAll(ArrayList* this);

/** \brief Funcion que imprime una variable estructurada de una lista por pantalla
 *
 * \param this numeroNatural* variable estructurada a mostrar
 * \return void
 *
 */
void printOne(numeroNatural* this,int id);

void completarNumero(ArrayList* this);

int buscarNumeroRepetido(ArrayList* this, ArrayList* repetidos, ArrayList* depurada);

int compararNumeros(void* numero1, void* numero2);

int comprobarSiElNumeroEsRepetido(ArrayList* repetido, numeroNatural* aux);
