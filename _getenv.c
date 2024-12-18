#include <stdio.h>
#include <string.h>
#include "find.h"

/**
 * _getenv - search a variable in the environnement
 *@search: the variable you search
 *Return: return a pointer to the the variable
 */
char *_getenv(const char *search)
{
	while (*environ != NULL)
	{
		if (strstr(*environ, search) != NULL)
		{
			return (*environ);
		}
		environ++;
	}
	return (*environ);
}
