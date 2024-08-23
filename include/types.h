#ifndef MAIN
#define MAIN

typedef enum { Keyword, Num, BinOpr, Str, Bool, End, Cont } type;

typedef struct {
  char add;
  char subtract;
  char multiply;
  char divide;
  char exponent;
  char parenthesis;
} precedence;

typedef struct {
  type type;
  char value[100];
} token;

struct node {
  token value;
  struct node *left;
  struct node *right;
};

#endif
