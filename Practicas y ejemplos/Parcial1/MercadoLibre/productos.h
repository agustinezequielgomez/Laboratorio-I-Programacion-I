#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED
#include"lib.h"
typedef struct
{
    int IdUsuario;
    char nombre[50];
    float precio;
    int stock;
    int Id;
    int estado;
}eProducto;

#endif // PRODUCTOS_H_INCLUDED


/** \brief Funcion que inicializa en 0 los estados de la Producto
 *
 * \param listadoProducto[] eProducto Producto a la que le inicializa el estado en 0
 * \param tamanio int Tamaño de la Producto
 * \return void
 *
 */
void inicializarEstadosProducto(eProducto listadoProducto[],int tamanio);

/** \brief Funcion que precarga con datos las Productos
 *
 * \param listadoProducto[] eProducto Producto a la que se va a cargar con datos
 * \param tamanio int Tamaño de la Producto que se va a cargar
 * \return void
 *
 */
void cargarHarcodeProducto(eProducto listadoProducto[],int tamanio);

/** \brief Funcion que muestra un menu principal con las opciones del programa e invoca al resto de las funciones
 *
 * \param listadoUsuario[] eUsuario Usuario que se le pasa al resto de las funciones
 * \param tamanio int Tamaño de la Usuario
 * \return void
 *
 */
void menu(eUsuario listadoUsuario[],eProducto listadoProducto[],int tamanio,int tamanioProducto);

/** \brief Funcion que da de alta a los Productos
 *
 * \param listadoProducto[] eProducto Producto en la que se va a dar de alta a los Productos
 * \param tamanio int Tamaño de la Producto
 * \param indice int Indice libre en el que se va a dar de alta al Producto
 * \return void
 *
 */
void altaProducto(eProducto listadoProducto[],eUsuario listadoUsuario[],int tamanio,int tamanioProducto,int indice);

/** \brief Funcion que busca un estado libre para ingresar al Producto
 *
 * \param listadoProducto[] eProducto Producto en la que se va a buscar el estado libre
 * \param tamanio int Tamaño de la Producto
 * \return int Indice en donde se encuentra el primer estado libre
 *
 */
int buscarLibreProducto(eProducto listadoProducto[],int tamanio);

/** \brief Funcion que asigna automaticamente un Id a las nuevas altas
 *
 * \param listadoProducto[] eProducto Producto a la que se le asigna el ID
 * \param tamanio int Tamaño de la Producto
 * \return int Retorna el siguiente ID
 *
 */
int idAutoIncrementalProducto(eProducto listadoProducto[],int tamanio);

/** \brief Funcion que muestra un elemento dentro de una Producto de arrays
 *
 * \param listadoProducto[] eProducto Producto a mostrar
 * \param tamanio int Tamaño de la Producto
 * \param i int Subindice de la Producto que se va a mostrar
 * \return void
 *
 */
void mostrarUnoProducto(eProducto listadoProducto[],int tamanio,int i);

/** \brief Funcion que invoca a mostrarUno y muestra todos los elementos de la Producto
 *
 * \param listadoProducto[] eProducto Producto que se muestra
 * \param tamanio int Tamaño de la Producto
 * \return void
 *
 */
void mostrarListaProducto(eProducto listadoProducto[],int tamanio);

/** \brief Funcion que le presenta al Producto un menu en el que le permite elegir que modificar
 *
 * \param listadoProducto[] eProducto Producto que se va a modificar
 * \param tamanio int Tamaño de la Producto
 * \return void
 *
 */
void modificarProducto(eProducto listadoProducto[],eUsuario listadoUsuario[],int tamanio,int tamanioProducto);

/** \brief Funcion que toma un Id ingresado por el Producto y lo compara con todos los ID pertenecientes a la Producto
 *
 * \param listadoProducto[] eProducto Producto con la que se comparara el ID ingresado
 * \param tamanio int Tamaño de la Producto
 * \param id int Id que ingresa el Producto
 * \return int El subindice en el que encontro el ID o -1 si no lo encontro
 *
 */
