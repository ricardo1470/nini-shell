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

int main(void)
{
	char *tok;
	char *path = NULL;

	path = _getenv("PATH");
	printf("%s\n", path ? path : "(nil)");
	tok = strtok(path, ":");
	while (tok)
	{
		printf("%s\n", tok);
		tok = strtok(NULL, ":");
	}
	return (0);
}
