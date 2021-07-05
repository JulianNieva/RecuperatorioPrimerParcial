/*
 * Funciones.h
 *
 *  Created on: 9 may. 2021
 *      Author: Julian Leandro Nieva 1°C
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include "Trabajo.h"
#include "Servicio.h"
#include "Mascota.h"
#include "Veterinario.h"

/**
 * @fn int DarAltaTrabajo(eTrabajo[], int, eServicio[], int, eMascota[], int, eVeterinario[], int, int*)
 * @brief Cargo un trabajo a la lista
 *
 * @param listaTrabajos Array de trabajos
 * @param tamTrabajos Tamaño del array de trabajos
 * @param servicios Array de servicios
 * @param tamServicios Tamaño del array de servicios
 * @param mascotas Array de mascotas
 * @param tamMascotas Tamaño del array de mascotas
 * @param veterinarios Array de veterinarios
 * @param tamVeterinarios Tamaño del array de veterinarios
 * @param idTrabajo Puntero al id que se le asignara al nuevo trabajo
 * @return Devuelvo -1 si no hay mas espacio, Devuelvo un numero distinto a -1 si se agrego a la lista
 */
int DarAltaTrabajo(eTrabajo listaTrabajos[], int tamTrabajos,eServicio servicios[],int tamServicios,eMascota mascotas[],int tamMascotas,eVeterinario veterinarios[],int tamVeterinarios, int* idTrabajo);

/**
 * @fn void MostrarTrabajos(eTrabajo[], int, eServicio[], int, eMascota[], int, eVeterinario[], int)
 * @brief Muestro la lista de trabajos cargados
 *
 * @param listaTrabajos Array de trabajos
 * @param tamTrabajos Tamaño del array de trabajos
 * @param listaServicios Array de servicios
 * @param tamServicios Tamaño del array de servicios
 * @param listaMascotas Array de mascotas
 * @param tamMascotas Tamaño del array de mascotas
 * @param listaVeterinarios Array de veterinarios
 * @param tamVeterinario Tamaño del array de veterinarios
 */
void MostrarTrabajos(eTrabajo listaTrabajos[],int tamTrabajos, eServicio listaServicios[],int tamServicios, eMascota listaMascotas[],int tamMascotas,eVeterinario listaVeterinarios[],int tamVeterinario);

/**
 * @fn int InicializarModificacionDeTrabajo(eTrabajo[], int, eServicio[], int, eMascota[], int, eVeterinario[], int)
 * @brief Inicio el proceso de modificarion de un trabajo
 *
 * @param listaTrabajos Array de trabajos
 * @param tamTrabajos Tamaño del array de trabajos
 * @param listaServicios Array de servicios
 * @param tamServicios Tamaño del array de servicios
 * @param listaMascotas Array de mascotas
 * @param tamMascotas Tamaño del array de mascotas
 * @param listaVeterinarios Array de veterinarios
 * @param tamVeterinario Tamaño del array de veterinarios
 * @return Devuelvo -1 si no se encontro el trabajo, 0 si se cancelo la operacion de modificacion, 1 si acepto la modificacion
 */
int InicializarModificacionDeTrabajo(eTrabajo listaTrabajos[], int tamTrabajos,eServicio listaServicios[],int tamServicios,eMascota listaMascotas[],int tamMascotas,eVeterinario listaVeterinarios[], int tamVeterinarios);

/**
 * @fn void OrdenarTrabajosPorAnio(eTrabajo[], int, eMascota[], int)
 * @brief Ordeno los trabajos por año
 *
 * @param trabajos Array de trabajos
 * @param tam Tamaño del array de trabajos
 * @param mascotas Array de mascotas
 * @param tamMascotas Tamaño del array de mascotas
 */
void OrdenarTrabajosPorAnio(eTrabajo trabajos[],int tam,eMascota mascotas[],int tamMascotas);

/**
 * @fn void OrdenarTrabajosPorNombreMascota(eTrabajo[], int, eMascota[], int)
 * @brief Ordeno los trabajos por nombre de mascota
 *
 * @param trabajos Array de trabajos
 * @param tam Tamaño del array de trabajos
 * @param mascotas Array de mascotas
 * @param tamMascotas Tamaño del array de mascotas
 */
