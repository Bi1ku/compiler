#ifndef LEXER
#define LEXER

typedef enum {
  keyword,
  number,
  string,
  operation,
  newline,
  boolean,
} type;

typedef struct {
  type type;
  char value[100];
} token;

int lexer(token tokens[], char path[]);

#endif
