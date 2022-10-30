#ifndef queueA
#define queueA

#include "linkedList.h"

typedef struct {
  LinkedList *pila;
  int size;
} Queue;

/**
 * Verifica si todavia hay elementos en la fila
 * @param direccion a la fila
 * @return si esta vacia
 */
short queueEmpty(Queue *queue) { return linkedListEmpty(queue->pila); }

/**
 * Inicializa el tamaño y el valor inicial de la lista
 * @param direccion al stack
 */
void queueInit(Queue *queue) {
  queue->pila = NULL;
  queue->size = 0;
}

/**
 * Agrega un elemento a la fila
 * @param queue direccion a el queue
 * @param valor a agregar
 */
void enqueue(Queue *queue, int value) {
  linkedListInsert(&queue->pila, linkedListNodeCreate(value), -1);
  queue->size += 1;
}

/**
 * Inserta un valor de manera ordenada, el valor de mayor valor esta
 * en las primeras posiciones y los de menor valor en las ultimas
 * @param direcciona a una cola
 * @param valor a encolar
 */
void orderedEnqueue(Queue *queue, int value){
  linkedListOrderedInsert(&queue->pila, linkedListNodeCreate(value));
  queue->size += 1;
}

/**
 * Quitar el primer elemento de la lista
 * @warning si se quiere extraer un valor de una fila vacia se retornara 0 y se
 * mostrara un mensaje de error
 * @param direccion a la lista
 * @return valor extraido
 */
int dequeue(Queue *queue) {
  if (queue->size == 0) {
    printf("ERROR: se extrajo un valor de la lista vacia\n");
    return 0;
  }

  int foo = linkedListGet(&queue->pila, 0);
  linkedListRemove(&queue->pila, 0);
  queue->size -= 1;
  return foo;
}

/**
 * Revisar el primer valor de la pila
 * @warning si se quiere extraer un valor de una fila vacia se retornara 0 y se
 * mostrara un mensaje de error
 * @param direccion a la fila
 * @return valor al inicio
 */
int peek(Queue *queue) {
  if (queueEmpty(queue)) {
    printf("ERROR: La lista esta vacia");
    return 0;
  }

  return linkedListGet(&queue->pila, 0);
}

/**
 * Liberar la memoria que esta usando la pila
 * @param queue direccion a el queue
 */
void queueFree(Queue *queue) {
  linkedListFree(&queue->pila);
  queue->size = 0;
}




void displayQueue2(Queue* queue) {
  LinkedList *head = queue->pila;
  LinkedListNode *ptrActual = head;

  if (linkedListEmpty(head)) {
    return;
  }

  int a = -1;
  for (int i = 0; ptrActual != NULL; i++) {    
    int foo = ptrActual->data;
    a = foo;

    printf("%3d: %d\n", i, a);
    
    ptrActual = ptrActual->next;
  }  
}




/**
 * Muestra los valores en el stack
 * @param stack direccion a el stack
 */
void displayQueue(Queue *queue) {
  LinkedList *head = queue->pila;
  LinkedListNode *ptrActual = head;

  if (linkedListEmpty(head)) {
    return;
  }

  int a = -1;
  for (int i = 0; ptrActual != NULL; i++) {    
    int foo = ptrActual->data;
    
    if(foo != a) {
      printf("\n\n");

      switch(foo) {
      case 0:
        printf(" Normal: ");
        break;
      case 1:
        printf("Premium: ");
        break;
      case 2:
        printf("   Gold: ");
        break;
      }
    } 

    printf("o");
    
    a = foo;
    ptrActual = ptrActual->next;
  }

}

#endif
