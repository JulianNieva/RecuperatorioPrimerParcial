/*
 * Mascota.h
 *
 *  Created on: 10 may. 2021
 *      Author: Julian
 */

#ifndef MASCOTA_H_
#define MASCOTA_H_

#define MAX_MASCOTAS 5

#define OCUPADO 1
#define VACIO 0

typedef struct
{
	int idMascota; //pk
	char nombreMascota[25];
	int edadMascota;
	char raza[25];
	int isEmpty;
}eMascota;

/**
 * @fn void InicializarMascotas(eMascota[], int)
 * @brief Inicializo el array de mascotas para que esten vacios
 *
 * @param mascotas[] Array de mascotas
 * @param tam Tamaño del array de mascotas
 */
void InicializarMascotas(eMascota[],int);

/**
 * @fn void HardcodearMascotas(eMascota[], int)
 * @brief Hardcodeo el listado de mascotas
 *
 * @param mascotas[] Array de mascotas
 * @param tam Tamaño del array de mascotas
 */
void HardcodearMascotas(eMascota[],int);

/**
 * @fn void MostrarMascotas(eMascota[], int)
 * @brief Muestro las mascotas cargadas en la lista
 *
 * @param mascotas[] Array de mascotas
 * @param tam Tamaño del array de mascotas
 */
void MostrarMascotas(eMascota[],int);

/**
 * @fn int ValidarIdMascota(char[], int, eMascota[], int)
 * @brief Valido el id de la mascota que ingreso el usuario
 *
 * @param mensajeError[] Mensaje de error
 * @param numeroAValidar Id a ser validad
 * @param mascotas[] Array de mascotas
 * @param tam Tamaño del array de mascotas
 * @return Retorna El id validado
 */
int ValidarIdMascota(char[],int, eMascota[],int);

/**
 * @fn eMascota DameUnaMascota(eMascota[], int, int)
 * @brief Obtengo una mascota con el id recibido y la devuelvo
 *
 * @param mascotas[] Array de mascotas
 * @param id ID de la mascota a buscar
 * @param tam Tamaño del array de mascotas
 * @return Devuelvo la mascota encontrada
 */
eMascota DameUnaMascota(eMascota[],int,int);

#endif /* MASCOTA_H_ */
