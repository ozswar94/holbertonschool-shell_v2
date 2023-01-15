#include "command.h"
#include <stdio.h>

/**
* interpret_token - interpret the line for setup list
* @tokens: token
*
* Return: return new command
*/
command_t *interpret_token(token_shell_t **tokens)
{
	int i;
	command_t *command = NULL;
	command_t *command_tmp;
	token_shell_t *token_tmp = *tokens;

	while (token_tmp)
	{
		command_tmp = add(&command);
		if (!command_tmp)
			return (NULL);

		command_tmp->command_argument = malloc(
			sizeof(char *) * token_length(*tokens));
		if (command_tmp->command_argument == NULL)
			return (NULL);

		for (i = 0; token_tmp && sepcial_op(token_tmp->op) == 0; i++)
		{
			command_tmp->command_argument[i] = _strdup(token_tmp->op);
			token_tmp = token_tmp->next;
		}
		command_tmp->command_argument[i] = NULL;
		op_output_file(&command_tmp, &token_tmp);
		command_tmp->command_name = _strdup(command_tmp->command_argument[0]);
	}
	delete_token(tokens);
	return (command);
}

/**
* sepcial_op - check if is a special token
* @op: string op token
*
* Return: find 1, not find 0
*/
int sepcial_op(char *op)
{
	if (_strstr(op, ">") || _strstr(op, ">>"))
		return (1);
	return (0);
}

/**
* option_open - setup file discriptor
* @signe: signe tokken
* @file: name of file
*
* Return: file descriptor
*/
int option_open(char *signe, char *file)
{
	int fd = 0;

	if (signe == NULL || file == NULL)
		return (1);

	if (_strstr(signe, ">>"))
		fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0600);
	else if (_strstr(signe, ">"))
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	return (fd);
}

/**
* op_output_file - setup file output
* @command: ptr command
* @token: ptr command
*
*/
void op_output_file(command_t **command, token_shell_t **token)
{
	if (*token && sepcial_op((*token)->op))
	{
		(*command)->signe = _strdup((*token)->op);
		(*token) = (*token)->next;
		if (_strstr((*command)->signe, ">") ||
			_strstr((*command)->signe, ">>"))
		{
			(*command)->redirect_file = _strdup((*token)->op);
			*token = (*token)->next;
		}
	}
	else
		(*command)->signe = NULL;
	(*command)->fd = option_open((*command)->signe, (*command)->redirect_file);
}
