#include "shell.h"

/**
 * @brief - Determines the type of the command
 *
 * This function analyzes the command to determine its type.
 *
 * @param command Command to be parsed
 * @return Type of the command (EXTERNAL_COMMAND, INTERNAL_COMMAND, PATH_COMMAND, or INVALID_COMMAND)
 */

CommandType parse_command(char *command)
{
	int i;
	char *internal_commands[] = {"env", "exit", NULL};
	char *path = NULL;

	for (i = 0; command[i] != '\0'; i++) 
	{
	if (command[i] == '/')
	return(EXTERNAL_COMMAND);
	}

	/* Check if the command is an internal command*/
	for (i = 0; internal_commands[i] != NULL; i++) 
	{
	if (strcmp(command, internal_commands[i]) == 0)
	return(INTERNAL_COMMAND);
	}

	/* Check if the command is found in the PATH*/
	path = check_path(command);
	if (path != NULL)
	{
	free(path);
        return(PATH_COMMAND);
	}

	return(INVALID_COMMAND);
}


/**
 * @brief Checks if a command is found in the PATH
 *
 * This function checks if the command is found in any of the directories in the PATH.
 *
 * @param command Command to be searched in the PATH
 * @return Path where the command is found, NULL if not found
 */
char *check_path(char *command)
{
	char *path = _getenv("PATH");
	if (path == NULL || strlen(path) == 0)
	return(NULL);

	char *path_copy = strdup(path);
	if (path_copy == NULL)
	{
	perror("Error: Unable to duplicate PATH");
	return(NULL);
	}

	char **path_tokens = tokenizer(path_copy, ":");
	free(path_copy);

	if (path_tokens == NULL)
	return (NULL);

	for (int i = 0; path_tokens[i] != NULL; i++)
	{
	char *temp2 = _strcat(path_tokens[i], "/");
	char *temp = _strcat(temp2, command);
	free(temp2);

	if (access(temp, F_OK) == 0)
	{
	free_string_array(path_tokens);
	return(temp);
	}

	free(temp);
	}

	free_string_array(path_tokens);
	return(NULL);
}

/**
 * @brief Retrieves a function based on the command given and a mapping
 *
 * This function searches for a command in a mapping and returns the corresponding function.
 *
 * @param command String to check against the mapping
 * @return Pointer to the proper function, or NULL on fail
 */
void (*get_command_function(char *command))(char **)
{
	typedef struct
	{
	char *command_name;
	void (*func)(char **);
	}
	CommandMapping;

	CommandMapping mapping[] = 
	{
	("env", env);
	("exit", quit);
	}

	for (size_t i = 0; i < sizeof(mapping) / sizeof(mapping[0]); i++)
	{
	if (_strcmp(command, mapping[i].command_name) == 0)
	return mapping[i].func;
	}

	return (NULL);
}


/**
 * @brief Gets the value of an environment variable
 *
 * This function retrieves the value of the specified environment variable.
 *
 * @param name Name of the environment variable
 * @return The value of the variable as a string, or NULL if not found
 */
char *get_environment_variable(const char *name)
{
	const char **env_var;

	for (env_var = environ; *env_var != NULL; env_var++)
	{
	const char *pair = *env_var;
	const char *name_cpy = name;

	while (*pair == *name_cpy && *pair != '=')
	{
	pair++;
	name_cpy++;
	}

	if (*pair == '=' && *name_cpy == '\0')
	return (char *)(pair + 1);
	}

	return(NULL);
}
