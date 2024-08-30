#include "push_swap.h"

void	current_index(t_stack *node)
{
	int	i;
	int	mid;

	i = 0;
	if (!node)
		return ;
	mid = length_stack(node) / 2;
	while (node)
	{
		node->index = i;
		if (i <= mid)
			node->above_median = 1;
		else
			node->above_median = 0;
		node = node->next;
		i++;
	}
}

static void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*current_b;
	t_stack	*target_node;
	long	best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		current_b = stack_b;
		while (current_b)
		{
			if (current_b->value < stack_a->value
				&& current_b->value > best_match_index)
			{
				best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target_node = find_max(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

static void	cost_analysis(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = length_stack(stack_a);
	len_b = length_stack(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->index;
		if (!(stack_a->above_median))
			stack_a->push_cost = len_a - (stack_a->index);
		if (stack_a->target_node->above_median)
			stack_a->push_cost += stack_a->target_node->index;
		else
			stack_a->push_cost += len_b - (stack_a->target_node->index);
		stack_a = stack_a->next;
	}
}

void	set_cheapest(t_stack *node)
{
	long	cheapeast_value;
	t_stack	*cheapeast_node;

	if (!node)
		return ;
	cheapeast_value = LONG_MAX;
	while (node)
	{
		if (node->push_cost < cheapeast_value)
		{
			cheapeast_value = node->push_cost;
			cheapeast_node = node;
		}
		node = node->next;
	}
	cheapeast_node->cheapest = 1;
}

void	prepare_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis(stack_a, stack_b);
	set_cheapest(stack_a);
}
