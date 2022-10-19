#ifndef arrayQueue
#define arrayQueue

#include <stdio.h>
#include <stdlib.h>

#define ARRAY_QUEUE_SIZE 20

typedef struct {
  int size;
  int data[ARRAY_QUEUE_SIZE];
} ArrayQueue;

/**
 * Inicializa la lista 
 * @param direcciona a una ArrayQueue
 */
void staticQueueInit(ArrayQueue* queue){
  queue->size = 0;
  
  for(int i=0;i < ARRAY_QUEUE_SIZE; i++){
    queue->data[i] = 4;
  }
}

/**
 * Retorna si la lista esta vacia
 * @param direccion a ArrayQueue
 */
short staticQueueEmpty(ArrayQueue *queue) {
  return queue->size == 0;
}

/**
 * Retorna si la lista esta llena
 * @param direccion a ArrayQueue
 */
short staticQueueFull(ArrayQueue *queue) {
  return queue->size == ARRAY_QUEUE_SIZE;
}

/**
 * añade un elemento a la cola
 * @param  
 * @return 
 */
void staticEnqueue(ArrayQueue *queue, int value) {
  if(staticQueueFull(queue)) {
    printf("Cola llena\n");
    return;
  }

  queue->data[queue->size] = value;
  queue->size += 1;
}

/**
 * Extrae el primer elemento de la cola
 * @param  
 * @return 
 */
int staticDequeue(ArrayQueue *queue) {
  int value = 0;
  if(staticQueueEmpty(queue)) {
    printf("ERROR: Cola Vacia\n");
    return 0;
  }

  value = queue->data[0];

  /* recorrer los datos una posicion */
  for(int i=0;i < queue->size-1; i++){
    queue->data[i] = queue->data[i+1];
  }
  
  queue->size -= 1;
  return value;
}

/**
 * Muesra el valor en la cola
 * @param  
 * @return 
 */
void displayStaticQueue(ArrayQueue *queue) {
  for(int i=0;i < queue->size; i++){
    printf("%d: %d\n",i,queue->data[i]);
  }
}





#endif

