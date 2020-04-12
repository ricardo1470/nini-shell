#include "holberton.h"

/**
 * _getenv - prints the environment
 * 
 *@name: int value
 *
 * Return: Always 0.
 */
char *_getenv(const char *name)
{
	(void)name;
	char *tok = NULL;
	int i = 0;

	tok = strtok(environ[i], "=");
	while (strcmp(name, tok) && environ[i])
	{
		tok = strtok(environ[i++], "=");
	}
	tok = strtok(NULL, "\n");
	if (environ[i] == 0)
		return (NULL);
	return (tok);
}

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *last = *head;
	int a;

	for (a = 0 ; *(str + a) != '\0' ; a++)
	{
	}

	new_node = (list_t *)malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->str = strdup(str);
	new_node->len = a;
	new_node->next = NULL;

	if (*head == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = new_node;
	}

	return (new_node);
}

int main(void)
{
	char *tok;
	char *path = NULL;
	list_t *head = NULL;
	list_t *cpy = NULL;

	path = _getenv("PATH");
	printf("%s\n", path ? path : "(nil)");
	tok = strtok(path, ":");
	while (tok)
	{
		add_node_end(&head, tok);
		// printf("correct insert\n");
		// printf("%s\n", tok);
		tok = strtok(NULL, ":");
	}
	cpy = head;
	while (cpy)
	{
		printf("%s\n", cpy->str);
		cpy = cpy->next;
	}
	return (0);
}
