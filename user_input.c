#include "shell.h"

/**
 * read_command - reads the command and interpretes
 * @enact: the given command
 * @size: the size of string
 * Return: Always void
 */

void read_command(char *enact, size_t size)
{
	if (fgets(enact, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			print("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			print("error while reading inputs.\n");
			exit(EXIT_FAILURE);
		}
	}
	enact[strcspn(enact, "\n")] = "\0";
}
