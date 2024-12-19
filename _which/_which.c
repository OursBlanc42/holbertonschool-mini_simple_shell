#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include "which.h"
#include "find.h"

/**
 * _which - Rewrite of which
 * Description : to retrieve the location of executable in current PATH
 * Return: NULL or executable path
 */

int main(void)
{
	/* declare & initialize variable */
	char *name = "PATH";			/* name of var env */
	char *mysearch = "/neofetch";
	char *separator = ":";			/* separator	*/
	char *env_path = _getenv(name);	/* get the env path */
	list_t *path_list;				/* single linked list */
	struct stat buffer_stat;	/* buffer to store stat result */
	char *string_concat = NULL;

	path_list = chopper(env_path, separator);

	/* Loop through the linked list */
	while (path_list != NULL)
	{
		string_concat = strcat(path_list->str, mysearch);
		printf("%s", path_list->str);
		
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


