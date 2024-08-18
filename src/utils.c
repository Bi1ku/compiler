#include "../include/types.h"
#include <stdbool.h>
#include <stdio.h>
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
