#include "monty.h"

/**
 * push - pushes an element to the stack.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newElement = malloc(sizeof(stack_t));

	if (!newElement)
	{
		dprintf(STDERR_FILENO, "L%u: Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (int_data == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	newElement->n = int_data->num;
	newElement->prev = NULL;
	newElement->next = *stack;
	if (!is_empty(*stack))
		(*stack)->prev = newElement;
	*stack = newElement;
}

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	if (is_empty(*stack))
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (is_empty(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (is_empty(*stack))
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(current);
}

/**
 * nop - doesn’t do anything.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
