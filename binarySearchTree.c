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

int bst_count(Bst* bst) {
  int count = 1;
  if(bst->left != NULL) {
    count += bst_count(bst->left);
  }
  if(bst->right != NULL) {
    count += bst_count(bst->right);
  }
  return count;
}

void bst_balance(Bst* bst) {
  int left = bst_count(bst->left);
  int right = bst_count(bst->right);
  while(left > right + 2 || right > left + 2) {
    if(left > right + 2) {
      Bst* sup = bst;
      while(sup->left != NULL) {
        sup = sup->left;
      }
      int value = sup->value;
      free(sup);
      Bst* a = (Bst*)malloc(sizeof(Bst));
      a->info = bst->info;
      a->right = bst->right;
      a->left = NULL;
      bst->right = a;
      bst->value = value;
    }
    if(right > left + 2) {
      Bst* sup = bst;
      while(sup->right != NULL) {
        sup = sup->right;
      }
      int value = sup->value;
      free(sup);
      Bst* a = (Bst*)malloc(sizeof(Bst));
      a->info = bst->info;
      a->left = bst->left;
      a->right = NULL;
      bst->left = a;
      bst->value = value;
    }
    left = bst_count(bst->left);
    right = bst_count(bst->right);
  }
}

void bst_balance_rotate(bst* bst) {
  int left = bst_count(bst->left);
  int right = bst_count(bst->right);
  if(left > right + 2 || right > left + 2) {
    if (left > right + 2) {
      Bst * sup = bst;
      bst = bst->left;
      sup->left = bst->right;
      bst->right = sup;
    } else if (right > left + 2) {
      Bst* sup = bst;
      bst = bst->right;
      sup->right = bst->left;
      bst->left = sup;
    }
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
    Bst* a = (Bst*)malloc(sizeof(Bst));
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