int buscarPorIdProducto(eProducto listadoProducto[],int tamanio,int id);

/** \brief Funcion que permite modificar un string dentro de una Producto
 *
 * \param listadoProducto[] eProducto Producto en la que se va a modificar el string
 * \param indice int Indice de la Producto en el que se va a modificar el string
 * \param caracter[] char Array de caracteres en donde se va a guardar el nuevo string ingresado
 * \return char Retorna el string modificado
 *
 */
char modificarStringProducto(eProducto listadoProducto[],int indice,char caracter[]);

/** \brief Funcion que permite modificar un entero dentro de una Producto
 *
 * \param listadoProducto[] eProducto Producto en la que se va a modificar el entero
 * \param indice int Indice de la Producto en el que se va a modificar el entero
 * \param dato int Variable que guarda el dato ingresado
 * \return int Retorna el entero modificado
 *
 */
int modificarEnteroProducto(eProducto listadoProducto[],int indice,int dato);

/** \brief Funcion que permite modificar un flotante dentro de una Producto
 *
 * \param listadoProducto[] eProducto Producto en la que se va a modificar el float
 * \param indice int Indice de la Producto en el que se va a modificar el float
 * \param dato float Variable que guarda el dato ingresado
 * \return float Retorna el flotante modificado
 *
 */
float modificarFlotanteProducto(eProducto listadoProducto[],int indice,float dato);

/** \brief Funcion que pide un ID al Producto para realizar una baja
 *
 * \param listadoProducto[] eProducto Producto en la que se va a dar de baja
 * \param tamanio int Tamaño de la Producto
 * \param mensaje[] char Mensaje que se va a mostrar al Producto preguntando si desea efectuar la baja
 * \return void
 *
 */
void darDeBajaProducto(eProducto listadoProducto[],eUsuario listado[],int tamanio,int tamanioProducto,char mensaje[]);

/** \brief Funcion que confirma si el Producto realmente quiere realizar la baja. Si es asi cambia el estado de la Producto por 2
 *
 * \param listadoProducto[] eProducto Producto a la que se va a realizar la baja
 * \param indice int Indice en la que se va a realizar la baja
 * \param mensaje[] char Mensaje que se le muestra al Producto
 * \return void
 *
 */
void borrarEntidadProducto(eProducto listadoProducto[],int indice,char mensaje[]);

/** \brief Funcion que muestra dos estructuras relacionadas de manera 1 con muchos
 *
 * \param listado[] eGenericaUsuario Primera estructura a mostrar (Uno)
 * \param tamanio int Tamaño de la primera estsructura
 * \param listado[] eGenericaEstructuraDos Segunda estructura a mostrar (Muchos)
 * \param tamanioEstructura2 int Tamaño de la segunda estructura
 * \return void
 *
 */
void mostrarUnoConMuchos(eUsuario listadoUsuario[],int tamanio,eProducto listadoProducto[],int tamanioProducto);

/** \brief Funcion que pide un ID al usuario para realizar una baja
 *
 * \param listadoUsuario[] eUsuario Usuario en la que se va a dar de baja
 * \param tamanio int Tamaño de la Usuario
 * \param mensaje[] char Mensaje que se va a mostrar al usuario preguntando si desea efectuar la baja
 * \return void
 *
 */
void darDeBajaUsuario(eUsuario listadoUsuario[],eProducto listadoProducto[],int tamanio,int tamanioProducto,char mensaje[]);

/** \brief Funcion que confirma si el usuario realmente quiere realizar la baja. Si es asi cambia el estado de la Usuario por 2
 *
 * \param listadoUsuario[] eUsuario Usuario a la que se va a realizar la baja
 * \param indice int Indice en la que se va a realizar la baja
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \return void
 *
 */
void borrarEntidadUsuario(eUsuario listadoUsuario[],eProducto listadoProducto[],int tamanioProducto,int indice,char mensaje[]);


void comprarProducto(eUsuario listadoUsuario[],eProducto listadoProducto[],int tamanio,int tamanioProducto);
