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
/**
 *_atoi - converts a string to an integer
 *@s: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;
	int legal = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			legal = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1 || legal == 0)
		return (-1);
	output = result;
	return (output);
}
