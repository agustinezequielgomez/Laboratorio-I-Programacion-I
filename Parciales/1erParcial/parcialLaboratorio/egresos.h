#ifndef EGRESOS_H_INCLUDED
#define EGRESOS_H_INCLUDED
#include"automovil.h"

typedef struct
{
    int idEgreso;
    int idIngreso;
    int horas;
    int marca;
    int estado;
    float recaudacion;
}eEgreso;

#endif // EGRESOS_H_INCLUDED


/** \brief Funcion que muestra un menu principal con las opciones del programa e invoca al resto de las funciones
 *
 * \param listadoPropietario[] ePropietario Propietario que se le pasa al resto de las funciones
 * \param tamanio int Tamaño de la Propietario
 * \return void
 *
 */
/** \brief Funcion que muestra un menu principal con las opciones del programa e invoca al resto de las funciones
 *
 * \param listadoPropietarioPropietario[] ePropietario Estructura que se le pasa al resto de las funciones
 * \param listadoAutomovil[] eAutomovil Estructura que se le pasa al resto de las funciones
 * \param listadoEgresos[] eEgreso Estructura que se le pasa al resto de las funciones
 * \param tamanioPropietario int Tamaño de la estructura propietario
 * \param tamanioAutomovil int Tamaño de la estructura Automovil
 * \param tamanioEgresos int Tamaño de la estructura Egresos
 * \return void
 *
 */
void menu(ePropietario listadoPropietarioPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioPropietario,int tamanioAutomovil,int tamanioEgresos);

/** \brief Funcion que inicializa los estados de la estructura Egresos en 0
 *
 * \param listadoEgreso[] eEgreso Estructura en la que se van a inicializar los estados
 * \param tamanio int Tamaño de la estructura
 * \return void
 *
 */
void inicializarEgresos(eEgreso listadoEgreso[],int tamanio);

/** \brief Funcion que carga la estructura con datos
 *
 * \param listadoEgreso[] eEgreso Estructura a ser cargada
 * \return int Retorna 1 si se cargaron los datos de manera efectiva
 *
 */
int egresosHarcode(eEgreso listadoEgreso[]);

/** \brief Funcion que crea un Id autoincremental cada vez que se realiza un egreso
 *
 * \param listadoEgresos[] eEgreso Estructura en la que se va a guardar el Id autoincremental
 * \param tamanio int Tamaño de la estructura
 * \return int Devuelve el Id
 *
 */
int idEgresoAutoIncremental(eEgreso listadoEgresos[],int tamanio);

/** \brief Funcion que pide un ID al usuario para realizar una baja
 *
 * \param listadoAutomovil[] eAutomovil eAutomovil Estructura en la que se va a dar de baja
 * \param listadoPropietario[] ePropietario Propietario a quien se le va a efectuar la baja
 * \param listadoEgresos[] eEgreso Estructura egresos donde se van a guardar los datos de la baja
 * \param tamanio int Tamaño de la estructura automovil
 * \param tamanioPropietario int Tamaño de la estructura propietario
 * \param mensaje[] char Mensaje que se le mostrara al usuario para confirmar si quiere dar de baja el automovil
 * \param tamanioEgreso int Tamaño de la estructura egreso
 * \param flag int Bandera que comprueba si previamente se ingreso algun automovil
 * \return int Retorna 1 si se dio de baja algun automovil
 *
 */
int darDeBajaAutomovil(eAutomovil listadoAutomovil[],ePropietario listadoPropietario[],eEgreso listadoEgresos[],int tamanio,int tamanioPropietario,char mensaje[],int tamanioEgreso,int flag);

/** \brief Funcion que realiza la baja del automovil
 *
 * \param listadoAutomovil[] eAutomovil Estructura en la que se va a dar de baja
 * \param listadoPropietario[] ePropietario Propietario a quien se le va a efectuar la baja
 * \param listadoEgresos[] eEgreso Estructura egresos donde se van a guardar los datos de la baja
 * \param indice int Indice de la estructura automovil donde se va a realizar la baja
 * \param indicePropietario int Indice de la estructura propietario donde se va a realizar la baja
 * \param mensaje[] char Mensaje que se le mostrara al usuario para confirmar si quiere dar de baja el automovil
 * \param tamanioEgreso int Tamaño de la estructura egreso
 * \return int Retorna 1 si se dio de baja el coche y 0 si no se dio de baja
 *
 */
