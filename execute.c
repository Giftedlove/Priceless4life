#include "shell.h"

/**
 * command_execution - executes the command given
 * @enact: the given command
 * Return: Always void
 */

void command_execution(const char *enact)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		execlp(enact, enact, (char *)NULL);
		perror("execlp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
