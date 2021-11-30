
#include "Controller.h"

/* Controlador de la funcion parser_libros. Valida la ejecucion de la funcion con respecto al estado de la ll.
 * No permite ingresar a la funcion si la linked list ya fue cargada.
 * Parametros: path, cadena con el nombre del archivo a abrir. Linked list, lista donde se guardan los datos.
 * retorno: -1 si la lista ya fue cargada o 0 si se cargaron los datos correctamente.
 */
int Controller_CargarDatosDeLibros(char* path, LinkedList* this) {

	int retorno = -1;
	FILE* pArchivo = NULL;

	pArchivo = fopen(path, "r");

	if(pArchivo != NULL && ll_isEmpty(this) == 1) {
		retorno = Parser_Libros(pArchivo, this);

		AlertMessageAndEnter(retorno, "Libros cargados correctamente.", "ERROR al cargar libros.");

	} else {

		AlertMessageAndEnter(retorno, "", "La lista de libros ya fue cargada.");
	}


	fclose(pArchivo);

	return retorno;
}

/* Controlador de la funcion parser_editoriales. Valida la ejecucion de la funcion con respecto al estado de la ll.
 * No permite ingresar a la funcion si la linked list ya fue cargada.
 * Parametros: path, cadena con el nombre del archivo a abrir. Linked list, lista donde se guardan los datos.
 * retorno: -1 si la lista ya fue cargada o 0 si se cargaron los datos correctamente.
 */
int Controller_CargarDaatosDeEditoriales(char* path, LinkedList* this) {

	int retorno = -1;
	FILE* pArchivo = NULL;

	pArchivo = fopen(path, "r");

	if(pArchivo != NULL && ll_isEmpty(this) == 1) {

		retorno = Parser_Editoriales(pArchivo, this);
		AlertMessageAndEnter(retorno, "Editoriales cargadas correctamente.", "ERROR al cargar editoriales.");

	} else {

		AlertMessageAndEnter(retorno, "", "La lista de editoriales ya fue cargada.");
	}

	fclose(pArchivo);

	return retorno;
}


/* Controlador de la funcion ll_sort. Valida la ejecucion de la funcion con respecto al estado de la ll.
 * No permite ingresar a la funcion si la linked list de los libros no fue cargada previamente.
 * Parametros: Linked list, lista donde se guardan los datos.
 * retorno: -1 si la lista esta vacia o 0 si se ordenaron los datos correctamente.
 */
int Controller_OrdenarListaPorAutores(LinkedList* ll_libros) {

	int retorno = -1;

	if(ll_libros != NULL && ll_isEmpty(ll_libros) != 1) {

		ll_sort(ll_libros, compareByName, 1);
		retorno = 0;
		AlertMessageAndEnter(retorno, "Lista ordenada", "No se pudo ordenar la lista.");
	} else {

		AlertMessageAndEnter(retorno, "" , "Primero cargue la lista de libros y de editoriales.");
	}


	return retorno;
}

/* Controlador de la funcion Mixtas_VerListado. Valida la ejecucion de la funcion con respecto al estado de ambas linked list.
 * No permite ingresar a la funcion si las linked list de los libros y de las editoriales no fueron cargadas previamente.
 * Parametros: Linked list ll_libros, lista de los libros. linkedList ll_editoriales linked list de las editoriales.
 * retorno: -1 si ninguna de las listas fue cargada o 0 si se mostraron los datos correctamente.
 */
int Controller_VerListadoDeLibros(LinkedList* ll_libros, LinkedList* ll_editoriales) {


	int retorno = -1;

	if(ll_isEmpty(ll_libros) != 1 && ll_isEmpty(ll_editoriales) != 1) {

		retorno = Mixtas_VerListado(ll_libros,ll_editoriales);
		AlertMessageAndEnter(retorno, "", "No se pudo mostrar la lista");

	} else {

		AlertMessageAndEnter(retorno, "", "Primero cargue la lista de libros y de editoriales.");
	}

	return retorno;
}

/* Controlador de la funcion ll_filter. Valida la ejecucion de la funcion con respecto al estado de la linked list de libros.
 * No permite ingresar a la funcion si la linked list de los libros no fue cargada previamente.
 * Parametros: path, archvio csv donde se guardaran los datos, Linked list ll_libros, lista de los libros.
 * retorno: -1 si la lista de libros no fue cargada o 0 si se ejecuto bien la funcion de filter.
 */
int Controller_LibrosDeMinotauro(char* path,LinkedList* ll_libros) {

	int retorno = -1;
	LinkedList* listaFiltrada = NULL;
	FILE* pArchivo = NULL;

	if(ll_libros != NULL && ll_isEmpty(ll_libros) != 1) {

		listaFiltrada = ll_filter(ll_libros, FuncionFiltroPorEditorial);

		if(listaFiltrada != NULL) {

			pArchivo = fopen(path,"w");

			if(pArchivo != NULL) {

				retorno = Parser_CargarLista(pArchivo, listaFiltrada);
				AlertMessageAndEnter(retorno, "Se guardaron los datos en el archivo MINOTAURO.csv", "ERROR al cargar los datos");

			}else {

				AlertMessageAndEnter(retorno, "", "Primero cargue la lista de libros");
			}

			fclose(pArchivo);
		}
	}
	return retorno;
}

int Controller_DescuentosYGuardado(char* path, LinkedList* ll_libros) {

	int retorno = -1;
	LinkedList* listaConDescuento = NULL;
	FILE* pArchivo;

	if(ll_libros != NULL && ll_isEmpty(ll_libros) != 1) {

		listaConDescuento = ll_map(ll_libros, FuncionFiltroPorPrecioYEditorial);

		pArchivo = fopen(path,"w");

		if(pArchivo != NULL) {

			retorno = Parser_CargarLista(pArchivo, listaConDescuento);
			AlertMessageAndEnter(retorno, "Se guardaron los datos en el archivo MAPEADO.csv", "ERROR al cargar los datos");

		}else {

			AlertMessageAndEnter(retorno, "", "Primero cargue la lista de libros");
		}

		fclose(pArchivo);
	}
	return retorno;
}


