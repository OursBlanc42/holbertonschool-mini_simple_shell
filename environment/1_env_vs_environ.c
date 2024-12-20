#include <stdio.h>
#include "find.h"

/**
 * main - print the adress of env and environ
 *@env: 2d array of environment
 *@ac: argument count
 *@av: argument vector
 *Return: return 0
 */
int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	printf("Address of env: %p\n", &**env);
	printf("Address of environ: %p\n", &**environ);

	if (&**env == &**environ)
		printf("It's the same address\n");
	else
		printf("The address is different\n");

	return (0);
}
