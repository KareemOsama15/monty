#include "monty.h"

/**
 * swap - swaps the top two elements of the stack.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL, *next = NULL;

	if (is_empty(*stack) || stack_size(*stack) < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	next = (*stack)->next;
	current->prev = next;
	current->next = next->next;
	next->prev = NULL;
	next->next = current;
	*stack = next;
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	int pchar_value = 0;

	if (is_empty(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	pchar_value = (*stack)->n;
	if (pchar_value >= 0 && pchar_value <= 127)
		printf("%c\n", pchar_value);
	else
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (is_empty(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
