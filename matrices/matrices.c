

#include <stdio.h>
#include <stdlib.h>

/* #define MAX_MATRIX_SIZE 8 */

void inicializar_matriz(int[][8]);
int selecionar_operacion();
void matriz_valida(size_t, size_t);
void mostrar_matriz(int[][8], size_t, size_t);
void captura_matriz(int[][8], size_t, size_t);
void sumar_matriz(int[][8], int[][8], int[][8]);
void multiplicar_matriz(int[][8], int[][8], int[][8], int, int, int, int);
void transpuesta_matriz(int[][8], int[][8]);

int main() {
  /* matrices de entrada */
  int A[8][8];
  int B[8][8];
  /* matriz resultado */
  int R[8][8];

  inicializar_matriz(A);
  inicializar_matriz(B);
  inicializar_matriz(R);

  /* dimensiones de A */
  int A_filas = 2;
  int A_columnas = 3;

  /* dimensiones de B */
  int B_filas = 2;
  int B_columnas = 3;

  switch (selecionar_operacion()) {
  case 0:
    printf("Adios :(");
    break;

  case 1:
    /* La suma de matrices solo de puede hacer  */
    /* entre matrices cuadradas */

    printf("Suma de matrices\n\n");
    printf("dimensiones (CxR): ");
    scanf("%dx%d", &A_filas, &A_columnas);

    /* verificar que las matrices sean validas */
    matriz_valida(A_filas, A_columnas);

    printf("Matriz A:\n");
    captura_matriz(A, A_filas, A_columnas);
    printf("Matriz B:\n");
    captura_matriz(B, A_filas, A_columnas);

    sumar_matriz(A, B, R);

    printf("\nMatriz A:\n");
    mostrar_matriz(A, A_filas, A_columnas);
    printf("\nMatriz B:\n");
    mostrar_matriz(B, A_filas, A_columnas);
    printf("\nMatriz R:\n");
    mostrar_matriz(R, A_filas, A_columnas);
    break;

  case 2:
    printf("Multiplicacion de matrices");
    printf("dimensiones A (CxR): ");
    scanf("%dx%d", &A_filas, &A_columnas);

    printf("dimensiones B (CxR): ");
    scanf("%dx%d", &B_filas, &B_columnas);

    printf("Matriz A:\n");
    captura_matriz(A, A_filas, A_columnas);
    printf("Matriz B:\n");
    captura_matriz(B, B_filas, B_columnas);

    multiplicar_matriz(A, B, R, A_filas, A_columnas, B_filas, B_columnas);

    printf("\nMatriz A:\n");
    mostrar_matriz(A, A_filas, A_columnas);
    printf("\nMatriz B:\n");
    mostrar_matriz(B, B_filas, B_columnas);
    printf("\nMatriz R:\n");
    mostrar_matriz(R, A_filas, B_columnas);
    break;

  case 3:
    printf("Transpuesta de matrices\n\n");
    printf("dimensiones (CxR): ");
    scanf("%dx%d", &A_filas, &A_columnas);

    printf("Matriz A:\n");
    captura_matriz(A, A_filas, A_columnas);

    transpuesta_matriz(A, R);
    printf("\nMatriz A:\n");
    mostrar_matriz(A, A_filas, A_columnas);
    printf("Matriz R:\n");
    mostrar_matriz(R, A_columnas, A_filas);
    break;
  }

  return 0;
}

void multiplicar_matriz(int A[][8], int B[][8], int R[][8], int A_filas,
                        int A_columnas, int B_filas, int B_columnas) {
  int n = 0;

  if (A_columnas != B_filas) {
    printf("numero incorrecto de filas y columnas");
    exit(EXIT_SUCCESS);
  }

  n = A_columnas;

  for (int r = 0; r < n; r++) {
    for (int i = 0; i < A_filas; i++) {
      for (int j = 0; j < B_columnas; j++) {
        R[i][j] += A[i][r] * B[r][j];
      }
    }
  }
}

void transpuesta_matriz(int A[][8], int R[][8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      R[j][i] = A[i][j];
    }
  }
}

void sumar_matriz(int A[][8], int B[][8], int R[][8]) {
  /* Matriz R es de resultado, se para como referencia para
     que la funcion no use tanta memoria */
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      R[i][j] = A[i][j] + B[i][j];
    }
  }
}

void mostrar_matriz(int A[][8], size_t filas, size_t columnas) {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      printf("%d ", A[i][j]);
    }
    printf("\n");
  }
}

void captura_matriz(int A[][8], size_t filas, size_t columnas) {
  for (int i = 0; i < filas; i++) {
    for (int j = 0; j < columnas; j++) {
      mostrar_matriz(A, filas, columnas);
      printf("[%d][%d]: ", i + 1, j + 1);
      scanf("%d", &A[i][j]);
      printf("\n");
    }
  }
}

void inicializar_matriz(int A[][8]) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      A[i][j] = 0;
    }
  }
}

void matriz_valida(size_t filas, size_t columnas) {
  /* no hay matrices de dimensiones negativas o
     menores a 2 */
  if (filas < 2 || columnas < 2) {
    printf("No es posible computar matrices con dimensión menor a 2\n");
    exit(EXIT_SUCCESS);
  }
}

int selecionar_operacion() {
  /* operaciones */
  int op;

  do {
    printf("Operaciones:\n");
    printf("- 1 :: Suma\n");
    printf("- 2 :: Multiplicacion\n");
    printf("- 3 :: Transpuesta\n");
    printf("- 0 :: Salir\n");
    printf("----------------------\n");
    printf("op: ");
    scanf("%d", &op);
    printf("\n");
  } while (op < 0 || op > 3);

  return op;
}
