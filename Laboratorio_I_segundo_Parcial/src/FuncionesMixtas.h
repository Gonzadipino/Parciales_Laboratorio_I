#ifndef FUNCIONESMIXTAS_H_
#define FUNCIONESMIXTAS_H_
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "LinkedList.h"
#include "Libros.h"
#include "Editoriales.h"

int Mixtas_VerListado(LinkedList* ll_libros, LinkedList* ll_editoriales);
void MostrarCabecera(void);
void ImprimirUnLibro(int id, char* titulo, char* autor, float precio, char* descripcion);

int Mixtas_OrdenarPorAutores(LinkedList* ll_libros);


#endif
