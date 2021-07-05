/*
 * Trabajo.h
 *
 *  Created on: 3 may. 2021
 *      Author: Julian Leandro Nieva 1°C
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_

#define MAX_TRABAJOS 10

#include "Fecha.h"

#define IS_EMPTY 0
#define NOT_EMPTY 1

typedef struct
{
	int id;
	int idMascota;//fk
	int idServicio;//fk
	int idVeterinario;//fk
	eFecha fecha;
	int isEmpty;
}eTrabajo;

/**
 * @fn void InicializarTrabajos(eTrabajo[])
 * @brief Incizalizo los trabajos para que esten vacios
 *
 * @param listaTrabajos[] Array de trabajos
 */
void InicializarTrabajos(eTrabajo[],int);

/**
 * @fn int BuscarLibre(eTrabajo[])
 * @brief Buusco un espacio libre en el array
 *
 * @param listaTrabajos[] Array de trabajos
 * @return	Retorna la posicion donde se encuetra libre
 */
int BuscarLibre(eTrabajo[],int);

/**
 * @fn int DarDeBajaDeTrabajo(eTrabajo[])
 * @brief Dar de baja un trabajo
 *
 * @param  listadoTrabajos[] array de trabajos
 * @return Retorna un valor dependiendo de lo que sucedio dentro de la funcion
 */
int DarDeBajaDeTrabajo(eTrabajo[],int);

/**
 * @fn int BuscarId(eTrabajo[], int)
 * @brief Busca el id de un trabajo
 *
 * @param listadoTrabajos[] Array de trabajos
 * @param id Id que se le pasa mediante parametros para realizar la busqueda
 * @param tam Tamaño del array
 * @return Devuelve la posicion del array donde se encuentra el trabajo
 */
int BuscarId(eTrabajo[], int,int);

#endif /* TRABAJO_H_ */
