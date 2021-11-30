
#include "FuncionesMixtas.h"

/*
 * Muestra una lista con los datos de los libros con su correspondiente editorial
 * valida los datos mediante getters, compara el idEditorial del libro con el de la eEditorial y si matchean lo imprime
 * parametros: ll_libros, linked list que contiene la lista de libros, ll_editoriales linked list que contiene los datos de las editoriales
 * retorno -1 si no pudo imprimr ningun dato o 0 si pudo
 */
int Mixtas_VerListado(LinkedList* ll_libros, LinkedList* ll_editoriales) {

	int retorno = -1;
	eLibro* pLibroAux = NULL;
	eEditorial* pEditAux = NULL;
	int len_libros;
	int len_editoriales;
	int id;
	char titulo[51];
	char autor[51];
	float precio;
	int idEditorial;

	int editorialNum;
	char editorialDes[51];

	len_libros = ll_len(ll_libros);
	len_editoriales = ll_len(ll_editoriales);

	MostrarCabecera();

	for(int i = 0; i < len_libros; i++) {

		pLibroAux = ll_get(ll_libros, i);

		if(Libro_GetId(pLibroAux,&id) == 0 && Libro_GetAutor(pLibroAux, autor) == 0 && Libro_GetTitulo(pLibroAux,titulo) == 0 &&
				Libro_GetPrecio(pLibroAux,&precio) == 0 && Libro_GetIdEditorial(pLibroAux,&idEditorial) == 0) {
			//printf("%d  %s  %s  %.2f  %d",id,autor,titulo,precio,idEditorial);
			for(int j = 0; j < len_editoriales; j++) {

				pEditAux = ll_get(ll_editoriales, j);

				if(Editorial_GetId(pEditAux, &editorialNum) == 0 && Editorial_GetNombre(pEditAux, editorialDes) == 0) {
					//printf("  %d  %s\n", editorialNum,editorialDes);
					if(idEditorial == editorialNum) {
						ImprimirUnLibro(id,titulo,autor,precio,editorialDes);
						retorno = 0;
					}

				}
			}
		}
	}

	return retorno;
}

/*
 * Muesra la cabecera de los datos a mostrar en pantalla al imprimir un libro
 *
 */
void MostrarCabecera(void) {

	  printf("  ID                                   TITULO                          AUTOR               PRECIO                  EDITORIAL\n\n");

}

/*
 * Imrime en pantalla los datos de un libro y los de su editorial
 * parametros: id, id del libro, titulo, titulo del libro, autor, autor del libro, precio, precio del libro,
 *  descripcion, nombre de la editorial correspondiente con el idEditorial del libro
 */
void ImprimirUnLibro(int id, char* titulo, char* autor, float precio, char* descripcion) {

	printf("%4d %40s %30s %20.2f %26s\n",id, titulo, autor, precio, descripcion);


}
