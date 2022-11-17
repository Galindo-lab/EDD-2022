
#ifndef stackA
#define stackA

#include "linkedList.h"

typedef struct {
  LinkedList* pila;
  int size;
} Stack;


TreeNodePtr stackTop(Stack* stack) {
  return stack->pila->data;
}


/**
 * Verifica si todavia hay elementos en el stack
 * @param direccion al stack
 * @return si esta vacio
 */
short stackEmpty(Stack *stack) {
  return linkedListEmpty(stack->pila);
}

/**
 * Inicializa el tamaño y el valor inicial de la lista 
 * @param direccion al stack
 */
void stackInit(Stack *stack) {
  stack->pila = NULL;
  stack->size = 0;
}

/**
 * Agrega un elemento a la pila
 * @param stack direccion a el stack
 * @param valor a agregar
 */
void stackPush(Stack *stack, TreeNodePtr value) {
  linkedListInsert(&stack->pila, linkedListNodeCreate(value), 0);
  stack->size += 1;
}

/**
 * Extrae un elementos de la pila, si la cantidad de elementos es 0 
 * no se detiene el programa pero manda un mensaje de error, siempre
 * se tiene que verificar si el esta vacio antes de hacer pop.
 * @param stack direccion a el stack 
 * @return valor del numero extraido
 */
TreeNodePtr stackPop(Stack *stack) {
  if(stack->size == 0) {
    printf("ERROR: se extrajo un valor del stack vacio\n");
    return 0;
  }

  TreeNodePtr foo = linkedListGet(&stack->pila,0);  
  linkedListRemove(&stack->pila,0);
  stack->size -= 1;
  return foo;
}

/**
 * Liberar la memoria que esta usando la pila
 * @param stack direccion a el stack 
 */
void stackFree(Stack *stack) {
  linkedListFree(&stack->pila);
  stack->size = 0;
}

/**
 * Muestra los valores en el stack
 * @param stack direccion a el stack 
 */
void displayStack(Stack *stack) {
  listValuesLinkedList(stack->pila);
}

#endif
