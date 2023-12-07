#include "shell.h"

/**
 * hisdisp - it displays history lis
 * @info: potential argument
 *
 * Return: 0
 */
int hisdisp(info_t *info)
{
	printl(info->histories);
	return (0);
}

/**
 * unseta - a function that alias the to string
 * @info: parameter struct
 * @strings: the string
 *
 * Return: o on sucess, 1 on error
 */
int unseta(info_t *info, char *strings)
{
	char *q;
	int n;

	q = stchar(strings, '=');
	if (!q)
		return (1);
	for (; *q != '\0'; q++)
	{
		char ch = *q;
		*q = '\0';
		n = dn(&(info->alias), gn(info->alias, ns(info->alias, strings, -1)));
		*q = ch;
		return (n);
	}
	return (n);
}

/**
 * seta -  a function that set to string
 * @info: parameter struct
 * @strings: ths string alias
 *
 * Return: o for suces , 1 eror
 */
int seta(info_t *info, char *strings)
{
	char *q;

	q = stchar(strings, '=');
	if (!q)
		return (1);
	while (*q != '\0')
	{
		if (!*++ q)
			return (unseta(info, strings));
	}
	unseta(info, strings);
	return (an(&(info->alias), strings, 0) == NULL);
}

/**
 * printa - print an alias string
 * @n:the alias node
 *
 * Return: o succes , 1 error
 */
int printa(lists_t *n)
{
	char *q = NULL, *b = NULL;

	if (n)
	{
		q = stchar(n->strings, '=');
		for (b = n->strings; b <= q; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * mima - mimics the alias bultin
 * @info: potential arrgument
 *
 * Return: o
 */
int mima(info_t *info)
{
	int x = 0;
	char *q = NULL;
	lists_t *n = NULL;

	if (info->argcs == 1)
	{
		n = info->alias;
		while (n)
		{
			printa(n);
			n = n->next;
		}
		return (0);
	}
	for (x = 1; info->argvs[x]; x++)
	{
		q = stchar(info->argvs[x], '=');
		if (q)
		{
			seta(info, info->argvs[x]);
		}
		else
		{
			lists_t *match_node = ns(info->alias, info->argv[i], '=');

			printa(match_node);
		}
	}
	return (0);
}
