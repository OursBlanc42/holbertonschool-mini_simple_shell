#include <stdio.h>

/**
 * main - Entry point
 * Description: prints all arguments it receives
 * (one by line followed by a new line) without using ac
 * @ac: number of arguments
 * @av: array who contains each arguments
 * Return: 0
 */

int main(int ac, char **av)
{
	int index = 1;

	/* hide ac to avoid error */
	(void)ac;

	/* While */
	while (av[index] != NULL)
	{
		printf("Av = %s \n", av[index]);
		index++;
	}

	return (0);
}

