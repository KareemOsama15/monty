#include "monty.h"

/**
 * check_file - function check for file and argv
 *
 * @argc: arguments count
 * @argv: array of the arguments
 *
 * Return: file
*/
FILE *check_file(int argc, char *argv[])
{
	FILE *fd;
	char *file_path = argv[1];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (isreadable(file_path))
		exit(EXIT_FAILURE);
	fd = fopen(file_path, "r");

	return (fd);
}

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
	FILE *file = NULL;
	char *lineptr = NULL, **tokens = NULL;
	unsigned int line_number = 1;
	stack_t *stack = NULL;

	file = check_file(argc, argv);
	while (1)
	{
		lineptr = read_file(file);
		if (lineptr == NULL)
		{
			free(lineptr);
			break;
		}
		if (lineptr[0] != '\n')
		{
			tokens = line_tokenization(lineptr);
			if (tokens[0] == NULL || tokens[0][0] == '#')
			{
				free(lineptr);
				free(tokens);
				continue;
			}
			run_opcode(tokens[0], line_number, &stack);
			free(tokens);
		}
		line_number++;
		free(lineptr);
	}
	fclose(file);
	free_stack(&stack, line_number);
	return (0);
}
