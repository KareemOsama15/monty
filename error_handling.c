#include "monty.h"

/**
 * print_error - prints the massage passed to the stderr
 *
 * @msg: the massage to be printed
 *
 * Return: no return
*/
void print_error(char *msg)
{
	size_t count;

	count = 0;
	while (msg[count] != 0)
		count++;
	write(STDERR_FILENO, msg, count);
}
