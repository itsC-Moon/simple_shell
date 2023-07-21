#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"
/**
 * path - test env
 *
 *@input: input
 * Return: buffer
 */
char *path(char *input)
{
	trim(input);
	return (input);
}
/**
 * empty - return true if it empty
 *
 *@str: input
 * Return: bool
 */
int empty(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (!_isspace(str[i]))
			return (0);
		i++;
	}
	return (1);
}
/**
 * _isspace - check white space
 *
 *@c: input
 * Return: bool
 */
int _isspace(char c)
{
	if (c == '\n' || c == '\v' || c == ' ' || c == '\t' || c == '\f')
		return (1);
	return (0);
}
/**
 * trim - check white space
 *
 *@str: input
 * Return: bool
 */
int trim(char *str)
{
	int start = 0;
	int end;
	int i, j;

	if (empty(str))
		return (-1);
	end = strlen(str) - 1;
	while (_isspace(str[start]))
	{
		start++;
	}

	while (end >= start && _isspace(str[end]))
	{
		end--;
	}

	for (i = start, j = 0; i <= end; i++, j++)
	{
		str[j] = str[i];
	}

	str[j] = '\0';
	return (1);
}
