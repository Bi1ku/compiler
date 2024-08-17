#include "../include/lexer.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  token value;
  struct node *left;
  struct node *right;
} node;

node *create_node(token value) {
  node *result = malloc(sizeof(node));

  if (result != NULL) {
    result->value = value;
    result->left = NULL;
    result->right = NULL;
  }

  return result;
}

char parser(token tokens[], int tokens_length) {
  node **trees = malloc(0);
  int trees_length = 0;

  token(*lines)[] = malloc(0);
  int lines_length = 0;

  for (int i = 0; i < tokens_length; i++) {
    if (tokens[i].type == newline) {
      trees = realloc(trees, sizeof(node) * (i + 1));
      trees[trees_length] = create_node(tokens[i]);
      trees_length++;
      lines_length = 0;
    }
  }

  for (int i = 0; i < trees_length; i++) {
    free(trees[i]);
  }
  free(trees);
  free(lines);

  return EXIT_SUCCESS;
}
