#include "shell.h"

/**
 * writechare - it write the charcter to given n
 * @ch: the character to printed in this programm
 * @n: is the file decripte
 *
 * Return: 1 sucess,-1 on errorr
 */
int writechare(char ch, int n)
{
	static int m;
	static char buffer[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(n, buffer, m);
	m = 0;
	}
	if (ch != BUF_FLUSH)
		buffer[m++] = ch;
	return (1);
}

/**
 * pinpn - a function that prints input strings
 * @strings: the strings that can be printed
 * @n:file descriptor
 *
 * Return: number of chartrs that can printed
 */
int pinpn(char *strings, int n)
{
	int counter = 0;

	if (!strings)
		return (0);
	while (*strings)
	{
		counter += writechare(*st++, n);
	}
	return (counter);
}
