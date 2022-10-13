#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"
#include "queueA.h"

int main() {
  int op;
  int value = 0;
  Queue queue;
  queueInit(&queue);

  printf("Instrucciones\n");
  printf(" Escribe el numero entre corchetes correpondiente \n");
  printf(" a la opcion.\n\n");
  printf(" [1] agregar elementos a la fila\n");
  printf(" [2] Extrae elementos de la fila\n");
  printf("-----------------------------------\n");
  printf(" [0] Salir\n");
  
  
  do {

    printf("\nFila\n");
    displayQueue(&queue);

    printf("\n");
    printf("[1] Enqueue [2] Dequeue [3] Peek | [0] Salir\n");
    printf("---------------------------------+----------\n");
    printf(" > ");
    scanf("%d", &op);

    switch(op){
    case 1:
      printf("Valor a ingresar: ");
      scanf("%d",&value);
      enqueue(&queue,value);
      
      break;

    case 2:
      if(queue.size > 0) {
        printf("valor extraido: %d \n", dequeue(&queue));
        break;
      } 

      printf("no hay valores para extraer\n");
      
      
      break;

    case 3:
      if(queue.size > 0) {
        printf("el primer valor es: %d\n", peek(&queue));
      }
      break;
      
    }
    
    
  }while(op);

  queueFree(&queue);
  
  return 0;
}
