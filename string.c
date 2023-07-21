#include "shell.h"
/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strncmp - compare n char from both string
 * @s1: frist string
 * @s2: scond string
 * @n: number of char to compare
 * Return: 0 if equal
 */
int _strncmp(char *s1, char *s2, int n)
{
	while ((*s1 || *s2) && n > 0)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}

/**
 * emptystring - retrun an empty string aka == '\0'
 * @ptr: pointer to set free
 * Return: string
 */
char *emptystring(char *ptr)
{

	char *new;

	new = (char *)malloc(1);
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
	assert(new != NULL);
	*new = '\0';
	return (new);
}

/**
 * _join - join two string with a sep (dest->sep->src)
 * @dest: frist string
 * @src: second string
 * @sep: sep
 * Return: new join string
 */
char *_join(char *dest, char *src, char *sep)
{
	int i;
	char *new;

	i = _strlen(src) + _strlen(sep) + _strlen(dest);
	new = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (dest && *dest)
	{
		new[i] = *dest;
		dest++;
		i++;
	}
	while (sep && *sep)
	{
		new[i] = *sep;
		sep++;
		i++;
	}
	while (src && *src)
	{
		new[i] = *src;
		src++;
		i++;
	}
	new[i] = '\0';
	return (new);
}
