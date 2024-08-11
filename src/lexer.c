#include "../include/utils.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>

typedef enum {
  keyword,
  number,
  string,
  operator,
  newline,
} type;

typedef struct {
  type type;
  char value[100];
} token;

void print_tokens(token *tokens, int length) {
  printf("[\n");
  for (int i = 0; i < length; i++) {
    char *type;

    switch (tokens[i].type) {
    case keyword:
      type = "keyword";
      break;
    case number:
      type = "number";
      break;
    case string:
      type = "string";
      break;
    case operator:
      type = "operator";
      break;
    case newline:
      type = "newline";
      break;
    }

    printf("{ type: %s, value: %s },\n", type, tokens[i].value);
  }
  printf("]\n");
}

int lexer() {
  FILE *file = fopen("../tests/print.bi", "r");

  char *keywords[] = {"print"};
  int length = sizeof(keywords) / sizeof(keywords[0]);

  token *tokens;
  int tokens_length = 0;

  char found_str = 0;

  char *output;
  while (fgets(output, INT_MAX, file)) {
    char *word = strtok(output, " ");

    while (word) {
      if (in_array(keywords, word, length)) {
        tokens[tokens_length].type = keyword;
        strcpy(tokens[tokens_length].value, word);
        tokens_length++;
      }

      else if (strchr(word, '"')) {
        if (found_str) {
          strcat(tokens[tokens_length].value, " ");
          strcat(tokens[tokens_length].value, word);
          found_str = 0;
          tokens_length++;
        } else {
          tokens[tokens_length].type = string;
          strcpy(tokens[tokens_length].value, word);
          found_str = 1;
        }
      }

      else if (found_str) {
        strcat(tokens[tokens_length].value, " ");
        strcat(tokens[tokens_length].value, word);
      }

      word = strtok(NULL, " ");
    }
  }

  print_tokens(tokens, tokens_length);

  fclose(file);

  return 0;
}

int main() {
  lexer();
  return 0;
}
