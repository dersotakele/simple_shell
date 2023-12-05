#include "shell.h"

/**
 * interactive_mode - shell is in interactive mode if it return the true value
 * @info: the address of the the structure
 *
 * Return: 1 it is intercative,0 otherwise
 */
int interactive_mode(info_t *info)
{
	if (isatty(STDIN_FILENO) && info->readfd <= 2)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * check_alpha - that can check the aphabetic character
 * @ch: the inputs of the char
 *
 * Return: it return 1 if ch is alpahebetic ,otherwise 0
 */
int check_alpha(int ch)
{
	return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

/**
 * _delimeter- that check the character is  adelimeter
 * @ch: A charcter checks
 * @delimeter: delimeter od string
 *
 * Return: true if is 1,false 0
 */
int _delimeter(char ch, char *delimeter)
{
	int j = 0;

	while (delimeter[j] != '\0')
	{
		if (ch == delimeter[j])
		{
			return (1);
		}
		j++;
	}
	return (0);
}

/**
 * string_toint -  afunction convert strings to int
 * @string: the string tha onverts to intger
 *
 * Return: if no number in string 0, otherwise converted number
 */
int string_toint(char *string)
{
	int n = 0;
	int signe = 1, out, flags = 0;
	unsigned int outcome = 0;

	while (string[n] != '\0' && flags != 2)
	{
		if (string[n] == '-')
		{
			signe *= -1;
		}
		else if (string[n] >= '0' && string[n] <= '9')
		{
			flags = 1;
			outcome *= 10;
			outcome += (string[n] - '0');
		}
		else if (flags == 1)
		{
			flags = 2;
		}
		n++;
	}
	if (signe == -1)
	{
		out = -outcome;
	}
	else
	{
		out = outcome;
	}
	return (out);
}
