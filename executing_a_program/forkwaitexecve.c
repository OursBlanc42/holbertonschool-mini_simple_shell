#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Entry point
 * Description : Execute the command ls -l /tmp in 5 differents child processes
 * Each child should be created by the same process (the father)
 * Wait for a child to exit before creating a new child.
 * Return: Always 0.
 */

int main(void)
{
	/* declare and initialize variable */
	pid_t child_pid[] = {0, 0, 0, 0, 0};	/* declare array to store PID */
	pid_t father_pid;
	pid_t current_pid;
	int index = 0;

	printf("Main program started\n");

	father_pid = getpid();

	/* setup argv[] for execve */
	char *argv[] = {"/bin/ls", "-l", "/tmp/test", NULL };

	/* loop 5x */
	for (index = 0; index < 5; index++)
	{
		/* fork process and check if suceed */
		child_pid[index] = fork();

		if (child_pid[index] == -1)
		{
			printf("Error!!\n");
			return (1);
		}

		/* mean = we are in the "child process" */
		if (child_pid[index] == 0) 
		{
			current_pid = getpid();
			printf("I am the child !\n");
			printf("Current child pid = \t\t%d\n", current_pid);
			
			/* execute command */
			if (execve(argv[0], argv, NULL) == -1)
			{
				printf("Error!!\n");
				return (1);
			}

		}
		else
		{
			wait(NULL);
			printf("I am you're father !\n");
			printf("father_pid = \t\t%d\n", father_pid);
			printf("child_pid[index] = \t%d\n\n", child_pid[index]);
		}

		printf("######## NEXT ########\n");
	}

	return (1);

}

