#include "monty.h"

/**
 * queue - function check to implement queue.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void queue(stack_t **stack, unsigned int line_number)
{
	(void) *stack, (void) line_number;
	int_data.lifo = 1;
}

/**
 * stack - function check to implement stack.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void stack(stack_t **stack, unsigned int line_number)
{
	(void) *stack, (void) line_number;
	int_data.lifo = 0;
}

/**
 * push_stack - function format of the data to a stack (LIFO).
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void push_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *newElement = malloc(sizeof(stack_t));
	(void) line_number;

	if (!newElement)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newElement->n = int_data.num;
	newElement->prev = NULL;
	newElement->next = *stack;
	if (!is_empty(*stack))
		(*stack)->prev = newElement;
	*stack = newElement;
}

/**
 * push_queue - function format of the data to a stack (FIFO).
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void push_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *newElement = NULL;
	stack_t *tail = NULL;
	(void) line_number;

	newElement = malloc(sizeof(stack_t));
	if (!newElement)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	newElement->n = int_data.num;
	newElement->next = NULL;
	if (is_empty(*stack))
	{
		newElement->prev = NULL;
		*stack = newElement;
	}
	else
	{
		tail = *stack;
		while (tail->next != NULL)
			tail = tail->next;
		newElement->prev = tail;
		tail->next = newElement;
	}
}
