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
  operation,
  newline,
  boolean,
  container,
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
    case operation:
      type = "operation";
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

char lexer(token tokens[100], char path[]) {
  FILE *file = fopen(path, "r");

  char *keywords[] = {"print", "input", "loop"};
  char *operations[] = {"+", "-", "*", "/", "(", ")"};
  char *containers[] = {"{", "}"};

  char keywords_length = 3;
  char operations_length = 6;
  char containers_length = 2;
  char tokens_length = 0;

  char found_str = 0;
  char in_container = 0;
  char found_num = 0;
  char end_line = 0;

  char line[100] = "";
  char word[100] = "";

  while (fgets(line, 100, file)) {
    for (int i = 0; i < strlen(line); i++) {
      char letter[2] = {line[i], '\0'};

      if (!isdigit(letter[0]) && found_num == 1) {
        found_num = 0;
        strcpy(word, "");
        tokens_length++;
      }

      if (!found_str && !(strcmp(letter, " ") == 0)) {
        if (strcmp(letter, "\n") == 0)
          end_line = 1;
        else
          strcat(word, letter);
      }

      // KEYWORDS
      if (in_string_array(keywords, word, keywords_length)) {
        tokens[tokens_length].type = keyword;
        strcpy(tokens[tokens_length].value, word);
        strcpy(word, "");
        tokens_length++;
      }

      // OPERATORS
      else if (in_string_array(operations, letter, operations_length)) {
        tokens[tokens_length].type = operation;
        strcpy(tokens[tokens_length].value, letter);
        strcpy(word, "");
        tokens_length++;
      }

      // CONTAINERS
      if (strcmp(letter, "{") == 0) {
        in_container = 1;
        tokens[tokens_length].type = container;
        strcpy(tokens[tokens_length].value, letter);
        strcpy(word, "");
        tokens_length++;
      }

      else if (strcmp(letter, "}") == 0) {
        in_container = 0;
        tokens[tokens_length].type = container;
        strcpy(tokens[tokens_length].value, letter);
        strcpy(word, "");
        tokens_length++;
      }

      // STRINGS
      else if (strcmp(letter, "\"") == 0) {
        if (found_str) {
          strcpy(word, "");
          found_str = 0;
          tokens_length++;
        }

        else {
          found_str = 1;
          tokens[tokens_length].type = string;
        }
      }

      else if (found_str) {
        strcat(tokens[tokens_length].value, letter);
      }

      // NUMBERS
      else if (isdigit(letter[0])) {
        found_num = 1;
        tokens[tokens_length].type = number;
        strcat(tokens[tokens_length].value, letter);
      }

      if (end_line) {
        end_line = 0;

        if (!in_container) {
          tokens[tokens_length].type = newline;
          strcpy(tokens[tokens_length].value, "newline");
          tokens_length++;
        }
      }
    }
  }

  print_tokens(tokens, tokens_length);

  fclose(file);

  return EXIT_SUCCESS;
}
