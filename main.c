#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	/* declare & initialize variable */
	char *string = NULL;
	size_t buffer_size = 0;
	ssize_t readed;

play_again:

	/* Waiting for input */
	printf("(づ｡◕‿◕｡)づ ♥ ");

	/* Read the input and print the input */
	readed = getline(&string, &buffer_size, stdin);

	if (readed == -1)
		printf("error\n");
	else
		printf("%s", string);

	goto play_again;

}

