#include"estructura.h"
#include<stdio.h>
#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED
/** \brief Funcion que escribe un archivo .csv desde una lista
 *
 * \param this ArrayList* Lista que va a escribir
 * \return void
 *
 */
void parserRead(ArrayList* this);

/** \brief Funcion que lee un archivo .csv y carga los datos de este en una lista
 *
 * \param this ArrayList* Lista en la que se van a cargar los datos
 * \return void
 *
 */
void parserWrite(ArrayList* this);

//--------------------------------------------------
//Parser para dos listas desde un mismo archivo-----

void parserDuoRead(ArrayList* this, ArrayList* this2);
void parserDuoWrite(ArrayList* this, ArrayList* this2);

//---------------------------------------------------
//Funciones que escriben y leen binarios-------------

/** \brief Funcion que guarda una lista en un archivo binario
 *
 * \param this ArrayList* Lista que se va a guardar
 * \return void
 *
 */
void saveBinary(ArrayList* this);

/** \brief Funcion que lee un archivo binario y carga sus datos en una lista
 *
 * \param this ArrayList* Lista en la que se van a cargar los datos
 * \return void
 *
 */
void loadBinary(ArrayList* this);
