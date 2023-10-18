#include "monty.h"

/**
* _isdigit - checks the input character whether it is a digit or not
*
* @chr: pointer to user input
*
* Return: 1 on success, 0 on failure
*/
int _isdigit(char chr)
{
	if (chr >= 48 && chr <= 57)
		return (1);
	return (0);
}

/**
 * _atoi - converts a string number to integer
 *
 * @str: string to be converted
 *
 * Return: the resulting integer
 */
int _atoi(const char *str)
{
	int num = 0, sign = 1, i = 0;

	while (str[i] == ' ')
		i++;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}

	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}

	return (num * sign);
}

/**
 * _strcmp - compares two strings
 *
 * @s1: first string to be compared
 * @s2: second string to be compared
 *
 * Return: comparison integer
*/
int _strcmp(char *s1, char *s2)
{
	int i, diff;

	diff = 0;
	i = 0;
	while (diff == 0)
	{
		if ((s1[i] == 0) && (s2[i] == 0))
			break;
		diff += s1[i] - s2[i];
		i++;
	}
	return (diff);
}
