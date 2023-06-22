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
	char *opcode, *arg;
	FILE *file;
	int value;
	stack_t *stack = NULL;
	
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
		line_number++;

		opcode = strtok(line, " \t\n");
		if (opcode == NULL || opcode[0] == '#')
		{
			continue;  /*Skip empty lines and comments*/
		}
		if (strcmp(opcode, "push") == 0)
		{
			arg = strtok(NULL, " \t\n");
			if (arg == NULL)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				fclose(file);
				return (EXIT_FAILURE);
			}
			value = atoi(arg);
			push(&stack, value);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, line_number);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, line_number);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			return (EXIT_FAILURE);
		}
	}
	fclose(file);
	/*Free the remaining stack (if any)*/
	return (EXIT_SUCCESS);
}
