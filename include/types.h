#ifndef MAIN
#define MAIN

typedef enum {
  keyword,
  expression,
  string,
  newline,
  boolean,
  container,
} type;

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
