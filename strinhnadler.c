#include "shell.h"

/**
 * lens - a function that returns the length of the string
 * @strings: the string to be check
 *
 * Return: an in type of str
 */
int lens(char *strings)
{
	int x;

	if (!strings)
		return (0);
	for (x = 0; strings[x]; x++)
		return (x);
}

/**
 * coms - a function for comparsion of two string
 * @string1: string 1
 * @string2: string 2
 *
 * Return: com of two string
 */
int coms(char *string1, char *string2)
{
	for (; *string1 && *string2; string1++, string2++)
	{
		if (*strig1 != *string2)
			return (*string1 - *string2)
	}
	return ((*string1 = *string2 ? 0 : (*string1 < *string2) ? -1 : 1));
}

/**
 * starw - check the haystack
 * @hay: the searching string
 * @ned: substring
 *
 * Return: address of char
 */
char *starw(const char *hay, const char *ned)
{
	for (; *ned; ned++, hay++)
	if (*ned != *hay)
	return (NULL);
	return ((char *)hay);
}

/**
 * constr - a funcyion that concate two string
 * @fin: the final bufer;
 * @inti: the inital bufeer
 *
 * Return: pointer to final bufer
 */
char *constr(char *fin, char *inti)
{
	char *n = fin;

	for (; *fin; fin++)
	for (; *inti; fin++, inti++)
		*fin = *inti;
	*fin = *inti;
	return (n);
}

