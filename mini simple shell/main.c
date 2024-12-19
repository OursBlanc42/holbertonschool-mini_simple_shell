#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>


/**
 * main - Entry point
 * Description : Mini Simple Shell
 * Return: Nothing (waiting to ctrl + c (abort))
 */

int main(void)
{
	/* declare & initialize variable */
	char *string = NULL;
	size_t buffer_size = 0;
	ssize_t readed;
	int i = 0;
	int random = 0;
	pid_t child_pid;

	char *emoji[] = {
		"⊂(◉‿◉)つ \t> ",
		"┌( ಠ_ಠ)┘ \t> ",
		"∩ʕ•ᴥ•ʔづ \t> ",
		"∩(✿◠‿◠)づ \t> ",
		"∩( ・ω・)∩ \t> ",
		"∩(｡*‿*｡)づ \t> ",
		"∩(⌐■_■)づ \t> ",
		"ლ(╹◡╹ლ) \t> ",
		"ᕦ(ò_óˇ)ᕤ \t> ",
		"(づ｡◕‿‿◕｡)づ \t> "
	};

	/* initialize seed for RNG */
	srand(time(NULL));

play_again: 

	/* generate random number */
	random = rand() % 10;

	/* Waiting for input */
	printf("%s",emoji[random]);

	/* Read the input and check if succeed */
	readed = getline(&string, &buffer_size, stdin);

	if (readed == -1)
		{
			printf("(╯°□°）╯︵ ┻━┻ (Error getline)\n");
			goto play_again;
		}

	/* fork current process and check if succeed */
	child_pid = fork();

	if (child_pid == -1)
	{
		printf("(╯°□°）╯︵ ┻━┻ (Error fork)\n");
		goto play_again;
	}



	/* clean string (remove last \n char) */
	for(i=0; string[i] != '\0'; i++)
	{
		if(string[i] == '\n')
		{
			string[i] = '\0';
		}
	}

	/* setup argv[] for execve */
	char *argv[] = {string, NULL };

	/* execute child process */
	if (child_pid == 0)
	{
		/* Check and execute command if no error */
		if (execve(argv[0], argv, NULL) == -1)
		{
			printf("(╯°□°）╯︵ ┻━┻ (Error execve)\n");
			goto play_again;
		}
	}

	/* waiting for child finish execution */
	else
	{
			wait(NULL);
			goto play_again;
	}
}


