

#include <stdio.h>

float fac(float valor){
  if(valor == 0) return 1;
  return valor * fac(valor-1);
}

float fibonacci(float valor) {
  if(valor == 0) return 0;
  if(valor == 1) return 1;
  return fibonacci(valor-1) + fibonacci(valor-2);
}

int main() {
  for(int i = 0; i < 20; i++){
    printf("fib(%d) -> %f\n", i,fibonacci(i));
  }
  
  return 0;
}


