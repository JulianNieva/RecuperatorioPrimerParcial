/*
 * Menu.c
 *
 *  Created on: 3 jul. 2021
 *      Author: Julian
 */
#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "Input.h"

int MenuPrincipal(void)
{
	int opcion;

	printf("1. ALTA trabajo\n");
	printf("2. MODIFICAR trabajo\n");
	printf("3. BAJA trabajo\n");
	printf("4. LISTAR trabajos\n");
	printf("5. LISTAR servicios\n");
	printf("6. Mostrar el total de los servicios prestados\n");
	printf("7. Listado de los trabajos ordenados por nombre de mascota\n");
	printf("8. El/los servicios con mas trabajos realizados\n");
	printf("9. Listar servicios con sus respectivas mascotas\n");
	printf("10. Promedio de edades de las mascotas\n");
	printf("11. Listar trabajos con un servicio y mascota especifica\n");
	printf("12. Listar veterinarios con mas trabajos en un servicio\n");
	printf("13. Salir\n");

	utn_getInt("Elija una opcion: ", "Error. Por favor ingrese una opcion valida.. ", 1, 13,6, &opcion);

	return opcion;
}

int SubMenuModificar(void)
{
	int opcion;

	printf("1. Mascota\n");
	printf("2. Servicio\n");
	printf("3. Veterinario\n");
	printf("4. Salir\n");
	utn_getInt("Elija una opcion: ", "Error. Ingrese una opcion valida",1,4,6, &opcion);

	return opcion;
}


