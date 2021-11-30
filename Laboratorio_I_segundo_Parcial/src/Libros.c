

#include "Libros.h"
/*
 * Crea un espacio en memoria dinamica del tamaño de la estructura eLibro.
 * retorna el puntero a la direccion dinamica de eLibro o NULL si no encuentra espacio
 */
eLibro* Nuevo_Libro() {

	eLibro* pNewLibro = NULL;

	pNewLibro = (eLibro*) malloc (sizeof(eLibro));

	return pNewLibro;

}
/*
 * Constructor parametrizado de libros
 * valida y setea los datos en una estructura de tipo eLibro y la retorna o retorna NULL de no poder acceder a la dir. de memoria
 * parametros: char* id, puntero a id, char* titulo, puntero a titulo, char* autor, puntero a autor, char* precio, puntero a precio, char* idEditorial, puntero a idEditorial
 *
 * retorna eLibro = NULL o retorna eLibro cargado
 */
eLibro* Libros_NuevosParametros(char* id, char* titulo, char* autor, char* precio, char* idEditorial) {

	eLibro * pNewLibro = NULL;
	pNewLibro = Nuevo_Libro();

	if(pNewLibro != NULL) {

		Libro_SetId(pNewLibro, atoi(id));
		Libro_SetTitulo(pNewLibro, titulo);
		Libro_SetAutor(pNewLibro, autor);
		Libro_SetPrecio(pNewLibro,atof(precio));
		Libro_SetIdEditorial(pNewLibro, atoi(idEditorial));
	} else {
		Borrar_Libro(pNewLibro);
		pNewLibro = NULL;
	}

	return pNewLibro;
}

/*
 * Borra el libro indicado y libera el espacio en memoria
 * parametro eLibro*, puntero a la estructura del tipo libro
 */
void Borrar_Libro(eLibro* this) {

	if(this != NULL) {

		free(this);
		this = NULL;
	}
}


/*
 * valida que el puntero a la estructura no sea NULL y que el id pasado como parametro no sea menor a 0;
 * setea dentro de esta estructura el id pasado como parametro.
 * parametros: eLibro* puntero a la estructura libro, id, id pasado como parametro.
 * retorna -1 si no pudo cargar el dato dentro de la estructura o 0 si pudo hacerlo.
 */
int Libro_SetId(eLibro* libro, int id) {

	int retorno = -1;

		if(libro !=NULL && id >= 0) {

			libro-> id = id;
			retorno = 0;
		}

	return retorno;

}

/*
 *Obtiene la direccion de memoria del campo id de la estructura eLibro y lo copia dentro del id pasado como parametro.
 *parametros: eLibro puntero a la estructura de tipo libro, *id direccion de memoria donde guardare el dato de la estructura.
 * retorna -1 si los parametros son NULL y 0 si pudo cargar el dato.
 */
int Libro_GetId(eLibro* libro, int* id) {

	int retorno = -1;

	if(libro != NULL && id != NULL) {

		*id = libro ->id;
		retorno = 0;

		}

		return retorno;
}

/*
 * valida que el puntero a la estructura no sea NULL y que la cadena de caracteres pasada como parametro no sea NULL;
 * setea dentro de esta estructura el titulo pasado como parametro.
 * parametros: eLibro* puntero a la estructura libro, titulo, titulo pasado como parametro.
 * retorna -1 si no pudo cargar el dato dentro de la estructura o 0 si pudo hacerlo.
 */
int Libro_SetTitulo(eLibro* libro, char* titulo) {

	int retorno = -1;
	if(libro != NULL && titulo != NULL) {

		strcpy(libro->titulo,titulo);
		retorno = 0;

	}
	return retorno;
}

/*
 *Obtiene la direccion de memoria del campo titulo de la estructura eLibro y lo copia dentro del titulo pasado como parametro.
 *parametros: eLibro puntero a la estructura de tipo libro, *titulo direccion de memoria donde guardare el dato de la estructura.
 * retorna -1 si los parametros son NULL y 0 si pudo cargar el dato.
 */
int Libro_GetTitulo(eLibro* libro, char* titulo) {

	int retorno = -1;

	if(libro != NULL && titulo != NULL) {

		strcpy(titulo, libro->titulo);
		retorno  = 0;
	}

	return retorno;

}

/*
 * valida que el puntero a la estructura no sea NULL y que la cadena de caracteres pasada como parametro no sea NULL;
 * setea dentro de esta estructura el autor pasado como parametro.
 * parametros: eLibro* puntero a la estructura libro, autor, autor  pasado como parametro.
 * retorna -1 si no pudo cargar el dato dentro de la estructura o 0 si pudo hacerlo.
 */
int Libro_SetAutor(eLibro* libro, char* autor) {

	int retorno = -1;

	if(libro != NULL && autor != NULL) {

		strcpy(libro->autor,autor);
		retorno = 0;
	}

	return retorno;
}

