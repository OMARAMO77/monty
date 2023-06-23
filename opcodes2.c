#include "monty.h"


/**
* nop - aa
* @stack: a
* @line_number: aa
* Return: nt
*/

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * print_char - aa
 * @stack: aa
 * @line_number: aa
 * Return: nt
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int value;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
    }

	value = (*stack)->n;
	if (value < 0 || value > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
    }
	putchar(value);
	putchar('\n');
}

/**
 * print_str - aa
 * @stack: aa
 * @line_number: aa
 * Return: nt
 */
void print_str(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL && current->n != 0 && (current->n >= 0 && current->n <= 127))
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
