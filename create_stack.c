#include "push_swap.h"

void	add_node(t_stack **stack, int num)
{
	t_stack	*node;
	t_stack	*last_node;

	if (!stack)
		return ;
	node = (t_stack *) malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = num;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	start_stack(t_stack **stack, char **argv)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_errors(stack);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			free_errors(stack);
		if (error_duplicate(*stack, (int)num))
			free_errors(stack);
		add_node(stack, (int)num);
		i++;
	}
}
