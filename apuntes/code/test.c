
#include <stdio.h>

int main() {
  int x = 7;
  int *ptry = &x;

  printf("%d\n", x);
  printf("%d\n", ptry);
  printf("%p\n", &x); 
  printf("%p\n", ptry);
  printf("%d\n", *ptry);
    
  return 0;
}
