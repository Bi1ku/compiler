#include "../include/generator.h"
#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/types.h"
#include <stdlib.h>

int main() {
  token tokens[100] = {};

  // TODO: fix this is hella jank
  int tokens_length = lexer(tokens, "../tests/test2.bi", tokens_length);

  parser(tokens, tokens_length);

  generate();

  return EXIT_SUCCESS;
}
