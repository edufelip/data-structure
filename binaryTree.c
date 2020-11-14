#include <stdio.h>
#include <stdlib.h>

struct tree {
  char info;
  struct tree *left;
  struct tree *right;
};
typedef struct tree Tree;

Tree* tree_create_empty(void) {
  return NULL;
}

Tree* tree_create(char c, Tree* l, Tree* r) {
  Tree* p = (Tree*)malloc(sizeof(Tree));
  p->info = c;
  p->left = l;
  p->right = r;
  return p;
}

Tree* tree_free(Tree* tree) {
  if(!tree_isEmpty(tree)) {
    tree_free(tree->left);
    tree_free(tree->right);
    free(tree);
  }
  return NULL;
}

int tree_isEmpty(Tree* tree) {
  return tree == NULL;
}

int tree_belongs(Tree* tree, char c) {
  if(tree_isEmpty(tree)) return 0;
  return tree->info == c || tree_belongs(tree->left, c) || tree_belongs(tree->right, c);
}

void tree_print(Tree* tree) {
  printf("<");
  if(!tree_isEmpty(tree)) {
    printf("%c ", tree->info);
    tree_print(tree->left);
    tree_print(tree->right);
  }
  printf(">");
}

void tree_print_simetric(Tree* tree) {
  if(tree != NULL) {
    tree_print_simetric(tree->left);
    printf("%c", tree->info);
    tree_print_simetric(tree->right);
  }
}

void tree_print_pos(Tree* tree) {
  if(tree != NULL) {
    tree_print_pos(tree->left);
    tree_print_pos(tree->right);
    printf("%c", tree->info);
  }
}