#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)    //chequeo que haya memoria reservada
    {
        this->size = 0;         //tengo que inicializar los valores de la lista para que no me tire basura
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
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
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode;
	    int len;
	    int i;

	    pNode = NULL;

	    if(this != NULL && nodeIndex>=0)
	    {
	        len = ll_len(this);
	        if(nodeIndex<len)//verifico que el indice sea mayor a cero y menor al size del LL
	        {
	            if(nodeIndex == 0)
	            {
	                pNode = this->pFirstNode;//si el indice es 0, directamente le retorno el primer nodo de la lista
	            }
	            else
	            {
	                pNode = this->pFirstNode;//obtengo la direccion de memoria del primer nodo de la lista
	                for(i=0; i<len; i++)
	                {
	                    if(i == nodeIndex)
	                    {
	                        break;
	                    }
	                    pNode = pNode->pNextNode;//le asigno la direccion de memoria del auxiliar
	                    //pAuxNode = pAuxNode->pNextNode;//cambio la direccion de memoria del siguiente nodo del auxiliar
	                }
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
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int returnAux = -1;
	    int len;
	    Node* pPreviousNode;
	    Node* pNewNode;

	    pPreviousNode = NULL;
	    pNewNode = (Node*) malloc(sizeof(Node));

	    len = ll_len(this);//pido el tama�o de la lista

	    if((this != NULL) && (nodeIndex>=0) && (nodeIndex<=len))//valido que la lista no sea nula
	    {
	        if(pNewNode != NULL)
	        {
	            pNewNode->pElement = pElement; //asigno la direccion al dato
	            pNewNode->pNextNode = NULL;

	            //PRIMER CASO: INDICE == 0
	            if(nodeIndex == 0)
	            {
	                //pPreviousNode = lista->pFirstNode;//obtengo el primer nodo
	                pNewNode->pNextNode = this->pFirstNode;//guardo en el nuevo nodo la direccion del previo primer nodo
	                this->pFirstNode = pNewNode;//hago que la lista apunte al nuevo primer nodo
	            }
	            else if(nodeIndex<len)
	            {
	                //SEGUNDO CASO: INDICE ENTRE 0 Y LEN
	                nodeIndex = nodeIndex-1;
	                pPreviousNode = getNode(this, nodeIndex);//obtengo el nodo anterior en la lista
	                pNewNode->pNextNode = pPreviousNode->pNextNode;//al nuevo nodo le asigno el nodo al que apuntaba el anterior
	                pPreviousNode->pNextNode = pNewNode;//al nodo anterior le asigno el nuevo nodo
	            }
	            else if (nodeIndex == len)
	            {
	                //TERCER CASO: INDICE == LEN
	                nodeIndex = nodeIndex-1;
	                pPreviousNode = getNode(this, nodeIndex);//obtengo el nodo anterior en la lista
	                pPreviousNode->pNextNode = pNewNode;//al nodo anterior le asigno el nuevo nodo
	                pNewNode->pNextNode = NULL; //dado que es el final de la lista, el nuevo nodo apunta a NULL
	            }

	        }
	        len++;
	        this->size = len;
	        returnAux = 0;
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
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;

    if(this != NULL)
    {
        len = ll_len(this);
        returnAux = addNode(this, len, pElement);
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
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    int len;
    Node* pNode = NULL;

    if(this != NULL)
    {
        len = ll_len(this);
        if(index>=0 && index<len)
        {
            pNode = getNode(this, index);
            if(pNode != NULL)
            {
                returnAux = pNode->pElement;
                /*free(pNode);
                pNode = NULL;*/
            }
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
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    int len;
    Node* pNode = NULL;

    if(this != NULL)
    {
        len = ll_len(this);
        if(index>=0 && index<len)
        {
            pNode = getNode(this, index);
            if(pNode != NULL)
            {
                pNode->pElement = pElement;
                returnAux = 0;
            }
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
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len;
    Node* pNodeRemoved;//guardo el nodo a eliminar
    Node* pPreviousNode;//guardo el previo
    if(this != NULL)
    {
        len = ll_len(this);

        pNodeRemoved = NULL;
        pPreviousNode = NULL;

        if(index>=0 && index<len)
        {
            //obtengo el nodo a eliminar
            pNodeRemoved = getNode(this, index);
            if(pNodeRemoved != NULL)
            {
                if(index == 0)
                {

                	this->pFirstNode = pNodeRemoved->pNextNode;//hago que la lista apunte al siguiente nodo
                    free(pNodeRemoved);//hago que la lista apunte al nuevo primer nodo
                    pNodeRemoved = NULL;


                }
                else
                {
                	index = index - 1;
                    pPreviousNode = getNode(this, index);//obtengo el nodo anterior en la lista
                    pPreviousNode->pNextNode = pNodeRemoved->pNextNode;//al nuevo nodo le asigno el nodo al que apuntaba el anterior
                    free(pNodeRemoved);//hago free del eliminado
                    pNodeRemoved = NULL;
                }
                len--;
                this->size = len;
                returnAux = 0;

                /*free(pPreviousNode);
                pPreviousNode = NULL;*/
            }
        }
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
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    int i;
    if(this != NULL)
    {
        len = ll_len(this);
        for(i=0; i<len; i++)
        {
            ll_remove(this, i);
        }
        returnAux = 0;
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
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
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
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    int i;
    void* pAux=NULL;
    if(this != NULL)
    {
        len = ll_len(this);
        for(i=0; i<len; i++)
        {
            pAux=ll_get(this,i);
            if(pAux == pElement)
            {
                returnAux = i;
                break;
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
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;
    if(this != NULL)
    {
        len = ll_len(this);
        if(len>0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
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
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int returnAdd = -1;
    if(this != NULL)
    {
        if(index>=0 && index <= ll_len(this))
        {
            returnAdd = addNode(this, index, pElement);
            if(returnAdd == 0)
            {
                returnAux = 0;
            }
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
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int retorno = -1;
    if(this != NULL)
    {
        if(index>=0 && index < ll_len(this))
        {
            returnAux = ll_get(this, index);
            retorno = ll_remove(this, index);
            if(retorno != 0)
            {
                returnAux = NULL;
            }

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
int ll_contains(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	int i;
	Node* pNodeAux;
	if(this != NULL)
		{
			pNodeAux = NULL;
	        returnAux = 0;
	        for(i=0; i<ll_len(this); i++)
	        {
	            pNodeAux = ll_get(this, i);
	            if(pNodeAux == pElement)
	            {
	                returnAux = 1;
	                break;
	            }
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
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    if (this!=NULL && this2!=NULL){
    	int len=ll_len(this2);
    	returnAux=1;
    	for(int i=0;i<len;i++){
    		if(ll_contains(this, ll_get(this2,i))==0){
    			returnAux=0;
    			break;
    		}
    	}
    }
    return returnAux;

    /*    int returnAux = -1;
    int i;
    int validate = -1;
    Node* pNodeAux;
    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        pNodeAux = NULL;
        for(i=0; i<ll_len(this2); i++)
        {
            pNodeAux = ll_get(this2, i);
            validate = ll_contains(this2, pNodeAux);
            if(validate != 1)
            {
                returnAux = 0;
                break;
            }

        }
    }

    return returnAux;*/
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
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pNodeAux;
    int i;
    if((this != NULL) && (from>=0 && from<=ll_len(this)) && (to>=from && to<=ll_len(this)))
    {
        pNodeAux = NULL;
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            for(i=from; i<to; i++)
            {
                pNodeAux = ll_get(this, i);
                addNode(cloneArray,i, pNodeAux);
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
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
            cloneArray = ll_subList(this, 0, ll_len(this));
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
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int order_validate;
    int i;
    int j;
    void* pElementOne;
    void* pElementTwo;
    void* pAuxElement;


    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        for(i=0; i<ll_len(this)-1; i++)
        {
            pElementOne = ll_get(this, i);
            for(j=i+1; j<ll_len(this); j++)
            {
                pElementTwo = ll_get(this, j);

                if(order == 1)
                {
                    order_validate = pFunc(pElementOne, pElementTwo);
                    if(order_validate == 1)
                    {
                        pAuxElement = pElementOne;
                        pElementOne = pElementTwo;
                        pElementTwo = pAuxElement;
                    }
                }
                else if(order == 0)
                {
                    order_validate = pFunc(pElementOne, pElementTwo);
                    if(order_validate == -1)
                    {
                        pAuxElement = pElementTwo;
                        pElementTwo = pElementOne;
                        pElementOne = pAuxElement;
                    }
                }
                ll_set(this, i, pElementOne);
                ll_set(this, j, pElementTwo);
            }
        }
        returnAux = 0;
    }
    return returnAux;

}

