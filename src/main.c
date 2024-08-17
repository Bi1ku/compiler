#include "../include/lexer.h"
#include "../include/parser.h"
#include <stdlib.h>

int main() {
  token tokens[100] = {};
  int tokens_length = lexer(tokens, "../tests/test2.bi", tokens_length);

  parser(tokens, tokens_length);

  return EXIT_SUCCESS;
}
