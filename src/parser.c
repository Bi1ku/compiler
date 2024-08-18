#include "../include/types.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node *create_node(token value) {
  struct node *result = malloc(sizeof(struct node));

  if (result != NULL) {
    result->value = value;
    result->left = NULL;
    result->right = NULL;
  }

  return result;
}

void set_branch(struct node *node, token token) {
  if (node->right)
    node->left = create_node(token);
  else
    node->right = create_node(token);
}

void create_ast(struct node *node, token line[], int line_length) {
  for (int i = 0; i < line_length; i++) {
    if (line[i].type == keyword) {
      node->value = line[i];
    }

    set_branch(node, line[i]);
  }
}

char parser(token tokens[], int tokens_length) {
  struct node **trees = malloc(0);
  int trees_length = 0;

  token line[100] = {};
  int line_length = 0;

  for (int i = 0; i < tokens_length; i++) {
    if (tokens[i].type == newline & tokens[i + 1].type != newline) {
      trees = realloc(trees, sizeof(struct node) * (i + 1));
      trees[trees_length] = create_node(tokens[i]);
      create_ast(trees[trees_length], line, line_length);
      line_length = 0;
      trees_length++;
    }

    else {
      line[line_length] = tokens[i];
      line_length++;
    }
  }

  for (int i = 0; i < trees_length; i++) {
    free(trees[i]);
  }
  free(trees);

  return EXIT_SUCCESS;
}