void OrdenarTrabajosPorNombreMascota(eTrabajo trabajos[], int tam,eMascota mascotas[],int tamMascotas);

/**
 * @fn void MostrarPrecioTotalPorLosServicioPrestados(eTrabajo[], int, eServicio[], int)
 * @brief Muestro el precio total de los servicios cargados en la lista de trabajos
 *
 * @param trabajos Array de trabajos
 * @param tam Tamaño del array de trabajos
 * @param servicios Array de servicios
 * @param tamServicios Tamaño del array de servicios
 */
void MostrarPrecioTotalPorLosServicioPrestados(eTrabajo trabajos[],int tamTrabajos, eServicio servicios[], int tamServicios);

/**
 * @fn void MostrarServiciosConMasTrabajosRealizados(eTrabajo[], int, eServicio[], int)
 * @brief Inicio el proceso de mostrar los servicios con mas trabajos
 *
 * @param trabajos Array de trabajos
 * @param tam Tamaño del array de trabajos
 * @param servicios Array de servicios
 * @param tamServicios Tamaño del array de servicios
 */
void MostrarServiciosConMasTrabajosRealizados(eTrabajo trabajos[],int tamTrabajos, eServicio servicios[],int tamServicios);

/**
 * @fn void ListarServiciosConMascotas(eTrabajo[], int, eServicio[], int, eMascota[], int)
 * @brief Listo los servicios con la mascota que le corresponde
 *
 * @param listaTrabajos Array de trabajos
 * @param tamTrabajos Tamaño de array de trabajos
 * @param listaServicios Array de servicios
 * @param tamServicios Tamaño de array de servicios
 * @param listaMascotas Array de mascotas
 * @param tamMascotas Tamaño de array de mascotas
 */
void ListarServiciosConMascotas(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[],int tamServicios,eMascota listaMascotas[],int tamMascotas);

/**
 * @fn void MostrarPromedioDeEdadesMascotasSegunServicio(eTrabajo[], int, eServicio[], int, eMascota[], int)
 * @brief Muestro el promedio de edades de mascotas segun el servicio elegido
 *
 * @param listaTrabajos Array de trabajos
 * @param tamTrabajos Tamaño de array de trabajos
 * @param listaServicios Array de servicios
 * @param tamServicios Tamaño de array de servicios
 * @param listaMascotas Array de mascotas
 * @param tamMascotas Tamaño de array de mascotas
 */
void MostrarPromedioDeEdadesMascotasSegunServicio(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[],int tamServicios,eMascota listaMascotas[],int tamMascotas);

/**
 * @fn void MostrarVeterinariosQueTrabajenEnUnServicioYMascotaEspecifico(eTrabajo[], int, eServicio[], int, eMascota[], int, eVeterinario[], int)
 * @brief Muestro los trabajos con un servicio y una mascota especifica ingresada por el usuario
 *
 * @param listaTrabajos Array de trabajos
 * @param tamTrabajos Tamaño de array de trabajos
 * @param listaServicios Array de servicios
 * @param tamServicios Tamaño de servicios
 * @param listaMascotas Array de mascotas
 * @param tamMascotas Tamaño de array de mascotas
 * @param listaVeterinarios Array de veterinarios
 * @param tamVeterinarios Tamaño del array de veterinarios
 */
void MostrarTrabajosConUnServicioYMascotaEspecifica(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[],int tamServicios,eMascota listaMascotas[],int tamMascotas,eVeterinario listaVeterinarios[],int tamVeterinarios);

/**
 * @fn void MostrarVeterinariosConMasTrabajosEnUnServicio(eTrabajo[], int, eServicio[], int, eVeterinario[], int)
 * @brief Muestro los veterinarios con mas trabajo en un servicio ingresado por el usuario
 *
 * @param listaTrabajos Array de trabajos
 * @param tamTrabajos Tamaño de array de trabajos
 * @param listaServicios Array de servicios
 * @param tamServicios Tamaño de servicios
 * @param listaVeterinarios Array de veterinarios
 * @param tamVeterinarios Tamaño del array de veterinarios
 */
void MostrarVeterinariosConMasTrabajosEnUnServicio(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[],int tamServicios,eVeterinario listaVeterinarios[],int tamVeterinarios);

#endif /* FUNCIONES_H_ */
