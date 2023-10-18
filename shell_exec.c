#include "shell.h"

/**
 * @brief Executes a command based on its type
 *
 * execute_command - This function executes a command based on its type using execve
 * or internal functions.
 *
 * @param tokenized_command Tokenized form of the command
 * @param command_type Type of the command
 * @return void
 */
void execute_command(char **tokenized_command, int command_type)
{
	void (*execute_func)(char **command);

	switch (command_type)
	{
	case EXTERNAL_COMMAND:
		execute_external_command(tokenized_command);
		break;

	case PATH_COMMAND:
		execute_command_with_path(tokenized_command);
		break;

	case INTERNAL_COMMAND:
		execute_func = get_command_function(tokenized_command[0]);
		execute_func(tokenized_command);
		break;

	case INVALID_COMMAND:
		handle_invalid_command(tokenized_command);
		break;

	default:
	/*Unknown command type*/
 		break;
	}
}

/**
 * execute_external_command - function to execute the command given
 * @param tokenized_command Tokenized form of the command
 */
void execute_external_command(char **tokenized_command)
{
	if (execve(tokenized_command[0], tokenized_command, NULL) == -1)
	{
		perror(get_enviroment_variable("PWD"));
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_command_with_path - function that executes commands with path
 * @param tokenized_command Tokenized form of the command
 */
void execute_command_with_path(char **tokenized_command)
{
	char *path = check_path(tokenized_command[0]);
	if (path == NULL)
	{
		perror(get_enviroment_variable("PWD"));
		exit(EXIT_FAILURE);
	}

	if (execve(path, tokenized_command, NULL) == -1)
	{
		perror(get_enviroment_variable("PWD"));
		exit(EXIT_FAILURE);
	}
	free(path);
}

/**
 * handle_invalid_command - funtion that handles invalid command
 * @param tokenized_command Tokenized form of the command
 */

void handle_invalid_command(char **tokenized_command)
{
	print(shell_name, STDERR_FILENO);
	print(": 1: ", STDERR_FILENO);
	print(tokenized_command[0], STDERR_FILENO);
	print(": not found\n", STDERR_FILENO);
	status = 127;
}
