#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "Editoriales.h"

/*
 * Crea un espacio en memoria dinamica del tamaño de la estructura eEditorial.
 * retorna el puntero a la direccion dinamica de eEditorial o NULL si no encuentra espacio
 */
eEditorial* Nueva_Editorial() {

	eEditorial* pNewEditorial = NULL;

	pNewEditorial = (eEditorial*) malloc ( sizeof(eEditorial));

	return pNewEditorial;
}

/*
 * Constructor parametrizado de eEditorial
 * valida y setea los datos en una estructura de tipo eEditorial y la retorna o retorna NULL de no poder acceder a la dir. de memoria
 * parametros: char* idEdirtorial, puntero al id de la editorial, char* nombre, puntero a nombre de la editorial
 *
 * retorna eEditorial = NULL o retorna eEditorial cargado
 */

eEditorial* Editorial_NuevosParametros(char* idEditorial, char* nombre) {

	eEditorial* pNewEditorial = NULL;

	pNewEditorial = Nueva_Editorial();

	if(pNewEditorial != NULL) {

		Editorial_SetId(pNewEditorial, atoi(idEditorial));
		Editorial_SetNombre(pNewEditorial, nombre);

	} else {

		Borrar_Editorial(pNewEditorial);
		pNewEditorial = NULL;
	}

	return pNewEditorial;
}

/*
 * Borra la editorial indicada y libera el espacio en memoria
 * parametro eEditorial*, puntero a la estructura del tipo editorial
 */
void Borrar_Editorial(eEditorial* this) {

	if(this != NULL) {

		free(this);
		this = NULL;
	}
}

/*
 * valida que el puntero a la estructura no sea NULL y que el id pasado como parametro no sea menor a 0;
 * setea dentro de esta estructura el id pasado como parametro.
 * parametros: eEditorial* puntero a la estructura editorial, id, id pasado como parametro.
 * retorna -1 si no pudo cargar el dato dentro de la estructura o 0 si pudo hacerlo.
 */
int Editorial_SetId(eEditorial* editorial, int idEditorial) {

	int retorno = -1;
	if(editorial != NULL) {

		editorial->idEditorial = idEditorial;
		retorno = 0;
	}

	return retorno;
}

/*
 *Obtiene la direccion de memoria del campo id de la estructura eEditorial y lo copia dentro del id de la editorial pasado como parametro.
 *parametros: eEditorial puntero a la estructura de tipo editorial, *idEditorial direccion de memoria donde guardare el dato de la estructura.
 * retorna -1 si los parametros son NULL y 0 si pudo cargar el dato.
 */
int Editorial_GetId(eEditorial* editorial, int* idEditorial) {

	int retorno = -1;
	if(editorial != NULL) {

		*idEditorial = editorial->idEditorial;
		retorno  = 0;
	}
	return retorno;
}

/*
 * valida que el puntero a la estructura no sea NULL y que la cadena de caracteres pasada como parametro no sea NULL;
 * setea dentro de esta estructura el nombre de la editorial pasado como parametro.
 * parametros: eEditorial* puntero a la estructura editorial, nombre, nombre de la editorial pasado como parametro.
 * retorna -1 si no pudo cargar el dato dentro de la estructura o 0 si pudo hacerlo.
 */
int Editorial_SetNombre(eEditorial* editorial, char* nombre) {

	int retorno = -1;

	if(editorial != NULL && nombre != NULL) {

		strcpy(editorial->nombre,nombre);
		retorno = 0;
	}

	return retorno;
}

/*
 *Obtiene la direccion de memoria del campo id de la estructura eEditorial y lo copia dentro del nombre de la editorial pasado como parametro.
 *parametros: eEditorial puntero a la estructura de tipo editorial, *nombre direccion de memoria donde copiare la cadena de la estructura.
 * retorna -1 si los parametros son NULL y 0 si pudo cargar el dato.
 */
int Editorial_GetNombre(eEditorial* editorial, char* nombre) {

	int retorno = -1;

	if(editorial != NULL && nombre != NULL) {

		strcpy(nombre,editorial->nombre);
		retorno = 0;
	}

	return retorno;
}

