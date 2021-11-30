
#ifndef __LINKEDLIST
#define __LINKEDLIST

struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif

//Publicas
//Constructor: instancia la lista en el heap, la va a crear fisicamente la lista
LinkedList* ll_newLinkedList(void);

//cuenta la cantidad de elementos qu etengo dentro de la lista, no existe el conecto de capacidad, trabajo sin olgura, puedo crear los nodos que quiera
int ll_len(LinkedList* this);

Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);

//add agrega un elemeto denro de la lista, pasar un puntero a void* es un dato generico por lo que me permite gestionar cualuiqer tipo de dato
int ll_add(LinkedList* this, void* pElement);

//devuelve un dato de la lista, por ejemplo, si le paso el indice 0 me devuelve el empleado 1
void* ll_get(LinkedList* this, int index);

//set: reemplaza un elemento con otro, le paso el indice ue quiero reemplazar y el elemento,
//si le paso el idnice 1 y el elemento x reeemplaza el empleado 2 con empleado x
// y los datos del nodo 2 apuntaran al nuevo dato entero
int ll_set(LinkedList* this, int index,void* pElement);

//remove: remueve un nodo especifico, no hace el free del dato
int ll_remove(LinkedList* this,int index);

//clear: limpia toda la lista, no guarda ningun nodo, es decir borrar todos los datos; es un destructor de lista
int ll_clear(LinkedList* this);

//deletelinkedList: borra los datos y la lista enlazada o la lista que le especifique, tmb irve para borrar listas auxiliares que ya no quiero
int ll_deleteLinkedList(LinkedList* this);

//El indice de un elemento especifico:  le paso el elemento, el dato y la funcion me dice donde esta
int ll_indexOf(LinkedList* this, void* pElement);

//si el linked list esta vacio 1 si esta vacio
int ll_isEmpty(LinkedList* this);

//push: agrega un nodo nuevo en el indice que le indique
int ll_push(LinkedList* this, int index, void* pElement);

//el pop devuelve el elemento que saco de la lista, y despues puedo hacer algo con eso que me devolvio
void* ll_pop(LinkedList* this,int index);

//preguntar si contiene ese elemtno especifico qu le paso y me dice si esta o no esta
int ll_contains(LinkedList* this, void* pElement);

//para verificar si una lista esta en otra
int ll_containsAll(LinkedList* this,LinkedList* this2);

//Crea una copia de la lista de un lugar hasta otro, la posicion que le paso no la incluye
LinkedList* ll_subList(LinkedList* this,int from,int to);

//copia una lista entera, llama a sublist de punto 0 al final. copia las direcciones de memoria
LinkedList* ll_clone(LinkedList* this);

//sort: ordenamiento
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);

LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element));

//linked list no trabaja al nivel de datos, solo gestiona los nodos
//ya que trabaja con datos genericos, osslo hace la mecanica de hacer cosas
//solo trabaja con punteros

LinkedList* ll_map(LinkedList* this, int(*fn)(void* element));
