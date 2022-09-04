

/* #include <stdio.h> */

/* int main(int argc, char *argv[]) { */
/*   int iVar = 20; */
/*   int *iPtr = NULL; */

/*   iPtr = &iVar; */
/*   printf("iPtr = %d\n", *iPtr); */

/*   *iPtr = 5; */
/*   printf("iPtr = %d\n", *iPtr); */

/*   return 0; */
/* } */


/* #include <stdio.h> */
/* #include <stdlib.h> */
/* #include <string.h> */

/* char* itoa(int); */

/* int main(int argc, char *argv[]) { */
/*   char *cadena = NULL; */

/*   cadena = itoa(255); */
/*   printf("String: %s\n", cadena); */

/*   return 0 ; */
/* } */

/* char* itoa(int n) { */
/*   char *buffer = malloc(5); */
/*   if(buffer == NULL) { */
/*     return NULL; */
/*   } */
/*   sprintf(buffer, "%d", n); */
/*   return buffer; */
/* } */


/* gcc -W -Wall -pedantic -std=c99 hola.c */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char *sCadena = NULL;
  int i;

  sCadena = malloc(80);
  if(!sCadena){
    printf("La asignacion fallo\n");
    exit(1);
  }

  
  fgets(sCadena, 80,stdin);
  for(i=strlen(sCadena)-1;i >= 0 ; i--){
    putchar(sCadena[i]);
  }
  free(sCadena);
  sCadena = NULL;
  
  return 0;
}
