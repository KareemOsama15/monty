#include "monty.h"

bool isEmpty(stack_t *stack)
{
    return (stack == NULL);
}

int stack_size(stack_t *stack)
{
	stack_t *current = stack;
	int count = 0;

	if (isEmpty(stack))
		return (count);
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

void destroy(stack_t **stack, unsigned int line_number)
{
	while (!isEmpty(*stack))
	{
		pop(stack, line_number);
	}
	*stack = NULL;
}
