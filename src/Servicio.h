/*
 * Servicio.h
 *
 *  Created on: 3 may. 2021
 *      Author: Julian Leandro Nieva 1°C
 */

#ifndef SERVICIO_H_
#define SERVICIO_H_

#define IS_EMPTY 0
#define NOT_EMPTY 1

#define MAX_SERVICIO 3

typedef struct
{
	int idServicio;//pk
	char descripcion[25];
	float precio;
	int isEmpty;
}eServicio;

/**
 * @fn void IncializarServicios(eServicio[], int)
 * @brief Incializo el array de servicio para que esten vacios
 *
 * @param servicios[] Array de servicios
 * @param tam Tamaño del array de servicios
 */
void IncializarServicios(eServicio[],int);

/**
 * @fn void HardcodearServicios(eServicio[])
 * @brief Hardcodeo el listado de los servicios
 *
 * @param listaServicios[] Array que se le insertaran los datos
 * @param tam Tamaño del array de servicios
 */
void HardcodearServicios(eServicio[],int);

/**
 * @fn int ValidarIdServicio(char[], int, eServicio[], int)
 * @brief Valido el id del servicio que ingreso el usuario
 *
 * @param mensajeError[] Mensaje de error que se mostrara si es invalido el id ingresado
 * @param numeroAValidar Es el id que sera validado
 * @param servicio[] Array de servicios
 * @param tam Tamaño del array para la iteracion
 * @return Retorna El id validado
 */
int ValidarIdServicio(char[], int, eServicio[], int);

/**
 * @fn void MostrarServicios(eServicio[])
 * @brief Muestra los servicios
 *
 * @param servicio[] Array de servicios que seran mostrados
 */
void MostrarServicios(eServicio[],int);

/**
 * @fn void MostrarUnServicio(eServicio)
 * @brief Muestra un solo servicio
 *
 * @param servicio Servicio recibido y que sera mostrado
 */
void MostrarUnServicio(eServicio);

/**
 * @fn eServicio DameUnServicio(eServicio[], int)
 * @brief Me da un servicio con el id recibido
 *
 * @param servicios[] Array de servicios
 * @param id Id del trabajo
 * @return Retorna un tipo de dato eServicio
 */
eServicio DameUnServicio(eServicio[], int,int);

#endif /* SERVICIO_H_ */
