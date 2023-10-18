#include "monty.h"

int int_data = 0;

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
		print_error("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
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
			opcode = tokens[0];
			int_data = _atoi(tokens[1]);
			f = get_opcode_instruction(opcode);
			if (f == NULL)
				dprintf(2, "L%u: unknown instruction\n", line_number);
			else
				f(&stack, line_number);
			free(tokens);
		}
		line_number++;
		free(lineptr);
	}
	fclose(test);
	(void) line_number, (void) opcode, (void) tokens, (void) f;
	return (0);
}
