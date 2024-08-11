#include "../include/utils.h"
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

int lexer() {
  FILE *file = fopen("../tests/print.bi", "r");

  char *keywords[] = {"print"};
  int length = sizeof(keywords) / sizeof(keywords[0]);

  char output[1000];
  token tokens[1000];

  while (fgets(output, 100, file)) {
    char *word = strtok(output, " ");

    while (word) {
      if (in_array(keywords, word, length)) {
        tokens[0].type = keyword;
        strcpy(tokens[0].value, word);
      }

      printf("%s\n", word);
      word = strtok(NULL, " ");
    }
  }

  printf("%d\n", tokens[0].type); // 0 (keyword)
  printf("%s\n", tokens[0].value);

  fclose(file);

  return 0;
}
