/*
 * Funciones.c
 *
 *  Created on: 9 may. 2021
 *      Author: Julian Leandro Nieva 1°C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "Funciones.h"
#include "Fecha.h"
#include "Menu.h"

//PROTOTIPO DE FUNCIONES AUXILIARES//
/**
 * @fn void InicializarArrayInt(int[], int)
 * @brief Inicializo un array de contador a 0
 *
 * @param Array de contadores
 * @param Tamaño del array
 */
void InicializarArrayInt(int contador[], int tam);

/**
 * @fn void MostrarUnTrabajo(eTrabajo, eServicio, eMascota, eVeterinario)
 * @brief Muestro un solo trabajo
 *
 * @param trabajo Trabajo a mostrar
 * @param servicio Servicio a mostrar
 * @param mascota Mascota a mostrar
 * @param veterinario Veterinario a mostrar
 */
void MostrarUnTrabajo(eTrabajo trabajo, eServicio servicio,eMascota mascota,eVeterinario veterinario);

/**
 * @fn void ModificarTrabajo(eTrabajo*, eServicio[], int, eMascota[], int, eVeterinario[], int)
 * @brief Realizo las modificacion segun lo que desea el usuario
 *
 * @param trabajo Puntero al trabajo que modificare su datos
 * @param listaServicios Array de servicios
 * @param tamServicios Tamaño del array de servicios
 * @param listaMascotas Array de mascotas
 * @param tamMascotas Tamaño del array de mascotas
 * @param listaVeterinarios Array de veterinarios
 * @param tamVeterinario Tamaño del array de veterinarios
 */
void ModificarTrabajo(eTrabajo* trabajo, eServicio listaServicios[],int tamServicios,eMascota listaMascotas[],int tamMascotas,eVeterinario listaVeterinarios[], int tamVeterinarios);

/**
 * @fn void ContarServiciosUtilizados(eTrabajo[], int, eServicio[], int, int[])
 * @brief Cuento
 *
 * @param trabajos Array de trabajos
 * @param tTrabajos Tamaño del array de trabajos
 * @param servicios Array de servicios
 * @param tServicios Tamaño del array de servicios
 * @param contador Array de contador
 */
void ContarServiciosUtilizados(eTrabajo trabajos[], int tTrabajos, eServicio servicios[], int tServicios, int contador[]);

/**
 * @fn int BuscarCantidadMayorArray(int[], int)
 * @brief Busco la mayor cantidad del array
 *
 * @param Array de contadores
 * @param Tamaño del array
 * @return Devuelvo la mayor cantidad
 */
int BuscarCantidadMayorArray(int[], int);

/**
 * @fn void MostrarServiciosMasUtilizados(int, int[], int, eServicio[])
 * @brief Muestro los servicio mas utilizados
 *
 * @param mayorCantidad Mayor cantidad de servicios utilizados
 * @param contador Array de contadores
 * @param tam Tamaño del array
 * @param servicios Array de servicios
 */
void MostrarServiciosMasUtilizados(int mayorCantidad, int contador[], int tam, eServicio servicios[]);

/**
 * @fn float DamePromedioEdades(eTrabajo[], int, eMascota[], int, int)
 * @brief Devuelvo el promedio de las edades de las mascotas que realizen el servicio ingresado
 *
 * @param listaTrabajos Array de trabajos
 * @param tamTrabajos Tamaño de array de trabajos
 * @param listaMascotas Array de mascotas
 * @param tamMascotas Tamaño de array de mascotas
 * @param idServicioAux Id del servicio ingresado
 * @return Devuelvo el promedio de las edades
 */
float DamePromedioEdades(eTrabajo listaTrabajos[],int tamTrabajos,eMascota listaMascotas[],int tamMascotas,int idServicioAux);

/**
 * @fn void ContarVeterinariosQueTrabajenEnUnServicio(eTrabajo[], int, eVeterinario[], int, int[], int)
 * @brief Cuento los veterinarios que trabajen en un servicio especifico
 *
 * @param listaTrabajos Array de trabajos
 * @param tamTrabajos Tamaño de array de trabajos
 * @param listaVeterinarios Array de veterinarios
 * @param tamVeterinarios Tamaño del array de veterinarios
 * @param arrayContador Array de contador
 * @param idServicioIngresado Id del servicio que ingreso el usuario
 */
