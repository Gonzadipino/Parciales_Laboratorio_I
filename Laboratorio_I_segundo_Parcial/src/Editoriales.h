

#ifndef EDITORIALES_H_
#define EDITORIALES_H_

typedef struct {
	int idEditorial;
	char nombre[50];
}eEditorial;



eEditorial* Nueva_Editorial();
eEditorial* Editorial_NuevosParametros(char* idEditorial, char* nombre);
void Borrar_Editorial(eEditorial* this);

int Editorial_SetId(eEditorial* editorial, int idEditorial);
int Editorial_GetId(eEditorial* editorial, int* idEditorial);

int Editorial_SetNombre(eEditorial* editorial, char* nombre);
int Editorial_GetNombre(eEditorial* editorial, char* nombre);

#endif
