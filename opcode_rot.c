#include "monty.h"

/**
 * rot_to_top - aa
 * @stack: aa
 * @line_number: aa
 * Return: nt
 */
void rot_to_top(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *last = *stack;
	(void)line_number;

	if (current == NULL || current->next == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	*stack = current->next;
	(*stack)->prev = NULL;
	last->next = current;
	current->prev = last;
	current->next = NULL;
}

/**
 * rot_to_bottom - aa
 * @stack: aa
 * @line_number: aa
 * Return: nt
 */
void rot_to_bottom(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	stack_t *last = *stack;
	(void)line_number;

	if (current == NULL || current->next == NULL)
		return;

	while (last->next != NULL)
		last = last->next;

	last->next = current;
	current->prev = last;
	*stack = current->next;
	(*stack)->prev = NULL;
	current->next = NULL;
}
