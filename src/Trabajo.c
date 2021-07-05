/*
 * Trabajo.c
 *
 *  Created on: 3 may. 2021
 *      Author: Julian Leandro Nieva 1°C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Trabajo.h"
#include "Input.h"

void InicializarTrabajos(eTrabajo listaTrabajos[],int tam)
{
	int i;

	for(i = 0;i < tam; i++)	//Recorro el array de trabajos y los inicializo en IS_EMPTY
	{
		listaTrabajos[i].isEmpty = IS_EMPTY;
	}
}

int BuscarLibre(eTrabajo listaTrabajos[],int tam)
{
    int i;
    int index;
    index = -1;

    for(i=0; i< tam ; i++)
    {
        if(listaTrabajos[i].isEmpty == IS_EMPTY)//Se busca si esta libre, si esta libre, guarda esa posicion y la devuelve
        {
            index = i;
            break;
        }
    }
    return index;
}


int DarDeBajaDeTrabajo(eTrabajo listadoTrabajos[],int tam)
{
	int valor = -1;
	int id;
	int posicionId;

	getInt(&id,"Ingrese el ID del trabajo que desea dar de baja");

	posicionId = BuscarId(listadoTrabajos,id,tam);

	if(posicionId != -1) //si devolvio -1, no entra
	{
		utn_getInt("Estas seguro que desea dar de baja este trabajo?(Ingrese 1 para aceptar, 0 para cancelar):  ","Error. Ingrese una opcion valida ",0, 1,6, &valor);

		if(valor)	//Si ingreso 1, se baja el trabajo
		{
			listadoTrabajos[posicionId].isEmpty = IS_EMPTY;
		}
	}

	return valor;
}

int BuscarId(eTrabajo listadoTrabajos[], int id,int tam)
{
	int i;
	int index;

	index = -1;

	for(i = 0; i < tam; i++)	//Recorro el array de trabajo
	{
		if(listadoTrabajos[i].isEmpty != IS_EMPTY)
		{
			if(id == listadoTrabajos[i].id) // Si coincide el id que recibe mediante parametros
			{
				index = i; //Se guarda la posicion en donde coincide el id
				break;
			}
		}
	}
	return index;
}
