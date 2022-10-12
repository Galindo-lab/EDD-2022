
/*
 * TITULO: Listas dobles enlazadas 
 * AUTOR: Luis Eduardo Galindo Amaya
 * FECHA: mar 20 sep 2022 19:51:44
 */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct doubleList {
  int dato;
  struct doubleList *ptrNext; /* siguiente */
  struct doubleList *ptrPrev; /* anterior */
};

typedef struct doubleList NodeList;
typedef NodeList *ptrNodeList;

int listEmpty(ptrNodeList ptrS);

int capturar_entero();
int estaVacia(ptrNodeList ptrS);
int menu_principal();
char capturar_caracter();
void instrucciones(void);

ptrNodeList newNode(int value);
void listInsert(ptrNodeList *ptrS, int position, int value);
void listRemove(ptrNodeList *ptrS, int position);
void listDisplay(ptrNodeList ptrS);

int main(void) {
  ptrNodeList lista = NULL;
  int op = -1;
  int captura;
  int posicion;


  instrucciones();

  while (op) {
    printf("-------------------------------------------------\n");
    printf("\n");
    listDisplay(lista);
    printf("\n");
    printf("-------------------------------------+-----------\n");
    printf("[a]gregar [e]liminar [i]nstrucciones | [s]alir? ");
    op = menu_principal();

    switch (op) {
    case 1: /* Insertar */
      printf("valor a insertar: ");
      captura = capturar_entero();
      printf("posicion a insertar (0: inicio, -1: final): ");
      posicion = capturar_entero();
      listInsert(&lista, posicion, captura);
      break;

    case 2: /* Eliminar */
      printf("posicion a eliminar (0: inicio, -1: final): ");
      posicion = capturar_entero();
      listRemove(&lista, posicion);
      break;

    case 3:
      instrucciones();
      break;
    }
  }  
 

  return 0;
}

/**
 * Verificar si la lista esta vacia
 * @param verdadero si está vacia
 */
int listEmpty(ptrNodeList ptrS) { return ptrS == NULL; }

/**
 * Mostrar el contenido de la lista en stdout
 * @param
 */
void listDisplay(ptrNodeList ptrS) {
  if (listEmpty(ptrS)) {
    printf("La lista esta vacia.\n");
    return;
  }

  for (int i = 0; ptrS != NULL; i++) {
    printf("[%d: %d]->", i, ptrS->dato);
    ptrS = ptrS->ptrNext;
  }

  printf("NULL\n");
}

/**
 * Crear un nodo nuevo
 * @param value del nodo nuevo
 * @return direccion de memoria del nodo
 */
ptrNodeList newNode(int value) {
  ptrNodeList ptrNuevo = malloc(sizeof(NodeList));

  /* Verificar que hay memoria para contirnuar */
  if (ptrNuevo == NULL) {
    printf("%d no se inserto. Memoria no disponible.\n", value);
    exit(EXIT_FAILURE);
  }

  ptrNuevo->dato = value;
  ptrNuevo->ptrNext = NULL;
  ptrNuevo->ptrPrev = NULL;
  return ptrNuevo;
}

/**
 * insertar un elemento en la lista, 0 al inicio -1 la final
 * @param direccion a la lista de punteros
 * @param posicion posicion de la lista 
 * @param calor del nodo
 */
void listInsert(ptrNodeList *ptrS, int position, int value) {
  ptrNodeList ptrNuevo;
  ptrNodeList ptrActual;
  ptrNodeList ptrAnterior;

  ptrActual = *ptrS;
  ptrNuevo = newNode(value);

  /* insertar al inicio si esta vacia */
  if (listEmpty(ptrActual)) {
    *ptrS = ptrNuevo;
    return;
  }

  /* insertar al inicio de la lista si No esta vacia */
  if (position == 0) {
    ptrActual->ptrPrev = ptrNuevo;
    ptrNuevo->ptrNext = ptrActual;
    *ptrS = ptrNuevo;
    return;
  }

  /* todos los nodos a partir de aqui tienen un predecesor  */

  /* insertar en el ultimo elemento */
  if(position <= -1 || ptrActual->ptrNext == NULL){
    /* ir al ultimo elemento */
    while (ptrActual->ptrNext != NULL)
      ptrActual = ptrActual->ptrNext;

    ptrNuevo->ptrPrev = ptrActual;
    ptrActual->ptrNext = ptrNuevo;
    return;
  }

  /* insertar en posicion 'n', si 'position' es mas grande que
     el tamaño de la lista el elemento se inserta al final */

  for (int i = position; i > 0; i--) {
    /* si el siguiente elemento es NULL, significa
       que estamos en el ultimo nodo */
    if (ptrActual->ptrNext == NULL)
      break;

    /* itear para los elementos de la lista */
    ptrAnterior = ptrActual;
    ptrActual = ptrActual->ptrNext;
  }

  ptrAnterior->ptrNext = ptrNuevo;
  ptrNuevo->ptrPrev = ptrActual->ptrPrev;
  ptrNuevo->ptrNext = ptrActual;
  ptrActual->ptrPrev = ptrNuevo;
}

