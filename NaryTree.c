struct Ntree {
  char info;
  struct Ntree *child;
  struct Ntree *brother;
}
typedef struct ntree Ntree;

Ntree* ntree_create(char c) {
  Ntree* tree = (Ntree*)malloc(sifeof(Ntree));
  tree->info = c;
  tree->child = NULL;
  tree->brother = NULL;
  return tree;
}

void ntree_insert(Ntree* tree, Ntree* insertion) {
  insertion->brother = tree->child;
  tree->child = insertion;
}

void ntree_print(Ntree* tree) {
  Ntree* p;
  printf("<%c\n", tree->info);
  for (p=tree->child; p!=NULL; p=p->brother) {
    ntree_print(p);
    printf(">");
  }
}

int ntree_belongs(Ntree* tree, char c) {
  Ntree* p;
  if (tree->info == c) {
    return 1;
  } else {
    for (p = tree->child; p!=NULL; p = p->brother) {
      if (ntree_belongs(p, c)) return 1;
    }
  }
  return 0;
}

void ntree_free(Ntree* tree) {
  Ntree* p = tree->child;
  while(p != NULL) {
    Ntree* t = p->brother;
    ntree_free(p);
    p = t;
  }
  free(tree);
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

int ntree_height(Ntree* tree) {
  if (tree == NULL) return -1;
  return max(1 + ntree_height(tree->child), ntree_height(tree->brother));
}