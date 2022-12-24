#include "main.h"
char *_getenv(char *key);
paths_t *add_node(paths_t **head, char *key, char *value);
paths_t *generate_paths();
void print_nodes(paths_t *node);

/**
 * generate_paths - this program generate paths
 * and store in a linked list
 * Return: nothing
 */

paths_t *generate_paths()
{
	char *path[100] = {NULL}, *env, *tok;
	int i = 1;
	paths_t *head = malloc(sizeof(paths_t));

	if (head == NULL)
		return (NULL);

	env = _getenv("PATH");
	path[0] = strtok(env, ":");

	while ((tok = strtok(NULL, ":")) != NULL)
	{
		path[i] = tok;
		i++;
	}
	path[i] = NULL;

	for (i = 0; path[i] != NULL; i++)
		path[i] = strtok(path[i], "\n");

	head->key = _strdup("PATH");
	head->value = path[0];
	for (i = 1; path[i] != NULL; i++)
		add_node(&head, "PATH", path[i]);

	return (head);
}

/**
 * add_node - add node to tail
 * @head: pointer to pointer
 * @key: key
 * @value: value
 * Return: opt_t
 */

paths_t *add_node(paths_t **head, char *key, char *value)
{
	paths_t *temp = (*head);
	paths_t *new_node = NULL;

	new_node = malloc(sizeof(paths_t));
	if (new_node == NULL)
		return (NULL);

	new_node->key = _strdup(key);
	new_node->value = _strdup(value);
	new_node->next = NULL;

	if (temp == NULL)
		*head = new_node;
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}

	return (*head);
}

/**
 * _getenv - get env
 * @key: key of env
 * Return: addr
 */

char *_getenv(char *key)
{
	char *front = NULL, *copy_env = NULL, *ret_res = NULL, *tok = NULL;
	int i = 0;

	for (i = 0; environ[i] != NULL; i++)
	{
		copy_env = _strdup(environ[i]);
		front = strtok(copy_env, "=");

		if (_strcmp(front, key) == 0)
		{
			tok = strtok(NULL, "=");
			ret_res = _strdup(tok);
			return (ret_res);
		}
		if (front != NULL)
			free(front);
	}
	return (NULL);
}

/**
 * free_paths - for all paths_t nodes
 * @node: head node
*/
void free_paths(paths_t *node)
{
	paths_t *temp;

	while (node != NULL)
	{
		if (node->key != NULL)
			free(node->key);
		if (node->value != NULL)
			free(node->value);

		if (node->next != NULL)
		{
			temp = node;
			node = node->next;
			if (temp != NULL)
				free(temp);
		}
		else
		{
			free(node);
			break;
		}
	}
}
