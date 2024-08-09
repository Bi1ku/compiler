#include <stdio.h>

int lexer() {
  FILE *file = fopen("../tests/print.bi", "r");

  char output[100];

  while (fgets(output, 100, file)) {
    printf("%s", output);
  }

  fclose(file);

  return 0;
}
