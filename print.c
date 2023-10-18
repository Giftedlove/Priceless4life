#include "shell.h"

/**
 * print - prints the message to the standard output
 * @note: the message to be printed
 * Return: Always void
 */

void print(const char *note)
{
	write(STDOUT_FILENO, note, strlen(note));
}
