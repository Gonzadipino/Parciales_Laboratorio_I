#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

/*struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
} typedef LinkedList; */

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */

LinkedList* ll_newLinkedList(void) {

    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL) {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this) {

    int returnAux = -1;

    if(this != NULL) {

    	returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */

static Node* getNode(LinkedList* this, int nodeIndex) {

	Node* pNode = NULL;
	int len;
	len = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex < len) {

			pNode = this->pFirstNode;

			if(pNode != NULL) {

				for(int i = 0; i < nodeIndex; i++) {

				pNode = pNode->pNextNode;

				}
			}
	}

	return pNode;

}
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement) {

	int returnAux = -1;
	Node* pNode = NULL;
	Node* aux_pNode = NULL;
	int len;
	len = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex <= len) {

		pNode = (Node*)malloc(sizeof(Node));

		if(pNode != NULL) {

			pNode->pElement = pElement;
			pNode->pNextNode = NULL;

			if(nodeIndex == 0) {

				pNode->pNextNode = this->pFirstNode ;
				this->pFirstNode = pNode;

			} else { // indice distinto de 0

				aux_pNode = getNode(this, nodeIndex - 1);
				pNode->pNextNode = aux_pNode->pNextNode;
				aux_pNode->pNextNode = pNode;

			}

			this->size = this->size + 1;
			returnAux = 0;

		}

	}
	return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement) {

    int returnAux = -1;
    int len;
    len = ll_len(this);

    if(this != NULL && addNode(this, len, pElement) == 0)  {
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */

void* ll_get(LinkedList* this, int index) {

	void* returnAux = NULL;
	Node* pNode = NULL;
	int len;
	len = ll_len(this);

	if(this!= NULL && index >= 0 && index <= len) {

		pNode = getNode(this, index);

		if(pNode != NULL) {

			returnAux = pNode->pElement;
		}
	}

	return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement) {

    int returnAux = -1;
    int len;
    len = ll_len(this);
    Node* pNode = NULL;

    if(this != NULL && index >= 0 && index <= len) {

    	pNode = getNode(this, index);
    	if(pNode != NULL) {

    		pNode->pElement = pElement;
    		returnAux = 0;
    	}

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index) {

    int returnAux = -1;
    int len;
    len = ll_len(this);
    Node* pNode = NULL;
    Node* pNodeAux = NULL;


    	if(this != NULL && index >= 0 && index <= len) {

    		pNode = getNode(this, index);

    		if(index == 0 && pNode != NULL) {

    			this->pFirstNode = pNode->pNextNode;
    		} else {

    			pNodeAux = getNode(this, (index - 1));
				if(pNode != NULL && pNodeAux != NULL) {

					pNodeAux->pNextNode = pNode->pNextNode;
				}

    		}

    		free(pNode);
    		pNode = NULL;
    		this->size--;
    		returnAux = 0;

    	}

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this) {

    int returnAux = -1;
    int len;
    Node* pNode = NULL;
    len = ll_len(this);
    if(this != NULL) {
    	for(int i = 0; i < len; i++) {

    		pNode = getNode(this, i);
    		if(pNode != NULL) {

    			ll_remove(this, i); //use remove como me corrigieron en el tp4
    		}
    	}
    	if(this->size == 0) {

    		this->pFirstNode = NULL;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this) {
	int returnAux = -1;

    if(this != NULL) {
    	ll_clear(this);
    	free(this);
    	this = NULL;
    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement) {

    int returnAux = -1;
    Node* pNode = NULL;
    int len;
    len = ll_len(this);

    if(this != NULL) {
    	for(int i = 0; i<len ; i++) {
    		pNode = getNode(this, i);
    		if(pNode != NULL) {
    			if(pNode->pElement == pElement) {
    				returnAux = i;
    				break;
    			}
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this) {

    int returnAux = -1;

    if(this != NULL && this->size == 0) {

    	returnAux = 1;

    }else if(this->size > 0) {

    	returnAux = 0;
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement) {

    int returnAux = -1;
    int len;
    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len) {
    	if(addNode(this, index, pElement) == 0) {
    		returnAux = 0;
    	}

    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index) {

    void* returnAux = NULL;

    int len;
    len = ll_len(this);

    if(this != NULL && index >= 0 && index <= len) {

    	returnAux = ll_get(this, index);

    	if(returnAux != NULL) {

    		ll_remove(this, index);
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement) {

    int returnAux = -1;
    int indice;

    if(this != NULL) {

    	indice = ll_indexOf(this, pElement);

    	if(indice != -1) {

    		returnAux = 1;
    	} else {

    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2) {

    int returnAux = -1;
    int len_1;
    int len_2;
    int contador = 0;
    Node* pNode_1 = NULL;
    Node* pNode_2 = NULL;
    len_1 = ll_len(this);
    len_2 = ll_len(this2);

    if(this != NULL && this2 != NULL) {

    	returnAux = 0;

    	for(int i = 0; i<len_2; i++) {
    		pNode_2 = getNode(this2, i);

    		if(pNode_2 != NULL) {

    			for(int j = 0; j<len_1; j++) {

    				pNode_1 = getNode(this, j);
    				if(pNode_1 != NULL ) {
    					if(pNode_2->pElement == pNode_1-> pElement) {

    						contador++;
    					}
    				}
    			}
    		}
    	}

    	 if(contador == len_2) {

       	returnAux = 1;

    	 }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to) {

    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    int len;
    len = ll_len(this);


    if(this != NULL &&  from >= 0 && from < len && to > from && to <= len) {

    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL) {

    		for(int i = from; i< to; i++) {

    				pElement = ll_get(this, i);

    				ll_add(cloneArray, pElement);

    			}

    		}
    	}

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this) {

    LinkedList* cloneArray = NULL;
    void* pElement = NULL;
    int len;
    len = ll_len(this);

    if(this != NULL) {

    	cloneArray = ll_newLinkedList();

    	if(cloneArray != NULL) {

    		for(int i = 0; i < len; i++) {

    			pElement = ll_get(this, i);
    			ll_add(cloneArray, pElement);
    		}
    	}
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order) {

    int returnAux = -1;
    int len;
    void* pElement_1 = NULL;
    void* pElement_2 = NULL;
    void* pAuxElement = NULL;

    len = ll_len(this);

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1)) {

    	for(int i = 0; i < len; i++) {

    		for(int j = i + 1; j < len; j++) {

    			pElement_1 = ll_get(this, i);
    			pElement_2 = ll_get(this, j);
    			pAuxElement = pElement_1;

    			if((order == 1 && pFunc(pElement_1,pElement_2) > 0) || (order == 0 && pFunc(pElement_1,pElement_2) < 0)) {//menor a mayor

    					ll_set(this, i, pElement_2);
    					ll_set(this, j, pAuxElement);
    					returnAux = 0;
    			}
    		}
    	}
    }

    return returnAux;
}


/*
 *
 *  La funci�n �ll_filter� recibir� una lista y una funci�n criterio �fn�. Se deber� iterar todos los elementos
 *	de la lista y pasarlos a la funci�n �fn�. La funci�n �fn� devolver� 1 si ese �tem se debe agregar a la
 *	lista resultado o 0 si no debe agregarse. La funci�n �ll_filter� generar� la nueva lista resultado,
 *	agregar� a la misma los �tems correspondientes y la devolver�.
 *
 */

LinkedList* ll_filter(LinkedList* this, int (*fn)(void* element)) {

	LinkedList* ListaFiltrada = NULL;
	int len;
	void* pElement = NULL;

	len = ll_len(this);
	ListaFiltrada =  ll_newLinkedList();

	if(ListaFiltrada != NULL) {

		for(int i = 0; i<len; i++) {

			pElement = ll_get(this, i);
			if(pElement != NULL && fn(pElement)== 1) {

				ll_add(ListaFiltrada, pElement);
			}
		}
	}
	return ListaFiltrada;
}


LinkedList* ll_map(LinkedList* this, int(*fn)(void* element)) {

	LinkedList* ListaConDescuento = NULL;
	int len;
	void* pElement = NULL;
	len = ll_len(this);

	ListaConDescuento = ll_newLinkedList();

	if(ListaConDescuento != NULL && this != NULL) {

		for(int i = 0; i < len; i++) {

			pElement = ll_get(this, i);

			if(pElement != NULL ) {
				fn(pElement);
				ll_add(ListaConDescuento, pElement);
			}
		}
	}
	return ListaConDescuento;
}



