/*
 * Fecha.h
 *
 *  Created on: 8 may. 2021
 *      Author: Julian Leandro Nieva 1°C
 */

#ifndef FECHA_H_
#define FECHA_H_

typedef struct
{
	int f_dia;
	int f_mes;
	int f_anio;
}eFecha;

/**
 * @fn eFecha PedirFecha(void)
 * @brief Pido los datos de la fecha
 *
 * @return Devuelvo la estructura a la que le cargue los datos
 */
eFecha PedirFecha(void);

#endif /* FECHA_H_ */
