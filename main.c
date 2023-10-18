#include "monty.h"

/**
 * main - Entry point of the program
 *
 * @argc: arguments count
 * @argv: array of the arguments
 *
 * Return: Always 0
*/
int main(int argc, char *argv[])
{
	FILE *test = NULL;
	char *file_path = argv[1], *lineptr = NULL;
	char **tokens = NULL, *opcode = NULL;
	void (*f)(stack_t **stack, unsigned int line_number) = NULL;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	if (isreadable(file_path))
		exit(EXIT_FAILURE);
	test = fopen(file_path, "r");
	while (1)
	{
		lineptr = read_file(test);
		if (lineptr == NULL)
			break;
		if (lineptr[0] != '\n')
		{
			tokens = line_tokenization(lineptr);
			if (tokens[0] == NULL || tokens[0][0] == '#')
				continue;
			opcode = tokens[0];
			f = get_opcode_instruction(opcode);
			if (f == NULL)
			{
				dprintf(2, "L%u: unknown instruction %s\n", line_number, tokens[0]);
				exit(EXIT_FAILURE); }
			else
			{
				f(&stack, line_number);
				free(int_data); }
			free(tokens);
		}
		line_number++;
		free(lineptr); }
	fclose(test), free_stack(&stack, line_number);
	return (0);
}
