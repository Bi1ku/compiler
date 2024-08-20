#include "../include/types.h"
#include "../include/utils.h"
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

// TODO: Recursion or something later for more advanced syntax and parsing
void create_ast(struct node *node, token line[], int line_length) {
  token *temp = malloc(0);

  for (int i = 0; i < line_length; i++) {
    if (line[i].type == container) {
      temp = slice_tokens(line, i, line_length);
      // create_ast(node->right, temp, line_length); pls fix this
      break;
    }

    if (line[i].type == keyword) {
      node->value = line[i];
    }

    if (i != 0)
      set_branch(node, line[i]);
  }

  free(temp);
}

void parser(token tokens[], int tokens_length, struct node **trees) {
  int trees_length = 0;

  token line[100] = {};
  int line_length = 0;

  for (int i = 0; i < tokens_length; i++) {
    if (tokens[i].type == newline && line_length > 0) {
      trees = realloc(trees, sizeof(struct node) * (i + 1));
      trees[trees_length] = create_node(tokens[i]);
      create_ast(trees[trees_length], line, line_length);
      print_tree(trees[trees_length]);
      line_length = 0;
      trees_length++;
    }

    else {
      if (tokens[i].type != newline) {
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
