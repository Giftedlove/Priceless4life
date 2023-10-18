#include "shell.h"

/**
 * strdup - function that duplicates a string
 *
 * Return: duplicated string;
 */

char *strdup(const char *s)
{
    size_t len = strlen(s) + 1;
    char *p = malloc(len);
    if (p != NULL)
        memcpy(p, s, len);
    return p;
}

/**
 * free_string_array - function to free memory allocated for an array of strings
 *
 */

void free_string_array(char **arr)
{
    if (arr == NULL)
        return;

    for (int i = 0; arr[i] != NULL; i++)
    {
        free(arr[i]);
    }

    free(arr);
}


/**
 * _strlen - returns the lenght of a string
 * @s: pointer that checks the lenght of a string
 * Return: 0
 */
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
return (0);
}


/**
 * *_strcpy - copies the string pointed by pointer src
 * to bufferpointed to by dest
 * @src: char type string
 * @dest: char type string
 * Return: Always 0
 */
char *_strcpy(char *dest, char *src)
{
	int x;

	for (x = 0; *(src + x) != '\0'; x++)
	{
		*(dest + x) = *(src + x);
	}
	*(dest + x) = '\0';

return (dest);
}


/**
 * _strcat - function that concatenates two strings
 * @src: string one
 * @dest: string two
 * Return: 0
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
