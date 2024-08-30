#include "push_swap.h"

int	error_syntax(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-')
		&& !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

int	error_duplicate(t_stack *node, int num)
{
	if (!node)
		return (0);
	while (node)
	{
		if (node->value == num)
			return (1);
		node = node->next;
	}
	return (0);
}

void	free_stack(t_stack **node)
{
	t_stack	*temp;
	t_stack	*current;

	if (!node)
		return ;
	current = *node;
	while (current)
	{
		temp = current->next;
		current->value = 0;
		free(current);
		current = temp;
	}
	*node = NULL;
}

void	free_errors(t_stack **stack_a)
{
	free_stack(stack_a);
	write(2, "Error\n", 6);
	exit(1);
}
