#include "monty.h"
/**
* push - forwards value to stack
* @stack: starting of stack
* @line_number: line number
*/
void push(stack_t **stack, unsigned int line_number)
{
	int element, index = 0;

	if (value == NULL)
	{
		error_int(line_number);
		exit(EXIT_FAILURE);
	}
	if (value[0] == '-')
		index++;
	for (; value[index]; index++)
	{
		if (value[index] >= '0' && value[index] <= '9')
			continue;
		error_int(line_number);
		exit(EXIT_FAILURE);
	}
	element = atoi(value);
	if (mode == 1)
		add_dnodeint_end(stack, element);
	else
		add_dnodeint(stack, element);
}
/**
* pall - Prints all components
* @stack: beginning of stack
* @line_number: line number
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse;
	(void)line_number;

	if (*stack == NULL || stack == NULL)
		return;
	traverse = *stack;

	while (traverse)
	{
		printf("%d\n", traverse->n);
		traverse = traverse->next;
	}

}
/**
* pint - prints first components
* @stack: starting of stack
* @line_number: line number
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		error_pint(line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
* pop - deletes top components
* @stack: starting of stack
* @line_number: line number
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL || stack == NULL)
	{
		error_pop(line_number);
		exit(EXIT_FAILURE);
	}
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
/**
* swap -swaps two components
* @stack: starting of stack
* @line_number: line number
*/
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack, *next = NULL;
	int leng = dlistint_len(*stack);

	if (leng < 2)
	{
		error_swap(line_number);
		exit(EXIT_FAILURE);
	}
	next = (*stack)->next;
	head->prev = next;
	head->next = next->next;
	next->next = head;
	next->prev = NULL;
	*stack = next;
}