int borrarEntidadAutomovil(eAutomovil listadoAutomovil[],ePropietario listadoPropietario[],eEgreso listadoEgresos[],int indice,int indicePropietario,char mensaje[],int tamanioEgreso);

/** \brief Funcion que busca un lugar libre para realizar otro egreso
 *
 * \param listadoEgresos[] eEgreso Estructura donde se van a realizar los egresos
 * \param tamanio int Tamaño de la estructura egresos
 * \return int Retorna el indice en donde se realizara el siguiente egreso o -1 si no hay mas lugares libres
 *
 */
int buscarLibreEgresos(eEgreso listadoEgresos[],int tamanio);

/** \brief Funcion que suma todas las recaudaciones de la estructura egreso y las imprime por pantalla
 *
 * \param listadoEgresos[] eEgreso Estructura que contiene los valores de egreso
 * \param tamanio int Tamaño de la estructura
 * \param flag int Bandera que indica si previamente se realizo el egreso de un automovil
 * \return void
 *
 */
void mostrarRecaudaciones(eEgreso listadoEgresos[],int tamanio,int flag);

/** \brief Funcion, que tomando las marcas de los coches, calcula las recaudaciones por marca
 *
 * \param listadoEgresos[] eEgreso Estructura en donde estan almacenados los valores
 * \param tamanio int Tamaño de la estructura egreso
 * \param flag int Bandera que indica si previamente se realizo el egreso de un automovil
 * \return void
 *
 */
void mostrarRecaudacionesPorMarca(eEgreso listadoEgresos[],int tamanio,int flag);

/** \brief Funcion que da pregunta que pide un ID para realizar una baja
 *
 * \param listadoPropietario[] ePropietario Estructura en la que se realizara la baja
 * \param listadoAutomovil[] eAutomovil Estructura que contiene los autos del propietario
 * \param listadoEgresos[] eEgreso Estructura que contiene los egresos del propietario
 * \param tamanioAutomovil int Tamaño de la estructura automovil
 * \param tamanioPropietario int Tamaño de la estructura propietario
 * \param tamanioEgreso int Tamaño de la estructura egreso
 * \param mensaje[] char Mensaje que se le mostrara al usuario para confirmar si desea realizar la baja
 * \param flag int Bandera que indica si se ingreso un propietario previamente
 * \return int Retorna 1 si se dio de baja algun autmovil en el proceso
 *
 */
int darDeBajaPropietario(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioAutomovil,int tamanioPropietario,int tamanioEgreso,char mensaje[],int flag);


/** \brief Funcion que efectua las bajas de los propietarios (Asi como tambien el egreso de sus coches si tienen alguno estacionado)
 *
 * \param listadoPropietario[] ePropietario  Estructura en la que se realizara la baja
 * \param listadoAutomovil[] eAutomovil Estructura que contiene los autos del propietario
 * \param listadoEgresos[] eEgreso Estructura que contiene los egresos del propietario
 * \param tamanioAutomovil int Tamaño de la estructura automovil
 * \param indice int Indice de la estructura propietario donde se realizara la baja
 * \param tamanioEgreso int Tamaño de la estructura egreso
 * \param mensaje[] char Mensaje que se le mostrara al usuario para confirmar si desea realizar la baja
 * \return int Retorna 1 si se dio de baja algun autmovil en el proceso
 *
 */
int borrarEntidadPropietario(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioAutomovil,int indice,int tamanioEgreso,char mensaje[]);

int tasarCochePropietario(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioAutomovil,int indice,int tamanioEgreso);

void egresarCochePropietario(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgresos[],int tamanioAutomovil,int indice,int tamanioEgreso,int valor,int horas);

float mostrarMayorTicket(ePropietario listadoPropietario[],eAutomovil listadoAutomovil[],eEgreso listadoEgreso[],int tamEgreso,int tamAutomovil,int tamPropietario);
