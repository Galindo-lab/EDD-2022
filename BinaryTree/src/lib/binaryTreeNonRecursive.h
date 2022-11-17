
#include "queueA.h"
#include "stackA.h"

void PreOrderNonRecursive(BinaryTree *root) {
  Stack s;
  stackInit(&s);

  while (1) {
    while (root) {
      printf("%d ", root->data);
      stackPush(&s, root);
      root = root->left;
    }

    if (stackEmpty(&s))
      break;

    root = stackPop(&s);
    root = root->right;
  }
  stackFree(&s);
}

void InOrderNonRecursive(BinaryTree *root) {
  Stack s;
  stackInit(&s);

  while (1) {
    while (root) {
      stackPush(&s, root);
      root = root->left;
    }

    if (stackEmpty(&s))
      break;

    root = stackPop(&s);
    printf("%d ", root->data);
    root = root->right;
  }

  stackFree(&s);
}

void PostOrderNonRecursive(BinaryTree *root) {
  Stack s;
  stackInit(&s);
  BinaryTree *previous = NULL;

  do {
    while (root != NULL) {
      stackPush(&s, root);
      root = root->left;
    }

    while (root == NULL && !stackEmpty(&s)) {
      root = stackTop(&s);
      if (root->right == NULL || root->right == previous) {
        printf("%d ", root->data);
        stackPop(&s);
        previous = root;
        root = NULL;
      } else {
        root = root->right;
      }
    }
  } while (!stackEmpty(&s));
}

void LevelOrder(BinaryTree *root) {
  BinaryTreeNode *temp;
  Queue q;
  queueInit(&q);

  if (!root)
    return;

  enqueue(&q, root);
  while (!queueEmpty(&q)) {
    temp = dequeue(&q);
    printf("%d ", temp->data);

    if (temp->left)
      enqueue(&q, temp->left);

    if (temp->right)
      enqueue(&q, temp->right);
  }

  queueFree(&q);
}
