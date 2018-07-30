#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[30];
    char genero[20];
    int duracion;
    char descripcion[250];
    int puntaje;
    char linkImagen[200];
    int id;
    int estado;
}EMovie;

/** \brief Funcion que inicializa los estados de la estructura en 0
 *
 * \param lista EMovie* Puntero a la estructura en la que se van a inicializar los estados
 * \param tamanio int Tamaño de la estructura
 * \return void
 *
 */
void inicializarEstados(EMovie* lista,int tamanio);

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

/** \brief Funcion que valida que un entero este entre determinados valores
 *
 * \param dato int* Dato a validar
 * \return void
 *
 */
void validarRangoEntero(int* dato);

/** \brief Funcion que convierte una cadena de caracteres a mayusculas
 *
 * \param caracter[] char Cadena a convertir a mayusculas
 * \return void
 *
 */
void stringToUpper(char caracter[]);

/** \brief Funcion que le pregunta al usuario si desea continuar
 *
 * \param mensaje[] char Pregunta que se le muestra al usuario
 * \param respuesta char* Puntero a la variable respuesta
 * \return void
 *
 */
void deseaContinuar(char mensaje[],char* respuesta);

/** \brief Funcion que busca si hay algun lugar libre en la estructura
 *
 * \param lista EMovie* Puntero a la estructura donde se van a buscar lugares libres
 * \param tamanio int Tamaño de la estructura
 * \param indice int* Puntero al indice
 * \return void
 *
 */
void buscarLibre(EMovie* lista,int tamanio,int* indice);

/** \brief Funcion que asigna de manera automatica el ID a la proxima alta
 *
 * \param lista EMovie* Puntero a la estructura en la que se va a buscar el proximo indice
 * \param tamanio int Tamaño de la estructura
 * \param indice int* Puntero al indice
 * \return void
 *
 */
void IdIncremental(EMovie* lista,int tamanio,int* indice);

/** \brief Funcion que da de alta una nueva pelicula
 *
 * \param lista EMovie* Puntero a la estructura en la que se va a realizar el alta
 * \param tamanio int Tamaño de la estructura
 * \param contador int* Puntero a un contador que lleva el registro de cuantas peliculas se ingresaron
 * \return void
 *
 */
void alta(EMovie* lista,int tamanio,int* contador);

/** \brief Funcion que lista por pantalla las peliculas ingresadas
 *
 * \param lista EMovie* Puntero a la estructura que contiene las peliculas
 * \param tamanio int Tamaño de la estructura
 * \return void
 *
 */
void mostrarPelicula(EMovie* lista,int tamanio);

/** \brief Funcion que busca la pelicula ingresada por el usuario
 *
 * \param lista EMovie* Puntero a la estructura que contiene las peliculas
 * \param tamanio int Tamaño de la estructura
 * \param id int ID ingresado por el usuario
 * \return int Retorna -1 si no encontro la pelicula. Si la encontro, retorna el indice en donde esta guardada
 *
 */
int buscarPelicula(EMovie* lista,int tamanio,int id);

/** \brief Funcion que borra una pelicula de la estructura
 *
 * \param lista EMovie* Puntero a la estructura que contiene las peliculas
 * \param tamanio int Tamaño de la estructura
 * \param contador int* Puntero a un contador que lleva el registro de las peliculas ingresdas
 * \return void
 *
 */
void borrarPelicula(EMovie* lista,int tamanio,int* contador);

/** \brief Funcion que permite modificar una pelicula
 *
 * \param lista EMovie* Puntero a la estructura que contiene las peliculas
 * \param tamanio int Tamaño de la estructura
 * \param contador int* Puntero a un contador que lleva el registro de las peliculas ingresdas
 * \return void
 *
 */
void modificarPelicula(EMovie* lista,int tamanio,int* contador);

/** \brief Funcion que presenta un menu preguntandole al usuario que atributo de la pelicula elegida desea modificar
 *
 * \param lista EMovie* Puntero a la estructura que contiene las peliculas
 * \param indice int Indice en donde se van a realizar las modificaciones
 * \return void
 *
 */
void menuModificar(EMovie* lista,int indice);

/** \brief Funcion que agrega o borra una pelicula al archivo binario
 *
 * \param lista EMovie* Puntero a la estructura que contiene las peliculas
 * \param tamanio int Tamaño de la estructura
 * \param contador int* Puntero a un contador que lleva el registro de las peliculas ingresdas en el archivo binario
 * \return void
 *
 */
void agregarPelicula(EMovie* lista,int tamanio,int* contador);

/** \brief Funcion que carga las estructuras desde un archivo binario
 *
 * \param lista EMovie* Puntero a la estructura que contiene las peliculas
 * \param tamanio int Tamaño de la estructura pelicula
 * \param contador int* Puntero a un contador que lleva el registro de las peliculas ingresdas en el archivo binario
 * \return void
 *
 */
void cargarPelicula(EMovie* lista,int tamanio,int* contador);

/** \brief Funcion que genera un archivo HTML con las peliculas ingresadas en el programa
 *
 * \param lista EMovie* Puntero a la estructura que contiene las peliculas
 * \param tamanio int Tamaño de la estructura
 * \param nombre[] char Nombre del archivo HTML
 * \return void
 *
 */
void generarPagina(EMovie* lista,int tamanio,char nombre[]);

#endif // FUNCIONES_H_INCLUDED
