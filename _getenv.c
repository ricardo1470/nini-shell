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
	if (environ[i] == 0)
		return (NULL);
	return (tok);
}

int main(void)
{
	char *path = NULL;
	path = _getenv("Pdfae");
	printf("%s\n", path ? path : "(nil)");
	return (0);
}
