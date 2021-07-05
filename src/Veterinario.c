/*
 * Veterinario.c
 *
 *      Author: Julian
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Veterinario.h"
#include "Input.h"

/**
 * @fn int ExisteElIdVeterinario(int, eVeterinario[], int)
 * @brief Compruebo de que exista el id del veterinario que ingreso el usuario en la lista
 *
 * @param numeroAValidar Id que ingreso el usuario
 * @param listaVeterinarios Array de veterinarios
 * @param tam Tamaño del array de veterinario
 * @return Devuelvo 0 si no existe el id ingresado, 1 si esta en la lista
 */
int ExisteElIdVeterinario(int numeroAValidar, eVeterinario listaVeterinario[],int tam);

void InicializarVeterinarios(eVeterinario listaVeterinarios[],int tam)
{
	int i;

	for(i = 0; i< tam; i++)
	{
		listaVeterinarios[i].isEmpty = VACIO;
	}
}

void HardcodearVeterinarios(eVeterinario listaVeterinarios[],int tam)
{
	int i;
	int auxId[MAX_VETERINARIOS] = {1000,1001,1002,1003};
	char auxNombre[MAX_VETERINARIOS][50] = {"Ramiro Perez", "Alicia Dominga","Robert Brajer", "Analia Duarte"};

	for(i = 0; i < tam;i++)
	{
		listaVeterinarios[i].idVeterinario = auxId[i];
		strcpy(listaVeterinarios[i].nombreVeterinario,auxNombre[i]);
		listaVeterinarios[i].isEmpty = OCUPADO;
	}
}

void MostrarVeterinarios(eVeterinario listaVeterinarios[],int tam)
{
	int i;

	printf(" _______________________________\n");
	printf("|ID\t|Nombre\t\t\t|\n");
	printf("|_______|_______________________|\n");

	for(i = 0; i < tam; i++)
	{
		if(listaVeterinarios[i].isEmpty == OCUPADO)
		{
			MostrarUnVeterinario(listaVeterinarios[i]);
		}
	}

	printf("|_______|_______________________|\n");
}

void MostrarUnVeterinario(eVeterinario veterinario)
{
	printf("|%d\t|%s\t\t|\n",veterinario.idVeterinario,veterinario.nombreVeterinario);
}

int ValidarIdVeterinario(char mensajeError[],int numeroAValidar,eVeterinario listaVeterinario[], int tam)
{
	int respuesta = 0;

	respuesta = ExisteElIdVeterinario(numeroAValidar, listaVeterinario,tam);

	while(respuesta == 0)
	{
		MostrarVeterinarios(listaVeterinario,tam);
		getInt(&numeroAValidar,mensajeError);

		respuesta = ExisteElIdVeterinario(numeroAValidar,listaVeterinario,tam);
	}

	return numeroAValidar;
}

int ExisteElIdVeterinario(int numeroAValidar, eVeterinario listaVeterinario[],int tam)
{
	int respuesta = 0;
	int i;

	for(i = 0; i< tam; i++)
	{
		if(listaVeterinario[i].isEmpty != VACIO && listaVeterinario[i].idVeterinario == numeroAValidar)
		{
			respuesta = 1;
			break;
		}
	}

	return respuesta;
}

eVeterinario DameUnVeterinario(eVeterinario listaVeterinarios[],int tam,int id)
{
	int i;
	eVeterinario aux;

	for(i = 0; i< tam; i++)
	{
		if(listaVeterinarios[i].isEmpty != VACIO && listaVeterinarios[i].idVeterinario == id)
		{
			aux = listaVeterinarios[i];
			break;
		}
	}

	return aux;
}
