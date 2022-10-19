#include <stdio.h>

#include "linkedList.h"

int main() {
  LinkedList *list = NULL;

  /* linkedListInsert(&list,linkedListNodeCreate(0),0);  */
  
  for(int i=0;i < 10; i++){
    linkedListInsert(&list,linkedListNodeCreate(i),-1);
  }

  displayLinkedList(list);
  printf("%d\n", linkedListGet(&list, -1));

  linkedListRemove(&list,-1);
  linkedListRemove(&list,-1);
  linkedListRemove(&list,-1);
    linkedListRemove(&list,-1);
      linkedListRemove(&list,-1);
        linkedListRemove(&list,-1);
          linkedListRemove(&list,-1);
            linkedListRemove(&list,-1);
              linkedListRemove(&list,0);
              linkedListRemove(&list,-1);
  displayLinkedList(list);
  
  
  return 0;
}
