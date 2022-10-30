#include <stdio.h>
#include <stdlib.h>

#include "lib/arrayCircularQueue.h"
#include "lib/arrayQueue.h"
#include "lib/circularList.h"
#include "lib/queueA.h"

int getInt();

void mainMenu();
void testArrayCircularQueue();
void testArrayQueue();
void testCircularList();
void testQueue();

int main() {
  int op;

  do {
    mainMenu();
    op = getInt();

    switch (op) {
    case 1:
      testArrayCircularQueue();
      break;

    case 2:
      testArrayQueue();
      break;

    case 3:
      testCircularList();
      break;

    case 4:
      testQueue();
      break;
    }

  } while (op);

  return 0;
}

int getInt() {
  int op;
  scanf("%d", &op);
  return op;
}

void mainMenu() {
  printf("                            \n"
         "ESTRUCTURA A PROBAR         \n"
         " |                          \n"
         " +- 1. ARRAY CIRCULAR QUEUE \n"
         " +- 2. ARRAY QUEUE          \n"
         " +- 3. CICULAR QUEUE        \n"
         " +- 4. QUEUE                \n"
         " |                          \n"
         " +- 0. SALIR                \n"
         "                            \n"
         " > ");
}


void testQueue(){
  int data = 0;
  int op = 0;
  Queue a;
  queueInit(&a);
  
  do {
    printf("\n");

    displayQueue2(&a);
    
    printf("                            \n"
           "ARRAY CICULAR QUEUE         \n"
           " |                          \n"
           " +- 1. ENQUEUE              \n"
           " +- 2. DEQUEUE              \n"
           " |                          \n"
           " +- 0. SALIR                \n"
           "                            \n"
           " > ");
    
    switch (op = getInt()) {
    case 1:
      printf("Agregar a la cola: ");
      data = getInt();
      enqueue(&a, data);
      break;

    case 2:
      if (a.size == 0)
        /* si no hay nada pues no hace nada */
        break;
      
      data = dequeue(&a);
      printf("valor extraido: %d\n", data);
      break;
    }

  } while (op);

  queueFree(&a);
}


void testCircularList() {
  int data = 0;
  int op = 0;
  CircularList a;
  circularListInit(&a);

  do {
    printf("\n");
    displayCircularList(&a);

    printf("                            \n"
           "CICULAR QUEUE               \n"
           " |                          \n"
           " +- 1. ENQUEUE              \n"
           " +- 2. DEQUEUE              \n"
           " +- 3. NEXT                 \n"
           " |                          \n"
           " +- 0. SALIR                \n"
           "                            \n"
           " > ");

    switch (op = getInt()) {
    case 1:
      printf("Valor a agregar: ");
      data = getInt();
      circularListEnqueue(&a, data);
      break;

    case 2:
      if (a.size == 0)
        /* si no hay elementos  pues nos hace nada */
        break;

      data = circularListDequeue(&a);
      printf("valor extraido: %d", data);
      break;

    case 3:
      circularListNext(&a);
      break;
    }
  } while (op);

  circularListFree(&a);
  
}

void testArrayQueue() {
  int data = 0;
  int op = 0;
  ArrayQueue a;
  staticQueueInit(&a);

  do {
    printf("                \n"
           "%d usados de %d\n", a.size, ARRAY_QUEUE_SIZE);

    displayStaticQueue(&a);

    printf("                            \n"
           "ARRAY CICULAR QUEUE         \n"
           " |                          \n"
           " +- 1. ENQUEUE              \n"
           " +- 2. DEQUEUE              \n"
           " |                          \n"
           " +- 0. SALIR                \n"
           "                            \n"
           " > ");

    switch (op = getInt()) {
    case 1:
      printf("Agregar a la cola: ");
      data = getInt();
      staticEnqueue(&a, data);
      break;

    case 2:
      if (a.size == 0)
        /* si no hay nada pues no hace nada */
        break;

      data = staticDequeue(&a);
      printf("valor extraido: %d\n", data);
      break;
    }

  } while (op);
}

void testArrayCircularQueue() {
  int data = 0;
  int op = 0;
  ArrayCircularQueue a;
  arrayCircularQueueInit(&a);

  do {
    printf("               \n"
           "%d usados de %d\n", a.size, ARRAY_CIRCULAR_QUEUE_SIZE);

    displayArrayCicularQueue(&a);

    printf("                            \n"
           "ARRAY CICULAR QUEUE         \n"
           " |                          \n"
           " +- 1. ENQUEUE              \n"
           " +- 2. DEQUEUE              \n"
           " +- 3. NEXT                 \n"
           " |                          \n"
           " +- 0. SALIR                \n"
           "                            \n"
           " > ");

    switch (op = getInt()) {
    case 1:
      printf("Valor a agregar: ");
      data = getInt();
      arrayCircularQueueEnqueue(&a, data);
      break;

    case 2:
      if (a.size == 0)
        /* si no hay elementos  pues nos hace nada */
        break;

      data = arrayCircularQueueDequeue(&a);
      printf("valor extraido: %d", data);
      break;

    case 3:
      arrayCircularQueueNext(&a);
      break;
    }
  } while (op);
}
