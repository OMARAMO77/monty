#include "monty.h"

/**
* push - aa
* @stack: a
* @value: aa
* Return: nt
*/



void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
        (*stack)->prev = new_node;
    }

    *stack = new_node;
}
/**
* pall - aa
* @stack: a
* Return: nth
*/

void pall(stack_t **stack)
{
	stack_t *current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
* pint - aa
* @stack: a
* @line_number: aa
* Return: nt
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
* pop - aa
* @stack: a
* @line_number: aa
* Return: nt
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(top);
}
