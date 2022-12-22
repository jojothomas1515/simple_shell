#include "main.h"
char *_getenv(char *key);
paths_t *add_node(paths_t **head, char *key, char *value);
paths_t *generate_paths();
void print_nodes(paths_t *node);

paths_t *generate_paths()
{
        char *path[100] = {NULL}, *env, *tok;
        int i = 1;
        paths_t *head;

        env = _getenv("PATH");
        path[0] = strtok(env, ":");

        while ((tok = strtok(NULL, ":")) != NULL)
                path[i++] = tok;
        path[i] = NULL;

        for (i = 0; path[i] != NULL; i++)
                path[i] = strtok(path[i], "\n");

        for (i = 0; path[i] != NULL; i++)
                add_node(&head, "PATH", path[i]);

        return (head);
}

paths_t *add_node(paths_t **head, char *key, char *value)
{
        paths_t *temp = *head;
        paths_t *new_node;

        new_node = malloc(sizeof(paths_t));
        if (new_node == NULL)
                return (NULL);

        new_node->key = _strdup(key);
        new_node->value = value;
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

char *_getenv(char *key)
{
        char *front, *copy_env, *ret_res, *tok;
        int i;

        for (i = 0; environ[i] != NULL; i++)
        {
                copy_env = _strdup(environ[i]);
                front = strtok(copy_env, "=");

                if (_strcmp(front, key) == 0)
                {
                        tok = strtok(NULL, "=");
                        ret_res = _strdup(tok);
                        free(front);
                        return (ret_res);
                }
                free(front);
        }
        return (NULL);
}

void print_nodes(paths_t *node)
{
        while (node)
        {
                printf("The key is %s, and value is = %s \n", node->key, node->value);
                if (node->next)
                        node = node->next;
                else
                        break;
        }
}
