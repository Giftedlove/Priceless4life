#include "shell.h"

/**
 * @brief Tokenizes input string using a specified delimiter
 *
 * This function tokenizes the input string using the provided delimiter
 * and stores the tokens in an array.
 *
 * @param input_string Input string to be parsed
 * @param delim Delimiter to be used (a single character string)
 * @return: Array of tokens
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
				return (tokens);
}
