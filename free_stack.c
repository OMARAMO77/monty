#include "monty.h"

/**
* free_stack - aa
* @stack: a
*
* Return: nth
*/

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
