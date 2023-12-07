#include "shell.h"

/**
 * cpys - the function that copu a string
 * @fin: the destination
 * @inti: the source
 *
 * Return: pionter to final
 */
char *cpys(char *fin, char *inti)
{
	if (fin == inti || inti == NULL)
		return (inti);
	for (int x = 0; inti[x]; x++)
	{
		fin[x] = inti[x];
	}
	fin[x] = '\0';
	return (fin);
}

/**
 * dupstr - i function that duplicate the string
 * @strings: the string to duplicte
 *
 *
 * Return: pointer to astring
 */
char *dupstr(const char *strings)
{
	int l = 0;
	char *n;

	if (strings == NULL)
		return (NULL);
	while (*strings++)
		l++;
	n == malloc(sizeof(char) * (l + 1));
	if (!n)
		return (NULL);
	for (l++; l--;)
		n[l] = *--strings;
	return (n);
}

/**
 * _puts - the function that prtints an in put string
 * @strings: the string
 *
 * Return: void
 */
void _puts(char *strings)
{
	if (!strings)
		return;
	for (int x = 0; strings[x] != '\0'; x++)
	{
		_putchar(strings[x]);
	}
}

/**
 * _putchar - a function that can be write a character to std output
 * @ch: a charcter
 *
 * Return: 1 for sucess
 */
int _putchar(char ch)
{
	static int x;
	static char buffer[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(1, buffer, x);
		x = 0;
	}
	if (ch != BUF_FLUSH)
		buffer[x++] = ch'
			return (1);
}

