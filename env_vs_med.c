#include "holberton.h"

/**
 * main - prints the environment
 *@ac: int value
 *@av: pointer value
 *@env: pointer value
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	printf("%p dir env\n", env);
	printf("%p dir environ\n", environ);
	return (0);
}