void ContarVeterinariosQueTrabajenEnUnServicio(eTrabajo listaTrabajos[],int tamTrabajos,eVeterinario listaVeterinarios[],int tamVeterinarios, int arrayContador[], int idServicioIngresado);

/**
 * @fn void MostrarVeterinariosConMayorTrabajo(int, int[], int, eVeterinario[], char[])
 * @brief Muestro los veterinario con mayor trabajo
 *
 * @param mayorCantidad Mayor cantidad de trabajos realizados
 * @param contadorArray Array del contador
 * @param tamVeterinario Tamaño del array de veterinarios
 * @param listaVeterinario Array de veterinarios
 * @param descripcionServicio Descripcion del servicio que ingreso el usuario
 */
void MostrarVeterinariosConMayorTrabajo(int mayorCantidad,int contadorArray[],int tamVeterinario,eVeterinario listaVeterinario[], char descripcionServicio[]);
//FIN DE LOS PROTOTIPOS DE FUNCIONES AUXILIARES//


int DarAltaTrabajo(eTrabajo listaTrabajos[], int tamTrabajos,eServicio servicios[],int tamServicios,eMascota mascotas[],int tamMascotas,eVeterinario veterinarios[],int tamVeterinarios, int* idTrabajo)
{
	int i;
	int idServicioAux;
	int idMascotaAux;
	int idVeterinarioAux;

	i = BuscarLibre(listaTrabajos,tamTrabajos);	//Llamo a la funcion de buscar libre y me tiene que devolver la posicion (Si encuentra uno libre)

	if(i != -1)	//Si me devuelve -1 no hay espacio, caso contrario, entra al if
	{
		listaTrabajos[i].id = *idTrabajo;
		*idTrabajo += 1;

		MostrarMascotas(mascotas,tamMascotas);
		getInt(&idMascotaAux,"Ingrese el id de la mascota: ");
		listaTrabajos[i].idMascota = ValidarIdMascota("Error. Ingrese El id de una mascota valida: ",idMascotaAux,mascotas,tamMascotas);

		MostrarServicios(servicios,tamServicios);
		getInt(&idServicioAux,"Ingrese el id del servicio deseado: ");
		listaTrabajos[i].idServicio = ValidarIdServicio("Error. Ingrese un id de un servicio valido: ", idServicioAux,servicios, tamServicios);

		MostrarVeterinarios(veterinarios,tamVeterinarios);
		getInt(&idVeterinarioAux,"Ingrese el id del veterinario al que desea asignar este trabajo: ");
		listaTrabajos[i].idVeterinario = ValidarIdVeterinario("Error. Ingrese un id de un veterinario valido",idVeterinarioAux,veterinarios, tamVeterinarios);

		listaTrabajos[i].fecha = PedirFecha();

		listaTrabajos[i].isEmpty = NOT_EMPTY;
	}

	return i;
}

void MostrarTrabajos(eTrabajo listaTrabajos[],int tamTrabajos, eServicio listaServicios[],int tamServicios, eMascota listaMascotas[],int tamMascotas,eVeterinario listaVeterinarios[],int tamVeterinario)
{
	eServicio auxServicio;
	eMascota auxMascota;
	eVeterinario auxVeterinario;
	int i;
	printf(" _____________________________________________________________________________________________________________________________\n");
	printf("|ID\t| Nombre\t| Edad  | Raza\t\t| Servicio\t\t| Precio\t| Veterinario/a\t\t| Fecha       |\n");
	printf("|_______|_______________|_______|_______________|_______________________|_______________|_______________________|_____________|\n");

	for(i = 0; i < tamTrabajos; i++)	//Realizo una iteracion
	{
		if(listaTrabajos[i].isEmpty == NOT_EMPTY)// Cuestiono si se encuentra vacio
		{
			auxServicio = DameUnServicio(listaServicios,listaTrabajos[i].idServicio,tamServicios);	//Llamo a la funcion para que me de un servicio, y para que coincida le paso el id del trabajo en la posicion actual
			auxMascota = DameUnaMascota(listaMascotas,listaTrabajos[i].idMascota,tamMascotas);
			auxVeterinario = DameUnVeterinario(listaVeterinarios,tamVeterinario,listaTrabajos[i].idVeterinario);
			MostrarUnTrabajo(listaTrabajos[i], auxServicio,auxMascota,auxVeterinario);	//Llamo a la funcion de mostrar un trabajo con su servicio correspondiente
		}
	}

	printf("|_______|_______________|_______|_______________|_______________________|_______________|_______________________|_____________|\n");
}

