#ifndef PROPIETARIO_H_INCLUDED
#define PROPIETARIO_H_INCLUDED

typedef struct
{
    int Id;
    char nombre[20];
    char tarjeta[20];
    char direccion[20];
    int edad;
    int estado;
}ePropietario;

#endif // PROPIETARIO_H_INCLUDED

/** \brief Funcion que inicializa en 0 los estados de la estructura
 *
 * \param listadoPropietarioPropietario[] ePropietario Estructura a la que le inicializa el estado en 0
 * \param tamanio int Tama�o de la estructura
 * \return void
 *
 */
void inicializarEstadosPropietario(ePropietario listadoPropietarioPropietario[],int tamanio);

/** \brief Funcion que precarga con datos las estructuras
 *
 * \param listadoPropietarioPropietario[] ePropietario Estructura a la que se va a cargar con datos
 * \param tamanio int Tama�o de la estructura que se va a cargar
 * \return int Retorna 1 si se cargaron los datos de manera efectiva
 *
 */
int cargarHarcodePropietario(ePropietario listadoPropietarioPropietario[],int tamanio);

/** \brief Funcion que toma un string y lo valida
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param caracter[] char Array que va a guardar el string ingresado
 * \return char Retorna el string validado
 *
 */
char getString(char mensaje[], char caracter[]);

/** \brief Funcion que toma un entero y lo valida
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param A int Entero que va a guardar el valor ingresado
 * \return int Retorna el entero validado
 *
 */
int getInt(char mensaje[],int A);

/** \brief Recibe un numero Flotante ingresado por el usuario y lo retorna
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param numeroIngresado float Numero flotante que ingresa el usuario
 * \return float El numero flotante ingresado por el usuario
 *
 */
float getFloat(char mensaje[],float numeroIngresado);

/** \brief Funcion que toma un caracter y lo valida
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param caracter char Caracter que va a guardar el input
 * \return char Caracter validado
 *
 */
char getChar(char mensaje[],char caracter);

/** \brief Funcion que hace mayusculas las primeras letras de los nombres o strings que se ingresen
 *
 * \param caracter[] char String a modificar
 * \return void
 *
 */
void stringToUpper(char caracter[]);

/** \brief Funcion que valida si el dato ingresado es un numero entero
 *
 * \param datoAValidar[] char Dato a validar que debe pasarse como string
 * \return int Retorna el entero ya validado
 *
 */
int validarStringEntero(char datoAValidar[]);

/** \brief Funcion que valida si el string ingresado es un string
 *
 * \param datoAValidar[] char Cadena a validar
 * \return char Retorna la cadena validada
 *
 */
char validarStringCadena(char datoAValidar[]);

/** \brief Funcion que valida si el caracter ingresado es un caracter
 *
 * \param datoAValidar char Caracter a validar
 * \return char Retorna el caracter validado
 *
 */
char validarStringCaracter(char datoAValidar);

/** \brief Funcion que valida si el dato ingresado es un numero flotante
 *
 * \param datoAValidar[] char Dato a validar que debe pasarse como string
 * \return float Retorna el flotante ya validado
 *
 */
float validarStringFloat(char datoAValidar[]);

/** \brief Funcion que le pregunta al usuario si desea continuar
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \return char Retorna la respuesta del usuario
 *
 */
char deseaContinuar(char mensaje[]);

/** \brief Funcion que da de alta a los propietarios
 *
 * \param listadoPropietarioPropietario[] ePropietario Estructura en la que se va a dar de alta a los propietarios
 * \param tamanio int Tama�o de la estructura
 * \param indice int Indice libre en el que se va a dar de alta al propietario
 * \return int Retorna 1 si se da de alta el propietario
 *
 */
int altaPropietario(ePropietario listadoPropietarioPropietario[],int tamanio,int indice);

/** \brief Funcion que busca un estado libre para ingresar al propietario
 *
 * \param listadoPropietarioPropietario[] ePropietario Estructura en la que se va a buscar el estado libre
 * \param tamanio int Tama�o de la estructura
 * \return int Indice en donde se encuentra el primer estado libre
 *
 */
int buscarLibrePropietario(ePropietario listadoPropietarioPropietario[],int tamanio);

/** \brief Funcion que asigna automaticamente un Id a las nuevas altas
 *
 * \param listadoPropietarioPropietario[] ePropietario Estructura a la que se le asigna el ID
 * \param tamanio int Tama�o de la estructura
 * \return int Retorna el siguiente ID
 *
 */
int idAutoIncrementalPropietario(ePropietario listadoPropietarioPropietario[],int tamanio);

/** \brief Funcion que muestra un elemento dentro de una estructura de arrays
 *
 * \param listadoPropietario[] ePropietario Estructura a mostrar
 * \param tamanio int Tama�o de la estructura
 * \param i int Subindice de la estructura que se va a mostrar
 * \return void
 *
 */
void mostrarUnoPropietario(ePropietario listadoPropietario[],int tamanio,int i);

/** \brief Funcion que invoca a mostrarUno y muestra todos los elementos de la estructura
 *
 * \param listadoPropietario[] ePropietario estructura que se muestra
 * \param tamanio int Tama�o de la estructura
 * \param flag int Bandera que indica si se ingreso un propietario previamente
 * \return void
 *
 */
void mostrarListaPropietario(ePropietario listadoPropietario[],int tamanio,int flag);

/** \brief Funcion que le presenta al usuario un menu en el que le permite elegir que modificar
 *
 * \param listado[] ePropietario estructura que se va a modificar
 * \param tamanio int Tama�o de la estructura
 * \param flag int Bandera que indica si se ingreso un propietario previamente
 * \return void
 *
 */
void modificarPropietario(ePropietario listadoPropietario[],int tamanio,int flag);

/** \brief Funcion que toma un Id ingresado por el usuario y lo compara con todos los ID pertenecientes a la estructura
 *
 * \param listado[] ePropietario estructura con la que se comparara el ID ingresado
 * \param tamanio int Tama�o de la estructura
 * \param id int Id que ingresa el usuario
 * \return int El subindice en el que encontro el ID o -1 si no lo encontro
 *
 */
int buscarPorIdPropietario(ePropietario listadoPropietario[],int tamanio,int id);

/** \brief Funcion que permite modificar un string dentro de una estructura
 *
 * \param listado[] ePropietario estructura en la que se va a modificar el string
 * \param indice int Indice de la estructura en el que se va a modificar el string
 * \param caracter[] char Array de caracteres en donde se va a guardar el nuevo string ingresado
 * \return char Retorna el string modificado
 *
 */
char modificarStringPropietario(ePropietario listadoPropietario[],int indice,char caracter[]);

/** \brief Funcion que valida el formato de tarjeta de credito ingresado
 *
 * \param tarjeta[] char Tarjeta a validar
 * \return void
 *
 */
void validarTarjetaDeCredito(char tarjeta[]);

/** \brief Funcion que transoforma todo una cadena a mayusculas
 *
 * \param cadena[] char Cadena a transformar
 * \return char Retorna la cadena transformadad
 *
 */
char stringMayusculas(char cadena[]);

void mostrarPropietarioPorNombre(ePropietario listadoPropietario[],int tamPropietario);

void ordenarPropietarios(ePropietario listadoPropietario[],int tamPropietario,int opcion);

void mostrarPropietariosSuperanEdad(ePropietario listadoPropietario[],int tamanioPropietario);
