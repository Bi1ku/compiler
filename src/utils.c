#include "../include/types.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char in_string_array(char *arr[], char str[], int length) {
  for (int i = 0; i < length; i++) {
    if (strcmp(arr[i], str) == 0) {
      return 1;
    }
  }

  return 0;
}

void print_tokens(token *tokens, int length) {
  printf("[\n");
  for (int i = 0; i < length; i++) {
    char *type;

    switch (tokens[i].type) {
    case keyword:
      type = "keyword";
      break;
    case expression:
      type = "expression";
      break;
    case string:
      type = "string";
      break;
    case newline:
      type = "newline";
      break;
    case boolean:
      type = "boolean";
      break;
    case container:
      type = "container";
      break;
    }

    printf("{ type: %s, value: %s },\n", type, tokens[i].value);
  }
  printf("]\n");
}

void print_tree(struct node *node) {
  if (node != NULL) {
    printf("NODE VALUE: %s \n", node->value.value);

    if (node->right != NULL)
      printf("RIGHT NODE VALUE: %s \n", node->right->value.value);
    else
      printf("RIGHT NODE VALUE: XX[NULL]XX \n");

    if (node->left != NULL)
      printf("LEFT NODE VALUE: %s \n", node->left->value.value);
    else
      printf("LEFT NDOE VALUE: XX[NULL]XX \n");

    printf("-----------NEW NODE-------------\n");
    print_tree(node->left);
    print_tree(node->right);
  }
}

void print_trees(struct node **trees, int trees_length) {
  for (int i = 0; i < trees_length; i++) {
    printf("-----------NEW NODE-------------\n");
    print_tree(trees[i]);
    printf("\n---------------NEW TREE--------------\n\n");
  }
}

token *slice_tokens(token tokens[], int start, int end) {
  token *res = malloc(sizeof(token) * start - end);

  for (int i = start; i < end; i++) {
    res[i - start] = tokens[i];
  }

  return res;
}
