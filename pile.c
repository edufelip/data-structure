#include <stdio.h>
#include <stdlib.h>

struct element {
  char info;
  struct element *next;
};
typedef struct element Element;

struct pile {
  Element* first;
};
typedef struct pile Pile;

Pile* pile_create(void) {
  Pile* i = (Pile*) malloc (sizeof(Pile));
  i->first = NULL;
  return i;
}

void pile_push(Pile* pile, char value) {
  Element* new = (Element*) malloc(sizeof(Element));
  new->info = value;
  new->next = pile->first;
  pile->first = new;
}

char pile_pop(Pile* pile) {
  Element* sup = pile->first;
  char value = sup->info;
  pile->first = sup->next;
  free(sup);
  return value;
}

void pile_free(Pile* pile) {
  Element* delete= pile->first;
  while (sup != NULL) {
    Element* sup = delete;
    free(delete);
    delete = sup->next;
  }
  free(pile);
}

int calculate_pos(char * e) {
  int i;
  Pile* pile;
  pile = pilha_create();
  int result;
  for (i = 0; e[i] != '\0'; i++) {
    pilha_push(pile, e[i]);
    if(e[i] == '*' || e[i] == '/' || e[i] == '+' || e[i] == '-' || e[i] == '^') {
      result = 0;
      char op = pilha_pop(pile);
      int value2 = pilha_pop(pile) - '0';
      int value1 = pilha_pop(pile) - '0';
      if (op == '*') {
        result += value1 * value2;
      } else if (op == '/') {
        result += value1/value2;
      } else if (op == '+') {
        result += value1 + value2;
      } else if (op == '-') {
        result += value1 - value2;
      } else {
        result += pow(value1, value2);
      }
      pilha_push(pile, result + '0');
    }
  }
  result = pilha_pop(pile) - '0';
  return result;
}