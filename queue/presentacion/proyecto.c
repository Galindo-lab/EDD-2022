
#include <stdio.h>
#include <stdlib.h>

/* #include "lib/arrayCircularQueue.h" */
/* #include "lib/arrayQueue.h" */
/* #include "lib/circularList.h" */
#include "lib/queueA.h"

int main() {
  int op;
  int loop = 1;
  int MAX_QUEUE = 30;
  
  Queue gente;
  queueInit(&gente);

  do {
    system("clear");

    printf("\n");
    printf("Parque de diversiones:                     %d / 30\n",gente.size);
    printf("                                                  \n"
           "               _____            ooo               \n"
           "              /\\ | /\\          .###.            \n"
           "   Tickets   |-- o --|        /-/-\\-\\           .__\n"
           "  /_______\\   \\_/_\\_/        /-/---\\-\\         /---\n"
           "  | .---. |    /   \\    ____/-/-----\\-\\_______/----\n"
           "  | | o | | \n"
           "--#########---|---|---|---|---|---|---|---|---|---|");

    displayQueue(&gente);

    printf("\n\n"
           "[Agregar personas a la fila]-----------------------\n"
           " 1:Normal  2:Premium  3:Gold           \n"
           "                                       \n"
           "[Acciones]                 [Opciones]  \n"
           " 4: Entrar 1 al parque      0: Salir   \n"
           " 5: Entrar 5 al parque                 \n"
           "                                       \n"
           "> ");
    
    scanf("%d", &op);

    switch (op) {
    case 1:
      /* agregar normal */
      if(gente.size < MAX_QUEUE)
        orderedEnqueue(&gente, 0);  
      break;
    case 2:
      /* agregar premium */
      if(gente.size < MAX_QUEUE)
        orderedEnqueue(&gente, 1);
      break;
    case 3:
      /* agregar gold */
      if(gente.size < MAX_QUEUE)
        orderedEnqueue(&gente, 2);
      break;
    case 4:
      /* entrar */
      dequeue(&gente);
      break;
    case 5:
      if(gente.size >= 5) {
        dequeue(&gente);
        dequeue(&gente);
        dequeue(&gente);
        dequeue(&gente);
        dequeue(&gente); 
      }
      break;
    case 0:
      loop = 0;
      break;
    }
  } while (loop);

  return 0;
}
