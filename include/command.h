#ifndef COMMAND_H
#define COMMAND_H

#include "printf.h"
#include "str_func.h"
#include "shell_lexer.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct command_s - struct for help built-in
 * @signe: signe op
 * @fd: file descriptor
 * @command_name: name of command
 * @command_argument: line split
 * @command_path: path of command
 * @redirect_file: filre redirect
 * @next: next element
 */
typedef struct command_s
{
	int fd;
	char *signe;
	char *command_name;
	char **command_argument;
	char *command_path;
	char *redirect_file;
	struct command_s *next;
} command_t;


/* function */
command_t *add(command_t **node);
void delete_command(command_t **node);
command_t *interpret_token(token_shell_t **tokens);
int sepcial_op(char *op);
void op_output_file(command_t **command, token_shell_t **token);
int option_open(char *signe, char *file);

#endif /*COMMAND_H*/
