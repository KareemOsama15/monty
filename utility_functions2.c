#include "monty.h"

/**
 * is_empty - checks if a stack is empty
 *
 * @stack: head pointer of the stack
 *
 * Return: 0 on success, 1 on failure
*/
bool is_empty(stack_t *stack)
{
	return (stack == NULL);
}

/**
 * stack_size - calculates a stack size
 *
 * @stack: head pointer of the stack
 *
 * Return: size of the stack
*/
int stack_size(stack_t *stack)
{
	stack_t *current = stack;
	int count = 0;

	if (is_empty(stack))
		return (count);
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

/**
 * free_stack - frees the allocated memory to a stack
 *
 * @stack: the head pointer address of the stack
 * @line_number: arbitrary value just passed for the struct constraint
 *
 * Return: no return
*/
void free_stack(stack_t **stack, unsigned int line_number)
{
	while (!is_empty(*stack))
	{
		pop(stack, line_number);
	}
	*stack = NULL;
}
