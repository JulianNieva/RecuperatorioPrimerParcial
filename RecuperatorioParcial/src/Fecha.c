/*
 * Fecha.c
 *
 *  Created on: 8 may. 2021
 *      Author: Julian
 */

#include <stdio.h>
#include <stdlib.h>
#include "Fecha.h"
#include "Input.h"

eFecha PedirFecha(void)
{
	eFecha aux;

	utn_getInt("Ingrese el dia: ","Error. Ingrese un dia valido.. ",1, 31,6, &aux.f_dia);
	utn_getInt("Ingrese el mes: ","Error. Ingrese un mes valido.. ",1, 12,6, &aux.f_mes);
	utn_getInt("Ingrese el año: ","Error. Ingrese un año valido.. ",2019, 2022,6, &aux.f_anio);

	return aux;
}
