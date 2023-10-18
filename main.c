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
		printf("%s", lineptr);
		if (lineptr[0] != '\n')
		{
			tokens = line_tokenization(lineptr);
			opcode = tokens[0];
			int_data = _atoi(tokens[1]);
			f = get_opcode_instruction(opcode);
			if (f == NULL)
			{
				print_error("L");
				/* print_error(itoa(line_number, buffer, 10)); */
				print_error(": unknown instruction\n");
			}
			else
				f(NULL, line_number);
			printf("0: %s\n", opcode);
			printf("1: %d\n", int_data);
			free(tokens);
		}
		printf("===============================\n");
		line_number++;
		free(lineptr);
	}
	fclose(test);
	(void) line_number, (void) opcode, (void) tokens, (void) f;
	return (0);
}
