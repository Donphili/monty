#include "monty.h"
/**
* delete_dnodeint_at_index - removes the node at given index
* @head: head of list
* @index: index of node
* Return: 1 assuming it succeeded, - 1 on the off chance that it fizzled
*/
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int i = 0;
	stack_t *tmp = *head, *back = NULL;

	if (head == NULL || tmp == NULL)
		return (-1);
	if (index == 0)
	{
		if (tmp->next != NULL)
			tmp->next->prev = NULL;
		*head = tmp->next;
		free(tmp);
		return (1);
	}
	while (i != index && tmp != NULL)
	{
		back = tmp;
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL)
		return (-1);
	back->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = back;
	free(tmp);
	return (1);

}