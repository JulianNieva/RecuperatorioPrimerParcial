/*
 * Servicio.ct
 *
 *  Created on: 3 may. 2021
 *      Author: Julian Leandro Nieva 1°C
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Servicio.h"
#include "Input.h"

//PROTOTIPO FUNCIONES AUXILIARES//
/**
 * @fn int ExisteElIdServicio(int, eServicio[], int)
 * @brief Compruebo de que exista el id del servicio que ingreso el usuario en la lista
 *
 * @param tam Tamaño del array de servicio
 * @param servicio[] Array de servicios
 * @param numeroAValidar Es el id que sera validado
 * @return Devuelvo 0 si no existe el id ingresado, 1 si esta en la lista
 */
int ExisteElIdServicio(int,eServicio[],int);

//FIN DE PROTOTIPOS FUNCIONES AUXILIARES//

void IncializarServicios(eServicio servicios[],int tam)
{
	int i;

	for(i = 0; i < tam; i++)	//Recorro el array de tlos servicios y los inicializo en IS_EMPTY
	{
		servicios[i].isEmpty = IS_EMPTY;
	}
}

void HardcodearServicios(eServicio listaServicios[], int tam)
{
	int i;
	//Creo las variables auxiliares para el hardcodeo
	int idAux[MAX_SERVICIO] = {20000, 20001, 20002};
	char auxDescrip[MAX_SERVICIO][25] = {"Corte   ", "Desparasitado", "Castrado"};
	float auxPrecio[MAX_SERVICIO] = {250, 300, 400};

	for(i = 0; i < tam; i++)	//Realizo una iteracion for y se van almacenando los datos hardcodeados
	{
		listaServicios[i].idServicio = idAux[i];
		strcpy(listaServicios[i].descripcion,auxDescrip[i]);
		listaServicios[i].precio = auxPrecio[i];
		listaServicios[i].isEmpty = NOT_EMPTY;
	}
}

int ValidarIdServicio(char mensajeError[], int numeroAValidar, eServicio servicio[], int tam)
{
	int respuesta = 0;

	respuesta = ExisteElIdServicio(tam,servicio,numeroAValidar);

	while(respuesta == 0)	//Si no encontro el id en la iteracion anterior, entra en el while
	{
		MostrarServicios(servicio,tam);	//Muestro todos los servicios
		getInt(&numeroAValidar,mensajeError); //Pido que vuelva a ingresar el id

		respuesta = ExisteElIdServicio(tam,servicio,numeroAValidar);
	}

	return numeroAValidar;
}

int ExisteElIdServicio(int tam,eServicio servicio[],int numeroAValidar)
{
	int respuesta = 0;
	int i;

	for(i = 0; i < tam; i++)
	{
		if(servicio[i].isEmpty != IS_EMPTY && servicio[i].idServicio == numeroAValidar)
		{
			respuesta = 1;
			break;
		}

	}

	return respuesta;
}

void MostrarServicios(eServicio servicio[],int tam)
{
	int i;

	printf("_________________________________________________\n");
	printf("|Id\t| Descripcion\t\t| Precio\t|\n");
	printf("|_______|_______________________|_______________|\n");

	for(i = 0; i < tam; i++)
	{
		if(servicio[i].isEmpty != IS_EMPTY)
		{
			MostrarUnServicio(servicio[i]);
		}
	}

	printf("|_______|_______________________|_______________|\n");
}

void MostrarUnServicio(eServicio servicio)
{
	printf("|%d\t| %s\t\t| %.2f\t|\n",servicio.idServicio, servicio.descripcion, servicio.precio);
}

eServicio DameUnServicio(eServicio servicios[], int id,int tam)
{
	eServicio aux;
	int i;

	for(i = 0; i < tam; i++)
	{
		if(servicios[i].idServicio == id)
		{
			aux = servicios[i];
			break;
		}
	}

	return aux;
}
