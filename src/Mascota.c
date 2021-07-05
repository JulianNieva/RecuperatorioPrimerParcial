/*
 * Mascota.c
 *
 *  Created on: 10 may. 2021
 *      Author: Julian
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mascota.h"
#include "Input.h"

//PROTOTIPO FUNCIONES AUXILIARES//
/**
 * @fn void MostrarUnaMascota(eMascota)
 * @brief Muestro una mascota
 *
 * @param mascota Mascota a mostrar
 */
void MostrarUnaMascota(eMascota);

/**
 * @fn int ExisteElIdMascota(int, eMascota[], int)
 * @brief Compruebo de que exista el id de la mascota que ingreso el usuario
 *
 * @param tam Tamaño del array de mascotas
 * @param mascotas[] Array de mascotas
 * @param numeroAValidar Es el id que sera validado
 * @return Devuelvo 0 si no existe el id ingresado, 1 si esta en la lista
 */
int ExisteElIdMascota(int,eMascota[],int);

//FIN DE PROTOTIPOS FUNCIONES AUXILIARES//

void InicializarMascotas(eMascota mascotas[],int tam)
{
	int i;

	for(i = 0; i < tam; i++)
	{
		mascotas[i].isEmpty = VACIO;
	}
}

void HardcodearMascotas(eMascota mascotas[],int tam)
{
	int i;
	int idAux[MAX_MASCOTAS] = {15,16,17,18,19};
	char nombreAux[MAX_MASCOTAS][25] = {"Leon", "Berto", "Pedro", "Kenai", "Luna"};
	int edadAux[MAX_MASCOTAS] = {4, 10, 5, 7, 3};
	char razaAux[MAX_MASCOTAS][25] = {"Carlino", "Frenchton", "Caniche", "Siberiano", "Golden "};

	for(i = 0; i < tam; i++)
	{
		mascotas[i].idMascota = idAux[i];
		strcpy(mascotas[i].nombreMascota,nombreAux[i]);
		mascotas[i].edadMascota = edadAux[i];
		strcpy(mascotas[i].raza,razaAux[i]);
		mascotas[i].isEmpty = OCUPADO;
	}
}

void MostrarMascotas(eMascota mascotas[],int tam)
{
	int i;

	printf(" ________________________________________________________\n");
	printf("| Id\t| Nombre\t| Edad\t| Raza\t	         |\n");
	printf("|_______|_______________|_______|________________________|\n");

	for(i = 0; i< tam; i++)
	{
		if(mascotas[i].isEmpty == OCUPADO)
		{
			MostrarUnaMascota(mascotas[i]);
		}
	}
	printf("|_______|_______________|_______|________________________|\n");
}

void MostrarUnaMascota(eMascota mascota)
{
	printf("| %d\t|\t%s\t| %d\t| %s\t\t |\n",mascota.idMascota,mascota.nombreMascota,mascota.edadMascota,mascota.raza);
}

int ValidarIdMascota(char mensajeError[],int numeroAValidar, eMascota mascotas[],int tam)
{
	int respuesta = 0;

	respuesta = ExisteElIdMascota(tam,mascotas,numeroAValidar);

	while(respuesta == 0)
	{
		MostrarMascotas(mascotas,tam);
		getInt(&numeroAValidar,mensajeError);

		respuesta = ExisteElIdMascota(tam,mascotas,numeroAValidar);
	}

	return numeroAValidar;
}

int ExisteElIdMascota(int tam,eMascota mascotas[],int numeroAValidar)
{
	int respuesta = 0;
	int i;

	for(i = 0; i < tam; i++)
	{
		if(mascotas[i].isEmpty != VACIO)
		{
			if(mascotas[i].idMascota == numeroAValidar)
			{
				respuesta = 1;
				break;
			}
		}

	}

	return respuesta;
}

eMascota DameUnaMascota(eMascota mascotas[],int id,int tam)
{
	eMascota aux;
	int i;

	for(i = 0; i<tam;i++)
	{
		if(mascotas[i].idMascota == id)
		{
			aux = mascotas[i];
			break;
		}
	}

	return aux;
}
