#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - prompt
 *
 * Return: Always 0.
 */

int main(void)
{
	/* declare & initialize variable */
	char *string = NULL;
	size_t buffer_size = 0;
	ssize_t readed;

	char *next_word = NULL;
	const char *space = " ";

	size_t array_length = 0;
	char **array = NULL;
	int index = 0;

	int play_again = 0;	/* boolean */

	/* Waiting for input */
	printf("$ ");

	/* Read the input and print the input */
	readed = getline(&string, &buffer_size, stdin);

	if (readed == -1)
		printf("error\n");
	else
		printf("%s", string);

	/* Loop in the printed result and separate each word in an array */	
	while (play_again == 0)
	{
		next_word = strtok(string, space);
		string = NULL;

		if (next_word == NULL)
		{
			play_again = 1;
			break;
		}

		/* increase array by one word */
		array_length++;
		array = realloc(array, sizeof(char) * array_length);
			if (array == NULL)
				return (-1);

		/* write word in the new index */
		array[index] = strdup(next_word);
		
		if (strdup(next_word) == NULL)
			return (-1);

		index++;
	}
	index = 0;

	while (index != array_length)
	{
		printf("Index = %d et Mot = %s \n", index, array[index]);
		index++;
	}

}

