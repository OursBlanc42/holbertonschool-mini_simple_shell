#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "which.h"

list_t *chopper(char *string, char *separator)
{
	/* declare & initialize variable */
	char *next_word = NULL;
	list_t *head = NULL;

	/* Loop in the printed result and separate each word in an linked list */
	next_word = strtok(string, separator);
	while (next_word != NULL)
	{
		add_node_end(&head, next_word);
		next_word = strtok(NULL, separator);
	}

	return (head);
}

