#ifndef SHELL_LEXER_H
#define SHELL_LEXER_H


typedef struct token_shell_s
{   
    char *op;
    struct token_shell_s *next;
} token_shell_t;


token_shell_t *tokenize(char *line);
void print_token(token_shell_t *node);
token_shell_t *add_token(token_shell_t **node, char *op);
void delete_token(token_shell_t **node);
unsigned int token_length(token_shell_t *node);

#endif /*SHELL_LEXER_H*/
