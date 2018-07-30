#include"numeroNatural.h"
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
void parserWrite(ArrayList* this,char nombre [20]);
