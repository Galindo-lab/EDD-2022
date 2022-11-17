
// AUTHOR: LUIS EDUARDO GALINDO AMAYA
//   DATE: 21-10-2022
//  DESC.: PRACTICA DE ARBOLES BINARIOS 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./lib/binaryTreeStruct.h"
#include "./lib/binaryTreeNonRecursive.h"
#include "./lib/binaryTreeRecursive.h"

void insertNode(TreeNodePtr *treePtr, int value);
TreeNodePtr captureNodes(int ntest);
void autogenerateTree(int ntest);

int main() {
  TreeNodePtr rootPtr;
  int op, ntest;

  while (1) {
    printf("\n"
           "----------------------------\n"
           "       Menu principal \n"
           "----------------------------\n"
           "Misc.\n"
           " 1. Autogenerar y probar \n"
           " 2. Level order \n"
           "\n"
           "No recursivos\n"
           " 3. Preorder no recursivo \n"
           " 4. Postorder no recursivo \n"
           " 5. Inorder no recursivo \n"
           "\n"
           "Recursivos\n"
           " 6. Preorder recursivo \n"
           " 7. Postorder recursivo \n"
           " 8. Inorder recursivo \n"
           "----------------------------\n"
           " 0. Salir\n"
           "\n"
           "op> ");
    
    scanf("%d", &op);
    
    if(op == 0) {               /* salir */
      exit(EXIT_SUCCESS);
    }
    
    printf("\nnumero de nodos: ");
    scanf("%d", &ntest);
    
    if(op == 1) {               /* pruebas */
      autogenerateTree(ntest);
      continue;
    }

    rootPtr = captureNodes(ntest);
    
    switch (op) {

    case 2:                     /* LevelOrder */
      printf("Level Order:\n");
      LevelOrder(rootPtr);      
      break;

    case 3:                     /* PreOrderNonRecursive */
      printf("PreOrder no recursivo: \n");
      PreOrderNonRecursive(rootPtr);
      break;

    case 4:                     /* PostOrderNonRecursive */
      printf("PostOrder no recursivo\n");
      PostOrderNonRecursive(rootPtr);
      break;

    case 5:                     /* InOrderNonRecursive */
      printf("InOrder no recursivo\n");
      InOrderNonRecursive(rootPtr);
      break;

    case 6:                     /* PreOrder */
      printf("PreOrder recursivo\n");
      PreOrder(rootPtr);
      break;

    case 7:                     /* PostOrder */
      printf("PostOrder recursivo\n");
      PostOrder(rootPtr);
      break;

    case 8:                     /* InOrder */
      printf("InOrder recursivo\n");
      InOrder(rootPtr);
      break;
    }

    printf("\n");
  }
    

  return 0;
}

TreeNodePtr captureNodes(int ntest){
  TreeNodePtr treePtr = NULL;
  int op;
  
  for (int i = 1; i < ntest+1; i++) {
    printf("nodo %d: ",i);
    scanf("%d",&op);
    insertNode(&treePtr, op);
  }

  puts("");
  return treePtr;
}

void autogenerateTree(int ntest) {
  TreeNodePtr rootPtr = NULL;
  srand(time(NULL));
  puts("\n"
       "The numbers being placed in the tree are:");

  for (int i = 0; i < ntest; i++) {
    int item = rand() % 15;
    printf(" %d", item);
    insertNode(&rootPtr, item);
  }

  printf("\n\nLevelOrder\n ");
  LevelOrder(rootPtr);

  printf("\n\n"
         "preOrder\n"
         " Recursivo:    ");
  PreOrder(rootPtr);
  printf("\n"
         " No Recursivo: ");
  PreOrderNonRecursive(rootPtr);

  printf("\n\n"
         "inOrder \n"
         " Recursivo:    ");
  InOrder(rootPtr);
  printf("\n"
         " No Recursivo: ");
  InOrderNonRecursive(rootPtr);

  printf("\n\n"
         "postOrder\n"
         " Recursivo:    ");
  PostOrder(rootPtr);
  printf("\n"
         " No Recursivo: ");
  PostOrderNonRecursive(rootPtr);

  printf("\n");
}

void insertNode(TreeNodePtr *treePtr, int value) {
  if (*treePtr) { /* si el nodo tiene contenido (no es NULL) */

    if (value < (*treePtr)->data) {
      /* si el valor es menor al valor del nodo actual inserta
         a la izquierda */
      insertNode(&((*treePtr)->left), value);
      return;
    }

    if (value > (*treePtr)->data) {
      /* si el valor es mayor al valor del nodo actua inserta
         a la izquierda */
      insertNode(&((*treePtr)->right), value);
      return;
    }

    /* no inserta el valor si es igual */
    printf(":dup");
    return;
  }

  if ((*treePtr = malloc(sizeof(BinaryTreeNode)))) {
    /* si el nodo esta vacio (es NULL) crea el nuevo nodo */
    (*treePtr)->data = value;
    (*treePtr)->left = NULL;
    (*treePtr)->right = NULL;
    return;
  }

  /* si no se pudo reveservar memoria se muestra el siguiente
     mensaje */
  printf("%d not inserted. No memory available.\n", value);
  exit(EXIT_FAILURE);
}


