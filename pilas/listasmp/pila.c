#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"
#include "stackA.h"

int main() {
  int op;
  int value = 0;
  Stack stack;
  stackInit(&stack);

  printf("Instrucciones\n");
  printf(" Escribe el numero entre corchetes correpondiente \n");
  printf(" a la opcion.\n\n");
  printf(" [1] Agrega elementos al stack\n");
  printf(" [2] Extrae elementos de la pila\n");
  printf("-----------------------------------\n");
  printf(" [0] Salir\n");
  
  
  do {

    printf("\nPila\n");
    displayStack(&stack);
    
    printf("\n[1] Push [2] Pop | [0] Salir |> ");
    scanf("%d", &op);

    switch(op){
    case 1:
      printf("Valor a ingresar: ");
      scanf("%d",&value);
      stackPush(&stack,value);
      break;

    case 2:
      if(stack.size > 0) {
        int a = stackPop(&stack);
        printf("valor extraido: %d \n", a);
      } else {
        printf("no hay valores para extraer\n");
      }
      
      break;
    }
    
    
  }while(op);

  stackFree(&stack);
  
  return 0;
}
