#include "monty.h"

/**
* add - aa
* @stack: a
* @line_number: aa
* Return: nt
*/


void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

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
 * sub - aa
 * @stack: aa
 * @line_number: aa
 * Return: nth
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * divide - aa
 * @stack: aa
 * @line_number: aa
 * Return: nth
 */
void divide(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
    }

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
    }

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);
}

/**
 * multiply - a
 * @stack: aa
 * @line_number: aa
 * Return: nth
 */
void multiply(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
    }

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
