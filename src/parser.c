#include "../include/lexer.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  token value;
  struct node *left;
  struct node *right;
} node;

node *createnode(token value) {
  node *result = malloc(sizeof(node));

  if (result != NULL) {
    result->value = value;
    result->left = NULL;
    result->right = NULL;
  }

  return result;
}

char parser(token tokens[]) {
  printf("Parser\n");

  return EXIT_SUCCESS;
}