void MostrarUnTrabajo(eTrabajo trabajo, eServicio servicio,eMascota mascota,eVeterinario veterinario)
{
	printf("|%d\t|%s\t\t|%d \t|%s\t| %s\t        |%.2f\t\t|%s\t\t| %d/%d/%d  |\n",
									trabajo.id,mascota.nombreMascota,mascota.edadMascota,mascota.raza,servicio.descripcion,servicio.precio,veterinario.nombreVeterinario,
									trabajo.fecha.f_dia,trabajo.fecha.f_mes,trabajo.fecha.f_anio);
}

int InicializarModificacionDeTrabajo(eTrabajo listaTrabajos[], int tamTrabajos,eServicio listaServicios[],int tamServicios,eMascota listaMascotas[],int tamMascotas,eVeterinario listaVeterinarios[], int tamVeterinarios)
{
	int valor = -1;
	int id;
	int posicionId;

	getInt(&id,"Ingrese el ID del trabajo que desea modificar: ");

	posicionId = BuscarId(listaTrabajos,id,tamTrabajos);	//Busco la posicion del id que ingreso el usuario

	if(posicionId != -1)	//Si recibo -1 quiere decir que no encontro ese id, en caso contrario, entra al if
	{
		utn_getInt("Esta seguro que desea modificar este trabajo? (Ingrese 1 para aceptar, 0 para cancelar): ", "Error. Ingrese una opcion valida",0,1,6, &valor);

		if(valor)
		{
			ModificarTrabajo(&listaTrabajos[posicionId], listaServicios,tamServicios,listaMascotas,tamMascotas,listaVeterinarios,tamVeterinarios);	//Llamo a la funcion de modificar y le paso la direccion de memoria del trabajo en la posicion recibida anteriormente
		}
	}
	return valor;
}

 void ModificarTrabajo(eTrabajo* trabajo, eServicio listaServicios[],int tamServicios,eMascota listaMascotas[],int tamMascotas,eVeterinario listaVeterinarios[], int tamVeterinarios)
{
	int salir = 0;
	int idServicioAux;
	int idMascotaAux;
	int idVeterinarioAux;

	do
	{
		switch(SubMenuModificar())
		{
		case 1:
			MostrarMascotas(listaMascotas,tamMascotas);
			getInt(&idMascotaAux,"Ingrese el nuevo id de la mascota: ");
			trabajo->idMascota = ValidarIdMascota("Error. Ingrese El id de una mascota valida: ",idMascotaAux,listaMascotas,tamMascotas);
			printf("Se modifico la mascota\n");
			break;
		case 2:
			MostrarServicios(listaServicios,tamServicios);
			getInt(&idServicioAux,"Ingrese el nuevo id del servicio ");
			trabajo->idServicio = ValidarIdServicio("Error. Por favor ingrese un id valido: ", idServicioAux, listaServicios, MAX_SERVICIO);
			printf("Se modifico el servicio de este trabajo\n");
			break;
		case 3:
			MostrarVeterinarios(listaVeterinarios,tamVeterinarios);
			getInt(&idVeterinarioAux,"Ingrese el id del veterinario al que desea asignar este trabajo: ");
			trabajo->idVeterinario = ValidarIdVeterinario("Error. Ingrese un id de un veterinario valido",idVeterinarioAux,listaVeterinarios, tamVeterinarios);
			break;
		case 4:
			utn_getInt("Estas seguro que desea salir? (Ingrese 1 para aceptar, 0 para cancelar): ", "Error. ingrese una opcion valida", 0, 1, 6, &salir);
			break;
		}
	}while(!salir);

}

 void OrdenarTrabajosPorAnio(eTrabajo trabajos[],int tam,eMascota mascotas[],int tamMascotas)
 {
 	eTrabajo aux;
 	eMascota auxMascotaI;
 	eMascota auxMascotaJ;
 	int i;
 	int j;

 	for(i=0; i < tam - 1; i++)
 	{
		auxMascotaI = DameUnaMascota(mascotas,trabajos[i].idMascota,tamMascotas);
 		for(j = i+1; j < tam; j++)
 		{
 			if(trabajos[i].fecha.f_anio > trabajos[j].fecha.f_anio)//Cuestiono si es mayor al año
 			{
 				aux = trabajos[i];
 				trabajos[i] = trabajos[j];
 				trabajos[j] = aux;
 			}
 			else// En caso de que no sea mayor
 			{
 				if(trabajos[i].fecha.f_anio == trabajos[j].fecha.f_anio) // Cuestiono si es igual el año
 				{
 					auxMascotaJ = DameUnaMascota(mascotas,trabajos[j].idMascota,tamMascotas);
 					if(stricmp(auxMascotaI.nombreMascota,auxMascotaJ.nombreMascota) > 0)//Si el año es igual, comparo por el nombre de la mascota
 					{
 						aux = trabajos[i];
 						trabajos[i] = trabajos[j];
 						trabajos[j] = aux;
 					}
 				}
 			}
 		}
 	}
 }

 void OrdenarTrabajosPorNombreMascota(eTrabajo trabajos[], int tam,eMascota mascotas[],int tamMascotas)
 {
 	eTrabajo aux;
 	eMascota auxMascotaI;
 	eMascota auxMascotaJ;
 	int i;
 	int j;

 	for(i = 0; i < tam - 1; i++)
 	{
 		auxMascotaI = DameUnaMascota(mascotas,trabajos[i].idMascota,tamMascotas);
 		for(j = i+1; j < tam; j++)
 		{
 			auxMascotaJ = DameUnaMascota(mascotas,trabajos[j].idMascota,tamMascotas);
 			if(stricmp(auxMascotaI.nombreMascota,auxMascotaJ.nombreMascota) > 0)//Se compara el nombre de las mascotas
 			{
 				aux = trabajos[i];
 				trabajos[i] = trabajos[j];
 				trabajos[j] = aux;
 			}
 		}
 	}
 }

 void MostrarPrecioTotalPorLosServicioPrestados(eTrabajo trabajos[],int tamTrabajos, eServicio servicios[], int tamServicios)
 {
 	int i;
 	float acumulador = 0;
 	eServicio aux;	//Creo un aux de tipo eServicio

 	for(i = 0; i < tamTrabajos; i++)	//Realizo una iteracion
 	{
 		if(trabajos[i].isEmpty != IS_EMPTY)	//Busco si la posicion del trabajo se encuentra ocupada
 		{
 			aux = DameUnServicio(servicios,trabajos[i].idServicio,tamServicios); //Llamo a la funcion para me devuelva el servicio, y le paso el id del servicio del trabajo
 			acumulador = acumulador + aux.precio; 	//Acumulo los precios de los servicios recibidos
 		}
 	}

 	printf("El precio total de los servicio prestados es: %.2f\n", acumulador);	//Muestro el precio total
 }