/*
 *Obtiene la direccion de memoria del campo autor de la estructura eLibro y lo copia dentro del autor pasado como parametro.
 *parametros: eLibro puntero a la estructura de tipo libro, *autor direccion de memoria donde guardare el dato de la estructura.
 * retorna -1 si los parametros son NULL y 0 si pudo cargar el dato.
 */
int Libro_GetAutor(eLibro* libro, char* autor) {

	int retorno = -1;

	if(libro != NULL && autor != NULL) {

		strcpy(autor,libro->autor);
		retorno = 0;
	}

	return retorno;
}

/*
 * valida que el puntero a la estructura no sea NULL y que el precio pasado como parametro no sea menor a 0;
 * setea dentro de esta estructura el precio pasado como parametro.
 * parametros: eLibro* puntero a la estructura libro, precio, precio pasado como parametro.
 * retorna -1 si no pudo cargar el dato dentro de la estructura o 0 si pudo hacerlo.
 */
int Libro_SetPrecio(eLibro* libro, float precio) {

	int retorno = -1;

	if(libro !=NULL && precio >= 0) {

		libro-> precio = precio;
		retorno = 0;
	}

	return retorno;

}

/*
 *Obtiene la direccion de memoria del campo precio de la estructura eLibro y lo copia dentro del precio pasado como parametro.
 *parametros: eLibro puntero a la estructura de tipo libro, *precio direccion de memoria donde guardare el dato de la estructura.
 * retorna -1 si los parametros son NULL y 0 si pudo cargar el dato.
 */
int Libro_GetPrecio(eLibro* libro, float* precio) {

	int retorno = -1;

	if(libro != NULL && precio >= 0) {

		*precio = libro-> precio;
		retorno = 0;
	}

	return retorno;
}

/*
 * valida que el puntero a la estructura no sea NULL y que el id de la editorial pasado como parametro no sea menor a 0;
 * setea dentro de esta estructura el id de la editorialpasado como parametro.
 * parametros: eLibro* puntero a la estructura libro, idEditoria, id de la editorial pasado como parametro.
 * retorna -1 si no pudo cargar el dato dentro de la estructura o 0 si pudo hacerlo.
 */
int Libro_SetIdEditorial(eLibro* libro, int idEditorial) {

	int retorno = -1;

	if(libro != NULL && idEditorial >= 0) {

		libro-> idEditorial = idEditorial;
		retorno = 0;
	}

	return retorno;
}

/*
 *Obtiene la direccion de memoria del campo idEditorial de la estructura eLibro y lo copia dentro del idEditorial pasado como parametro.
 *parametros: eLibro puntero a la estructura de tipo libro, *idEditorial direccion de memoria donde guardare el dato de la estructura.
 * retorna -1 si los parametros son NULL y 0 si pudo cargar el dato.
 */
int Libro_GetIdEditorial(eLibro* libro, int* idEditorial) {

	int retorno = -1;

	if(libro != NULL && idEditorial >= 0) {

		*idEditorial = libro-> idEditorial;
		retorno = 0;
	}

	return retorno;
}

/*
 * obtiene los nombres de dos autores mediante getters y los compara metiante la funcion strcmp.
 * parametros punteros a void de las estructuras de tipo libro de cada autor
 * retorna el resultado de la funcion strcmp
 */
int compareByName(void* libroUno,void* libroDos) {

	int ret;
	char primero[50];
	char segundo[50];

	Libro_GetAutor(libroUno, primero);
	Libro_GetAutor(libroDos, segundo);
	ret = strcmp(primero, segundo);

	return ret;

}

/*Funcion utilizada para verificar, mediante un getter que el dato del id de la editorial del autor sea 4 (por el Id de la editorial MINOTAURO)
 * puntero a void de la estructura de tipo libro
 *retorna -1 si el puntero a la estructura es NULL o si el campo Ideditorial es distinto de 4 o 0 si valido el dato.
 */
int FuncionFiltroPorEditorial(void* libro) {

	int retorno = 0;
	int idEditorial;
	Libro_GetIdEditorial(libro, &idEditorial);

	if(libro != NULL && idEditorial == 4) {
		retorno = 1;
	}
	return retorno;
}

/* funcion de parcial
 *
 * trae elementos de l linked list, si cumplen con las validaciones retorna 1 a la funcion de ll_map para
 */
int FuncionFiltroPorPrecioYEditorial(void* libro) {

	int retorno = 0;
	int idEditorial;
	float precio;

	Libro_GetIdEditorial(libro, &idEditorial);
	Libro_GetPrecio(libro, &precio);

	if(idEditorial == 1 && precio >= 300) {

		retorno = 1;
		precio =  precio * 0.8;
		Libro_SetPrecio(libro, precio);
	}
	if(idEditorial == 2 && precio <= 200) {

		retorno = 1;
		precio = precio * 0.9;
		Libro_SetPrecio(libro, precio);
	}
	return retorno;
}

