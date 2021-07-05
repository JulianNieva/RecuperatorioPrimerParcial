/*
 ============================================================================
 Name        : Parcial2021.c
 Author      : Julian Leandro Nieva 1°C
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Servicio.h"
#include "Trabajo.h"
#include "Mascota.h"
#include "Veterinario.h"
#include "Fecha.h"
#include "Input.h"
#include "Funciones.h"
#include "Menu.h"

int main(void)
{
	eServicio listaServicios[MAX_SERVICIO];
	eTrabajo listaTrabajos[MAX_TRABAJOS];
	eMascota listaMascotas[MAX_MASCOTAS];
	eVeterinario listaVeterinarios[MAX_VETERINARIOS];

	int retornoFuncion;
	int salir = 0;
	int contadorTrabajosCargados = 0;
	int idAutoIncremental = 1;

	setbuf(stdout,NULL);

	IncializarServicios(listaServicios,MAX_SERVICIO);
	HardcodearServicios(listaServicios,MAX_SERVICIO);
	InicializarMascotas(listaMascotas,MAX_MASCOTAS);
	HardcodearMascotas(listaMascotas,MAX_MASCOTAS);
	InicializarVeterinarios(listaVeterinarios,MAX_VETERINARIOS);
	HardcodearVeterinarios(listaVeterinarios,MAX_VETERINARIOS);
	InicializarTrabajos(listaTrabajos,MAX_TRABAJOS);

	do{
		switch(MenuPrincipal())
		{
		case 1:
			retornoFuncion = DarAltaTrabajo(listaTrabajos,MAX_TRABAJOS,listaServicios,MAX_SERVICIO,listaMascotas,MAX_MASCOTAS,listaVeterinarios,MAX_VETERINARIOS,&idAutoIncremental);
			if(retornoFuncion != -1)
			{
				printf("Se dio de alta el trabajo con exito!\n");
				contadorTrabajosCargados++;
			}
			else
			{
				printf("No hay mas espacio disponible\n");
			}
			break;
		case 2:
			if(contadorTrabajosCargados != 0)
			{
				MostrarTrabajos(listaTrabajos,MAX_TRABAJOS,listaServicios,MAX_SERVICIO,listaMascotas,MAX_MASCOTAS,listaVeterinarios,MAX_VETERINARIOS);
				retornoFuncion = InicializarModificacionDeTrabajo(listaTrabajos,MAX_TRABAJOS,listaServicios,MAX_SERVICIO,listaMascotas,MAX_MASCOTAS,listaVeterinarios,MAX_VETERINARIOS);
				if(retornoFuncion == -1)
				{
					printf("No se encontro la id del trabajo\n");
				}
				else
				{
					if(retornoFuncion == 0)
					{
						printf("Se cancelo la operacion\n");
					}
				}
			}
			else
			{
				printf("No hay trabajos para modificar\n");
			}
			break;
		case 3:
			if(contadorTrabajosCargados != 0)
			{
				MostrarTrabajos(listaTrabajos,MAX_TRABAJOS,listaServicios,MAX_SERVICIO,listaMascotas,MAX_MASCOTAS,listaVeterinarios,MAX_VETERINARIOS);
				retornoFuncion = DarDeBajaDeTrabajo(listaTrabajos,MAX_TRABAJOS);
				if(retornoFuncion == -1)
				{
					printf("No se encontro la id del trabajo\n");
				}
				else
				{
					if(retornoFuncion == 0)
					{
						printf("Se cancelo la operacion\n");
					}
					else
					{
						printf("Se dio de baja el trabajo con exito!\n");
						contadorTrabajosCargados--;
					}
				}
			}
			else
			{
				printf("No hay trabajos para dar de baja\n");
			}
			break;
		case 4:
			if(contadorTrabajosCargados != 0)
			{
				OrdenarTrabajosPorAnio(listaTrabajos,MAX_TRABAJOS,listaMascotas,MAX_MASCOTAS);
				MostrarTrabajos(listaTrabajos,MAX_TRABAJOS,listaServicios,MAX_SERVICIO,listaMascotas,MAX_MASCOTAS,listaVeterinarios,MAX_VETERINARIOS);
			}
			else
			{
				printf("No hay trabajos para listar\n");
			}
			break;
		case 5:
			MostrarServicios(listaServicios,MAX_SERVICIO);
			break;
		case 6:
			if(contadorTrabajosCargados != 0)
			{
				MostrarPrecioTotalPorLosServicioPrestados(listaTrabajos,MAX_TRABAJOS,listaServicios,MAX_SERVICIO);
			}
			else
			{
				printf("No hay trabajos para sacar el precio de los servicios prestados\n");
			}
			break;
		case 7:
			if(contadorTrabajosCargados != 0)
			{
				OrdenarTrabajosPorNombreMascota(listaTrabajos,MAX_TRABAJOS,listaMascotas,MAX_MASCOTAS);
				MostrarTrabajos(listaTrabajos,MAX_TRABAJOS,listaServicios,MAX_SERVICIO,listaMascotas,MAX_MASCOTAS,listaVeterinarios,MAX_VETERINARIOS);
			}
			else
			{
				printf("No hay trabajos para listar\n");
			}
			break;
		case 8:
			if(contadorTrabajosCargados != 0)
			{
				MostrarServiciosConMasTrabajosRealizados(listaTrabajos,MAX_TRABAJOS, listaServicios,MAX_SERVICIO);
			}
			else
			{
				printf("No hay trabajos para sacar los servicios mas utilizados\n");
			}
			break;
		case 9:
			if(contadorTrabajosCargados != 0)
			{
				ListarServiciosConMascotas(listaTrabajos,MAX_TRABAJOS,listaServicios,MAX_SERVICIO,listaMascotas,MAX_MASCOTAS);
			}
			else
			{
				printf("No hay trabajos Para poder listar servicios con sus mascotas\n");
			}
			break;
		case 10:
			if(contadorTrabajosCargados != 0)
			{
				MostrarPromedioDeEdadesMascotasSegunServicio(listaTrabajos,MAX_TRABAJOS,listaServicios,MAX_SERVICIO,listaMascotas,MAX_MASCOTAS);
			}
			else
			{
				printf("No hay trabajos para mostrar el promedio de edad de las mascotas\n");
			}
			break;
		case 11:
			if(contadorTrabajosCargados != 0)
			{
				MostrarTrabajosConUnServicioYMascotaEspecifica(listaTrabajos,MAX_TRABAJOS,listaServicios,MAX_SERVICIO,listaMascotas,MAX_MASCOTAS,listaVeterinarios,MAX_VETERINARIOS);
			}
			else
			{
				printf("No hay trabajos cargados para mostrar veterinarios\n");
			}
			break;
		case 12:
			if(contadorTrabajosCargados != 0)
			{
				MostrarVeterinariosConMasTrabajosEnUnServicio(listaTrabajos,MAX_TRABAJOS,listaServicios,MAX_SERVICIO,listaVeterinarios,MAX_VETERINARIOS);
			}
			else
			{
				printf("No hay trabajos cargados para determinar que veterinario tiene mas trabajos\n");
			}
			break;
		case 13:
			utn_getInt("Estas seguro que desea salir? (Ingrese 1 para aceptar, 0 para cancelar): ", "Error. ingrese una opcion valida", 0, 1, 6, &salir);
			break;
		}
	}while(!salir);

}
