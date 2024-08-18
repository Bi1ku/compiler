#ifndef LEXER
#define LEXER

#include "types.h"

char in_string_array(char *arr[], char str[], int length);
void print_tokens(token *tokens, int length);

#endif