void InicializarArrayInt(int contador[], int tam)
{
	 int i;

	 for(i = 0; i < tam; i++)
	 {
		 contador[i] = 0;
	 }
}

 void MostrarServiciosConMasTrabajosRealizados(eTrabajo trabajos[],int tamTrabajos, eServicio servicios[],int tamServicios)
 {
	 int contador[tamServicios];
	 int mayorCantidadServicios;

	 InicializarArrayInt(contador, tamServicios);
	 ContarServiciosUtilizados(trabajos, tamTrabajos, servicios, tamServicios,contador);
	 mayorCantidadServicios = BuscarCantidadMayorArray(contador, tamServicios);
	 MostrarServiciosMasUtilizados(mayorCantidadServicios,contador,tamServicios,servicios);
 }

 void ContarServiciosUtilizados(eTrabajo trabajos[], int tTrabajos, eServicio servicios[], int tServicios, int contador[])
 {
	 int i;
	 int j;

	 for(i = 0; i < tTrabajos; i++)
	 {
		 for(j = 0; j < tServicios; j++)
		 {
			 if(trabajos[i].idServicio == servicios[j].idServicio)
			 {
				 contador[j]++;
			 }
		 }
	 }
 }

 int BuscarCantidadMayorArray(int contador[], int tam)
 {
	int i;
	int mayorCantidad;

	mayorCantidad = contador[0];

	for(i = 0; i < tam; i++)
	{
		if(mayorCantidad < contador[i])
		{
			mayorCantidad = contador[i];
		}
	}

	return mayorCantidad;
 }

 void MostrarServiciosMasUtilizados(int mayorCantidad, int contador[], int tam, eServicio servicios[])
 {
	 int i;

	printf("Los servicios mas utilizados son: \n");

	printf("_________________________________________________\n");
	printf("|Id\t| Descripcion\t\t| Precio\t|\n");
	printf("|_______|_______________________|_______________|\n");

	 for(i = 0; i < tam; i++)
	 {
		 if(mayorCantidad == contador[i])
		 {
			 MostrarUnServicio(servicios[i]);
		 }
	 }

	 printf("|_______|_______________________|_______________|\n");
 }

 void ListarServiciosConMascotas(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[],int tamServicios,eMascota listaMascotas[],int tamMascotas)
 {
	 int i;
	 int j;
	 eMascota aux;
	 int hayMascotas;

	 printf("__________________________________________________________________________\n");
	 printf("| Servicio\t| Nombre\t\t| Edad\t\t| Raza\t\t  |\n");
	 printf("|_______________|_______________________|_______________|_________________|\n");
	 for(i = 0; i < tamServicios; i++)
	 {
		 hayMascotas = 0;
		 printf("|%s\t",listaServicios[i].descripcion);
		 for(j = 0; j < tamTrabajos;j++)
		 {
			 if(listaTrabajos[j].isEmpty != IS_EMPTY && listaTrabajos[j].idServicio == listaServicios[i].idServicio)
			 {
				 hayMascotas = 1;
				 aux = DameUnaMascota(listaMascotas,listaTrabajos[j].idMascota,tamMascotas);
				 printf("|%s\t\t\t|\t%d\t|%s\t  |\n",aux.nombreMascota,aux.edadMascota,aux.raza);
				 printf("|\t\t");
			 }
		 }

		 if(hayMascotas){
			 printf("|_______________________|_______________|_________________|\n");
		 }
		 else{
			 printf("|_______________________|_______________|_________________|\n");
		 }
	 }
	 printf("|_______________|_______________________|_______________|_________________|\n");
 }

 void MostrarPromedioDeEdadesMascotasSegunServicio(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[],int tamServicios,eMascota listaMascotas[],int tamMascotas)
 {
	 int idServicioAux;
	 float promedioEdades;

	 MostrarServicios(listaServicios,tamServicios);
	 getInt(&idServicioAux,"Ingrese el id del servicio que desea sacar el promedio de edades: ");
	 idServicioAux = ValidarIdServicio("Error. ingrese un id de un servicio valido: ", idServicioAux,listaServicios, tamServicios);

	 promedioEdades = DamePromedioEdades(listaTrabajos,tamTrabajos,listaMascotas,tamMascotas,idServicioAux);

	 if(promedioEdades != 0)
	 {
		 printf("El promedio de edad de las mascotas que utilizan este servicio es: %.2f\n",promedioEdades);
	 }
	 else
	 {
		 printf("No hay mascotas que utilizen este servicio\n");
	 }
 }

