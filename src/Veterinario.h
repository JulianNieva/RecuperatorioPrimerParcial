/*
 * Veterinario.h
 *
 *      Author: Julian
 */

#ifndef VETERINARIO_H_
#define VETERINARIO_H_

#define MAX_VETERINARIOS 4

#define OCUPADO 1
#define VACIO 0

typedef struct
{
	int idVeterinario;
	char nombreVeterinario[50];
	int isEmpty;
}eVeterinario;

/**
 * @fn void InicializarVeterinarios(eVeterinario[], int)
 * @brief Inicializo a los veterinarios en VACIO
 *
 * @param listaVeterinarios Array de veterinarios
 * @param tam Tamaño del array de veterinario
 */
void InicializarVeterinarios(eVeterinario listaVeterinarios[],int tam);

/**
 * @fn void HardcodearVeterinarios(eVeterinario[], int)
 * @brief Hardcodeo a los veterinarios
 *
 * @param listaVeterinarios Array de veterinarios
 * @param tam Tamaño del array de veterinario
 */
void HardcodearVeterinarios(eVeterinario listaVeterinarios[],int tam);

/**
 * @fn void MostrarVeterinarios(eVeterinario[], int)
 * @brief Muestro a los veterinarios cargados actualmente
 *
 * @param listaVeterinarios Array de veterinarios
 * @param tam Tamaño del array de veterinario
 */
void MostrarVeterinarios(eVeterinario listaVeterinarios[],int tam);

/**
 * @fn void MostrarUnVeterinario(eVeterinario)
 * @brief Muestro un solo veterinario
 *
 * @param veterinario Veterinario a mostrar
 */
void MostrarUnVeterinario(eVeterinario veterinario);

/**
 * @fn int ValidarIdVeterinario(char[], int, eVeterinario[], int)
 * @brief Valido el id de veterinario que ingreso el usuario
 *
 * @param mensajeError Mensaje de error
 * @param numeroAValidar Id que ingreso el usuario
 * @param listaVeterinarios Array de veterinarios
 * @param tam Tamaño del array de veterinario
 * @return Devuelvo el Id del veterinario validado que ingreso el usuario
 */
int ValidarIdVeterinario(char mensajeError[],int numeroAValidar,eVeterinario listaVeterinario[], int tam);

/**
 * @fn eVeterinario DameUnVeterinario(eVeterinario[], int, int)
 * @brief Obtengo un veterinario con el id pasado como parametro
 *
 * @param listaVeterinarios Array de veterinarios
 * @param tam Tamaño del array de veterinario
 * @param id Id a buscar
 * @return Devuelvo el veterinario encontrado
 */
eVeterinario DameUnVeterinario(eVeterinario listaVeterinarios[],int tam,int id);

#endif /* VETERINARIO_H_ */
