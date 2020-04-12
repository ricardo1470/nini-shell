#include "holberton.h"

/**
 * gmain - Entry point.
 *@ac: value
 *@av: pointer value
 * Return: Always 0 (Success)
 */
int main(__attribute__((unused)) int ac, char **av)
{
	int i;

	if (av == '\0')
	{
		return (0);
	}
	while (av[i])
	{
		printf("%s\n",av[i]);
		i++;
	}
	return (0);
}
