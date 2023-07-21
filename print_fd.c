#include "shell.h"
/**
 * _putnbr_fd - print number to file descriptor
 * @fd: file dicription
 * @nb: number
 * Return: void
 */
void _putnbr_fd(int fd, int nb)
{
	unsigned int n;

	n = nb;
	if (nb < 0)
	{
		n *= -1;
		_putchar_fd(2, '-');
	}

	if (n < 10)
		_putchar_fd(fd, n + 48);
	else
	{
		_putnbr_fd(fd, n / 10);
		_putnbr_fd(fd, n % 10);
	}
}
/**
 * _putchar_fd - print a char to file descriptor
 * @fd: file descriptor
 * @c: char
 * Return: 1 on success -1 error
 */
int _putchar_fd(int fd, char c)
{
	return (write(fd, &c, 1));
}
/**
 * _puts_fd - print to file discription
 * @fd: file discription
 * @str: string to print
 * Return: void
 */
void _puts_fd(int fd, char *str)
{
	int len;

	len = _strlen(str);
	write(fd, str, len);
}
