/*
 ============================================================================
 Name        : Laboratorio_I_segundo_Parcial.c
 Author      : DI PINO GONZALO
 Version     :
 Copyright   : Your copyright notice
 Description :Un programa que realice lo siguiente:
1. Leer un archivo con los datos de libros, guard�ndolos en un linkedList de entidades
eLibro.
ACLARACI�N: El nombre del archivo se debe pasar como par�metro por l�nea de
comandos.
2. Leer un archivo con los datos de editoriales, guard�ndolos en un linkedList de entidades
eEditorial.
ACLARACI�N: El nombre del archivo se debe pasar como par�metro por l�nea de
comandos.
3. Ordenar la lista generada en el �tem anterior, con la funci�n ll_sort, seg�n el criterio de
ordenamiento �Autor� de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros.
ACLARACI�N: Se deber� imprimir la descripci�n de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deber� utilizar la
funci�n ll_filter* del LinkedList. Guardar el listado en un archivo csv.
Detalle de la funci�n �ll_filter()�
Prototipo de la funci�n:
LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element))
La funci�n �ll_filter� recibir� una lista y una funci�n criterio �fn�. Se deber� iterar todos los elementos
de la lista y pasarlos a la funci�n �fn�. La funci�n �fn� devolver� 1 si ese �tem se debe agregar a la
lista resultado o 0 si no debe agregarse. La funci�n �ll_filter� generar� la nueva lista resultado,
agregar� a la misma los �tems correspondientes y la devolver�.
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
