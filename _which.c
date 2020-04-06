#include "holberton.h"

/**
 * gmain - Entry point.
 *@ac: value
 *@av: pointer value
 * Return: Always 0 (Success)
 */
int main(int ac, char **av)
{
	unsigned int i;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: %s filename ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printf("%s:", av[i]);
		if (stat(av[i], &st) == 0)
		{
			printf(" FOUND\n");
		}
		else
		{
			printf(" NOT FOUND\n");
		}
		i++;
	}
	return (0);
}
