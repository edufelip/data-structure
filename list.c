#include <stdio.h>
#include <stdlib.h>

typedef struct list List;
struct list {
  int info;
  List* next;
};

List* list_create(void);
List* list_insert(List* list, int value);
List* list_insert_ordenated(List* list, int value);
void list_print(List* list);
void list_print_recursion(List* list);
void list_print_recursion_invert(List* list);
int list_isEmpty(List* list);
List* list_search(List* list, int value);
List* list_remove(List* list, int value);
List* list_remove_recursion(List* list, int value);
int is_equal(List* listOne, List* listTwo);
int is_equal_recursion(List* listOne, List* listTwo);
void list_free(List* list);
int list_size(List* list);
int list_isGreater(List* list, int value);
List* list_lastElement(List* list);
List* list_concatenate(List* listOne, List* listTwo);
List* list_removeNumber(List* list, int value);
List* split(List* list, int value);

List* list_create(void) {
  return NULL;
}

List* list_insert(List* list, int value) {
  List* new = (List*) malloc(sizeof(List));
  new->info = value;
  new->next = list;
  return new;
}

List* list_insert_ordenated(List* list, int value) {
  List* new;
  List* i = list;
  List* previous = NULL;

  while(i != NULL && i->info < value) {
    previous = i;
    i = i->next;
  }
  new = (List*) malloc(sizeof(List));
  new->info = value;
  if(previous == NULL) {
    new->next = list;
    list = new;
  } else {
    new->next = previous->next;
    previous->next = new;
  }
  return list;
}

void list_print(List* list) {
  List* i;
  for(i = list; i != NULL; i = i->next) {
    printf("%d\n", i->info);
  }
}

void list_print_recursion(List* list) {
  if(!list_isEmpty(list)) {
    printf("%d\n", list->info);
    list_print_recursion(list->next); 
  }
}

void list_print_recursion_invert(List* list) {
  if(!list_isEmpty(list)) {
    list_print_recursion_invert(list->next);
    printf("%d\n", list->info);
  }
}

int list_isEmpty(List* list) {
  return (list == NULL);
}

List* list_search(List* list, int value) {
  List* i;
  for(i = list; i != NULL; i = i->next) {
    if (i->info == value) {
      return i;
    }
  }
  return NULL;
}

List* list_remove(List* list, int value) {
  List* previous = NULL;
  List* i = list;
  while(i != NULL && i->info != value) {
    previous = i;
    i = i->next;
  }

  // printf("%d\n", i->info);

  if(i == NULL) return list;
  if(!previous) {
    // printf("%d", i->next->info);
    list = i->next;
  } else {
    previous->next = i->next;
  }
  free(i);
  return list;
}

List* list_remove_recursion(List* list, int value) {
  List* i;
  if(!list_isEmpty(list)) {
    if(list->info == value) {
      i = list;
      list = list->next;
      free(i);
    } else {
      list_remove_recursion(list->next, value);
    }
  }
  return list;
}

int list_isEqual(List* listOne, List* listTwo) {
  List* i;
  List* j;
  for(i = listOne, j = listTwo; i != NULL && j != NULL; i = listOne->next, j = listTwo->next) {
    if(i->info != j->info) return 0;
  }
  return 1;
}

int list_isEqual_recursion(List* listOne, List* listTwo) {
  if(listOne == NULL && listTwo == NULL) return 1;
  if(listOne == NULL || listTwo == NULL) return 0;
  return (listOne->info == listTwo->info) && list_isEqual_recursion(listOne->next, listTwo->next);
}

void list_free(List* list) {
  List* i = list;
  while(i != NULL) {
    List* j = i->next;
    free(i);
    i = j;
  }
}

int list_size(List* list) {
  int count = 0;
  List* i;
  for(i = list; i != NULL; i = i->next) {
    count++;
  }
  return count;
}

int list_isGreater(List* list, int value) {
  int count = 0;
  List* i;
  for(i = list; i != NULL; i = i->next) {
    if(i->info > value) count++;
  }
  return count;
}

List* list_lastElement(List* list) {
  List* i = list;
  if(i->next == NULL) return list;
  while(i->next != NULL) {
    i = i->next;
  }
  return i;
}

List* list_concatenate(List* listOne, List* listTwo) {
  List* i = listOne;
  while(i->next != NULL) {
    i = i->next;
  }
  i->next = listTwo;
  return listOne;
}

List* list_removeNumber(List* list, int value) {
  List* i;
  List* j;
  for(i = list; i != NULL; i = i->next) {
    List* j = i;
    i = i->next;
    free(j);
  }
  return list;
}

List* list_removeNumber_recursion(List* list, int value) {
  List* i = list;
  if(i != NULL) {
    list_remove_recursion(i->next, value);
    if(i->info == value) {
      List* j = i;
      i = i->next;
      free(j);
    }
  }
  return list;
}

List* split(List* list, int value) {
  List* i = list;
  while(i->info != value && i != NULL) {
    i = i->next;
  }
  List* j = i->next;
  i->next = NULL;
  return j;
}