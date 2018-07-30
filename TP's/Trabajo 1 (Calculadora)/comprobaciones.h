#ifndef COMPROBACIONES_H_INCLUDED
#define COMPROBACIONES_H_INCLUDED



#endif // COMPROBACIONES_H_INCLUDED

/** \brief Pregunta al usuario si desea continuar con el programa
 *
 * \param repuesta char Parametro que recibe la respuesta del usuario
 * \return char La respuesta del usuario
 *
 */
char seguirConElPrograma(char repuesta);

/** \brief Comprueba si hay valores ingresados y los reemplaza en el menu
 *
 * \param flagA int Bandera del operando x que indica si este tiene valor cargado o no
 * \param flagB int Bandera del operando y que indica si este tiene valor cargado o no
 * \param auxiliar1 float Flotante que almacena el valor del primer operando
 * \param auxiliar2 float Flotante que almacena el valor del segundo operando
 * \return float Los operandos ingresados por el usuario
 *
 */
float comprobarValores(int flagA,int flagB,float auxiliar1,float auxiliar2);


/** \brief Comprueba mediante banderas si hay algun numero ingresado por el usuario antes de realizar una operacion
 *
 * \param opcion int Opcion que el usuario elige en el menu principal
 * \param flagA int Bandera correspondiente al primer operando
 * \param flagB int Bandera correspondiente al segundo operando
 * \return int La opcion correspondiente a ingresar el numero restante
 *
 */
int comprobarOperando(int opcion,int flagA,int flagB);


