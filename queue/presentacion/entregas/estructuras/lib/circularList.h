
#ifndef circularList
#define circularList

#include "linkedList.h"

typedef struct {
  int size;
  LinkedList *nodes;
  LinkedListNode *front;
  LinkedListNode *rear;
} CircularList;

/**
 *
 * @param
 * @return
 */
void circularListInit(CircularList *list) {
  list->size = 0;
  list->nodes = NULL;
  list->front = NULL;
  list->rear = NULL;
}

short circularListEmpty(CircularList *list) {
  return linkedListEmpty(list->nodes);
}

/**
 *
 * @param
 * @return
 */
void circularListEnqueue(CircularList *list, int value) {
  LinkedListNode *foo = linkedListNodeCreate(value);

  if (circularListEmpty(list)) {
    list->front = foo;
  }

  linkedListInsert(&list->nodes, foo, -1);
  list->rear = foo;
  list->size += 1;
}

/**
 *
 * @param
 * @return
 */
int circularListDequeue(CircularList *list) {
  if (circularListEmpty(list)) {
    printf("circularListDequeue - Lista Circular Vacia\n");
    return 0;
  }

  int foo = linkedListGet(&list->nodes, 0);
  linkedListRemove(&list->nodes, 0);
  list->front = list->nodes;
  list->size -= 1;

  return foo;
}

void circularListNext(CircularList *list) {
  if (circularListEmpty(list)) {
    printf("circularListNext - Lista Circular Vacia\n");
    return;
  }

  /* pasar el l siguiente nodo */
  list->nodes = list->nodes->next;

  /* cambiar el front al rear */
  list->rear->next = list->front;
  list->front->next = NULL;

  /* actualizar los valores del front y rear */
  list->rear = list->front;
  list->front = list->nodes;
}

int circularListPeek(CircularList *list) {
  if (circularListEmpty(list)) {
    printf("circularListPeek - Lista Circular Vacia\n");
    return 0;
  }

  return linkedListGet(&list->nodes, 0);
}

/**
 * 
 * @param
 * @return
 */
void displayCircularList(CircularList *list) {

  if(circularListEmpty(list)) {
    printf("lista circular vacia\n");
    return;
  }
  
  LinkedListNode *current = list->nodes;

  /* printf("+-----+-------+\n"); */
  /* printf("|  #  | valor │\n"); */
  /* printf("+-----+-------+\n"); */
  
  for (int i = 0; current != NULL; i++) {
    /* printf(" %d %d |-", i, current->data); */
    printf("%3d: %d \n", i, current->data);
    
    current = current->next;
  }

  /* printf("+-----+-------+\n"); */
}

void circularListFree(CircularList *list) {
  list->size = 0;
  list->front = NULL;
  list->rear= NULL;
  linkedListFree(&list->nodes);
}

#endif
