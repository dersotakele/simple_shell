# include "shell.h"

/**
 * strword - it separate or split astring in to word
 * * @str: the input string
 * @d: the string delimeter
 *
 * Return: string array on sucess,NULL on error
 */
char **strword(char *str, char *d)
{
	int n = 0;
	int i, j, m, p;
	char **c;

	if (!str || !str[0])
		return (NULL);
	d = d ?: " ";
	for (i = 0; str[i]; ++i)
	{
		if (!_delimeter(str[i], d) && (_delimeter(str[i + 1], d) || !str[i + 1]))
			n++;
	}
	if (!n)
		return (NULL);
	c = malloc((n + 1) * sizeof(char *));
	if (!c)
		return (NULL);
	for (i = 0, j = 0; j < n; ++j)
	{
		while (_delimeter(str[i], d))
			++i;
		m = 0;
		while (!_delimeter(str[i + m], d) && str[i + m])
		m++;
		c[j] = malloc((m + 1) * sizeof(char));
		if (!c[j])
		{
			for (m = 0; m < j; m++)
				free(c[j]);
			free(c);
			return (NULL);
		}
		for (p = 0; p < m; ++p)
			c[j][p] = str[i++];
		c[j][m] = 0;
	}
	c[j] = NULL;
	return (c);
}

