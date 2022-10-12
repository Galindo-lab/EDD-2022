
struct IntegerListNode {
  int data;
  struct IntegerListNode *nextNode;
} IntegerListNode;

typedef IntegerListNode *ptrIntegerList;

short IntegerListIsEmpty(ptrIntegerList list) {
  return list == NULL;
}

void IntegerListAdd(ptrIntegerList *list,
                    short position,
                    int value) {
  
}

void IntegerListRemove(ptrIntegerList *list,
                       short position) {
}

void IntegerListFree(ptrIntegerList *list) {
  
}

