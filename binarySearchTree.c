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

Bst* tree_create(int value, Bst* l, Bst* r) {
  Bst* p = (Bst*)malloc(sizeof(Bst));
  p->info = value;
  p->left = l;
  p->right = r;
  return p;
}

Bst* tree_free(Bst* bst) {
  if(!tree_isEmpty(bst)) {
    tree_free(bst->left);
    tree_free(bst->right);
    free(bst);
  }
  return NULL;
}

int tree_isEmpty(Bst* bst) {
  return bst == NULL;
}

int tree_belongs(Bst* bst, int value) {
  if(tree_isEmpty(bst)) return 0;
  return bst->info == value || tree_belongs(bst->left, value) || tree_belongs(bst->right, value);
}

void bst_print(Bst* bst) {
  if(bst != NULL) {
    bst_print(bst->left);
    printf("%f ", bst->info);
    bst_print(bst->right);
  }
}

Bst* bst_search(Bst* bst, int value) {
  if(bst == NULL) return NULL;
  if(bst->info > value) return bst_search (bst->left, value);
  if(bst->info < value) return bst_search (bst->right, value);
  return bst;
}

Bst* bst_insert(Bst* bst, int value) {
  if (bst == NULL) {
    a = (Bst*)malloc(sizeof(Bst));
    a->info = value;
    a->left = NULL;
    a->right = NULL;
  } else if (v < a->info) {
    a->left = bst_insert(a->left, value);
  } else if (v > a->info) {
    a->right = bst_insert(a->right, value);
  }
  return a;
}

Bst* bst_remove(Bst* bst, int value) {
  if (bst == NULL) {
    return NULL;
  } else if (bst->info > value) {
    bst->left = bst_remove(bst->left, value);
  } else if (bst->info < value) {
    bst->rigth = bst_remove(bst->right, value);
  } else {
    if (bst->left == NULL && bst->right == NULL) {
      free(bst);
      bst = NULL;
    } else if (bst->left == NULL) {
      Bst* sup = bst;
      bst = bst->right;
      free(sup);
    } else if (bst->right == NULL) {
      Bst* sup = bst;
      bst = bst->left;
      free(sup);
    } else {
      Bst* sup = bst->left;
      while(sup->right != NULL) {
        sup = sup->right;
      }
      bst->info = sup->info;
      sup->info = value;
      bst->left = bst_remove(bst->left, value);
    }
  }
  return bst;
}