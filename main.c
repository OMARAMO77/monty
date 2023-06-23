#include "monty.h"

/**
* main - aa
* @argc: a
* @argv: aa
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	unsigned int line_number = 0;
	char line[MAX_LINE_LENGTH];
	char *opcode = NULL, *arg;
	FILE *file;
	int value;
	stack_t *stack = NULL;
	void (*op_func)(stack_t **, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		line_number++;
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
			continue; /* Skip empty lines and comments */
		op_func = select_op(opcode);
		if (op_func == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			if (arg == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				fclose(file);
				free_stack(stack);
				exit(EXIT_FAILURE);
			}
			value = atoi(arg);
			push(&stack, value);
		}
		else
			op_func(&stack, line_number);
	}
	fclose(file);
	free_stack(stack);
	return (EXIT_SUCCESS);
}