float DamePromedioEdades(eTrabajo listaTrabajos[],int tamTrabajos,eMascota listaMascotas[],int tamMascotas,int idServicioAux)
{
	float resultado = 0;
	int acumulador = 0;
	int contador = 0;
	int i;
	eMascota auxMascota;

	for(i = 0; i < tamTrabajos;i++)
	{
		if(listaTrabajos[i].isEmpty != IS_EMPTY && listaTrabajos[i].idServicio == idServicioAux)
		{
			auxMascota = DameUnaMascota(listaMascotas,listaTrabajos[i].idMascota,tamMascotas);
			acumulador += auxMascota.edadMascota;
			contador++;
		}
	}

	if(contador != 0)
	{
		resultado = (float)acumulador/contador;
	}

	return resultado;
}

void MostrarTrabajosConUnServicioYMascotaEspecifica(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[],int tamServicios,eMascota listaMascotas[],int tamMascotas,eVeterinario listaVeterinarios[],int tamVeterinarios)
{
	int auxIdMascota;
	int auxIdServicio;
	int i;
	eVeterinario auxVeterinario;
	eMascota auxMascota;
	eServicio auxServicio;

	MostrarServicios(listaServicios,tamServicios);
	getInt(&auxIdServicio,"Ingrese el id del servicio para filtrar los trabajos: ");
	auxIdServicio = ValidarIdServicio("Error. ingrese un id de un servicio valido: ", auxIdServicio,listaServicios, tamServicios);

	MostrarMascotas(listaMascotas,tamMascotas);
	getInt(&auxIdMascota,"Ingrese el id de la mascota filtrar los trabajos: ");
	ValidarIdMascota("Error. Ingrese El id de una mascota valida: ",auxIdMascota,listaMascotas,tamMascotas);

	auxMascota = DameUnaMascota(listaMascotas,auxIdMascota,tamMascotas);
	auxServicio =  DameUnServicio(listaServicios,auxIdServicio,tamServicios);

	printf(" _____________________________________________________________________________________________________________________________\n");
	printf("|ID\t| Nombre\t| Edad  | Raza\t\t| Servicio\t\t| Precio\t| Veterinario/a\t\t| Fecha       |\n");
	printf("|_______|_______________|_______|_______________|_______________________|_______________|_______________________|_____________|\n");

	for(i = 0; i < tamTrabajos; i++)
	{
		if(listaTrabajos[i].isEmpty != IS_EMPTY && listaTrabajos[i].idMascota == auxIdMascota && listaTrabajos[i].idServicio == auxIdServicio)
		{
			auxVeterinario = DameUnVeterinario(listaVeterinarios,tamVeterinarios,listaTrabajos[i].idVeterinario);
			MostrarUnTrabajo(listaTrabajos[i],auxServicio,auxMascota,auxVeterinario);
		}
	}
	printf("|_______|_______________|_______|_______________|_______________________|_______________|_______________________|_____________|\n");

}

