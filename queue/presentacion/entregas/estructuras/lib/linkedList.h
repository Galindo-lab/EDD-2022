#ifndef linkedList
#define linkedList

#include <stdio.h>
#include <stdlib.h>

struct _LinkedListNode {
  int data;
  struct _LinkedListNode *next;
};

typedef struct _LinkedListNode LinkedList;
typedef LinkedList LinkedListNode;

/**
 * Restorna si la lista esta vacia
 * @param *head lista de nodos
 * @return verdadero si la lista esta vacia
 */
short linkedListEmpty(LinkedList *head) { return head == NULL; }

/**
 * Restorna si la lista esta vacia
 * @param *head lista de nodos
 * @return verdadero si la lista esta vacia
 */
short linkedListHasOneItem(LinkedList **head) {
  LinkedListNode *current = *head;
  return current->next == NULL;
}

/**
 * Algunas operaciones requieren modificar el penultimo y el ultimo elemento y
 * para no repetir esa operacion exsite esta funcion
 * @param direccion al primer nodo de la lista
 * @return direccion al penultimo nodo
 */
LinkedListNode *linkedListGetSecondLastNode(LinkedList **head) {
  LinkedListNode *current = *head;
  LinkedListNode *next = current->next;

  if (linkedListEmpty(*head)) {
    printf("ERROR: linkedListGetSecondLastNode - La lista esta vacia!\n");
    exit(EXIT_FAILURE);
  }

  if (linkedListHasOneItem(&current)) {
    printf("ERROR: linkedListGetSecondLastNode - Solo tiene un elemento\n");
    exit(EXIT_FAILURE);
  }

  while (next->next != NULL) {
    current = next;
    next = current->next;
  }

  return current;
}

/**
 * obtener el ultimo nodo de la lista
 * @param direccion a la lista
 * @return posiscion en memoeria del ultimo nodo
 */
LinkedList *linkedListGetLastNode(LinkedList **head) {
  LinkedList *second_last = NULL;

  if (linkedListEmpty(*head)) {
    printf("ERROR: linkedListGetLastNode - Lista vacia\n");
    exit(EXIT_FAILURE);
  }

  if (linkedListHasOneItem(head)) {
    return *head;
  }

  second_last = linkedListGetSecondLastNode(head);
  return second_last->next;
}

/**
 * cualqiuier valor mayor o igual a -1 es valido, si no es
 * valido termina el programa
 * @param position a verificar
 */
void _llValidPosition(int position) {
  if (position < -1) {
    printf("ERROR: _llValidPosition - La posicion es menor a -1\n");
    exit(EXIT_SUCCESS);
  }
}

/**
 * Crea un nodo para la lista
 * @param valor del nodo
 * @return direccion al nuevo nodo
 */
LinkedListNode *linkedListNodeCreate(int value) {
  LinkedListNode *foo = malloc(sizeof(LinkedListNode));

  if (foo == NULL) {
    printf("no se pudo reservar memoria\n");
    exit(EXIT_FAILURE);
  }

  foo->data = value;
  foo->next = NULL;

  return foo;
}

/**
 * Inserta un nodo en la lista.
 * si la lista esta vacía se inserta al inicio.
 * si la posición es 0 se inserta al inicio.
 * si la posición es -1 se inserta al final.
 * si la posición es mayor al tamaño del arreglo se inserta al final.
 * si la posición es 'n' se inserta en la posición 'n'.
 * @param head lista de nodos
 * @param nodo a insertar
 * @param position en el cual insertar
 */
void linkedListInsert(LinkedList **head, LinkedListNode *node, int position) {
  LinkedListNode *new = node;
  LinkedListNode *current = *head;
  LinkedListNode *previous = NULL;

  _llValidPosition(position);

  /* Nodo inicial */
  if (linkedListEmpty(*head)) {
    *head = node;
    return;
  }

  /* Insertar al inicio */
  if (position == 0) {
    new->next = *head;
    *head = new;
    return;
  }

  /* Insertar al final  */
  if (position == -1) {
    linkedListGetLastNode(head)->next = new;
    return;
  }

  /* Insertar en cualquier posicion */
  for (int i = 0; i < position; i++) {
    previous = current;
    current = current->next;

    /* si no existe la posicion se termina el bucle
       y se inserta al final*/
    if (current == NULL)
      break;
  }

  previous->next = new;
  new->next = current;
}

