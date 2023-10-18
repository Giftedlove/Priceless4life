#include "shell.h"
#include <string.h>
#include <sys/stat.h>

int input_execcmd(char **input);
/**
 * This function implements the main logic of the shell.
 *
 * @argc: Number of arguments passed
 * @argv: Program arguments to be parsed
 * @return 0 on success
 */

int main(void)
{
	struct stat buffer;
	char *input;
	char *str;
	char *token;
	int i;
	char **love = NULL;
	char *alx = NULL;
	char *gifted = NULL;
	char *part = 0;
	char *current_love[1024];
	int type_love = 0;
	size_t n = 0;

	while (1)
	{
		type_love = isatty(STDIN_FILENO);
	if (type_love != 0)
		write(1,"$", strlen("$"));

	if (getline(&alx, &n, stdin) == -1)
	{
		free(alx);
		break;
	}

		/*remove_newline_character(alx);*/
		/*remove_comment(alx);*/
		/*love = tokenizer(alx, ";");*/

	input = strdup(alx);
	str =strdup(alx);
	token = strtok(str," \t\r");

	if (strcmp(input,"\n") == 0 || strcmp(token, "\n") == 0)
		continue;
	part = strtok(alx, " \n\r\t");
	i = 0;
	
	current_love[i] = part;
	i++;
	part = strtok(NULL," \n\r\t");
	for (;part != NULL; i++)
	{
		current_love[i] = part;
		part = strtok(NULL, " \n\r\t");
	}
	current_love[i] = NULL;
	if (strcmp(current_love[0],"exit") == 0 && current_love[1] == NULL)
		break;

	if (input_execcmd(current_love) == 0)
		continue;
/*	if (stat(current_love[0], &buffer) == -1)
	{
	perror("./hsh");
	continue;
	}*/
	if (type_love == 0)
		break;
	continue;
	/*for (int i = 0; love[i] != NULL; i++)
{
		current_love = tokenizer(love[i], " ");
	}
		if (current_love[0] == NULL)
		{
			free(current_love);
		}	break;
	}*/

	/*type_love = parse_command(current_love[0]);
	initialize execution(current_love, type_love);

	free(current_love);
	}
		free(love);
	}

	free(alx);
	return (part);*/
}
}
int input_execcmd(char **input)
{
	int check;
	struct stat buff;
	int status;
        pid_t pid;
        pid = fork();
	if (stat(input[0], &buff) != -1)
	{
        if (pid == -1)
        {
                return (1);
        }
        if (pid == 0)
        {
                if (execve(input[0], input, NULL)== -1)
                {
                        exit(1);
                }

        }
        else
        {
                check = wait(&status);
		if (check == 1)
		{
			return(1);
		}
		else
		{
			return(0);
		}
        }
	}
	return(1);

}
