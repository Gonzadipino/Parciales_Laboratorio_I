/*
 ============================================================================
 Name        : Laboratorio_I_segundo_Parcial.c
 Author      : DI PINO GONZALO
 Version     :
 Copyright   : Your copyright notice
 Description :Un programa que realice lo siguiente:
1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades
eLibro.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.
2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades
eEditorial.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de
comandos.
3. Ordenar la lista generada en el ítem anterior, con la función ll_sort, según el criterio de
ordenamiento “Autor” de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros.
ACLARACIÓN: Se deberá imprimir la descripción de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la
función ll_filter* del LinkedList. Guardar el listado en un archivo csv.
Detalle de la función “ll_filter()”
Prototipo de la función:
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
La función “ll_filter” recibirá una lista y una función criterio “fn”. Se deberá iterar todos los elementos
de la lista y pasarlos a la función “fn”. La función “fn” devolverá 1 si ese ítem se debe agregar a la
lista resultado o 0 si no debe agregarse. La función “ll_filter” generará la nueva lista resultado,
agregará a la misma los ítems correspondientes y la devolverá.
 ============================================================================
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Biblioteca.h"
#include "Controller.h"
#include "LinkedList.h"
#include "Libros.h"
#include "Editoriales.h"

#define TAM_LIBROS 300
#define TAM_EDITORIALES 6

int main(void) {

	int opcion = -1;
	setbuf(stdout, NULL);
	LinkedList* ll_libros = NULL;
	LinkedList* ll_Editoriales = NULL;

	ll_libros = ll_newLinkedList();
	ll_Editoriales = ll_newLinkedList();





	do {
		system("cls");
		printf("* * * * * * * * * * * * * * * * LIBROS Y EDITORIALES * * * * * * * * * * * * * * * \n");
		printf("*                                                                                *\n");
		printf("* 1 - Cargar los datos de los libros desde el archivo Libros.csv                 *\n");
		printf("* 2 - Cargar los datos de las editoriales desd el archivo Editoriales.csv        *\n");
		printf("* 3 - Ordenar la lista por autores                                               *\n");
		printf("* 4 - Ver listado de libros                                                      *\n");//mostrar editorial
		printf("* 5 - Listado de los libros de la editorial MINOTAURO                            *\n");
		printf("* 6 - dar descuentos y crear nueva lista                                         *\n");
		printf("* 0 - Salir                                                                      *\n");
		printf("*                                                                                *\n");
		printf("* * * * * * * * * * * * * * * * * * * *  * * * * * * * * * * * * * * * * * * * * * \n\n");
		opcion = LoadInt("   OPCION : ", 0, 6);

		switch(opcion) {

		case 1:
			Controller_CargarDatosDeLibros("LIBROS.CSV",ll_libros);
			break;

		case 2:
			Controller_CargarDaatosDeEditoriales("EDITORIALES.CSV", ll_Editoriales);
			break;

		case 3:
			Controller_OrdenarListaPorAutores(ll_libros);
			break;

		case 4:
			system("cls");
			Controller_VerListadoDeLibros(ll_libros, ll_Editoriales);
			break;

		case 5:

			Controller_LibrosDeMinotauro("MINOTAURO.csv", ll_libros);
			break;
		case 6:

			Controller_DescuentosYGuardado("MAPEADO.csv", ll_libros);
			break;

		}


	} while(opcion != 0);
	system("cls");
	ll_deleteLinkedList(ll_libros);
	ll_deleteLinkedList(ll_Editoriales);

	printf("SEGUNDO PARCIAL LABORATORIO\n");
	printf("Alumno: Di Pino Gonzalo\n");
	printf("Div.: F Turno Noche\n");
	printf("Nov. 2021\n");
	system("pause");

	return EXIT_SUCCESS;
}
