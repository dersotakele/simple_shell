#include "shell.h"

/**
 * handlestrtoint - is the function that used for convert str to int
 * @strings: the string cobertred to an integer
 * Return: -1 error ,0 no coverted num
 */
int handlestrtoint(char *strings)
{
	int x = 0;
	unsigned long int outcome = 0;

	if (*strings == '+')
		strings++;
	for (x = 0; strings[x] != '\0'; x++)
	{
		if (strings[x] >= '0' && strings[x] <= '9')
		{
			outcome *= 10;
			outcome += (strings[x] - '0');
			if (outcome > INT_MAX)
				return (-1);
		}
		else
		{
			return (-1);
		}
	}
	return (outcome);
}

/**
 * errorm - the function that prints an eror mesaage
 * @info: the parameter that used for an info sturuct
 * @streror: a string it conatins  asepciefe error meassage
 *
 * Return: -1 error  ,o no covert num
 */
void errorm(info_t *info, char *streror)
{
	writechare(info->firstname);
	writechare(": ");
	deciprint(info->line_counter, STDERR_FILENO);
	writechare(": ");
	writechare(info->argvs[0]);
	writechare(": ");
	writechare(streror);
}

/**
 * deciprint - it print decimal number
 * @inp: the input varaible
 * @n: file decriptor
 *
 * Return: nmber of char
 */
int deciprint(int inp, int n)
{
	int (*__putchar)(char) = (n = STDERR_FILENO) ? writechar : writechar;
	int counter = 0;
	unsigned int a, b;

	if (inp < 0)
	{
		a = -inp;
		__putchar('-');
		counter++;
	}
	else
	{
		a = inp;
	}
	b = a;
	for (int m = 1000000000; m > 1; m /= 10)
	{
		if (a / m)
		{
			__putchar('0' + b / m);
			counter++;
		}
		b %= m;
	}
	__putchar('0' + b);
	counter++;
	return (counter);
}


