#include <stdio.h>

int main() {
  FILE *file = fopen("../tests/print.bi", "r");

  char output[100];

  while (fgets(output, 100, file)) {
    printf("%s", output);
  }

  fclose(file);
}
