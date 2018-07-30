#ifndef INPUTS_H_INCLUDED
#define INPUTS_H_INCLUDED



#endif // INPUTS_H_INCLUDED

/** \brief Recibe un numero Flotante ingresado por el usuario y lo retorna
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param numeroIngresado float Numero flotante que ingresa el usuario
 * \return float El numero flotante ingresado por el usuario
 *
 */
float getFloat(char mensaje[],float numeroIngresado);

/** \brief Recibe un numero entero ingresado por el usuario (entre un minimo y un maximo), y lo retorna
 *
 * \param mensaje[] char Mensaje que se le muestra al usuario
 * \param A int Numero que ingresa el usuario
 * \param maximo int Numero maximo que puede ingresar el usuario
 * \param minimo int Numero minimo que puede ingresar el usuario
 * \return int El numero entero ingresado por el usuario
 *
 */
int getInt(char mensaje[], int A, int maximo, int minimo);
