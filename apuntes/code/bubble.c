#include <stdio.h>

int main(int argc, char *argv[]) {

  /* int A[] = {2, 5, 8, 9, 3, 21, 7, 39, 45, 8, 16}; */
  /* int A_size = 11; */

  int A[] = {82,79,96,34,0};
  int A_size = 5;
  
  int actual = 0;
  int siguiente = 0;

  int desordenado = 0;
  /* bubble sort */

  while(!desordenado) {
    desordenado = 1;
    
    for (int i = 0; i < A_size - 1; i++) {
      actual = A[i];
      siguiente = A[i + 1];

      if (actual > siguiente) {
        A[i + 1] = actual;
        A[i] = siguiente;
        desordenado = 0;
        i = 0;
      }
    }
  }

  /* mostrar contenido */
  
  for (int i = 0; i < A_size; i++) {
    printf("%d\n", A[i]);
  }
}
