int input_execcmd(char **input)
{
	pid_t pid;
	pid = fork();
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
		wait(NULL);
		return(0);
	}

}
