#include <stdio.h>
#include <stdlib.h>

struct bst {
  int value;
  struct bst *left;
  struct bst *right;
};
typedef struct bst Bst;

Bst* tree_create_empty(void) {
  return NULL;
}

// Bst* tree_create(char c, Bst* l, Bst* r) {
//   Bst* p = (Bst*)malloc(sizeof(Bst));
//   p->info = c;
//   p->left = l;
//   p->right = r;
//   return p;
// }

// Bst* tree_free(Bst* bst) {
//   if(!tree_isEmpty(bst)) {
//     tree_free(bst->left);
//     tree_free(bst->right);
//     free(bst);
//   }
//   return NULL;
// }

// int tree_isEmpty(Bst* bst) {
//   return bst == NULL;
// }

// int tree_belongs(Bst* bst, char c) {
//   if(tree_isEmpty(bst)) return 0;
//   return bst->info == c || tree_belongs(bst->left, c) || tree_belongs(bst->right, c);
// }

void bst_print(Bst* bst) {
  if(bst != NULL) {
    bst_print(bst->left);
    printf("%c ", bst->info);
    bst_print(bst->right);
  }
}

Bst* bst_search(Bst* bst, int value) {
  if(bst == NULL) return NULL;
  if(bst->info > value) return bst_search (bst->left, value);
  if(bst->info < value) return bst_search (bst->right, value);
  return bst;
}

// void tree_print_simetric(Bst* bst) {
//   if(bst != NULL) {
//     tree_print_simetric(bst->left);
//     printf("%c", bst->info);
//     tree_print_simetric(bst->right);
//   }
// }

// void tree_print_pos(Bst* bst) {
//   if(bst != NULL) {
//     tree_print_pos(bst->left);
//     tree_print_pos(bst->right);
//     printf("%c", bst->info);
//   }
// }