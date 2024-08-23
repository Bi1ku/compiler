#include "../include/generator.h"
#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/types.h"
#include <stdlib.h>

int main() {
  token tokens[100] = {};
  int tokens_length = lexer(tokens, "../tests/test3.bi");

  struct node **trees = malloc(0);
  parser(tokens, tokens_length, trees);

  generate(trees, tokens_length);

  return EXIT_SUCCESS;
}
