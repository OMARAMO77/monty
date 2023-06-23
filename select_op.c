#include "monty.h"

/**
  * select_op - selects the corresponding opcode function
  * @str: The instruction to be executed
  *
  * Return: pointer to the function if the opcode exists or
  * NULL othewise
  */
void (*select_op(char *str))(stack_t **, unsigned int)
{
	instruction_t opcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{NULL, NULL}
	};
	int i = 0;

	while (opcs[i].opcode)
	{
		if (strcmp(str, opcs[i].opcode) == 0)
			return (opcs[i].f);
		++i;
	}
	return (NULL);
}
