#ifndef arrayCircularQueue
#define arrayCircularQueue

#define ARRAY_CIRCULAR_QUEUE_SIZE 20

typedef struct {
  int size;
  int data[ARRAY_CIRCULAR_QUEUE_SIZE];
} ArrayCircularQueue;

/**
 * Inicializa la estrucutra
 * @param *queue un puntero a la cola
 */
void arrayCircularQueueInit(ArrayCircularQueue *queue) {
  queue->size = 0;

  for (int i = 0; i < ARRAY_CIRCULAR_QUEUE_SIZE; i++) {
    queue->data[i] = 0;
  }
}

/**
 * Verificar si la lista esta vacia
 * @param *queue un puntero a la cola
 * @return si esta llena
 */
short arrayCircularQueueFull(ArrayCircularQueue *queue) {
  return queue->size == ARRAY_CIRCULAR_QUEUE_SIZE;
}

/**
 * Verificar si esta vacia
 * @param *queue un puntero a la cola
 * @return si esta vacia
 */
short arrayCircularQueueEmpty(ArrayCircularQueue *queue) {
  return queue->size == 0;
}

/**
 * Añadir un entero a la cola
 * @param *queue un puntero a la cola
 * @param value el valor a agregar
 */
void arrayCircularQueueEnqueue(ArrayCircularQueue *queue, int value) {
  if (arrayCircularQueueFull(queue)) {
    printf("arrayCircularQueueEnqueue - Lista llena\n");
    return;
  }

  queue->data[queue->size] = value;
  queue->size += 1;
}

/**
 * extraer un valor de la cola
 * @param *queue un puntero a la cola
 */
int arrayCircularQueueDequeue(ArrayCircularQueue *queue) {
  if (arrayCircularQueueEmpty(queue)) {
    printf("arrayCircularQueueDequeue - Esta sacando un elemento invalido de "
           "la lista\n");
    return 0;
  }

  int foo = 0;
  foo = queue->data[0];
  queue->size -= 1;

  for (int i = 1; i < ARRAY_CIRCULAR_QUEUE_SIZE; i++) {
    queue->data[i - 1] = queue->data[i];
  }

  return foo;
}

/**
 * Pasar al siguiente elemento en la cola
 * @param *queue un puntero a la cola
 */
void arrayCircularQueueNext(ArrayCircularQueue *queue) {
  if (arrayCircularQueueEmpty(queue)) {
    return;
  }

  int foo = queue->data[0];
  for (int i = 1; i < ARRAY_CIRCULAR_QUEUE_SIZE; i++)
    queue->data[i - 1] = queue->data[i];

  queue->data[queue->size - 1] = foo;
}

/**
 * Mostrar el contenido de la pila
 * @param *queue un puntero a la cola
 */
void displayArrayCicularQueue(ArrayCircularQueue *queue) {
  if(arrayCircularQueueEmpty(queue)) {
    printf("La cola esta vacia\n");
    return;
  }

  
  for (int i = 0; i < queue->size; i++) {
    printf("%3d: %d\n", i, queue->data[i]);
  }
}

#endif
