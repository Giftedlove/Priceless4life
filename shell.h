#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include <fcntl.h>
#include <ctype.h>


/**
 *struct map - a struct that maps a command name to a function
 *
 *@command_name: name of the command
 *@func: the function that executes the command
 */

	typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;

/**
 * @brief Represents the types of commands
 */
	typedef enum
{
	EXTERNAL_COMMAND = 1,
	INTERNAL_COMMAND,
	PATH_COMMAND,
	INVALID_COMMAND = -1
} CommandType;

	typedef struct
    {
        char *command_name;
        void (*func)(char **);
    } CommandMapping;

	extern char **environ;
	extern char *alx;
	extern char **love;
	extern char *gifted;
	extern int part;

CommandType parse_command(char *command);
char *check_path(char *command);
void execute_command(char **tokenized_command, int command_type);
void execute_external_command(char **tokenized_command);
void execute_command_with_path(char **tokenized_command);
void handle_invalid_command(char **tokenized_command);
void (*get_command_function(char *command))(char **);
char *get_environment_variable(const char *name);
void print_string(char *string, int stream);
void *reallocate_memory(void *ptr, unsigned int old_size, unsigned int new_size);
int string_compare(const char *first, const char *second);
void initialize_execution(char **current_command, int type_command);
char **tokenizer(char *input_string, const char *delim);
void remove_newline_character(char *str);
void remove_comment(char *input);
void handle_non_interactive_mode(void);
char *strdup(const char *s);
void free_string_array(char **arr);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

#endif /*SHELL_H*/
