#include "monty.h"

/**
*addnode - ...
*@head: ...
*@n: ...
*Return: ...
*/
void addnode(stack_t **head, int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
