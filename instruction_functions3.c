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

	(void) line_number;
	current = *stack;
	while (current != NULL && current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}

/**
 * rotl - function make top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *firstElement = *stack;
	stack_t *newElement = NULL;

	(void) line_number;
	if (*stack == NULL)
		return;

	if (stack_size(*stack) > 1)
	{
		while (current->next != NULL)
			current = current->next;

		newElement = malloc(sizeof(stack_t));
		if (!newElement)
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		newElement->n = (*stack)->n;
		newElement->next = NULL;
		newElement->prev = current;
		current->next = newElement;
		*stack = (*stack)->next;
		free(firstElement);
	}
}

/**
 * rotr - function make The last element of the stack
 *  becomes the top element of the stack
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *lastElement = *stack;
	stack_t *newElement = NULL, *temp = NULL;

	(void) line_number;
	if (*stack == NULL)
		return;

	if (stack_size(*stack) > 1)
	{
		while (lastElement->next != NULL)
			lastElement = lastElement->next;
		temp = lastElement->prev;

		newElement = malloc(sizeof(stack_t));
		if (!newElement)
		{
			dprintf(STDERR_FILENO, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		newElement->n = lastElement->n;
		newElement->next = *stack;
		newElement->prev = NULL;

		(*stack)->prev = newElement;
		*stack = newElement;

		temp->next = NULL;
		free(lastElement);
	}
}
