#include "shell.h"

/**
 * con_num - it convert the number
 * @number: number
 * @b: base
 * @f:flags
 *
 * Return: a str
 */
char con_num(long int number, int b, int f)
{
	static char *ar;
	static char buf[50];
	char si = 0;
	char *pt;
	unsigned long m = number;

	if (!(f & CONVERT_UNSIGNED) && number < 0)
	{
		m = -number;
		si = '-';
	}
	ar = f & CONVERT_LOWERCASE ? "0123456789abcdef" :  "0123456789ABCDEF";
	pt = &buf[49];
	*pt = '\0';
	while (m != 0)
	{
		*--pt = ar[m % b];
		n /= base;
	}
	if (si)
		*--pt = si;
	return (pt);
}

/**
 * replace_comm - it replace the coment # with'\0'
 * @buffer: string adress
 *
 * Return: void 0
 */
void replace_comm(char *buffer)
{
	for (int x = 0 ; buffer[x] != '\0'; x++)
	{
		if (buffer[x] == '#' && (!x || buffer[x - 1] == ' '))
		{
			buffer = '\0';
			break;
		}
	}
}


