#include "../include/lexer.h"
#include <stdio.h>
#include <string.h>

int main() {
  lexer("../tests/test2.bi");

  printf("%d", strcmp("2", "true"));

  return 0;
}
