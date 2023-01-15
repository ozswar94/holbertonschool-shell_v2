#include "command.h"
#include <unistd.h>

/**
* add - add new element in node
* @node: command
*
* Return: new element in node
*/
command_t *add(command_t **node)
{
	command_t *tmp = *node;
	command_t *new_node = (command_t *)malloc(sizeof(command_t));

	if (!new_node)
		return (NULL);

	new_node->fd = 1;
	new_node->signe = NULL;
	new_node->command_name = NULL;
	new_node->command_argument = NULL;
	new_node->command_path = NULL;
	new_node->redirect_file =  NULL;
	new_node->next = NULL;

	if (*node == NULL)
		*node = new_node;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
	}

	return (new_node);
}

/**
* delete_command - remove all element on the list
* @node: command
*
* Return: new element in node
*/
void delete_command(command_t **node)
{
	command_t *tmp = *node;

	while (tmp)
	{
		*node = (*node)->next;
		if (tmp->command_path)
			free(tmp->command_path);
		tmp->command_path = NULL;

		if (tmp->command_name)
			free(tmp->command_name);
		tmp->command_name = NULL;

		free_dptr(tmp->command_argument);

		if (tmp->redirect_file != NULL)
			free(tmp->redirect_file);
		tmp->redirect_file = NULL;

		if (tmp->fd > 2)
			close(tmp->fd);

		free(tmp);
		tmp = *node;
	}
	*node = NULL;
}
