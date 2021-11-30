
#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Libros.h"
#include "Editoriales.h"
#include "Biblioteca.h"
#include "Parser.h"
#include "LinkedList.h"
#include "FuncionesMixtas.h"

int Controller_CargarDatosDeLibros(char* path, LinkedList* this);
int Controller_CargarDaatosDeEditoriales(char* path, LinkedList* this);
int Controller_OrdenarListaPorAutores(LinkedList* ll_libros);
int Controller_VerListadoDeLibros(LinkedList* ll_libros, LinkedList* ll_editoriales);
int Controller_LibrosDeMinotauro(char* path,LinkedList* ll_libros);
int Controller_DescuentosYGuardado(char* path, LinkedList* ll_libros);

#endif
