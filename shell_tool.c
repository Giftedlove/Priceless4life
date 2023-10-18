#include "shell.h"

/**
 * @brief Removes the newline character from a string
 *
 * @param str Pointer to the string
 */
void remove_newline_character(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
	if (str[i] == '\n')
		break;
	i++;
	}
	str[i] = '\0';
}


/**
 * @brief Removes the comment portion (everything after '#') from a string
 *
 * This function modifies the input string to remove any characters
 * after the '#' symbol, effectively removing the comment portion.
 *
 * @param input Pointer to the input string
 */
void remove_comment(char *input)
{
	int i = 0;
	bool found_comment = false;

	/* Find the '#' and remove the comment, considering a space before '#'*/
	while (input[i] != '\0')
	{
	if (input[i] == '#' && (i == 0 || input[i - 1] == ' '))
	{
		found_comment = true;
		break;
	}
	i++;
	}

	if (found_comment)
	input[i] = '\0';
}


/**
 * @brief Handles non-interactive mode by reading commands from stdin
 *
 * @return void
 */
void handle_non_interactive_mode(void)
{
	char **current_command = NULL;
	int i, command_type = 0;
	size_t n = 0;

	/* Check if stdin is not a terminal (e.g., piped input)*/
	if (!(isatty(STDIN_FILENO)))
    {
	while (getline(&line, &n, stdin) != -1)
	{
		/* Remove newline characters and comments from the input line*/
		remove_newline(line);
		remove_comment(line);

		/* Tokenize commands by semicolon*/
		commands = tokenizer(line, ";");
		for (i = 0; commands[i] != NULL; i++)
	{
		/* Tokenize individual commands by space*/
		current_command = tokenizer(commands[i], " ");
		if (current_command[0] == NULL)
		{
		free(current_command);
		break;
                }

		/*Determine the type of command (e.g., built-in, external)*/
		command_type = parse_command(current_command[0]);

		/* Initialize and execute the command*/
		initializer(current_command, command_type);
		free(current_command);
            }
		free(commands);
        }
	free(line);
	exit(status);
    }
}



