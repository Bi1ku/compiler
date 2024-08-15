#include "../include/lexer.h"
#include "../include/parser.h"
#include <stdlib.h>

int main() {
  token tokens[100];

  lexer(tokens, "../tests/test2.bi");
  parser(tokens);

  return EXIT_SUCCESS;
}
