
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int sumatoria(int*, int);
void bubble_sort_acendente(int*, int);
void bubble_sort_decendente(int*, int);
void mostrar_lista(int*, int);
int mediana(int*, int);

int main() {
  int A[1000];
  int A_size;
  int sum;

  srand(time(NULL));
  printf("Elementos? (2-100)\n");
  scanf("%d", &A_size);
  printf("----------------------\n");

  /* poblar arreglo */
  for (int i = 0; i < A_size; i++) {
    A[i] = rand() % 100 + 1;
    printf("%d\n", A[i]);
  }

  sum = sumatoria(A, A_size);
  printf("sumatoria: %d\n", sum);
  
  printf("Acendente ------------\n");
  bubble_sort_acendente(A, A_size);
  
  mostrar_lista(A, A_size);
  printf("Decendente -----------\n");
  
  bubble_sort_decendente(A, A_size);
  mostrar_lista(A, A_size);

  sum = mediana(A, A_size);
  printf("mediana: %d\n", sum);
  
}


void bubble_sort_acendente(int A[100], int A_size) {
  int actual = 0;
  int siguiente = 0;
  int desordenado = 0;

  /* bubble sort */

  while (!desordenado) {
    desordenado = 1;

    for (int i = 0; i < A_size; i++) {
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
}

void bubble_sort_decendente(int A[100], int A_size) {
  int actual = 0;
  int siguiente = 0;
  int desordenado = 0;

  /* bubble sort */

  while (!desordenado) {
    desordenado = 1;
    for (int i = 0; i < A_size - 1; i++) {
      actual = A[i];
      siguiente = A[i + 1];

      if (actual < siguiente) {
        A[i + 1] = actual;
        A[i] = siguiente;
        desordenado = 0;
        i = 0;
      }
    }
  }
}

int sumatoria(int A[100], int A_size) {
  int a = 0;
  
  for (int i = 0; i < A_size - 1; i++) {
    a += A[i];
  }

  return a;
}

void mostrar_lista(int A[100], int A_size) {
  for (int i = 0; i < A_size ; i++) {
    printf("%d\n", A[i]);
  }  
}


int mediana(int A[100], int A_size) {
  return A[A_size/2];
}
