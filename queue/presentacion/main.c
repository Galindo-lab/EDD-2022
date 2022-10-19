
#include <stdio.h>

#include "lib/arrayQueue.h"
#include "lib/circularList.h"
#include "lib/queueA.h"

int main() {

  CircularList a;
  circularListInit(&a);

  circularListEnqueue(&a, 9);
  circularListEnqueue(&a, 10);
  circularListEnqueue(&a, 11);
  circularListEnqueue(&a, 12);
  circularListEnqueue(&a, 3);


  displayCircularList(&a);

  for(int i=0;i < 10; i++){
    circularListDequeue(&a);
    displayCircularList(&a);
  }


  /* ArrayQueue a; */

  /* staticQueueInit(&a); */

  /* for(int i=0;i < 21; i++){ */
  /*   staticEnqueue(&a,i+3);  */
  /* } */

  /* int foo = staticDequeue(&a); */
  /* staticDequeue(&a); */
  /* staticDequeue(&a); */
  /* staticDequeue(&a); */
  /* staticDequeue(&a); */
  /* staticDequeue(&a); */

  /* staticEnqueue(&a,10);  */

  /* displayStaticQueue(&a); */

  /* printf("extraido %d\n",foo); */

  /* Queue cola; */
  /* LinkedList* lista= NULL; */

  /* linkedListOrderedInsert(&lista, linkedListNodeCreate(1)); */
  /* linkedListOrderedInsert(&lista, linkedListNodeCreate(1)); */
  /* linkedListOrderedInsert(&lista, linkedListNodeCreate(2)); */
  /* linkedListOrderedInsert(&lista, linkedListNodeCreate(1)); */
  /* linkedListOrderedInsert(&lista, linkedListNodeCreate(1)); */
  /* linkedListOrderedInsert(&lista, linkedListNodeCreate(9)); */
  /* linkedListOrderedInsert(&lista, linkedListNodeCreate(0)); */

  /* displayLinkedList(lista); */

  /* /\* system("clear"); *\/ */

  /* /\* enqueue(&cola,2); *\/ */
  /* orderedEnqueue(&cola, 1); */
  /* orderedEnqueue(&cola, 1); */
  /* orderedEnqueue(&cola, 2); */
  /* orderedEnqueue(&cola, 1); */
  /* orderedEnqueue(&cola, 1); */
  /* orderedEnqueue(&cola, 9); */
  /* orderedEnqueue(&cola, 0); */
  /* orderedEnqueue(&cola, 10); */

  /* displayQueue(&cola); */

  return 0;
}
