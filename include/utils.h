#ifndef LEXER
#define LEXER

#include "types.h"

char in_string_array(char *arr[], char str[], int length);
void print_tokens(token *tokens, int length);
void print_tree(struct node *tree);
void print_trees(struct node **trees, int trees_length);

#endif
