#include "../include/utils.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  keyword,
  number,
  string,
  operator,
  newline,
  boolean,
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
    case boolean:
      type = "boolean";
      break;
    }

    printf("{ type: %s, value: %s },\n", type, tokens[i].value);
  }
  printf("]\n");
}

int lexer(char path[]) {
  FILE *file = fopen(path, "r");

  char *keywords[] = {"print", "input"};

  token tokens[100];
  int tokens_length = 0;

  char *operators[] = {"+", "-", "*",
                       "/"}; // parsing from files results in string comparisons

  char found_str = 0;
  char end_line = 0;

  char output[100];

  while (fgets(output, 100, file)) {
    char *word = strtok(output, " ");

    while (word) {
      if (strchr(word, '\n')) {
        word[strcspn(word, "\n")] = 0;
        end_line = 1;
      }

      if (in_string_array(keywords, word, 2)) {
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
        }

        else {
          tokens[tokens_length].type = string;
          strcpy(tokens[tokens_length].value, word);
          found_str = 1;
        }
      }

      else if (found_str) {
        strcat(tokens[tokens_length].value, " ");
        strcat(tokens[tokens_length].value, word);
      }

      else if (isdigit(word[0])) {
        tokens[tokens_length].type = number;
        strcpy(tokens[tokens_length].value, word);
        tokens_length++;
      }

      else if (in_string_array(operators, word, 4)) {
        tokens[tokens_length].type = operator;
        strcpy(tokens[tokens_length].value, word);
        tokens_length++;
      }

      else if (strcmp(word, "true") == 0 || strcmp(word, "false") == 0) {
        tokens[tokens_length].type = boolean;
        strcpy(tokens[tokens_length].value, word);
        tokens_length++;
      }

      if (end_line) {
        end_line = 0;
        tokens[tokens_length].type = newline;
        strcpy(tokens[tokens_length].value, "newline");
        tokens_length++;
      }

      word = strtok(NULL, " ");
    }
  }

  print_tokens(tokens, tokens_length);

  fclose(file);

  return 0;
}
