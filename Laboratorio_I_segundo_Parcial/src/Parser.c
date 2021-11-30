
#include "Parser.h"
/*
 *  convierte los datos desde el archivo .csv y los introduce en la linked list.
 *  parametros: pArchivo, archvio que ya fue abierto en el parser y trae los datos, this, la linked list donde los guardare
 * retorna -1 si no pudo validar ningun dato de la lista, no pudo abrir el archivo, la linked list no existe o si no se pudo cargar los datos en la linked list;
 * retorna 0 si se cargaron los datos correctamente.
 *
 */
int Parser_Libros(FILE* pArchivo, LinkedList* this) {

	int retorno = -1;
	char id[51];
	char titulo[51];
	char autor[51];
	char precio[51];
	char idEditorial[51];
	int splits;
	eLibro* pLibro = NULL;

	if(pArchivo != NULL && this != NULL) {

		fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,idEditorial);

		while(!feof(pArchivo)) {

			splits = fscanf(pArchivo,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,autor,precio,idEditorial);

			if(splits == 5) {
				//printf("%10s%50s%50s%10s%10s\n",id,titulo,autor,precio,idEditorial);
				if(ValidateIntNumber(id) != -1 && ValidateString(titulo) != -1 && ValidateString(autor) != -1 &&
						ValidateFloatNumber(precio) != -1 && ValidateIntNumber(idEditorial) != -1) {
					pLibro = Libros_NuevosParametros(id,titulo,autor,precio,idEditorial);

					if(ll_add(this, pLibro) != -1) {

						retorno = 0;

					} else if (pLibro == NULL) {

						retorno = -1;
						break;
					}
				}
			}
		}
	}

	return retorno;
}

/*
 *  convierte los datos desde el archivo .csv y los introduce en la linked list.
 *  parametros: pArchivo, archvio que ya fue abierto en el parser y trae los datos, this, la linked list donde guarda los datos de editorial
 * retorna -1 si no pudo validar ningun dato de la lista, no pudo abrir el archivo, la linked list no existe o si no se pudo cargar los datos en la linked list;
 * retorna 0 si se cargaron los datos correctamente.
 *
 */
int Parser_Editoriales(FILE* pArchivo, LinkedList* this) {

	int retorno = -1;
	char idEditorial[51];
	char nombre[51];
	int splits;

	eEditorial* pEditorial = NULL;

	if(pArchivo != NULL && this != NULL) {

		fscanf(pArchivo,"%[^,],%[^\n]\n",idEditorial,nombre);

		while(!feof(pArchivo)) {

			splits = fscanf(pArchivo,"%[^,],%[^\n]\n",idEditorial,nombre);

			if(splits == 2) {

				if(ValidateIntNumber(idEditorial) != -1 && ValidateString(nombre) != -1) {

					pEditorial = Editorial_NuevosParametros(idEditorial, nombre);

					if(ll_add(this, pEditorial) != -1) {

						retorno = 0;

					} else if (pEditorial == NULL) {

						retorno = -1;
						break;
					}
				}
			}
		}
	}

	return retorno;
}


/*
 * Carga los datos de una linked list en un archivo.csv
 * valida los datos mediante getters.
 * parametros: pArchivo, puntero al archivo .csv, this, linked list donde se anexan los datos
 * retorna -1 si no udo cargar ningun dato al archvio y 0 si pudo
 */
int Parser_CargarLista(FILE* pArchivo, LinkedList* this) {

	int retorno = -1;
	int len;
	int idAux;
	char tituloAux[51];
	char autorAux[51];
	float precioAux;
	int idEditorialAux;
	eLibro* pLibro = NULL;

	len = ll_len(this);

	fprintf(pArchivo,"id,titulo,autor,precio,idEditorial\n");

	for(int i = 0; i < len; i++) {
		pLibro = ll_get(this, i);

		if(pLibro != NULL) {

			if(Libro_GetId(pLibro, &idAux) == 0 && Libro_GetTitulo(pLibro, tituloAux) == 0 &&
					Libro_GetAutor(pLibro, autorAux) == 0 && Libro_GetPrecio(pLibro, &precioAux) == 0 && Libro_GetIdEditorial(pLibro, &idEditorialAux) == 0) {

				fprintf(pArchivo,"%d,%s,%s,%.2f,%d\n", idAux,tituloAux,autorAux,precioAux,idEditorialAux);
				retorno = 0;
			}
		}
	}
	return retorno;
}
