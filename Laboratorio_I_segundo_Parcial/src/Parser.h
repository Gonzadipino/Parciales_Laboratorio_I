
#ifndef PARSER_H_
#define PARSER_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Biblioteca.h"
#include "LinkedList.h"
#include "Libros.h"
#include "Editoriales.h"


int Parser_Libros(FILE* pArchivo, LinkedList* this);
int Parser_Editoriales(FILE* pArchivo, LinkedList* this);

int Parser_CargarLista(FILE* pArchivo, LinkedList* this);

#endif
