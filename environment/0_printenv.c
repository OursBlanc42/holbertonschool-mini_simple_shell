#include <stdio.h>
#include "find.h"

/**
 * main - print the environment variable
 * Description: With a pointer browse environment and print all line
 *Return: return 0
 */
int main(void)
{
	char **ptr_env = environ;

	while (*ptr_env != NULL)
	{
		printf("%s\n", *ptr_env);
		ptr_env++;
	}
	return (0);
}
