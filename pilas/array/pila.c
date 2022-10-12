#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 20

struct _stack {
  int pila[MAX_STACK_SIZE];
  int size;
};

typedef struct _stack Stack;

/**
 * Revisar si el stack esta lleno
 * @param puntero a la pila
 * @return si esta lleno
 */
short full(Stack *stack) { return stack->size == MAX_STACK_SIZE; }

/**
 * Revisar si la lista esta vacia
 * @param puntero a la pila
 * @return si esta vacio
 */
short empty(Stack *stack) { return stack->size == 0; }

/**
 * Inicializa los valores a 0 en el stack
 * @param puntero a la pila
 */
void iniciar_pila(Stack *stack) {
  stack->size = 0;
  for (int i = 0; i < MAX_STACK_SIZE; i++)
    stack->pila[i] = 0;
}

/**
 * Inserta un elemento "hasta arriba"
 * @param puntero al stack
 * @param valor a insertar
 */
void push(Stack *stack, int valor) {
  if (full(stack)) {
    printf("Pila Llena\n");
    return;
  }

  /* posicion de "hasta arriba" */
  int top = stack->size;
  stack->pila[top] = valor;
  stack->size += 1;
}

/**
 * Extrae el ultimo elemento del stack
 * @param puntero a la lista
 * @return el valor del elemento
 */
int pop(Stack *stack) {
  if (empty(stack)) {
    printf("El stack está vacia\n");
    return 0;
  }

  int top = stack->size - 1;
  int value = stack->pila[top];

  stack->pila[top] = 0;
  stack->size -= 1;
  return value;
}

/**
 * Muestra el contenido del stack
 * @param
 * @return
 */
void display(Stack *stack) {
  printf("%d used of %d\n", stack->size, MAX_STACK_SIZE);
  for (int i = 0; i < stack->size; i++)
    printf("%3d: %d\n", i, stack->pila[i]);
}

int main() {
  short loop = 1;
  int op;
  int foo;
  Stack a;
  iniciar_pila(&a);

  while (loop) {

    display(&a);
    printf("\n");
    printf(" 1: Push\n");
    printf(" 2: Pop\n");
    printf("-----------\n");
    printf(" 0: Salir\n");

    scanf("%d", &op);

    switch(op){
    case 1:                     /* Push */
      printf("valor a ingresar: ");
      scanf("%d", &op);
      push(&a, op);
      break;

    case 2:                     /* Pop */
      foo = pop(&a);
      printf("el valor extraido: %d\n", foo);
      break;

    case 0:                     /* salir */
      loop = 0;
      break;

    default:                    /* eror */
      printf("No existe esa opcion.\n");
      break;
    }
  }
  
  return 0;
}
