
#include <stdio.h>
#include <stdlib.h>

struct linkedListNode {
  int data;
  struct linkedListNode *next;  
};

typedef struct linkedListNode LinkedList;
typedef struct linkedListNode LinkedListNode;


LinkedListNode* linkedListNodeCreate(int value);
int linkedListEmpty(LinkedList *head);

void linkedListInsert(LinkedList *head, LinkedListNode *node, int position);
void linkedListRemove(LinkedList *head, int position);
void linkedListFree(LinkedList *head);


void imprimeLista(LinkedList *head) {
  LinkedListNode *ptrActual = head;

  if (head == NULL) {
    printf("La lista esta vacia.\n");
    return;
  }

  for(int i = 0; ptrActual != NULL; i++){
    printf("[%d: %d]->", i, ptrActual->data);
    ptrActual = ptrActual->next;    
  }
  
  printf("NULL\n");
}

int main() {
  LinkedList *list = NULL;
  imprimeLista(list);

  linkedListInsert(list,linkedListNodeCreate(2),0);
  
  /* list = linkedListNodeCreate(0); */
  imprimeLista(list);

  
  return 0;
}

/**
 * 
 * @param  
 * @return 
 */
int linkedListEmpty(LinkedList* head) {
  return head == NULL;
}


/**
 * Crear un nodo para la lista 
 * @param  
 * @return 
 */
LinkedListNode* linkedListNodeCreate(int value) {
  LinkedListNode *foo = malloc(sizeof(LinkedListNode));
  
  if(foo == NULL){
    printf("no se pudo reservar memoria\n");
    exit(EXIT_FAILURE);
  }

  foo->data = value;
  foo->next = NULL;

  return foo;
}


void linkedListInsert(LinkedList *head, LinkedListNode *node, int position) {
  LinkedListNode *new = node;
  LinkedListNode *current = head;
  LinkedListNode *previous = NULL;

  printf("%d\n",new->data);

  if(linkedListEmpty(head)){
    printf("aaaaaa\n");
    new->next = head;
    head = *new;
  }

  
}
