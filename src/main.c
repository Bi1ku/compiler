#include "../include/lexer.h"

int main() {
  token tokens[100];

  lexer(tokens, "../tests/test2.bi");

  return 0;
}
