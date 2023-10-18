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

	isreadable = access(file_path, R_OK);
	if (isreadable == -1)
	{
		print_error("Error: Can't open file ");
		print_error(file_path);
		print_error("\n");
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

/**
 * line_tokenization - extract tokens from strings
 *
 * @str: string to be tokenized
 *
 * Return: array of string tokens
*/
char **line_tokenization(char *str)
{
	char **tokens, *token = NULL;

	tokens = malloc(sizeof(char *) * 2);
	if (tokens == NULL)
		return (NULL);

	token = strtok(str, " \t\n");
	tokens[0] = token;

	token = strtok(NULL, " \t\n");
	if (token != NULL)
	{
		if (_isdigit(token[0]))
			tokens[1] = token;
		else
			tokens[1] = "-1";
	}
	else
		tokens[1] = "-1";
	return (tokens);
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
