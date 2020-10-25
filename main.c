#include <stdio.h>
#include "list.c"

int main(void) {

  List* listOne;
  List* listTwo;

  listOne = create();
  listOne = insert(listOne, 1.0);
  listOne = insert(listOne, 4.5);
  listOne = insert(listOne, 2.1);

  listTwo = create();
  
  listTwo = insert(listTwo, 9.8);
  listTwo = insert(listTwo, 3.1);
  listTwo = insert(listTwo, 7.2);

}
