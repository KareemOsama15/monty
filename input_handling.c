#include "monty.h"

/**
 * isreadable - check if the file at the file_path has the read permission
 *
 * @file_path: the path to the file to be checked
 *
 * Return: 0 on success, 1 on failure
*/
int isreadable(char *file_path)
{
	int isreadable;

	isreadable = access(file_path, F_OK);
	if (isreadable == -1)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (1);
	}
	isreadable = access(file_path, R_OK);
	if (isreadable == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file_path);
		return (1);
	}
	return (0);
}

/**
 * read_file - read the input file line by line
 *
 * @file: the file to be read
 *
 * Return: no return
*/
char *read_file(FILE *file)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t length_read = 0;

	length_read = getline(&lineptr, &n, file);
	if (length_read == -1)
	{
		free(lineptr);
		return (NULL);
	}
	return (lineptr);
}

value_t *int_data = NULL;

/**
 * line_tokenization - extract tokens from strings
 *
 * @str: string to be tokenized
 *
 * Return: array of string tokens
*/
char **line_tokenization(char *str)
{
	char **args, *token = NULL;

	args = malloc(sizeof(char *) * 2);
	if (args == NULL)
	{
		dprintf(2, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(str, " \t\n");
	args[0] = token;
	/*if (token != NULL && token[0] == '#' && args[0][0] == '#')
		return (NULL);*/

	token = strtok(NULL, " \t\n");
	args[1] = token;

	if (token == NULL)
	{
		int_data = NULL;
	}
	else
	{
		if (_isdigit(token))
		{
			int_data = malloc(sizeof(value_t));
			if (int_data == NULL)
			{
				dprintf(2, "Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			int_data->num = _atoi(token);
		}
		else
			int_data = NULL;
	}
	return (args);
}

/**
 * get_opcode_instruction - matches the opcode to the corresponding function
 *
 * @opcode: the opcode to be matched
 *
 * Return: the fuction related to the opcode
*/
void (*get_opcode_instruction(char *opcode))(stack_t **, unsigned int)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", Div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{NULL, NULL}
	};
	int i = 0;

	i = 0;
	while (instructions[i].opcode)
	{
		if (_strcmp(opcode, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}
