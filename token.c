#include "shell.h"

/**
 * _split_line - split line
 * @buffer: line to split with ;
 * @argv: program name
 * Return: 2d array
 */
char **_split_line(char *buffer, char *argv)
{
	int i, j;
	int line_count;
	int len, k;
	char **hold;

	if (error_line(buffer, argv))
		return (NULL);
	line_count = count_word(buffer, ';');
	hold = (char **)malloc(sizeof(char *) * (line_count + 1));
	i = 0;
	line_count = 0;
	while (buffer[i])
	{
		j = i;
		len = 0;
		while (buffer[i] && buffer[i] != ';')
		{
			len++;
			i++;
		}
		hold[line_count] = (char *)malloc(sizeof(char) * len + 1);
		k = 0;
		while (buffer[j] && buffer[j] != ';')
		{
			hold[line_count][k] = buffer[j];
			k++;
			j++;
		}
		hold[line_count][k] = '\0';
		line_count++;
		if (buffer[i])
			i++;
	}
	hold[line_count] = NULL;
	return (hold);
}
/**
 * error_line - check error for ;
 * @line: line to check
 * @argv: program name
 * Return: 1 error 0 succuss
 */
int error_line(char *line, char *argv)
{
	if (!line)
		return (1);
	if (*line == ';')
	{
		_puts_fd(2, argv);
		_puts_fd(2, ": ");
		_puts_fd(2, "Syntax error: ");
		_putchar_fd(2, '"');
		_puts_fd(2, ";");
		_putchar_fd(2, '"');
		_puts_fd(2, " unexpected\n");

		return (1);
	}
	while (*line)
	{
		if (*line == ';')
		{
			if (*(line + 1) && *line == *(line + 1))
			{
				_puts_fd(2, argv);
				_puts_fd(2, ": ");

				_puts_fd(2, "Syntax error: ");
				_putchar_fd(2, '"');
				_puts_fd(2, ";;");
				_putchar_fd(2, '"');
				_puts_fd(2, " unexpected\n");
				return (1);
			}
		}
		line++;
	}
	return (0);
}
/**
 * trim_line - remove with space (still under test)
 * @str: string
 * @flag: flag
 * Return: new trim  line
 */
char *trim_line(char *str, int flag)
{
	char *new;
	int i, j;
	int len;
	int size;

	len = _strlen(str) - 1;
	size = len;

	i = 0;
	j = 0;
	while (_isspace(str[i]))
		i++;
	while (_isspace(str[len--]))
		j++;
	size = size - (i + j) + 1;
	new = (char *)malloc(sizeof(char) * size + 1);
	j = 0;
	while (i <= len + 1)
		new[j++] = str[i++];
	new[j] = '\0';
	if (flag)
		free(str);
	return (new);
}

/**
 * count_word - count number of word in string sep with d
 * @str: string
 * @d:  sep
 * Return: number of word
 */
int count_word(char *str, char d)
{
	int i;
	int numwords;

	i = 0;
	numwords = 0;
	while (str[i])
	{
		while (str[i] && str[i] == d)
			i++;
		if (!str[i])
			break;
		while (str[i] && str[i] != d)
			i++;
		numwords++;
	}
	return (numwords);
}
