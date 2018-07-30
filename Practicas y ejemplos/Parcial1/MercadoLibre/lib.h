#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED
#define TAMPRODUCTO 1000

typedef struct
{
    char nombre[50];
    char password[50];
    float calificacion;
    int Id;
    int estado;
}eUsuario;

#endif // LIB_H_INCLUDED

/** \brief Funcion que inicializa en 0 los estados de la Usuario
 *
 * \param listadoUsuario[] eUsuario Usuario a la que le inicializa el estado en 0
 * \param tamanio int Tamaño de la Usuario
 * \return void
 *
 */
void inicializarEstadosUsuario(eUsuario listadoUsuario[],int tamanio);

/** \brief Funcion que precarga con datos las Usuarios
 *
 * \param listadoUsuario[] eUsuario Usuario a la que se va a cargar con datos
 * \param tamanio int Tamaño de la Usuario que se va a cargar
 * \return void
 *
 */
void cargarHarcodeUsuario(eUsuario listadoUsuario[],int tamanio);

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

/** \brief Funcion que da de alta a los usuarios
 *
 * \param listadoUsuario[] eUsuario Usuario en la que se va a dar de alta a los usuarios
 * \param tamanio int Tamaño de la Usuario
 * \param indice int Indice libre en el que se va a dar de alta al usuario
 * \return void
 *
 */
void altaUsuario(eUsuario listadoUsuario[],int tamanio,int indice);

/** \brief Funcion que busca un estado libre para ingresar al usuario
 *
 * \param listadoUsuario[] eUsuario Usuario en la que se va a buscar el estado libre
 * \param tamanio int Tamaño de la Usuario
 * \return int Indice en donde se encuentra el primer estado libre
 *
 */
int buscarLibreUsuario(eUsuario listadoUsuario[],int tamanio);

/** \brief Funcion que asigna automaticamente un Id a las nuevas altas
 *
 * \param listadoUsuario[] eUsuario Usuario a la que se le asigna el ID
 * \param tamanio int Tamaño de la Usuario
 * \return int Retorna el siguiente ID
 *
 */
int idAutoIncrementalUsuario(eUsuario listadoUsuario[],int tamanio);

/** \brief Funcion que muestra un elemento dentro de una Usuario de arrays
 *
 * \param listadoUsuario[] eUsuario Usuario a mostrar
 * \param tamanio int Tamaño de la Usuario
 * \param i int Subindice de la Usuario que se va a mostrar
 * \return void
 *
 */
void mostrarUnoUsuario(eUsuario listadoUsuario[],int tamanio,int i);

/** \brief Funcion que invoca a mostrarUno y muestra todos los elementos de la Usuario
 *
 * \param listadoUsuario[] eUsuario Usuario que se muestra
 * \param tamanio int Tamaño de la Usuario
 * \return void
 *
 */
void mostrarListaUsuario(eUsuario listadoUsuario[],int tamanio);

/** \brief Funcion que le presenta al usuario un menu en el que le permite elegir que modificar
 *
 * \param listadoUsuario[] eUsuario Usuario que se va a modificar
 * \param tamanio int Tamaño de la Usuario
 * \return void
 *
 */
void modificarUsuario(eUsuario listadoUsuario[],int tamanio);

/** \brief Funcion que toma un Id ingresado por el usuario y lo compara con todos los ID pertenecientes a la Usuario
 *
 * \param listadoUsuario[] eUsuario Usuario con la que se comparara el ID ingresado
 * \param tamanio int Tamaño de la Usuario
 * \param id int Id que ingresa el usuario
 * \return int El subindice en el que encontro el ID o -1 si no lo encontro
 *
 */
int buscarPorIdUsuario(eUsuario listadoUsuario[],int tamanio,int id);

/** \brief Funcion que permite modificar un string dentro de una Usuario
 *
 * \param listadoUsuario[] eUsuario Usuario en la que se va a modificar el string
 * \param indice int Indice de la Usuario en el que se va a modificar el string
 * \param caracter[] char Array de caracteres en donde se va a guardar el nuevo string ingresado
 * \return char Retorna el string modificado
 *
 */
char modificarStringUsuario(eUsuario listadoUsuario[],int indice,char caracter[]);

/** \brief Funcion que permite modificar un entero dentro de una Usuario
 *
 * \param listadoUsuario[] eUsuario Usuario en la que se va a modificar el entero
 * \param indice int Indice de la Usuario en el que se va a modificar el entero
 * \param dato int Variable que guarda el dato ingresado
 * \return int Retorna el entero modificado
 *
 */
int modificarEnteroUsuario(eUsuario listadoUsuario[],int indice,int dato);

/** \brief Funcion que permite modificar un flotante dentro de una Usuario
 *
 * \param listadoUsuario[] eUsuario Usuario en la que se va a modificar el float
 * \param indice int Indice de la Usuario en el que se va a modificar el float
 * \param dato float Variable que guarda el dato ingresado
 * \return float Retorna el flotante modificado
 *
 */
float modificarFlotanteUsuario(eUsuario listadoUsuario[],int indice,float dato);

/** \brief Funcion que ordena una Usuario segun el criterio de ordenamiento que se requiera
 *
 * \param listadoUsuario[] eUsuario Usuario a ordenar
 * \param tamanio int Tamaño de la Usuario
 * \return void
 *
 */
void ordenarSegunCriterio(eUsuario listadoUsuario[],int tamanio);

/** \brief Funcion que muestra todos los usuarios dados de baja
 *
 * \param listadoUsuario[] eUsuario Usuario que tiene los usuarios borrados a mostrar
 * \param tamanio int Tamaño de la Usuario
 * \return void
 *
 */
void mostrarBorrados(eUsuario listadoUsuario[],int tamanio);