/**
 * Elimina un nodo de una posicion.
 * si la lista esta vacia muestra un mensaje pero no termina el programa.
 * si la posición es 0 se elimina al inicio.
 * si la posicion es -1 se elimina al final.
 * si la posicion es 'n' se elimina el elemento en la posiscion 'n'
 * si la posicion es mayor al tamaño del arreglo muestra un mensaje pero no
 * termina el programa.
 * @param head lista de nodos
 * @param posicion a insertar
 */
void linkedListRemove(LinkedList **head, int position) {
  LinkedListNode *current = *head;
  LinkedListNode *previous = NULL;

  _llValidPosition(position);

  /* no existe el primer elemento */
  if (linkedListEmpty(*head)) {
    printf("ERROR: linkedListRemove - La lista esta vacia\n");
    return;
  }

  /* elimna la primera posicion o eliminar un elemento unico*/
  if (position == 0 || linkedListHasOneItem(head)) {
    previous = current;
    *head = current->next;
    free(previous);
    return;
  }

  /* elimina la ultima posicion */
  if (position == -1) {
    current = linkedListGetSecondLastNode(head);
    free(current->next);
    current->next = NULL;
    return;
  }

  /* caso base */
  for (int i = 0; i < position; i++) {
    previous = current;
    current = current->next;

    /* si no existe la posicion se termina el bucle, exepto si es la ultima
       iteracion */
    if (current->next == NULL && !(i + 1 < position)) {
      printf("ERROR: linkedListRemove - Elemento fuera del rango de la lista\n");
      exit(EXIT_FAILURE);
    }
  }

  previous->next = current->next;
  free(current);
}

/**
 * obtener posicion en la lista
 * @param head lista de nodos
 * @param posicion a obtener
 * @return el valor del nodo
 */
int linkedListGet(LinkedList **head, int position) {
  LinkedListNode *current = *head;

  _llValidPosition(position);

  if (linkedListEmpty(*head)) {
    printf("ERROR: linkedListGet - La linkedList esta vacia!\n");
    return 0;
  }

  /* retorna el valor de la ultima posición */
  if (position == -1) {
    return linkedListGetLastNode(head)->data;
  }

  for (int i = 0; i < position; i++) {
    current = current->next;

    /* si no existe la posicion se termina el bucle, exepto si es la ultima
       iteracion */
    if (current->next == NULL && !(i + 1 < position)) {
      printf("Elemento fuera del rango de la lista\n");
      exit(EXIT_FAILURE);
    }
  }

  return current->data;
}

void linkedListOrderedInsert(LinkedList **head, LinkedListNode *node) {
  LinkedListNode *current = *head;
  int i = 0;

  /* Nodo inicial */
  if (linkedListEmpty(*head)) {
    *head = node;
    return;
  }

  /* mientras halla un siguiente se continua iterando, hasta que el valor
     den nodo actual sea mayor que el del nodo que se decea insertar */
  while (node->data < current->data) {
    i++;
    
    if(current->next == NULL)
      break;

    current = current->next;
  }

  linkedListInsert(head, node, i);
}

/**
 * Numero de elementos en la lista
 * @param posicion a obtener
 * @return tamaño de lista
 */
int linkedListLenght(LinkedList *head) {
  LinkedListNode *current = head;
  int size = 1;

  /* si no hay nada la lista esta vacia */
  if (linkedListEmpty(head))
    return 0;

  while ((current = current->next) != NULL)
    size++;

  return size;
}

/**
 * Liberar la memoria que esta usando la lista
 * @param head lista de nodos
 * @return
 */
void linkedListFree(LinkedList **head) {
  int lenght = linkedListLenght(*head);

  for (int i = 0; i < lenght; i++) {
    linkedListRemove(head, 0);
  }
}

/**
 * Impime el contenido de la lista en stdlib
 * @param head lista de nodos
 */
void displayLinkedList(LinkedList *head) {
  LinkedListNode *ptrActual = head;

  if (linkedListEmpty(head)) {
    printf("displayLinkedList - La lista esta vacia.\n");
    return;
  }

  for (int i = 0; ptrActual != NULL; i++) {
    printf("[%d: %d]->", i, ptrActual->data);
    ptrActual = ptrActual->next;
  }

  printf("NULL\n");
}

void listValuesLinkedList(LinkedList *head) {
  LinkedListNode *ptrActual = head;

  if (linkedListEmpty(head)) {
    return;
  }

  for (int i = 0; ptrActual != NULL; i++) {
    printf("%3d: %d\n", i, ptrActual->data);
    ptrActual = ptrActual->next;
  }
}

#endif
