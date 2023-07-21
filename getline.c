#include "shell.h"

/**
 * newline - check for newline
 * @buffer: string
 * @size: size of string for op
 * Return: true or false
 */
int newline(char *buffer, int size)
{
	int i = 0;

	while (i < size)
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
/**
 * parse - concate buffer and hold
 * @buffer: buffer from read function
 * @hold: var for stoke file contain untile newline
 * Return: hold
 */
char *parse(char *buffer, char *hold)
{
	char *new;
	int blen;
	int hlen;
	int nlen;
	int i;

	blen = _strlen(buffer);
	if (hold)
		hlen = _strlen(hold);
	else
		hlen = 0;

	new = (char *)malloc(sizeof(char) * (hlen + blen + 1));

	for (nlen = 0; nlen < hlen; nlen++)
		new[nlen] = hold[nlen];
	for (i = 0; i < blen; nlen++, i++)
		new[nlen] = buffer[i];
	new[nlen] = '\0';
	if (hold)
		memdel(hold);
	return (new);
}

/**
 * get_line - get line from hold
 * @hold: hold line
 * @line: line
 * Return: line
 */
char *get_line(char *hold, char **line)
{
	int lsize;
	char *new;
	int hsize;
	int j, i;

	lsize = 0;
	for (i = 0; hold && hold[i] != '\0' && hold[i] != '\n'; i++)
		lsize++;
	memdel(*line);
	*line = (char *)malloc(sizeof(char) * lsize + 2);
	for (i = 0; i < lsize; i++)
		(*line)[i] = hold[i];
	(*line)[i] = '\0';
	hsize = _strlen(hold + lsize);
	if (hsize == 0)
		return (memdel(hold));

	new = (char *)malloc(sizeof(char) * hsize + 1);

	for (i = lsize + 1, j = 0; hold[i] != '\0'; i++, j++)
		new[j] = hold[i];

	new[j] = '\0';
	memdel(hold);
	return (new);
}
/**
 * _getline - get line from a file
 * @fd: file discription
 * @line: buffer to store line
 * Return: -1 on error 0 if file in finish 1 if still more
 */
int _getline(int fd, char **line)
{

	int readsize = 1;
	static char *hold;
	char buffer[READSIZE + 1] = {0};

	if (fd == -69)
	{
		memdel(hold);
		return (0);
	}
	if (fd < 0 || read(fd, buffer, 0) == -1)
		return (-1);
	while (!newline(buffer, readsize))
	{
		readsize = read(fd, buffer, READSIZE);
		buffer[readsize] = '\0';
		if (readsize == 0)
			break;

		hold = parse(buffer, hold);
	}

	hold = get_line(hold, line);

	if (hold == NULL)
		return (0);
	return (1);
}
