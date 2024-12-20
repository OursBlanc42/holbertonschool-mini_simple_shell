#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "which.h"
#include "find.h"

/**
 * main - Entry point - Rewrite of the `which` command
 * Description: This program searches for the location of an executable
 *				in the directories specified by the PATH environment variable.
 *
 * Algorithm:
 * 1. Split the PATH environment variable into a list of directories.
 * 2. For each dir, concatenate the full path (ex : /usr/bin/ + / + neofetch)
 * 3. For each full path, check with "stat" if the executable exist.
 * 4. Return the full path of the command if found; print an error otherwise.
 * @argc: The number of arguments passed to the program.
 * @argv: An array of strings representing the arguments passed to the program.
 * Return: 
 * - 0: All commands were found successfully.
 * - 1: An error occurred or at least one command was not found.
 */

int main(int argc, char *argv[])
{
	/* declare & initialize variable */
	char *var_env_name = "PATH";
	char *program_name = NULL;
	char *separator = ":";
	char *env_path = _getenv(var_env_name);
	list_t *head_path_list;
	list_t *path_list;
	struct stat buffer_stat;
	char *string_concat = NULL;
	int index;
	int founded;
	int fail = 0;

	if (argc < 2)
	{
		printf("Usage: _which <program_name1> <program_name2> ...\n");
		return (1);
	}

	/* generate path list and stock in single linked list */
	head_path_list = chopper(env_path, separator);

	/* Loop through all provided program names */
    for (index = 1; argv[index] != NULL; index++)
    {
		printf("Looking for argv[%d] = %s\n",index,argv[index]);

		program_name = argv[index];
		path_list = head_path_list; /* Reset path_list to the beginning */
		founded = 0;

		/* Loop through the linked list and check if the programm exist */
		while (path_list != NULL)
		{
			string_concat = concat_path(path_list->string, program_name);

			if (string_concat == NULL)
			{
				free_list(head_path_list);
				return (1);
			}

			if (stat(string_concat, &buffer_stat) == 0)
			{
				printf("(⌐■_■) Yeah ! I find the command : %s\n", string_concat);
				free(string_concat);
				founded = 1;
				break;
			}

			free(string_concat);	/* Always free string after use */
			string_concat = NULL; /* Reset string_concat to avoid double free*/
			path_list = path_list->next;
		}

		if (founded == 0)
		{
			fail = 1;
			printf("(T_T) Nope ! I didnt find the command %s\n",argv[index]);
		}
	}

	free_list(head_path_list);
	return (fail);
}
