#include "monty.h"

/**
 * push - pushes one element to the top of the stack
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
		dprintf(2, "L%u: Error: malloc failed\n", line_number);
		exit(EXIT_FAILURE);
	}

	newElement->n = int_data;
	newElement->prev = NULL;
	newElement->next = *stack;
	if (!isEmpty(*stack))
		(*stack)->prev = newElement;
	*stack = newElement;
}

/**
 * push - pushes one element to the top of the stack
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

	if (isEmpty(*stack))
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * push - pushes one element to the top of the stack
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (isEmpty(*stack))
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d", (*stack)->n);
}

/**
 * push - pushes one element to the top of the stack
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (isEmpty(*stack))
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free(current);
}

/**
 * push - pushes one element to the top of the stack
 *
 * @stack: the stack to be used
 * @line_number: the instruction line number
 *
 * Return: no return
*/
void swap(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("success call\n");
}

/**
 * push - pushes one element to the top of the stack
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
 * push - pushes one element to the top of the stack
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
	printf("success call\n");
}

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *secondTop = NULL;

	if (isEmpty(*stack) || stack_size(*stack) < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	secondTop = (*stack)->next;
	secondTop->n -= (*stack)->n;
	pop(stack, line_number);
}


void Div(stack_t **stack, unsigned int line_number)
{
	stack_t *secondTop = NULL;

	if (isEmpty(*stack) || stack_size(*stack) < 2)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	if ((*stack)->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	} 
	secondTop = (*stack)->next;
	secondTop->n /= (*stack)->n;
	pop(stack, line_number);
}

void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *secondTop = NULL;

	if (isEmpty(*stack) || stack_size(*stack) < 2)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	secondTop = (*stack)->next;
	secondTop->n *= (*stack)->n;
	pop(stack, line_number);
}
