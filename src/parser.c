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

token body_token = {
    .type = Body,
    .value = "body",
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

int get_precedence(char value[]) {
  if (strcmp(value, "+") == 0 || strcmp(value, "-") == 0)
    return 1;

  else if (strcmp(value, "*") == 0 || strcmp(value, "/") == 0)
    return 2;

  else if (strcmp(value, "**") == 0)
    return 3;

  return -1;
}

struct node *parse_primary();

struct node *parse_expression(int precedence_thresh) {
  struct node *left = parse_primary();

  while (1) {
    if (line_length < idx)
      break;

    token peek = line[idx];

    int curr_precedence = get_precedence(peek.value);
    if (curr_precedence < precedence_thresh)
      break;

    idx++;

    struct node *right = parse_expression(curr_precedence + 1);
    struct node *temp = left;

    left = create_node(peek);
    left->left = temp;
    left->right = right;
  }

  return left;
};

struct node *parse_primary() {
  struct node *node;

  if (line[idx].type == Num) {
    node = create_node(line[idx]);
    idx++;
  }

  else if (strcmp(line[idx].value, "(") == 0) {
    idx++;
    node = parse_expression(0);
    idx++;
  }

  return node;
}

struct node *parse_line();

// TODO: IMPLEMENT PARSE_CONTAINER
struct node *parse_container(struct node *body) {
  idx++;

  body->left = parse_line();

  return body;
}

struct node *parse_line() {
  struct node *node;

  switch (line[idx].type) {
  case Keyword:
    node = create_node(line[idx]);
    break;

  case Num:
  case BinOpr:
    node = parse_expression(0);
    break;

  case Str:
    node = create_node(line[idx]);
    break;

  case Cont:
    // stuff
    break;

  default:
    node = NULL;
    break;
  }

  if (idx < line_length - 1) {
    idx++;

    node->right = parse_line();
  }

  return node;
};

void parser(token tokens[], int tokens_length, struct node **trees) {
  int trees_length = 0;

  // TODO: fix this to work with new lexer updates (newlines in containers)
  for (int i = 0; i < tokens_length; i++) {
    if (tokens[i].type == End && line_length > 0) {
      trees = realloc(trees, sizeof(struct node) * (i + 1));
      print_tokens(line, line_length);
      trees[trees_length] = parse_line();
      idx = 0;
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
