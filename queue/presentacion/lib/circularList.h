
#ifndef circularList
#define circularList

#include "linkedList.h"

typedef struct {
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
  list->nodes = NULL;
  list->front = NULL;
  list->rear = NULL;
}

void circularListEnqueue(CircularList *list, int value) {
  linkedListInsert(&list->nodes, linkedListNodeCreate(value), -1);
}

int circularListDequeue(CircularList *list) {
  if (linkedListEmpty(list->nodes)) {
    printf("circularListDequeue - Lista Circular Vacia\n");
    return 0;
  }

  int foo = linkedListGet(&list, 0);
  linkedListRemove(&list->nodes, 0);

  return foo;
}

void displayCircularList(CircularList *list) { displayLinkedList(list->nodes); }

#endif