void MostrarVeterinariosConMasTrabajosEnUnServicio(eTrabajo listaTrabajos[],int tamTrabajos,eServicio listaServicios[],int tamServicios,eVeterinario listaVeterinarios[],int tamVeterinarios)
{
	int auxIdServicio;
	int arrayContador[tamVeterinarios];
	int mayorCantidadVeterinarios;
	eServicio aux;

	InicializarArrayInt(arrayContador, tamVeterinarios);

	MostrarServicios(listaServicios,tamServicios);
	getInt(&auxIdServicio,"Ingrese el id del servicio para determinar que veterinario tiene mayor trabajo con ese servicio: ");
	auxIdServicio = ValidarIdServicio("Error. ingrese un id de un servicio valido: ", auxIdServicio,listaServicios, tamServicios);

	ContarVeterinariosQueTrabajenEnUnServicio(listaTrabajos,tamTrabajos,listaVeterinarios,tamVeterinarios, arrayContador,auxIdServicio);
	mayorCantidadVeterinarios = BuscarCantidadMayorArray(arrayContador,tamVeterinarios);

	if(mayorCantidadVeterinarios != 0)
	{
		aux = DameUnServicio(listaServicios, auxIdServicio,tamServicios);
		MostrarVeterinariosConMayorTrabajo(mayorCantidadVeterinarios,arrayContador,tamVeterinarios,listaVeterinarios, aux.descripcion);
	}
	else
	{
		printf("No hay ningun veterinario que trabaje en ese servicio\n");
	}
}

void ContarVeterinariosQueTrabajenEnUnServicio(eTrabajo listaTrabajos[],int tamTrabajos,eVeterinario listaVeterinarios[],int tamVeterinarios, int arrayContador[], int idServicioIngresado)
{
	int i;
	int j;

	for(i = 0; i< tamTrabajos; i++)
	{
		if(listaTrabajos[i].isEmpty != IS_EMPTY && listaTrabajos[i].idServicio == idServicioIngresado)
		{
			for(j = 0; j < tamVeterinarios; j++)
			{
				if(listaTrabajos[i].idVeterinario == listaVeterinarios[j].idVeterinario)
				{
					arrayContador[j]++;
					break;
				}
			}
		}
	}
}

void MostrarVeterinariosConMayorTrabajo(int mayorCantidad,int contadorArray[],int tamVeterinario,eVeterinario listaVeterinario[], char descripcionServicio[])
{
	int i;

	printf("Los veterinarios que trabajan en el servicio %s son: \n",descripcionServicio);

	printf(" _______________________________\n");
	printf("|ID\t|Nombre\t\t\t|\n");
	printf("|_______|_______________________|\n");

	for(i = 0; i < tamVeterinario; i++)
	{
		if(mayorCantidad == contadorArray[i])
		{
			MostrarUnVeterinario(listaVeterinario[i]);
		}
	}
	printf("|_______|_______________________|\n");
}
