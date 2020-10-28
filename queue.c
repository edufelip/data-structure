#include <stdio.h>
#include <stdlib.h>

struct list {
  float info;
  struct list* next;
};
typedef struct list List;

struct queue {
  List* init;
  List* end;
};
typedef struct queue Queue;

Queue* fila_create(void) {
  Queue* i = (Queue*) malloc (sizeof(Queue));
  i->init = NULL;
  i->end = NULL;
  return i;
}

Queue* queue_insert(Queue* queue, float value) {
  List* i = (List*) malloc (sizeof(List));
  i->info = value;
  i->next = NULL;
  if(queue->end != NULL){
    queue->end->next = i;
  } else {
    queue->init = i;
  }
  queue->end = i;
}

float queue_remove(Queue* queue) {
  List* i = queue->init;
  float value = i->info;
  queue->init = i->next;
  if(queue->init == NULL) {
    queue->end == NULL;
  }
  free(i);
  return value;
}

int queue_isEmpty(Queue* queue) {
  return (queue->init == NULL);
}

void queue_free(Queue* queue) {
  List* i = queue->init;
  while(i != NULL) {
    List* sup = i->next;
    free(i);
    i = sup;
  }
  free(queue);
}

int queue_multiply(Queue * queue) {
  if (queue->init == queue->end) return queue->init->info;
  List* i = queue->init;
  List* sup = i->next;
  queue->init = sup;
  float multiply = i->info * fila_multiplica(queue);
  free(i);
  return multiply;
}