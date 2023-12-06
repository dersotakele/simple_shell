#include "shell.h"

/**
 * pinpustr - prints an input string character
 * @strings: the string that can be printed
 *
 *
 * Return: 0
 */
void pinpustr(char *strings)
{
	if (!strings)
		return;
	for (int x = 0; strings[x] != '\0'; x++)
		writechar(strings[x]);
}

/**
 * writechar - it writies the char std eror
 * @ch: the character to be printed
 *
 * Return: 1 for success , -1 for errno
 */
int writechar(char ch)
{
	static int x;
	static char buffer[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || x >= WRITE_BUF_SIZE)
	{
		write(2, buffer, x);
			x = 0;
	}
	if (ch != BUF_FLUSH)
		buffer[x++] = ch;
	return (1);
}
