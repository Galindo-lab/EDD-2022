

void PreOrder(BinaryTree *root) {
  if (!root)
    return;                     /* termina si la raiz es nula */

  printf("%d ", root->data);
  PreOrder(root->left);
  PreOrder(root->right);
}

void InOrder(BinaryTree *root) {
  if (!root)
    return;                     /* termina si la raiz es nula */

  InOrder(root->left);
  printf("%d ", root->data);
  InOrder(root->right);
}

void PostOrder(BinaryTree *root) {
  if (!root)
    return;                     /* termina si la raiz es nula */

  PostOrder(root->left);
  PostOrder(root->right);
  printf("%d ", root->data);
}

