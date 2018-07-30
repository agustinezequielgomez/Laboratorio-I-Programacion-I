#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona* lista);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona* lista, int dni);

/** \brief Funcion que inicializa todos los estados de una estructura como vacios
 *
 * \param lista[] EPersona Estructura que se va a inicializar como vacia
 * \return void
 *
 */
void inicializarEstados(EPersona*);

/** \brief Funcion que previamente carga la estructura con usuarios
 *
 * \param lista[] EPersona Estructura que se va a cargar
 * \return void
 *
 */
void inicializarHarcode(EPersona*);

/** \brief Funcion que toma un string y lo valida
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param caracter[] char Array que va a guardar el string ingresado
 * \return char Retorna el string validado
 *
 */
char getString(char mensaje[], char* caracter);

/** \brief Funcion que toma un entero y lo valida
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param A int Entero que va a guardar el valor ingresado
 * \return int Retorna el entero validado
 *
 */
int getInt(char mensaje[],int *A);

/** \brief Funcion que hace mayusculas las primeras letras de los nombres o strings que se ingresen
 *
 * \param caracter[] char String a modificar
 * \return void
 *
 */
void stringToUpper(char* caracter);

/** \brief Funcion que valida si el dato ingresado es un numero entero
 *
 * \param datoAValidar[] char Dato a validar que debe pasarse como string
 * \return int Retorna el entero ya validado
 *
 */
int validarStringEntero(char* datoAValidar[]);

/** \brief Funcion que valida si el string ingresado es un string
 *
 * \param datoAValidar[] char Cadena a validar
 * \return char Retorna la cadena validada
 *
 */
char validarStringCadena(char* datoAValidar[]);

/** \brief Funcion que permite agregar una persona al sistema
 *
 * \param lista[] EPersona Estructura en la que se va a almacenar la persona dada de agregada
 * \return void
 *
 */
void agregarPersona(EPersona* lista[]);

/** \brief Estructura que, ingresando un DNI, permite dar de baja un usuario
 *
 * \param lista[] EPersona Estructura en la que se encuentra el usuario a dar de baja
 * \param flag int Bandera que valida si previamente se ingreso algun usuario para dar de baja
 * \return void
 *
 */
void borrarPersona(EPersona* lista[],int* flag);

/** \brief Funcion que lista por pantalla los usuarios y sus campos
 *
 * \param lista[] EPersona Estructura en la que estan los usuarios a mostrar
 * \return void
 *
 */
void mostrarLista(EPersona* lista[]);

/** \brief Funcion que ordena por nombre los usuarios de la estructura
 *
 * \param lista[] EPersona Estructura que contiene los usuarios a ordenar
 * \param flag int Bandera que valida si previamente se ingreso algun usuario para ordenar
 * \return void
 *
 */
void ordenarListaPorNombre(EPersona* lista[],int flag);

/** \brief Funcion que tomando las edades ingresadas realiza un grafico estadistico representandolas
 *
 * \param lista[] EPersona Estructura en la que se van a basar los datos del grafico
 * \return void
 *
 */
void imprimirGrafico(EPersona lista[]);

#endif // FUNCIONES_H_INCLUDED
