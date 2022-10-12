#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

// Tipos de datos ----------------------------------------------

struct nodoLista {
  int dato;
  struct nodoLista *ptrSiguiente;
};

typedef struct nodoLista NodoLista;
typedef NodoLista *ptrNodoLista;

// Prototipos --------------------------------------------------

int capturar_entero();
int estaVacia(ptrNodoLista ptrS);
int menu_principal();
char capturar_caracter();

void insertar(ptrNodoLista *ptrS, int posicion, int valor);
void eliminar(ptrNodoLista *ptrS, int posicion);
int size(ptrNodoLista ptrS);
void imprimeLista(ptrNodoLista ptrActual);
void instrucciones(void);
void liberarMemoria(ptrNodoLista *ptrS);

// Main --------------------------------------------------------



int main() {
  ptrNodoLista lista = NULL;
  int op = -1;
  int captura;
  int posicion;

  instrucciones();

  while (op) {
    printf("-------------------------------------------------\n");
    printf("\n");
    imprimeLista(lista);
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
      insertar(&lista, posicion, captura);
      break;

    case 2: /* Eliminar */
      printf("posicion a insertar (0: inicio, -1: final): ");
      posicion = capturar_entero();
      eliminar(&lista, posicion);
      break;

    case 3:
      instrucciones();
      break;
    }
  }

  /* liberarMemoria(&lista); */

  return 0;
}

// Funciones ---------------------------------------------------


int size(ptrNodoLista ptrS) {
  ptrNodoLista current = ptrS;
  int cont = 0;
  
  if(current == NULL)
    return 0;

  do {
    current = current->ptrSiguiente;
    cont++;
  } while( current != ptrS );

  return cont;
}

/**
 * Verificar si esta vacia la lista
 *
 * @param  ptrS lista de punteros
 * @return Regrasa 1 si la lista esta vacia de lo contrario 0.
 */
int estaVacia(ptrNodoLista ptrS) { return ptrS == NULL; }

/**
 * Liberar la memoria del programa
 *
 * @param  ptrS
 */
void liberarMemoria(ptrNodoLista *ptrS) {
  ptrNodoLista ptrAnterior;
  ptrNodoLista ptrActual;

  /* determinar si esta vacia */
  if (estaVacia(*ptrS)) {
    printf("La lista esta Vacia, nada que liberar.\n");
    return;
  }

  ptrActual = *ptrS;
  ptrAnterior = NULL;

  for (int i = 0; ptrActual != NULL; i++) {
    ptrAnterior = ptrActual;
    ptrActual = ptrActual->ptrSiguiente;
    free(ptrAnterior);
  }

  printf("MEMORIA LIBERADA CON EXITO!\n");
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

/**
 * Imprime los valore de la lista
 *
 * @param ptrActual puntero a la lista
 */
void imprimeLista(ptrNodoLista ptrActual) {
  ptrNodoLista current = ptrActual;
  
  if (estaVacia(ptrActual)) {
    printf("La lista esta vacia.\n");
    return;
  }

  do {
    printf("%d = ", current->dato);
    current = current->ptrSiguiente;
  } while(current != ptrActual);

  printf("NULL\n");
}

/**
 * Elimina un elemento de la lista
 * NOTE: posicion < 0, Inserta en el ultimo elemento de la lista
 * NOTE: 0, Inserta en el Primer elemento de la lista
 *
 * @param posicion del elemento a eliminar
 */
void eliminar(ptrNodoLista *ptrS, int posicion) {
  ptrNodoLista temp = *ptrS;
  ptrNodoLista current = *ptrS;

  /* determinar si esta vacia */
  if (estaVacia(*ptrS)) {
    printf("La lista esta Vacia\n");
    return;
  }

  /* eliminar elemento al final */
  if (posicion <= -1) {
    while (current->ptrSiguiente != (*ptrS)) {
      temp = current;
      current = current->ptrSiguiente;
    }

    /* asigna el como nodo siguiente NULL por que se elimina
       el ultimo */
    temp->ptrSiguiente = current->ptrSiguiente;
    free(current);
    return;
  }


  if (posicion == 0) {
    while(current->ptrSiguiente != (*ptrS))
      current = current->ptrSiguiente;

    current->ptrSiguiente = (*ptrS)->ptrSiguiente;
    *ptrS = (*ptrS)->ptrSiguiente;
    free(temp);
    return;
  }
  

  /* /\* eliminar elemento por posicion *\/ */
  /* for (int i = posicion; i > 0; --i) { */
  /*   /\* iterar los punteros *\/ */
  /*   ptrAnterior = ptrActual; */
  /*   ptrActual = ptrActual->ptrSiguiente; */
  /*   /\* si el siguiente putero no existe  *\/ */
  /*   if (ptrActual == NULL) { */
  /*     printf("Fuera de rango\n"); */
  /*     return; */
  /*   } */
  /* } */

  /* ptrAnterior->ptrSiguiente = ptrActual->ptrSiguiente; */
  /* printf("Valor %d eliminado\n", ptrActual->dato); */
  /* free(ptrActual); */
}

/**
 * Inserta un elemento en la lista,
 * NOTE: posicion < 0, Inserta en el ultimo elemento de la lista
 * NOTE: 0, Inserta en el Primer elemento de la lista
 *
 * @param *ptrS puntero a la lista
 * @param posicion en la lista
 * @param valor a insertar
 */
void insertar(ptrNodoLista *ptrS, int posicion, int valor) {
  ptrNodoLista ptrActual = *ptrS;
  ptrNodoLista ptrNuevo = malloc(sizeof(NodoLista));

  /* Verificar que hay memoria para contirnuar */
  if (ptrNuevo == NULL) {
    printf("%d no se inserto. Memoria no disponible.\n", valor);
    exit(EXIT_FAILURE);
  }

  ptrNuevo->dato = valor;
  ptrNuevo->ptrSiguiente = ptrNuevo;

  if(estaVacia(*ptrS)){
    *ptrS = ptrNuevo;
    return;
  }
  
  /* insertar al inicio o si la lista esta vacia insertamos
     termino en el primer nodo y termina */
  if (posicion == 0) {
    while( ptrActual->ptrSiguiente != *ptrS ) {
      ptrActual = ptrActual->ptrSiguiente;
    }
    
    ptrNuevo->ptrSiguiente = *ptrS;
    ptrActual->ptrSiguiente = ptrNuevo;
    *ptrS = ptrNuevo;
    return;
  }

  /* Si la posicion es -1 entonces insertamos al final */
  if (posicion < 0) {
    while(ptrActual->ptrSiguiente != *ptrS)
      ptrActual = ptrActual->ptrSiguiente;

    ptrNuevo->ptrSiguiente = ptrNuevo;

    if(*ptrS == NULL){
      *ptrS = ptrNuevo;
      return;
    }

    ptrNuevo->ptrSiguiente = *ptrS;
    ptrActual->ptrSiguiente = ptrNuevo;
    return;
  }

  /* /\* Si el valor es mayor a 0 entonces sustituyes el valor en la */
  /*    posicion espesificada *\/ */
  /* for (int i = posicion; i > 0; --i) { */
  /*   /\* iterar los punteros *\/ */
  /*   ptrAnterior = ptrActual; */
  /*   ptrActual = ptrActual->ptrSiguiente; */
  /*   /\* si el siguiente putero no existe  *\/ */
  /*   if (ptrActual == NULL) */
  /*     break; */
  /* } */
  /* ptrAnterior->ptrSiguiente = ptrNuevo; */
  /* ptrNuevo->ptrSiguiente = ptrActual; */
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
 *
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
