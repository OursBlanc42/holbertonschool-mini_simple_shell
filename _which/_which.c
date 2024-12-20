#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "which.h"
#include "find.h"

/**
 * _which - Rewrite of the `which` command
 * Description: This program searches for the location of an executable
 *				in the directories specified by the PATH environment variable.
 * 
 * Algorithm:
 * 1. Split the PATH environment variable into a list of directories.
 * 2. Loop through each directory:
 *    - Check if the command exists and is executable.
 * 3. Return the full path of the command if found; print an error otherwise.
 *
 * Return: 0 if the command is found, 1 otherwise.
 */


int main(int argc, char *argv[])
{
	/* declare & initialize variable */
	char *name = "PATH"; /* name of var env */
	char *mysearch = NULL;
	char *separator = ":";			/* separator	*/
	char *env_path = getenv(name);	/* get the env path */
	list_t *path_list;				/* single linked list */
	struct stat buffer_stat;	/* buffer to store stat result */
	char *string_concat = NULL;

	if (argc != 2)
	{
		printf("Please enter one command name after which\n");
		return (1);
	}

	mysearch = argv[1];

	/* generate path list and stock in single linked list */
	path_list = chopper(env_path, separator);

	/* Loop through the linked list */
	while (path_list != NULL)
	{
		string_concat = strcat(path_list->str, "/");
		string_concat = strcat(path_list->str, mysearch);

		/* check if stat return value, that mean the thing exist */
		if (stat(path_list->str, &buffer_stat) == 0)
		{
			printf("(⌐■_■) Yeah ! I find the command : %s\n", string_concat);
			return (0);
		}

		path_list = path_list->next;
	}

	printf("(T_T) Nope ! I didnt find the command\n");

	return (0);
}


