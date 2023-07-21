#include "shell.h"
/**
 * subprint - print a sub string
 * @str: string
 * @c: end of sub string
 * Return: void
 */
void subprint(char *str, char c)
{
	while (*str && *str != c)
		write(1, str++, 1);
}
/**
 * _putchar - putchar
 *@c: go and read nigga
 * Return: 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - putchar
 *@str: go and read nigga
 * Return: 1
 */
int _puts(char *str)
{
	int len;

	len = _strlen(str);
	write(1, str, len);
	return (len);
}
