#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void add(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("success call\n");
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

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *secondTop = NULL;

	if (is_empty(*stack) || stack_size(*stack) < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	secondTop = (*stack)->next;
	secondTop->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * Div - divides the second top element of the stack
 * by the top element of the stack.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void Div(stack_t **stack, unsigned int line_number)
{
	stack_t *secondTop = NULL;

	if (is_empty(*stack) || stack_size(*stack) < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		dprintf(STDERR_FILENO, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	secondTop = (*stack)->next;
	secondTop->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies the second top element of the stack
 * with the top element of the stack.
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *secondTop = NULL;

	if (is_empty(*stack) || stack_size(*stack) < 2)
	{
		dprintf(STDERR_FILENO, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	secondTop = (*stack)->next;
	secondTop->n *= (*stack)->n;
	pop(stack, line_number);
}