/**
 * Eliminar un elemento en la lista, 0 al inicio -1 la final
 * @param direccion a la lista de punteros
 * @param posicion posicion de la lista 
 * @param calor del nodo
 */
void listRemove(ptrNodeList *ptrS, int position) {
  ptrNodeList ptrAnterior;
  ptrNodeList ptrActual = *ptrS;
  ptrNodeList ptrSiguiente;

  /* No se puede eliminar nada de una lista vacia, no hace nada */
  if (listEmpty(ptrActual)) {
    return;
  }

  /* eliminar el primer elemento de la lista o el ultimo
     cuando hay menos de una elemento */
  if (position == 0 || ptrActual->ptrNext == NULL) {
    *ptrS = ptrActual->ptrNext;
    free(ptrActual);
    return;
  }

  /* eliminar el ultimo elemento de la lista cuando
     hay mas de 1 elemento */
  if (position <= -1) {
    /* ir al ultimo elemento */
    while (ptrActual->ptrNext != NULL)
      ptrActual = ptrActual->ptrNext;

    ptrAnterior = ptrActual->ptrPrev;

    ptrAnterior->ptrNext = NULL;
    free(ptrActual);
    return;
  }

  /* insertar en posicion 'n', si 'position' es mas grande que
   el tamaño de la lista el elemento se inserta al final */

  for (int i = position; i > 0; i--) {
    /* itear para los elementos de la lista */
    ptrAnterior = ptrActual;
    ptrActual = ptrActual->ptrNext;

    /* si el siguiente elemento es NULL, significa
       que estamos en el ultimo nodo */
    if (ptrActual == NULL) {
      printf("No existe esa posicion\n");
      return;
    }
  }

  if ((ptrSiguiente = ptrActual->ptrNext) != NULL) {
    ptrSiguiente->ptrPrev = ptrSiguiente->ptrPrev;
  }

  ptrAnterior->ptrNext = ptrActual->ptrNext;
  free(ptrActual);
}

/**
 * Muestra el menu principal, captura el caracter de opcion y
 * retorna el indice de la operacion a realizar
 *
 * @return operacion
 */
int menu_principal() {
  char foo = 0;
  foo = capturar_caracter();

  // convertr a minuscula
  foo = foo | 32;

  if (foo == 's')
    return 0;
  if (foo == 'a')
    return 1;
  if (foo == 'e')
    return 2;
  if (foo == 'i')
    return 3;

  printf("\nERROR: No existe esa opcion\n");
  return -1;
}

/**
 * Retorna el caracter capturado o 10 si esta vacio.
 * el numero 10 corresponde a 'Line Feed / newline'
 *
 * Extraido de: https://stackoverflow.com/a/40949122
 *
 * @return caracter
 */
char capturar_caracter() {
  char line[256];
  char ch;

  if (fgets(line, sizeof line, stdin) == NULL) {
    printf("Input error.\n");
    exit(EXIT_FAILURE);
  }

  ch = line[0];
  return ch;
}

/**
 * Captura un numero entero y vacia el stdin 
 * @return valor capturado
 */
int capturar_entero() {
  int foo = 0;
  scanf("%d", &foo);

  /* vaciar inputbuffer de LF (10)
     https://stackoverflow.com/a/7898516 */
  int c;
  while ((c = getchar()) != '\n' && c != EOF);

  return foo;
}

/**
 * Muestra las intrucciones del progrma
 */
void instrucciones() {
  printf("\nIngresa el caracter entre corchetes para\n");
  printf("realizar la operacion.\n\n");
  printf(" a - agregar elementos a la lista\n");
  printf(" e - eliminar elementos de la lista\n");
  printf(" i - mostrar las instrucciones \n");
  printf(" s - salir\n\n");
}
