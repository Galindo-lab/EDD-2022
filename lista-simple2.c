
#include <stdio.h>
#include <stdlib.h>

struct _LinkedListNode {
  int data;
  struct _LinkedListNode *next;
};

typedef struct _LinkedListNode LinkedList;
typedef struct _LinkedListNode LinkedListNode;

/**
 * Restorna si la lista esta vacia
 * @param *head lista de nodos
 * @return verdadero si la lista esta vacia
 */
short linkedListEmpty(LinkedList *head);

/**
 * cualqiuier valor mayor o igual a -1 es valido, si no es
 * valido termina el programa
 * @param position a verificar 
 */
void _llValidPosition(int position);

/**
 * Crea un nodo para la lista
 * @param valor del nodo
 * @return direccion al nuevo nodo
 */
LinkedListNode *linkedListNodeCreate(int value);

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
void linkedListInsert(LinkedList **head, LinkedListNode *node, int position);

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
void linkedListRemove(LinkedList **head, int position);

/**
 * obtener posicion en la lista
 * @param head lista de nodos
 * @param posicion a obtener
 * @return el valor del nodo
 */
int linkedListGet(LinkedList **head, int position);

/**
 * Numero de elementos en la lista
 * @param posicion a obtener
 * @return tamaño de lista
 */
int linkedListLenght(LinkedList *head);

/**
 * Liberar la memoria que esta usando la lista
 * @param head lista de nodos
 * @return
 */
void linkedListFree(LinkedList **head);

/**
 * Impime el contenido de la lista en stdlib
 * @param head lista de nodos
 */
void displayLinkedList(LinkedList *head);



int main() {
  LinkedList *a = NULL;

  linkedListRemove(&a, 0);
  displayLinkedList(a);

  linkedListInsert(&a, linkedListNodeCreate(0), 0);
  linkedListInsert(&a, linkedListNodeCreate(1), 0);
  linkedListInsert(&a, linkedListNodeCreate(3), 1);
  linkedListInsert(&a, linkedListNodeCreate(4), -1);
  linkedListInsert(&a, linkedListNodeCreate(5), 99);
  linkedListFree(&a);

  displayLinkedList(a);

  /* printf("%d\n",linkedListGet(&a,0)); */
  /* printf("%d\n",linkedListGet(&a,1)); */
  /* printf("%d\n",linkedListGet(&a,2)); */
  /* printf("%d\n",linkedListGet(&a,3)); */
  /* printf("%d\n",linkedListGet(&a,4)); */
  /* printf("%d\n",linkedListGet(&a,-5)); */
  /* printf("%d\n",linkedListGet(&a,6)); */

  /* linkedListRemove(&a, 2); */
  /* displayLinkedList(a); */

  /* linkedListRemove(&a, 2); */
  /* displayLinkedList(a); */
  /* linkedListRemove(&a, 2); */
  /* displayLinkedList(a); */

  return 0;
}

short linkedListEmpty(LinkedList *head) { return head == NULL; }

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
    /* iterar hasta el ultimo nodo */
    while (current != NULL) {
      previous = current;
      current = current->next;
    }

    previous->next = new;
    new->next = current;
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

void displayLinkedList(LinkedList *head) {
  LinkedListNode *ptrActual = head;

  if (linkedListEmpty(head)) {
    printf("La lista esta vacia.\n");
    return;
  }

  for (int i = 0; ptrActual != NULL; i++) {
    printf("[%d: %d]->", i, ptrActual->data);
    ptrActual = ptrActual->next;
  }

  printf("NULL\n");
}

void linkedListRemove(LinkedList **head, int position) {
  LinkedListNode *current = *head;
  LinkedListNode *previous = NULL;

  _llValidPosition(position);

  /* no existe el primer elemento */
  if (linkedListEmpty(*head)) {
    printf("La lista esta vacia\n");
    return;
  }

  /* elimna la primera posicion o eliminar un elemento unico*/
  if (position == 0 || current->next == NULL) {
    printf("caso 1\n");
    previous = current;
    *head = current->next;
    free(previous);
    return;
  }

  /* elimina la ultima posicion */
  if (position == -1) {
    printf("caso 2\n");
    while (current->next != NULL) {
      previous = current;
      current = current->next;
    }

    previous->next = NULL;
    free(current);
    return;
  }

  /* caso base */
  printf("caso base\n");
  for (int i = 0; i < position; i++) {
    previous = current;
    current = current->next;

    /* si no existe la posicion se termina el bucle, exepto si es la ultima
       iteracion */
    if (current->next == NULL && !(i + 1 < position)) {
      printf("Elemento fuera del rango de la lista\n");
      exit(EXIT_FAILURE);
    }
  }

  previous->next = current->next;
  free(current);
}

int linkedListGet(LinkedList **head, int position) {
  LinkedListNode *current = *head;

  _llValidPosition(position);

  if (linkedListEmpty(*head)) {
    printf("La lista esta vacia!\n");
    exit(EXIT_FAILURE);
  }

  /* retorna el valor de la ultima posición */
  if (position == -1) {
    while (current->next != NULL)
      current = current->next;
    return current->data;
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

void linkedListFree(LinkedList **head) {
  int lenght = linkedListLenght(*head);

  for (int i = 0; i < lenght; i++) {
    linkedListRemove(head, 0);
  }
}

void _llValidPosition(int position){
  if(position < -1) {
    printf("La posicion es menor a -1\n");
    exit(EXIT_SUCCESS);
  }
}
