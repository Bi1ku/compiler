#include "../include/types.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

precedence pemdas = {
    .add = 1,
    .subtract = 1,
    .multiply = 2,
    .divide = 2,
    .exponent = 3,
    .parenthesis = 4,
};

int idx = 0;
token line[100] = {};
int line_length = 0;

struct node *create_node(token value) {
  struct node *result = malloc(sizeof(struct node));

  if (result != NULL) {
    result->value = value;
    result->left = NULL;
    result->right = NULL;
  }

  return result;
}

// TODO: Implement binary tree parser
int get_precedence(char value[]) {
  if (strcmp(value, "+") || strcmp(value, "-"))
    return 1;

  else if (strcmp(value, "*") || strcmp(value, "/"))
    return 2;

  else
    return 3;
}

struct node *parse_primary();

struct node *parse_expression(int precedence_thresh) {
  struct node *left = parse_primary();

  while (1) {
    if (get_precedence(line[idx].value) < precedence_thresh)
      break;
  }
  return create_node(line[idx]);
};

struct node *parse_primary() {
  if (line[idx].type == Num) {
    idx++;
    return create_node(line[idx]);
  }

  else if (line[idx].type == Cont) {
    idx++;
    struct node *expr = parse_expression(0);
    idx++;
    return expr;
  }

  else
    return EXIT_FAILURE;
}

void parse_statement(struct node *node) {};

void parser(token tokens[], int tokens_length, struct node **trees) {
  int trees_length = 0;

  for (int i = 0; i < tokens_length; i++) {
    if (tokens[i].type == End && line_length > 0) {
      trees = realloc(trees, sizeof(struct node) * (i + 1));
      trees[trees_length] = create_node(tokens[i]);
      line_length = 0;
      trees_length++;
    }

    else {
      if (tokens[i].type != End) {
        line[line_length] = tokens[i];
        line_length++;
      }
    }
  }

  print_trees(trees, trees_length);

  for (int i = 0; i < trees_length; i++) {
    free(trees[i]);
  }
  free(trees);
}
