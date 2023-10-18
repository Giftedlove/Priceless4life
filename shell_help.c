#include "shell.h"

/**
 * @brief Prints a string to a specified stream
 *
 * This function writes the given string to the specified stream (e.g., STDOUT_FILENO).
 *
 * @param string String to be printed
 * @param stream Stream to print out to (e.g., STDOUT_FILENO)
 * @return void
 */
void print_string(char *string, int stream)
{
	int i = 0;

	while (string[i] != '\0')
	{
		write(stream, &string[i], 1);
		i++;
	}
}


/**
 * @brief Reallocates a memory block
 *
 * This function reallocates a memory block.
 *
 * @param ptr Pointer to the memory previously allocated with malloc
 * @param old_size Size of ptr
 * @param new_size Size of the new memory to be allocated
 * @return Pointer to the address of the new memory block
 */
void *reallocate_memory(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_block;
	unsigned int i;

	if (ptr == NULL)
	{
		new_block = malloc(new_size);
		return(new_block);
	}
	else if (new_size == old_size)
	{
		return(ptr);
	}
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return(NULL);
	}
	else
	{
		new_block = malloc(new_size);
		if (new_block != NULL)
		{
			for (i = 0; i < min(old_size, new_size); i++)
				*((char *)new_block + i) = *((char *)ptr + i);
			free(ptr);
			return new_block;
		}
		else
		{
			return NULL;
		}
	}
}


/**
 * @brief Compares two strings
 *
 * This function compares two strings character by character and returns
 * the difference between the first differing characters.
 *
 * @param first First string to be compared
 * @param second Second string to be compared
 * @return The difference of the two strings
 */
int string_compare(const char *first, const char *second)
{
	int i = 0;

	while (first[i] != '\0')
	{
		if (first[i] != second[i])
			break;
		i++;
	}

	return first[i] - second[i];
}


/**
 * @brief Initializes command execution based on its type
 *
 * This function decides how to execute the given command based on its type.
 *
 * @param current_command The command to be executed
 * @param type_command Type of the command (EXTERNAL_COMMAND, PATH_COMMAND, INTERNAL_COMMAND)
 * @return void
 */
void initialize_execution(char **current_command, int type_command)
{
	pid_t child_pid;

	if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
	{
		child_pid = fork();

		if (child_pid == 0)
		{
			/* Child process*/
			execute_command(current_command, type_command);
		}
		else
		{
			/* Parent process*/
			waitpid(child_pid, &status, 0);
			status >>= 8;
		}
	}
	else

		execute_command(current_command, type_command);
}
}


/**
 * @brief Tokenizes input string using a specified delimiter
 *
 * This function tokenizes the input string using the provided delimiter
 * and stores the tokens in an array.
 *
 * @param input_string Input string to be parsed
 * @param delim Delimiter to be used (a single character string)
 * @return Array of tokens
 */
char **tokenizer(char *input_string, const char *delim)
{
	int num_tokens = 0;
	char *tokens[100];
	char *token = NULL;
	char *save_ptr = NULL;
	int a = 0;

	token = strtok(delim, input_string);

	while (input_string[num_tokens] != '\0')
	{
		if (strchr(delim, input_string[num_tokens])
				num_tokens++;
				a++;
				}
				tokens = malloc(sizeof(*tokens) * (a + 1));
				if (tokens == NULL)
                                 {
                                perror("Error: Unable to allocate memory");
				exit(EXIT_FAILURE);
				}
				while (token != NULL)
				{

				tokens[num_tokens] = token;
				num_tokens++;
				token = strtok(NULL, delim);
				}

				tokens[num_tokens] = NULL;

				return tokens;
}

