/*

NOTAS:
Nota 0: El código deberá tener comentarios con la documentación de cada una de las funciones y respetar las
reglas de estilo de la cátedra.
Nota 1: Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Nota 2: Se deberán utilizar las bibliotecas LinkedList, Libro y Editorial (desarrollando las funciones setter y getter
necesarias).
Nota 3: Los datos (editoriales y libros) deberán estar en listas separadas, realizando las relaciones
correspondientes entre las entidades.
Nota 4: Utilizar MVC (modelo vista controlador)
 */

#ifndef LIBROS_H_
#define LIBROS_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int id;
	char titulo[50];
	char autor[50];
	float precio;
	int idEditorial;
}eLibro;

eLibro* Nuevo_Libro();
eLibro* Libros_NuevosParametros(char* id, char* titulo, char* autor, char* precio, char* idEditorial);
void Borrar_Libro(eLibro* this);

int Libro_SetId(eLibro* libro, int id);
int Libro_GetId(eLibro* libro, int* id);

int Libro_SetTitulo(eLibro* libro, char* titulo);
int Libro_GetTitulo(eLibro* libro, char* titulo);

int Libro_SetAutor(eLibro* libro, char* autor);
int Libro_GetAutor(eLibro* libro, char* autor);

int Libro_SetPrecio(eLibro* libro, float precio);
int Libro_GetPrecio(eLibro* libro, float* precio);

int Libro_SetIdEditorial(eLibro* libro, int idEditorial);
int Libro_GetIdEditorial(eLibro* libro, int* idEditorial);

int compareByName(void* libroUno,void* libroDos);

int FuncionFiltroPorEditorial(void* libro);
int FuncionFiltroPorPrecioYEditorial(void* libro);

#endif /* LIBROS_H_ */
