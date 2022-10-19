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
  queue->first = 0;
  queue->last = 0;
  
  for(int i=0;i < ARRAY_QUEUE_SIZE; i++){<na si la lista esta vacia
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
 * 
 * @param  
 * @return 
 */
void staticEnqueue(ArrayQueue *queue, int value) {
  if(staticQueueFull(queue)) {
    printf("Cola llena\n");
    return;
  }

  
}


#endif
