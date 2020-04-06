#include "holberton.h"
/**
 * _split - Entry point.
 *@av: pointer value
 * Return: Always 0 (Success)
 */
char **_split(char *av)
{
	int i;
	char *tok = NULL;
	char *buffer = NULL;
	size_t size = 0;
	char **array = NULL;
	buffer = malloc(sizeof(char) * strlen(av) + 1);
	if (!buffer)
		return (NULL);
	strcpy(buffer, av);
	tok = strtok(av, " \t\n\r");
	while (tok)
	{
		size++;
		tok = strtok(NULL, " \t\n\r");
	}
	array = calloc(sizeof(char *), (size + 1));
	if (!array)
	{
		free(buffer);
		return (NULL);
	}
	tok = strtok(buffer, " \t\n\r");
	size = 0;
	while (tok)
	{
		array[size] = malloc(sizeof(char) * strlen(tok) + 1);
		if (!array[size])
		{
			for (i = 0; array[size]; i++)
				free(array[size]);
			free(array);
			free(buffer);
			return(NULL);
		}
		strcpy(array[size], tok);
		size++;
		tok = strtok(NULL, " \t\n\r");
	}
	array[size] = NULL;
	free(buffer);
	return (array);	
}
/**
 * main - simple shell
 * 
 * Return: 0
 */
int main(void)
{
	pid_t child;
	char *buff = NULL;
	char **array = NULL;
	size_t len = 0;
	int status;
	while (1)
	{
		printf("#cisfun$ ");
		getline(&buff, &len, stdin);
		array = _split(buff);
		if (buff && strcmp(buff, "\n"))
		{
			child = fork();
			if (!child)
			{
				if (execve(array[0], array, NULL) == -1)
					perror("Error");
			}
			else
			{
				wait(&status);
			}
		}
	}
	return (0);
}
