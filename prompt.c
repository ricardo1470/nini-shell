#include "holberton.h"

/**
 * main - Entry point.
 *@ac: value
 *@av: pointer value
 * Return: Always 0 (Success)
 */
int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av)
{
	char *buffer = NULL;
	size_t size = 0;

	// if (isatty(STDIN_FILENO))
	printf("$ ");
	getline(&buffer, &size, stdin);
	printf("%s", buffer);
	free(buffer);
	return (0);
}
