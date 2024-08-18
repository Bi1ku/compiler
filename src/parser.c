#include "../include/lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  token value;
  struct node *left;
  struct node *right;
};

struct node *create_node(token value) {
  struct node *result = malloc(sizeof(struct node));

  if (result != NULL) {
    result->value = value;
    result->left = NULL;
    result->right = NULL;
  }

  return result;
}

double calculate(char arithmetics, int arithmetics_length) { return 0; }

void create_ast(struct node *node, token line[], int line_length) {
  struct node *curr_node = node;
  char arithmetics[100][100] = {};
  int arithmetics_length = 0;

  for (int i = 0; i < line_length; i++) {
    if (line[i].type == operation || line[i].type == number) {
      strcpy(arithmetics[arithmetics_length], line[i].value);
      arithmetics_length++;
    }
  }

  for (int i = 0; i < arithmetics_length; i++) {
    printf("Val: %s \n", arithmetics[i]);
  }

  printf("NEWLINE \n");
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
