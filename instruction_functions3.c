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
