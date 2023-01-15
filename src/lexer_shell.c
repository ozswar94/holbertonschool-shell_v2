#include "shell_lexer.h"
#include <stdlib.h>
#include "str_func.h"
#include "printf.h"
#include <string.h>
#include <stdio.h>

/**
* tokenize - interpret the line for setup list
* @line: line of command
*
* Return: token of line
*/
token_shell_t *tokenize(char *line)
{
	int i, j = 0;
	unsigned int size = _strlen(line);
	token_shell_t *tokens = NULL;
	char *str = (char *)malloc(sizeof(char) * size);

	if (str == NULL)
		return (NULL);
	memset(str, '\0', size);
	for (i = 0; line[i]; i++)
	{
		switch (line[i])
		{
			case '\n':
				if (_strlen(str))
				add_token(&tokens, str);
				memset(str, '\0', size);
				j = 0;
				break;
			case ' ':
				add_token(&tokens, str);
				memset(str, '\0', size);
				j = 0;
				break;
			case '>':
				while (line[i] == '>')
					str[j++] = line[i++];
				add_token(&tokens, str);
				memset(str, '\0', size);
				j = 0;
				break;
			default:
				str[j++] = line[i];
				break;
		}
	}
	free(str);
	return (tokens);
}

/**
* add_token - create a new token
* @node: ptr of token
* @op: op add on list of token
*
* Return: new token or NULL if error
*/
token_shell_t *add_token(token_shell_t **node, char *op)
{
	token_shell_t *tmp = *node;
	token_shell_t *new_node;


	new_node = (token_shell_t *)malloc(sizeof(token_shell_t));
	if (!new_node)
		return (NULL);

	new_node->op = _strdup(op);
	if (new_node->op == NULL)
		return (NULL);

	if (*node == NULL)
	{
		new_node->next = NULL;
		*node = new_node;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->next = NULL;
	}

	return (new_node);
}

/**
* delete_token - clean token list
* @node: ptr of token
*
*/
void delete_token(token_shell_t **node)
{
	token_shell_t *tmp = *node;

	while (tmp)
	{
		*node = (*node)->next;
		free(tmp->op);
		free(tmp);
		tmp = *node;
	}
	*node = NULL;
}

/**
* print_token - print tokens
* @node: ptr of token
*
*/
void print_token(token_shell_t *node)
{
	token_shell_t *tmp = node;

	while (tmp)
	{
		_printf("%s\n", tmp->op);
		tmp = tmp->next;
	}
}

/**
* token_length - len of token
* @node: ptr of token
*
* Return: len of node
*/
unsigned int token_length(token_shell_t *node)
{
	unsigned int size = 0;
	token_shell_t *tmp = node;

	while (tmp)
	{
		size += 1;
		tmp = tmp->next;
	}

	return (size);
}
