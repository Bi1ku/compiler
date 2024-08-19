#include "../include/types.h"
#include "../include/utils.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

int lexer(token tokens[100], char path[]) {
  FILE *file = fopen(path, "r");

  char *keywords[] = {"print", "input", "loop"};
  char *operations[] = {"+", "-", "*", "/", "(", ")"};
  char *containers[] = {"{", "}"};

  char keywords_length = 3;
  char operations_length = 6;
  char containers_length = 2;
  int tokens_length = 0;

  char found_str = 0;
  char in_container = 0;
  char found_expression = 0;
  char end_line = 0;

  // TODO: Make dynamic?
  char line[100] = "";
  char word[100] = "";

  while (fgets(line, 100, file)) {
    for (int i = 0; i < strlen(line); i++) {
      char letter[2] = {line[i], '\0'};

      if (!(strcmp(letter, " ") == 0)) {

        // TRACK/PERSIST EXPRESSIONS
        if (!isdigit(letter[0]) &&
            !in_string_array(operations, letter, operations_length) &&
            found_expression) {
          found_expression = 0;
          tokens_length++;
        }

        // TRACK/PERSIST STRINGS
        if (!found_str) {
          if (strcmp(letter, "\n") == 0)
            end_line = 1;
          else
            strcat(word, letter);
        }
      }

      // KEYWORDS
      if (in_string_array(keywords, word, keywords_length)) {
        tokens[tokens_length].type = keyword;
        strcpy(tokens[tokens_length].value, word);
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

      // EXPRESSIONS
      else if (isdigit(letter[0])) {
        found_expression = 1;
        tokens[tokens_length].type = expression;
        strcat(tokens[tokens_length].value, letter);
      }

      else if (in_string_array(operations, letter, operations_length)) {
        found_expression = 1;
        tokens[tokens_length].type = expression;
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

  // print_tokens(tokens, tokens_length);

  fclose(file);

  return tokens_length;
}
