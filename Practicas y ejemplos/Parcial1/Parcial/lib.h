#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define TAMC 25 //TAMAÑO CLIENTES
#define TAMR 100 //TAMAÑO RENTAS
#define AMOLADORA 101
#define MEZCLADORA 102
#define TALADRO 103

   typedef struct
    {
      int id;
      char nombre[256];
      char apellido[256];
      int dni;
      int estado;

    }eClient;

    typedef struct
    {
        int idCliente;
        int equipo;
        int tiempoEstimado;
        char operador[256];
        int estado;

    }eRent;

/** \brief Da de alta a un cliente
 * \param Pide la estructura clientes
 * \param Pide el tamaño de la estructura
 * \return Retorna 0 si hubo un error o 1 si esta todo bien
 *
 */
int alta(eClient clientes[],int tam);

/** \brief Inicializa los estados de clientes en 0
 * \param Pide la estructura clientes
 * \param Pide el tamaño de la estructura
 */
void inicializarClientes(eClient clientes[],int tam);

/** \brief Inicializa en -1 la estructura rentas
 * \param Pide la estructura rentas
 * \param Pide el tamaño de la estructura
 */
void inicializarRenta(eRent rentas[],int tamR);

/** \brief Muestra un menu y pide una opcion.
 * \param Pide el mensaje que va a ser mostrado.
 * \return Retorna la opcion
 */
int menu(char mensaje[]);

/** \brief Muestra un mensaje y pide al usuario ingresar un string
 * \param  Pide el mensaje a ser mostrado
 * \param  Pide la cadena en la que el usuario va a escribir
 */
void getString(char mensaje[],char input[]);

/** \brief Pide un string y valida que contenga solo numeros
 * \param  Pide la cadena que va a ser validada
 * \return Retorna 0 si la cadena tiene letras, sino retorna 1
 */
int getStringLetras(char mensaje[],char input[]);

/** \brief Pide un string y valida que contenga solo letras
 * \param  Pide la cadena que va a ser validada
 * \return Retorna 0 si la cadena tiene numero, sino retorna 1
 */
int esSoloLetras(char str[]);

/** \brief Muestra un mensaje, pide al usuario un string y despues valida que solo contenga numeros
 * \param  Pide el mensaje a ser mostrado
 * \param  Pide la cadena en la que el usuario va a escribir
 * \return Retorna 1 si esta todo validado, sino retorna 0
 */
int getStringNumeros(char mensaje[],char input[]);

/** \brief Pide un string y valida que contenga solo numeros
 * \param  Pide la cadena que va a ser validada
 * \return Retorna 0 si la cadena tiene letras, sino retorna 1
 */
int esNumerico(char str[]);

/** \brief Verifica que el id no este repetido
 * \param Pide la estructura clientes
 * \param Pide el tamaño de la estructura
 * \param Pide el id que va a ser verificado
 * \return Retorna 0 si encontro el id repetido o 1 si esta todo bien
 */
int verificarId(eClient clientes[],int tam,int id);

/** \brief Verifica que el dni no este repetido
 * \param Pide la estructura clientes
 * \param Pide el tamaño de la estructura
 * \param Pide el dni que va a ser verificado
 * \return Retorna 0 si encontro el dni repetido o 1 si esta todo bien
 */
int verificarDni(eClient clientes[],int tam,int dni);

/** \brief Pre carga datos a las estructuras
 * \param Pide la estructura clientes
 * \param Pide la estructura rentas
 */
void hardCodear(eClient clientes[],eRent rentas[]);

/** \brief Muestra todas las rentas de cada cliente
 * \param Pide la estructura clientes
 * \param Pide la estructura rentas
 * \param Pide sus tamaños
 */
void rentasxclientes(eClient clientes[],eRent rentas[],int tamC,int tamR);


/** \brief Busca una posicion libre en la estructura clientes
 * \param Pide la estructura clientes
 * \param Pide el tamaño de la estructura
 * \return Retorna la posicion libre o -1 si no encontro un lugar libre
 */
int posicionLibre(eClient clientes[],int tam);

/** \brief Busca una posicion libre en la estructura rentas
 * \param Pide la estructura rentas
 * \param Pide el tamaño de la estructura
 * \return Retorna la posicion libre o -1 si no encontro un lugar libre
 */
int posicionLibreR(eRent rentas[],int tam);


/** \brief Busca una posicion libre en la estructura rentas
 * \param Pide la estructura rentas
 * \param Pide el tamaño de la estructura
* \param Pide la estructura clientes
 * \param Pide el tamaño de la estructura
 * \return Retorna 0 si no se realizo el alta
 */
int nuevoAlquiler(eClient clientes[],eRent rentas[],int tamC,int tamR);

/** \brief Modifica una de las tantas opciones de un cliente
 * \param Pide la estructura clientes
 * \param Pide la estructura rentas
 * \param Pide el tamaño de la estructura clientes
 * \param Pide el tamaño de la estructura rentas
 * \return Retorna 1 si esta todo bien y si hubo un error retorna 0
 */
int modificar(eClient clientes[],eRent rentas[], int tamC, int tamR);
